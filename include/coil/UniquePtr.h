#pragma once

#include "detail/Utility.h"
#include "Assert.h"

namespace coil
{
    template<typename T>
    class UniquePtr
    {
    public:
        explicit UniquePtr(T* ptr = nullptr) : m_ptr(ptr) {}
        UniquePtr(UniquePtr&& rhs)
        {
            coil::exchange(m_ptr, rhs.m_ptr);
        }
        ~UniquePtr()
        {
            if (m_ptr)
                delete m_ptr;
        }

        UniquePtr& operator=(UniquePtr&& rhs)
        {
            coil::exchange(m_ptr, rhs.m_ptr);
            return *this;
        }

        T const& operator*() const { COIL_ASSERT(m_ptr); return *m_ptr; }
        T& operator*() { COIL_ASSERT(m_ptr); return *m_ptr; }

        T const* operator->() const { COIL_ASSERT(m_ptr); return m_ptr; }
        T* operator->() { COIL_ASSERT(m_ptr); return m_ptr; }

        template<typename T2>
        operator UniquePtr<T2>()&&
        {
            UniquePtr<T2> result{ m_ptr };
            m_ptr = nullptr;
            return result;
        }

    private:
        T* m_ptr = nullptr;
    };

    template<typename T, typename... Args>
    UniquePtr<T> makeUnique(Args&&... args)
    {
        return UniquePtr<T>(new T(Forward<Args>(args)...));
    }
}