#include "NamedExample.h"

#include "common/ExamplesCommon.h"
#include <iostream>

namespace
{
    enum class Source
    {
        None,
        Loot,
        Reward,
        Debug,
    };

    enum class Type
    {
        None,
        Key,
        Weapon,
        Currency,
    };

    struct Item
    {
        std::uint64_t id = 0;
        std::string_view name;
        std::size_t amount = 1;
        Source source = Source::None;
        Type type = Type::None;
    };

    std::vector<Item> items = {
        {0, "coin", 7000, Source::Loot, Type::Currency},
        {1, "gems", 40, Source::Reward, Type::Currency},
        {2, "sword", 1, Source::Loot, Type::Weapon},
        {3, "machete", 1, Source::Reward, Type::Weapon},
        {4, "katana", 1, Source::Loot, Type::Weapon},
        {5, "rifle", 1, Source::Loot, Type::Weapon},
        {6, "knife", 2, Source::Reward, Type::Weapon},
        {7, "key", 1, Source::Loot, Type::Key},
    };

    void printItem(Item const& item)
    {
        std::cout << item.id << '\t' << item.name << '\t' << item.amount << '\t' << magic_enum::enum_name(item.source) << '\t' << magic_enum::enum_name(item.type) << std::endl;
    }

    void printItems(coil::Context& context, coil::NamedArgs& namedArgs)
    {
        auto name = namedArgs.get<std::string_view>("name", context, coil::NamedArgs::ArgType::Optional);
        auto minAmount = namedArgs.get<std::size_t>("min_amount", context, coil::NamedArgs::ArgType::Optional);
        auto source = namedArgs.get<Source>("source", context, coil::NamedArgs::ArgType::Optional);
        auto type = namedArgs.get<Type>("type", context, coil::NamedArgs::ArgType::Optional);

        if (context.hasErrors())
            return;

        auto doesItemMatch = [&](Item const& item)
        {
            bool const nameOk = !name || (item.name.find(*name) != std::string_view::npos);
            bool const minAmountOk = !minAmount || item.amount >= *minAmount;
            bool const sourceOk = !source || item.source == *source;
            bool const typeOk = !type || item.type == *type;

            return nameOk && minAmountOk && sourceOk && typeOk;
        };

        std::cout << "ID\tName\tAmount\tSource\tType" << std::endl;

        for (Item const& item : items)
            if (doesItemMatch(item))
                printItem(item);
    }

    void addItem(coil::Context& context, coil::NamedArgs& namedArgs, std::uint64_t id, std::string_view name)
    {
        auto amount = namedArgs.get<std::size_t>("amount", context, coil::NamedArgs::ArgType::Optional, 1);
        auto type = namedArgs.get<Type>("type", context, coil::NamedArgs::ArgType::Optional, Type::Weapon);

        if (!amount || !type)
            return;

        items.push_back({id, name, *amount, Source::Debug, *type});
    }

    void printArgs(coil::NamedArgs& namedArgs)
    {
        for (coil::NamedAnyArgView arg : namedArgs)
            std::cout << arg.key() << ": " << arg.value().getRaw() << std::endl;
    }

    void printFloats(coil::NamedArgs& namedArgs)
    {
        for (coil::NamedAnyArgView arg : namedArgs)
            if (arg.value().get<float>())
                std::cout << arg.key() << ": " << arg.value().getRaw() << std::endl;
    }

    enum class SaveGameType
    {
        Disk,
        Memory,
    };

    void saveGame(coil::Context& context, coil::NamedArgs& namedArgs)
    {
        auto type = namedArgs.get<SaveGameType>("type", context, coil::NamedArgs::ArgType::Required);
        auto delay = namedArgs.get<float>("delay", context, coil::NamedArgs::ArgType::Optional, 0.0f);

        if (!type || !delay)
            return;

        std::cout << "Saving game with type " << magic_enum::enum_name(*type) << " and delay " << *delay << "ms" << std::endl;
    }

    void requiredAndOptional(coil::Context& context, coil::NamedArgs& namedArgs)
    {
        auto requiredAnyArg = namedArgs.get("required", context, coil::NamedArgs::ArgType::Required);
        if (!requiredAnyArg)
            return; // the error is already reported

        if (auto valueBool = requiredAnyArg->get<bool>())
            std::cout << "Required: " << *valueBool << std::endl;
        else if (auto valueInt = requiredAnyArg->get<int>())
            std::cout << "Required: " << *valueInt << std::endl;
        else
            context.reportErrors(std::move(valueBool), std::move(valueInt));

        auto optionalAnyArg = namedArgs.get("optional", context, coil::NamedArgs::ArgType::Optional);
        if (optionalAnyArg)
        {
            if (auto valueBool = optionalAnyArg->get<bool>())
                std::cout << "Optional: " << *valueBool << std::endl;
            else if (auto valueInt = optionalAnyArg->get<int>())
                std::cout << "Optional: " << *valueInt << std::endl;
            else
                context.reportErrors(std::move(valueBool), std::move(valueInt));
        }
    }
}

void NamedExample::run()
{
    coil::Bindings bindings;

    bindings["print_items"] = &printItems;
    bindings["add_item"] = &addItem;
    bindings["print_args"] = &printArgs;
    bindings["print_floats"] = &printFloats;
    bindings["save_game"] = &saveGame;
    bindings["required_and_optional"] = &requiredAndOptional;

    common::printSectionHeader("NamedArgs can be used to specify named arguments:");
    common::executeCommand(bindings, "print_items");
    common::executeCommand(bindings, "print_items name = if");
    common::executeCommand(bindings, "print_items min_amount=2");
    common::executeCommand(bindings, "print_items min_amount=2 source=reward");
    common::executeCommand(bindings, "print_items source=reward type=weapon");

    common::printSectionHeader("You can also use normal arguments with it");
    common::executeCommand(bindings, "add_item 8 pistol");
    common::executeCommand(bindings, "add_item 9 dollar type=Currency amount=10");
    common::executeCommand(bindings, "add_item 10 key2 type=Key");
    common::executeCommand(bindings, "print_items");

    common::printSectionHeader("You can iterate over NamedArgs:");
    common::executeCommand(bindings, "print_args arg1 = value1 arg2 = 0.1 arg3 = true arg4 = 3.1415");

    common::printSectionHeader("You can treat individual argument as AnyArgView:");
    common::executeCommand(bindings, "print_floats arg1 = value1 arg2 = 0.1 arg3 = true arg4 = 3.1415");

    common::printSectionHeader("You can use NamedArgs to override default values");
    common::executeCommand(bindings, "save_game type=Disk");
    common::executeCommand(bindings, "save_game type=Memory delay=150");

    common::printSectionHeader("You can use special method to automatically report the errors if the input is bad");
    common::executeCommand(bindings, "save_game type=Memori delay=none");
    common::executeCommand(bindings, "print_items min_amount=2.5");
    common::executeCommand(bindings, "add_item -9 unicorn type=Something");
    common::executeCommand(bindings, "save_game");
    common::executeCommand(bindings, "required_and_optional");
    common::executeCommand(bindings, "required_and_optional required=3.14");
    common::executeCommand(bindings, "required_and_optional required=true optional=1.5");
    common::executeCommand(bindings, "required_and_optional required=10");
    common::executeCommand(bindings, "required_and_optional required=true optional=false");
}
