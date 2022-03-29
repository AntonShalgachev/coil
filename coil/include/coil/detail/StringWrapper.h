#pragma once

#include <string_view>
#include <optional>

namespace coil
{
    template<typename UnderlyingType>
    class BasicStringWrapper
    {
    public:
        static_assert(std::is_same_v<UnderlyingType, std::decay_t<UnderlyingType>>, "UnderlyingType should be a decayed type");
        static_assert(std::is_convertible_v<UnderlyingType, std::string_view>, "UnderlyingType should be convertible to std::string_view");

        BasicStringWrapper(std::string_view str) : m_str(str) {}

        std::string_view view() const
        {
            return m_str;
        }

        operator std::string_view() const { return view(); }

        bool operator==(BasicStringWrapper<UnderlyingType> const& rhs) const
        {
            return view() == rhs.view();
        }

    private:
        UnderlyingType m_str;
    };
}

namespace std
{
    template<typename UnderlyingType>
    struct hash<coil::BasicStringWrapper<UnderlyingType>>
    {
        size_t operator()(coil::BasicStringWrapper<UnderlyingType> const& value) const noexcept
        {
            return std::hash<std::string_view>{}(value);
        }
    };
}
