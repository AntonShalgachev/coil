#include <iostream>

#include "coil/Bindings.h"
#include "coil/CommandCollection.h"
#include "coil/utils/MemberFunctionFunctor.h"
#include "coil/utils/VariableWrapper.h"

namespace services
{
    coil::Bindings& getBindings()
    {
        static coil::Bindings bindings;
        return bindings;
    }
}

namespace services
{
    class InventoryService
    {
    public:
        InventoryService() { enable(); }
        virtual ~InventoryService() { disable(); }

        void enable()
        {
            m_commands = coil::CommandCollection{ services::getBindings() };
            auto& commands = *m_commands;

            commands["services"]["inventory"]["add"] = coil::bind(&InventoryService::add, this);
            commands["services"]["inventory"]["remove"] = coil::bind(&InventoryService::remove, this);
            commands["services"]["inventory"]["count"] = coil::bind(&InventoryService::count, this);
        }

        void disable()
        {
            m_commands = {};
        }

        void add(std::uint64_t, std::size_t) {}
        void remove(std::uint64_t, std::size_t) {}
        std::size_t count(std::uint64_t) { return 42; }

    private:
        std::optional<coil::CommandCollection> m_commands;
    };
}

namespace widgets
{
    class Widget
    {
    public:
        Widget(std::string_view name) : name(name) {}
        virtual ~Widget() { disable(); }

        void toggle() {}

        virtual void enable()
        {
            m_commands = coil::CommandCollection{ services::getBindings() };

            addCommands();
        }

        virtual void disable()
        {
            m_commands = {};
        }

        virtual void addCommands()
        {
            auto& commands = *m_commands;
            commands["widgets"][name] = coil::bind(&Widget::toggle, this);
            commands["widgets"][name]["anchor"] = coil::variable(&Widget::anchor, this);
            commands["widgets"][name]["alpha"] = coil::variable(&Widget::alpha, this);
            commands["widgets"][name]["set_params"] = [this](coil::Context context)
            {
                if (auto alphaArg = context.namedArgs().getOrReport<float>("alpha"))
                    alpha = *alphaArg;
                if (auto anchorArg = context.namedArgs().getOrReport<std::string>("anchor"))
                    anchor = *std::move(anchorArg);
            };
        }

        std::string_view name;

        std::string anchor = "TopLeft";
        float alpha = 0.5f;

    protected:
        std::optional<coil::CommandCollection> m_commands;
    };

    class InventoryWidget : public Widget
    {
    public:
        InventoryWidget() : Widget("inventory") {}

        void addCommands() override
        {
            Widget::addCommands();

            auto& commands = *m_commands;
            commands["widgets"][name]["clear_log"] = coil::bind(&InventoryWidget::clearLog, this);
            commands["widgets"][name]["mask"] = coil::variable(&InventoryWidget::mask, this);
        }

        std::string mask = "All";

        void clearLog() {}
    };
}

int main()
{
    coil::ExecutionResult res;
    auto& bindings = services::getBindings();

    {
        services::InventoryService inventoryService;
        widgets::InventoryWidget inventoryWidget;

        inventoryWidget.enable();

        res = bindings.execute("widgets.inventory");
        res = bindings.execute("widgets.inventory.anchor BottomLeft");
        res = bindings.execute("widgets.inventory.alpha 0.72");
        res = bindings.execute("widgets.inventory.mask Weapons");
        res = bindings.execute("widgets.inventory.clear_log");
        res = bindings.execute("widgets.inventory.set_params alpha=0.2 anchor=Middle");
        res = bindings.execute("widgets.inventory.set_params alpha=one anchor=Middle");
    }

    res = bindings.execute("widgets.inventory");
    res = bindings.execute("widgets.inventory.anchor BottomLeft");
    res = bindings.execute("widgets.inventory.alpha 0.72");
    res = bindings.execute("widgets.inventory.mask Weapons");
    res = bindings.execute("widgets.inventory.clear_log");
    res = bindings.execute("widgets.inventory.set_params alpha=0.2 anchor=Middle");
    res = bindings.execute("widgets.inventory.set_params alpha=one anchor=Middle");
}
