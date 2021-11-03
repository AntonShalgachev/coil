#include <iostream>
#include <entt/entt.hpp>

#include "dapi/DebugApi.h"
#include "network/NetworkService.h"
#include "gui/CursesWindow.h"
#include "ec/ComponentFramework.h"
#include "demo/ec/Demo.h"
#include "gui/NotificationManager.h"
#include "Services.h"
#include "utils/Timer.h"
#include "demo/ec/BarComponent.h"
#include "demo/ec/FooComponent.h"
#include "cmdapi/CommandListener.h"
#include "utils/FuncTraits.h"
#include "cmdapi/VariadicArg.h"
#include "cmdapi/tests/Test.h"

// namespace ecs
// {
//     struct position {
//         float x;
//         float y;
//     };
// 
//     struct velocity {
//         float dx;
//         float dy;
//     };
// 
//     void update(entt::registry &registry) {
//         auto view = registry.view<const position, velocity>();
// 
//         // use a callback
//         view.each([](const auto &pos, auto &vel) { /* ... */ });
// 
//         // use an extended callback
//         view.each([](const auto entity, const auto &pos, auto &vel) { /* ... */ });
// 
//         // use a range-for
//         for (auto[entity, pos, vel] : view.each()) {
//             // ...
//         }
// 
//         // use forward iterators and get only the components of interest
//         for (auto entity : view) {
//             auto &vel = view.get<velocity>(entity);
//             // ...
//         }
//     }
// 
//     void test() {
//         entt::registry registry;
// 
//         for (auto i = 0u; i < 10u; ++i) {
//             const auto entity = registry.create();
//             registry.emplace<position>(entity, i * 1.f, i * 1.f);
//             if (i % 2 == 0) { registry.emplace<velocity>(entity, i * .1f, i * .1f); }
//         }
// 
//         update(registry);
//     }
// }

namespace
{
    class CommandExecutioner
    {
    public:
        virtual ~CommandExecutioner() = default;

        virtual std::string name() const = 0;
        virtual std::string execute(std::string const& command) = 0;
    };

    class DebugApiExecutioner : public CommandExecutioner
    {
    public:
        DebugApiExecutioner(dapi::DebugApi& api) : m_api(api) {}

        std::string name() const override { return m_api.getName(); }
        std::string execute(std::string const& command) override
        {
            auto result = m_api.execute(command);

            std::stringstream ss;
            ss << result.output;
            if (!result.errorMessage.empty())
                ss << result.errorMessage << std::endl;
            return ss.str();
        }

    private:
        dapi::DebugApi& m_api;
    };

    class CommandListenerExecutioner : public CommandExecutioner
    {
    public:
        CommandListenerExecutioner(cmdapi::CommandListener& listener) : m_listener(listener) {}

        std::string name() const override { return "Command listener"; }
        std::string execute(std::string const& command) override
        {
            cmdapi::ExecutionResult result = m_listener.execute(command);

            std::stringstream ss;
            for (const auto& error : result.errors)
                ss << error << std::endl;
            ss << result.output;
            return ss.str();
        }

    private:
        cmdapi::CommandListener& m_listener;
    };
}

class App
{
public:
    void run()
    {
        init();
        loop();
    }

private:
    void init()
    {
		createServices();
        createCommandExecutioner();
		setupServices();

		ec_demo::Demo demo{ m_services };
		demo.createEntities(m_ecWorld);
    }

    void loop()
    {
        utils::Timer frameTimer;

		while (true)
		{
            float const dt = frameTimer.loop();
			update(dt);
		}
    }

    void update(float dt)
    {
        network::NetworkService* const networkService = m_services.getNetworkService();
        gui::NotificationManager* const notificationManager = m_services.getNotificationManager();

        m_ecWorld.update(dt);
        if (networkService)
            networkService->update();
        if (notificationManager)
            notificationManager->update(dt);

        draw();
    }

    void draw()
    {
        gui::CursesWindow* const window = m_services.getWindow();
        network::NetworkService* const networkService = m_services.getNetworkService();
        gui::NotificationManager* const notificationManager = m_services.getNotificationManager();

        if (!window)
            return;

        window->clear();

        int const w = window->getWidth();
        int const h = window->getHeight();

        std::string demoState = getWorldDebugInfo();
        window->print(demoState.c_str());

        if (networkService)
            window->printCentered(w / 2, h - 1, "Connected clients: %d", networkService->getSessionsAmount());

        if (notificationManager)
            notificationManager->draw(*window);

        window->refresh();
    }

    void createServices()
    {
        try
        {
            m_services.setNetworkService(std::make_unique<network::NetworkService>());
            m_services.setWindow(std::make_unique<gui::CursesWindow>());
            m_services.setNotificationManager(std::make_unique<gui::NotificationManager>());
            m_services.setDebugApi(std::make_unique<dapi::DebugApi>());
        }
        catch (std::exception const& e)
        {
            onError(e.what());
        }
    }

    void createCommandExecutioner()
    {
        if (auto* debugApi = m_services.getDebugApi())
            m_commandExecutioner = std::make_unique<DebugApiExecutioner>(*debugApi);

        //m_commandExecutioner = std::make_unique<CommandListenerExecutioner>(m_commandListener);
    }

    void setupServices()
    {
        network::NetworkService* const networkService = m_services.getNetworkService();
        dapi::DebugApi* const debugApi = m_services.getDebugApi();
        gui::NotificationManager* const notificationManager = m_services.getNotificationManager();

        std::string welcomeMessage = "<No command executioner created>";
        if (m_commandExecutioner)
        {
            welcomeMessage = m_commandExecutioner->name();
        }

        if (networkService)
        {
            networkService->setWelcomeMessage(std::move(welcomeMessage));
            networkService->setExecuteCommandFunc([this](std::string const& command)
            {
                return executeCommand(command);
            });
            networkService->start(8080);
        }

        if (gui::CursesWindow* const window = m_services.getWindow())
            window->hideCursor();

        if (debugApi)
        {
            debugApi->registerObject("debugApi", debugApi, "Debug API");
            debugApi->registerObject("networkService", networkService, "Network service");
            debugApi->registerObject("notificationManager", notificationManager, "Notification manager");
            debugApi->registerObject("ecWorld", &m_ecWorld, "EC world");
        }
    }

    std::string executeCommand(std::string const& command)
    {
        if (!m_commandExecutioner)
            return "Command executioner is unavailable\n";

        return m_commandExecutioner->execute(command);
    }

    std::string getWorldDebugInfo()
    {
        auto const& entities = m_ecWorld.entities().entities;

        std::stringstream ss;

        ss << entities.size() << " entities in the world:" << std::endl;
        for (std::unique_ptr<ec::Entity> const& entity : entities)
        {
            ss << entity->getId() << std::endl;

            for (auto const& info : entity->getComponentsInfo())
            {
                ss << '\t' << info.name << std::endl;
            }
        }

        return ss.str();
    }

    void onError(std::string message)
    {
        gui::NotificationManager* const notificationManager = m_services.getNotificationManager();
        if (!notificationManager)
            return;

        notificationManager->add(std::move(message), 10.0f);
    }

    Services m_services;
    cmdapi::CommandListener m_commandListener;

    std::unique_ptr<CommandExecutioner> m_commandExecutioner;

    ec::World m_ecWorld;
};

namespace test
{
    class ServiceB
    {
    public:
        float update(cmdapi::Context& context, float dt)
        {
            if (dt < 1.0f)
            {
                context.reportError("Very low dt");
                return 0;
            }

            std::cout << "ServiceB::update " << dt << std::endl;
            return dt;
        }
    };

    cmdapi::VariadicArg freeFunction(cmdapi::Context&, cmdapi::VariadicArg arg)
    {
        std::cout << "I'm a free function!" << std::endl;
        return !arg.as<bool>();
    }

    std::optional<bool> optionalArgFunc(std::optional<bool> arg)
    {
        std::cout << "Optional arg!" << std::endl;

        if (arg.has_value())
            return !arg.value();

        return {};
    }

    void test()
    {
        cmdapi::CommandListener cmd;

        ServiceB serviceB;

        cmd.addObject("service", &serviceB);

        cmd.bind<ServiceB>("update", &ServiceB::update);

        cmd.bind("func", &optionalArgFunc);

		auto execute = [&cmd](std::string command)
		{
			std::cout << "Executing [" << command << "]" << std::endl;
			auto result = cmd.execute(std::move(command));

			for (const auto& error : result.errors)
				std::cout << "\t" << "Error: " << error << std::endl;
			if (!result.output.empty())
				std::cout << "\t" << "Output: '" << result.output << "'" << std::endl;
            std::cout << std::endl;
		};

        //execute("service.update 0.16");
        //execute("service.update 1.16");
        //execute("service.update 1.16s");
        execute("func true");
        execute("func trues");
        execute("func");
    }
}

int main()
{
    try
    {
        //App app;
        //app.run();

        cmdapi::tests::test();

        test::test();
        std::getchar();
    }
    catch (std::exception& e)
    {
        std::cout << "Finished with exception:" << std::endl;
        std::cout << e.what();
        std::getchar();
    }

	return 0;
}
