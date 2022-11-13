#pragma once

namespace coil
{
    template<typename T>
    class ReferenceWrapper
    {
    public:
        constexpr ReferenceWrapper(T& value) : m_value(&value) {}

        constexpr T& get() const noexcept
        {
            return *m_value;
        }
        constexpr operator T&() const noexcept
        {
            return get();
        }

    private:
        T* m_value = nullptr;
    };
}
