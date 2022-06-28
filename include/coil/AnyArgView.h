#pragma once

#include "Expected.h"
// #include "TypeSerializer.h"

#include <string_view>
#include <vector>

namespace coil
{
    template<typename T, typename>
    struct TypeSerializer;

    // TODO it's not a "view" anymore
    struct AnyArgView
    {
        AnyArgView();
        AnyArgView(std::string_view value);
        AnyArgView(std::vector<std::string_view> subvalues);

        bool operator==(AnyArgView const& rhs) const;

        template<typename T>
        Expected<T, std::string> get() const
        {
            return TypeSerializer<T>::fromString(*this);
        }

        std::string str() const;

        std::vector<std::string_view> subvalues;
    };

    std::ostream& operator<<(std::ostream& os, AnyArgView const& rhs);

    template<>
    struct TypeSerializer<AnyArgView, void>
    {
        static Expected<AnyArgView, std::string> fromString(AnyArgView const& value)
        {
            return value; // TODO prevent a copy
        }
    };
}
