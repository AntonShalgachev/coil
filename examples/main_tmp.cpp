#include <iostream>

#include "coil/Bindings.h"
#include "coil/utils/MemberFunctionFunctor.h"

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
            coil::CommandCollection commands = services::getBindings().createCollection();

            commands.add({ "services", "inventory", "add" }, coil::bind(&InventoryService::add, this));
            commands["services"]["inventory"]["remove"] = coil::bind(&InventoryService::remove, this);
            commands["services"]["inventory"]["count"] = coil::bind(&InventoryService::count, this);

            m_commands = std::move(commands);
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
    enum class Anchor
    {
        TopLeft,
        TopRight,
    };

    class Widget
    {
    public:
        Widget() { enable(); }
        virtual ~Widget() { disable(); }

        void toggle() {}

        void enable()
        {

        }

        void disable()
        {

        }

        Anchor anchor = Anchor::TopLeft;
        float alpha = 0.5f;
    };

    class InventoryWidget : public Widget
    {
    public:
        enum class Mask
        {
            All,
            Weapons,
            Keys,
        };

        Mask mask = Mask::All;

        void clearLog() {}
    };
}

int main()
{
    services::InventoryService inventoryService;
    widgets::InventoryWidget inventoryWidget;

    //coil::Bindings bindings;

    //bindings["cat"] = [](coil::Context) {
    //    return "cat";
    //};

    //bindings["cat"]["test"] = []() {
    //    return "cat.test";
    //};

    //auto res0 = bindings.execute(coil::ExecutionInput{ "", {"cat"}, {}, {} });
    //auto res1 = bindings.execute(coil::ExecutionInput{ "", {"cat", "test"}, {}, {} });

    //bindings["cat"] = nullptr;

    //auto res2 = bindings.execute(coil::ExecutionInput{ "", {"cat"}, {}, {} });
    //auto res3 = bindings.execute(coil::ExecutionInput{ "", {"cat", "test"}, {}, {} });
}