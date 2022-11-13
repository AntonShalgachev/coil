#pragma once

#include "detail/TypeTraits.h"
#include "detail/Utility.h"

namespace coil
{
    template<typename T>
    class Unexpected
    {
        static_assert(!IsVoidV<T>, "T shouldn't be void");

    public:
        Unexpected(T value);

        T const& value() const&;
        T& value() &;
        T&& value() &&;

        template<typename U>
        operator Unexpected<U>() const&;

        template<typename U>
        operator Unexpected<U>() &;

        template<typename U>
        operator Unexpected<U>() &&;

    private:
        T m_value;
    };

    template<typename T>
    Unexpected<T> makeUnexpected(T value)
    {
        return Unexpected<RemoveCvT<RemoveReferenceT<T>>>(coil::move(value));
    }

    //////////////////////////////////////////////////////////////////////////

    template<typename T>
    coil::Unexpected<T>::Unexpected(T value) : m_value(coil::move(value))
    {
    }

    template<typename T>
    T const& coil::Unexpected<T>::value() const&
    {
        return m_value;
    }

    template<typename T>
    T& coil::Unexpected<T>::value() &
    {
        return m_value;
    }

    template<typename T>
    T&& coil::Unexpected<T>::value() &&
    {
        return coil::move(m_value);
    }

    template<typename T>
    template<typename U>
    coil::Unexpected<T>::operator Unexpected<U>() const&
    {
        return Unexpected<U>{m_value};
    }

    template<typename T>
    template<typename U>
    coil::Unexpected<T>::operator Unexpected<U>() &
    {
        return Unexpected<U>{m_value};
    }

    template<typename T>
    template<typename U>
    coil::Unexpected<T>::operator Unexpected<U>() &&
    {
        return Unexpected<U>{coil::move(m_value)};
    }
}
