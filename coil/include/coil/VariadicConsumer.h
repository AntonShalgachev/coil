#pragma once

#include <vector>
#include <optional>
#include <string_view>

namespace coil
{
    template<typename T>
    struct VariadicConsumer
    {
        static constexpr std::size_t minArgs = 1;
        static constexpr bool isUnlimitedArgs = false;
        static constexpr std::size_t maxArgs = 1;

        static std::optional<T> consume(Context context, ExecutionInput const& input, std::size_t index)
        {
            auto result = TypeSerializer<T>::fromString(input.arguments[index]);
            if (result)
                return *std::move(result);

            context.reportError(std::move(result).error());
            return {};
        }
    };

    template<typename T>
    struct VariadicConsumer<std::vector<T>>
    {
        static constexpr std::size_t minArgs = 0;
        static constexpr bool isUnlimitedArgs = true;
        static constexpr std::size_t maxArgs = 0;

        static std::optional<std::vector<T>> consume(Context context, ExecutionInput const& input, std::size_t index)
        {
            auto const& arguments = input.arguments;

            std::vector<T> args;
            args.reserve(arguments.size() - index);

            for (auto i = index; i < arguments.size(); i++)
            {
                Expected<T, std::string> expectedArg = TypeSerializer<T>::fromString(arguments[i]);
                if (expectedArg)
                    args.push_back(*std::move(expectedArg));
                else
                    context.reportError(std::move(expectedArg).error());
            }

            if (context.hasErrors())
                return {};

            return args;
        }
    };

    template<typename T>
    struct VariadicConsumer<std::optional<T>>
    {
        static constexpr std::size_t minArgs = 0;
        static constexpr bool isUnlimitedArgs = false;
        static constexpr std::size_t maxArgs = 1;

        static std::optional<std::optional<T>> consume(Context context, ExecutionInput const& input, std::size_t index)
        {
            auto const& arguments = input.arguments;

            if (index >= arguments.size())
                return std::optional<T>{};

            Expected<T, std::string> optionalValue = TypeSerializer<T>::fromString(arguments[index]);
            if (optionalValue)
                return *std::move(optionalValue);

            context.reportError(std::move(optionalValue).error());
            return {};
        }
    };
}
