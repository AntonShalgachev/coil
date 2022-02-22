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

    void printItem(std::ostream& os, Item const& item)
    {
        os << item.id << '\t' << item.name << '\t' << item.amount << '\t' << magic_enum::enum_name(item.source) << '\t' << magic_enum::enum_name(item.type) << std::endl;
    }

    void printItems(coil::Context context)
    {
        auto& namedArgs = context.namedArgs();

        auto name = namedArgs.getOrReport<std::string_view>("name", coil::NamedArgs::ArgType::Optional);
        auto minAmount = namedArgs.getOrReport<std::size_t>("min_amount", coil::NamedArgs::ArgType::Optional);
        auto source = namedArgs.getOrReport<Source>("source", coil::NamedArgs::ArgType::Optional);
        auto type = namedArgs.getOrReport<Type>("type", coil::NamedArgs::ArgType::Optional);

        // if any of the above arguments didn't have the correct type, then the error would be reported and
        // the returned value would be an empty std::optional
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

        context.out() << "ID\tName\tAmount\tSource\tType" << std::endl;

        for (Item const& item : items)
            if (doesItemMatch(item))
                printItem(context.out(), item);
    }

    void addItem(coil::Context context, std::uint64_t id, std::string_view name)
    {
        auto& namedArgs = context.namedArgs();

        auto amount = namedArgs.getOrReport<std::size_t>("amount", coil::NamedArgs::ArgType::Optional, 1);
        auto type = namedArgs.getOrReport<Type>("type", coil::NamedArgs::ArgType::Optional, Type::Weapon);

        // This might happen if the above arguments exist, but they can't be represented in the specified C++ type
        if (!amount || !type)
            return;

        items.push_back({id, name, *amount, Source::Debug, *type});
    }

    void printArgs(coil::Context context)
    {
        for (coil::NamedAnyArgView arg : context.namedArgs())
            context.out() << arg.key() << ": " << arg.value().getRaw() << std::endl;
    }

    void printFloats(coil::Context context)
    {
        for (coil::NamedAnyArgView arg : context.namedArgs())
            if (arg.value().get<float>())
                context.out() << arg.key() << ": " << arg.value().getRaw() << std::endl;
    }

    enum class SaveGameType
    {
        Disk,
        Memory,
    };

    void saveGame(coil::Context context)
    {
        auto& namedArgs = context.namedArgs();

        auto type = namedArgs.getOrReport<SaveGameType>("type", coil::NamedArgs::ArgType::Required);
        auto delay = namedArgs.getOrReport<float>("delay", coil::NamedArgs::ArgType::Optional, 0.0f);

        if (!type || !delay)
            return;

        context.out() << "Saving game with type " << magic_enum::enum_name(*type) << " and delay " << *delay << "ms" << std::endl;
    }

    void requiredAndOptional(coil::Context context)
    {
        auto& namedArgs = context.namedArgs();

        auto requiredAnyArg = namedArgs.getOrReport("required", coil::NamedArgs::ArgType::Required);
        if (!requiredAnyArg)
            return; // the error is already reported

        if (auto valueBool = requiredAnyArg->get<bool>())
            context.out() << "Required: " << std::boolalpha << *valueBool << std::noboolalpha << std::endl;
        else if (auto valueInt = requiredAnyArg->get<int>())
            context.out() << "Required: " << *valueInt << std::endl;
        else
            context.reportErrors(std::move(valueBool).error(), std::move(valueInt).error());

        auto optionalAnyArg = namedArgs.getOrReport("optional", coil::NamedArgs::ArgType::Optional);
        if (optionalAnyArg)
        {
            if (auto valueBool = optionalAnyArg->get<bool>())
                context.out() << "Optional: " << std::boolalpha << *valueBool << std::noboolalpha << std::endl;
            else if (auto valueInt = optionalAnyArg->get<int>())
                context.out() << "Optional: " << *valueInt << std::endl;
            else
                context.reportErrors(std::move(valueBool).error(), std::move(valueInt).error());
        }
    }
}

void NamedExample::run()
{
    coil::Bindings bindings;

    bindings["inventory.list"] = &printItems;
    bindings["inventory.add"] = &addItem;

    bindings["print_args"] = &printArgs;
    bindings["print_floats"] = &printFloats;
    bindings["save_game"] = &saveGame;
    bindings["required_and_optional"] = &requiredAndOptional;

    common::printSectionHeader("NamedArgs can be used to specify named arguments:");
    common::executeCommand(bindings, "inventory.list");
    common::executeCommand(bindings, "inventory.list name = if");
    common::executeCommand(bindings, "inventory.list min_amount=2");
    common::executeCommand(bindings, "inventory.list min_amount=2 source=reward");
    common::executeCommand(bindings, "inventory.list source=reward type=weapon");

    common::printSectionHeader("You can also use normal arguments with it");
    common::executeCommand(bindings, "inventory.add 8 pistol");
    common::executeCommand(bindings, "inventory.add 9 dollar type=Currency amount=10");
    common::executeCommand(bindings, "inventory.add 10 key2 type=Key");
    common::executeCommand(bindings, "inventory.list");

    common::printSectionHeader("You can iterate over NamedArgs:");
    common::executeCommand(bindings, "print_args arg1 = value1 arg2 = 0.1 arg3 = true arg4 = 3.1415");

    common::printSectionHeader("You can treat individual argument as AnyArgView:");
    common::executeCommand(bindings, "print_floats arg1 = value1 arg2 = 0.1 arg3 = true arg4 = 3.1415");

    common::printSectionHeader("You can use NamedArgs to override default values");
    common::executeCommand(bindings, "save_game type=Disk");
    common::executeCommand(bindings, "save_game type=Memory delay=150");

    common::printSectionHeader("You can use special method to automatically report the errors if the input is bad");
    common::executeCommand(bindings, "save_game type=Memori delay=none");
    common::executeCommand(bindings, "inventory.list min_amount=2.5");
    common::executeCommand(bindings, "inventory.add -9 unicorn type=Something");
    common::executeCommand(bindings, "save_game");
    common::executeCommand(bindings, "required_and_optional");
    common::executeCommand(bindings, "required_and_optional required=3.14");
    common::executeCommand(bindings, "required_and_optional required=true optional=1.5");
    common::executeCommand(bindings, "required_and_optional required=10");
    common::executeCommand(bindings, "required_and_optional required=true optional=false");
}

