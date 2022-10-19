#pragma once

#include "../StringView.h"

#include <functional> // TODO remove

namespace coil
{
    template<typename UnderlyingType>
    class BasicStringWrapper
    {
    public:
        BasicStringWrapper(StringView str) : m_str(str) {}

        StringView view() const
        {
            return m_str;
        }

        operator StringView() const
        {
            return view();
        }

        bool operator==(BasicStringWrapper<UnderlyingType> const& rhs) const
        {
            return view() == rhs.view();
        }

    private:
        UnderlyingType m_str;
    };
}

// TODO remove
namespace std
{
    template<typename UnderlyingType>
    struct hash<coil::BasicStringWrapper<UnderlyingType>>
    {
        size_t operator()(coil::BasicStringWrapper<UnderlyingType> const& value) const noexcept
        {
            size_t hash = 0;

            coil::StringView str = value.view();

            for (char c : value.view())
                hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

            return hash;
        }
    };
}
