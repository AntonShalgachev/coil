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

    void printItems(coil::NamedArgs& namedArgs)
    {
        auto name = namedArgs.tryGet<std::string_view>("name");
        auto minAmount = namedArgs.tryGet<std::size_t>("min_amount");
        auto source = namedArgs.tryGet<Source>("source");
        auto type = namedArgs.tryGet<Type>("type");

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

    void addItem(coil::NamedArgs& namedArgs, std::uint64_t id, std::string_view name)
    {
        std::size_t amount = namedArgs.tryGet<std::size_t>("amount").value_or(1);
        Type type = namedArgs.tryGet<Type>("type").value_or(Type::Weapon);

        items.push_back({id, name, amount, Source::Debug, type});
    }

    void printArgs(coil::NamedArgs& namedArgs)
    {
        for (coil::NamedArg arg : namedArgs)
            std::cout << arg.key() << ": " << arg.value() << std::endl;
    }

    void printFloats(coil::NamedArgs& namedArgs)
    {
        for (coil::NamedArg arg : namedArgs)
            if (arg.asAny().is<float>())
                std::cout << arg.key() << ": " << arg.value() << std::endl;
    }

    enum class SaveGameType
    {
        Disk,
        Memory,
    };

    void saveGame(coil::NamedArgs& namedArgs)
    {
        SaveGameType type = namedArgs.tryGet<SaveGameType>("type").value_or(SaveGameType::Disk);
        float delay = namedArgs.tryGet<float>("delay").value_or(0.0f);

        std::cout << "Saving game with type " << magic_enum::enum_name(type) << " and delay " << delay << "ms" << std::endl;
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
    common::executeCommand(bindings, "save_game");
    common::executeCommand(bindings, "save_game type=Memory");
    common::executeCommand(bindings, "save_game type=Memory delay=150");
}

