#pragma once

#include "../StringView.h"
#include "../Hash.h"

// TODO remove

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

        bool operator==(BasicStringWrapper<UnderlyingType> const& rhs) const
        {
            return view() == rhs.view();
        }

    private:
        UnderlyingType m_str;
    };

    template<typename UnderlyingType>
    struct Hash<BasicStringWrapper<UnderlyingType>>
    {
        size_t operator()(BasicStringWrapper<UnderlyingType> const& value)
        {
            return Hash<StringView>{}(value.view());
        }
    };
}
