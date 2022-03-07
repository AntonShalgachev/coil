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
    struct VariadicConsumer<std::optional<T>>
    {
        static constexpr std::size_t minArgs = 0;
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
