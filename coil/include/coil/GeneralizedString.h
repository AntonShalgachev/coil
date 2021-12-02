#pragma once

#include <string_view>
#include <optional>

namespace coil
{
    template<typename StorageType>
    class BasicGeneralizedString
    {
    public:
        static_assert(std::is_same_v<StorageType, std::decay_t<StorageType>>, "StorageType should be a decayed type");
        static_assert(std::is_convertible_v<StorageType, std::string_view>, "StorageType should be convertible to std::string_view");

        BasicGeneralizedString(char const* str) : m_view(str) {}
        BasicGeneralizedString(std::string_view str) : m_view(str) {}
        BasicGeneralizedString(StorageType str) : m_storage(std::move(str)) {}

        std::string_view getView() const
        {
            if (m_storage)
                return *m_storage;
            return m_view;
        }

        operator std::string_view() const { return getView(); }

        bool operator==(BasicGeneralizedString<StorageType> const& rhs) const
        {
            return getView() == rhs.getView();
        }

    private:
        std::string_view m_view;
        std::optional<StorageType> m_storage;
    };
}

namespace std
{
    template<typename StorageType>
    struct hash<coil::BasicGeneralizedString<StorageType>>
    {
        size_t operator()(coil::BasicGeneralizedString<StorageType> const& value) const noexcept
        {
            return std::hash<std::string_view>{}(value);
        }
    };
}
