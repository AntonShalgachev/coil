#pragma once

#include <string>
#include <sstream>
#include <cctype>

#include <algorithm>
#include <optional>

namespace coil
{
    template<typename T, typename OnError>
    static void reportConversionError(OnError&& onError, std::string_view inputString, std::string_view details = {})
    {
        std::string typeName = utils::Types<T>::name();

        if (details.empty())
            onError(utils::formatString("Unable to convert '%.*s' to type '%s'", inputString.length(), inputString.data(), typeName.c_str()));
        else
            onError(utils::formatString("Unable to convert '%.*s' to type '%s': %.*s", inputString.length(), inputString.data(), typeName.c_str(), details.length(), details.data()));
    }

    template<typename T, typename = void>
    struct Converter
    {
        static_assert(!std::is_void_v<T>, "Void isn't a valid conversion type");
        
        // TODO static_assert that T can be used with streams

        template<typename OnError>
        static T fromString(std::string_view str, OnError&& onError)
        {
            std::stringstream ss;
            ss << str;

            T value{};
            ss >> value;

            if (ss.eof() && !ss.fail())
                return value;

            reportConversionError<T>(std::forward<OnError>(onError), str);
            return T{};
        }

        static std::string toString(T const& value)
        {
            std::stringstream ss;
            ss << value;

            return ss.str();
        }
    };

    template<>
    struct Converter<bool>
    {
        template<typename OnError>
        static bool fromString(std::string_view str, OnError&& onError)
        {
            std::string lowercaseStr{ str };
            std::transform(lowercaseStr.begin(), lowercaseStr.end(), lowercaseStr.begin(),
                           [](unsigned char c) { return static_cast<unsigned char>(std::tolower(c)); });

            if (lowercaseStr == "0" || lowercaseStr == "false")
                return false;
            if (lowercaseStr == "1" || lowercaseStr == "true")
                return true;

            reportConversionError<bool>(std::forward<OnError>(onError), str);
            return false;
        }

        static std::string toString(bool value)
        {
            return value ? "true" : "false";
        }
    };

    template<>
    struct Converter<std::string>
    {
        template<typename OnError>
        static std::string fromString(std::string_view str, [[maybe_unused]] OnError&& onError)
        {
            return std::string{ str };
        }

        static std::string toString(std::string const& value)
        {
            return value;
        }
    };

    //template<>
    //struct Converter<char const*>
    //{
    //    template<typename OnError>
    //    static char const* fromString(std::string_view str, [[maybe_unused]] OnError&& onError)
    //    {
    //        return str.c_str();
    //    }

    //    static std::string toString(char const* const& value)
    //    {
    //        return std::string{ value };
    //    }
    //};

    template<typename T>
    struct Converter<std::optional<T>>
    {
        template<typename OnError>
        static std::optional<T> fromString(std::string_view const& str, [[maybe_unused]] OnError&& onError)
        {
            if (str.empty())
                return {};

            return Converter<T>::fromString(str, std::forward<OnError>(onError));
        }

        static std::string toString(std::optional<T> const& value)
        {
            if (!value.has_value())
                return {};

            return Converter<T>::toString(value.value());
        }
    };

    // TODO return some default string for non-convertible types
    // TODO support enums
}
