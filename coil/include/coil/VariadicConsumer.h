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

        template<typename OnError>
        static T consume(std::vector<std::string_view> const& arguments, std::size_t index, OnError&& onError)
        {
            return TypeSerializer<T>::fromString(arguments[index], std::forward<OnError>(onError));
        }
    };

    template<typename T>
    struct VariadicConsumer<std::vector<T>>
    {
        static constexpr std::size_t minArgs = 0;
        static constexpr bool isUnlimitedArgs = true;
        static constexpr std::size_t maxArgs = 0;

        template<typename OnError>
        static std::vector<T> consume(std::vector<std::string_view> const& arguments, std::size_t index, OnError&& onError)
        {
            std::vector<T> args;
            args.reserve(arguments.size() - index);

            for (auto i = index; i < arguments.size(); i++)
                args.push_back(TypeSerializer<T>::fromString(arguments[i], onError));

            return args;
        }
    };

    template<typename T>
    struct VariadicConsumer<std::optional<T>>
    {
        static constexpr std::size_t minArgs = 0;
        static constexpr bool isUnlimitedArgs = false;
        static constexpr std::size_t maxArgs = 1;

        template<typename OnError>
        static std::optional<T> consume(std::vector<std::string_view> const& arguments, std::size_t index, OnError&& onError)
        {
            if (index >= arguments.size())
                return {};

            return TypeSerializer<T>::fromString(arguments[index], std::forward<OnError>(onError));
        }
    };
}
