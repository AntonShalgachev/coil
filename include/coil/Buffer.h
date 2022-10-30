#pragma once

#include "Assert.h"
#include "detail/New.h"
#include "detail/Utility.h"

#include <stddef.h>

// TODO double-check casts

namespace coil
{
    class Buffer
    {
    public:
        Buffer(size_t count = 0, size_t chunkSize = 0);
        Buffer(Buffer const& rhs);
        Buffer(Buffer&& rhs);
        ~Buffer();

        Buffer& operator=(Buffer const& rhs);
        Buffer& operator=(Buffer&& rhs);

        char* data();
        char const* data() const;
        size_t count() const;
        size_t size() const;
        bool empty() const;

        void resize(size_t newSize);

        char* get(size_t index);
        char const* get(size_t index) const;

        void copy(void const* ptr, size_t size);

        template<typename T, typename... Args>
        T* constructNext(Args&&... args)
        {
            COIL_ASSERT(m_ptr);
            COIL_ASSERT(m_size < m_count);

            T* obj = new (NewTag{}, m_ptr + m_size * sizeof(T)) T(Forward<Args>(args)...);
            m_size++;

#if COIL_CONFIG_ENABLE_ASSERTS
            m_constructedObjectsCount++;
#endif

            return obj;
        }

        template<typename T>
        void destructLast()
        {
            COIL_ASSERT(m_size > 0);

            get<T>(m_size - 1)->~T();
            m_size--;

#if COIL_CONFIG_ENABLE_ASSERTS
            COIL_ASSERT(m_constructedObjectsCount > 0);
            m_constructedObjectsCount--;
#endif
        }

        template<typename T>
        void destructAll()
        {
            for (size_t i = 0; i < m_size; i++)
                get<T>(m_size - 1 - i)->~T();

            m_size = 0;

#if COIL_CONFIG_ENABLE_ASSERTS
            m_constructedObjectsCount = 0;
#endif
        }

        template<typename T>
        T* get(size_t index)
        {
            return reinterpret_cast<T*>(get(index * sizeof(T))); // it is legal to cast pointer to char array to any type
        }

        template<typename T>
        T const* get(size_t index) const
        {
            return reinterpret_cast<T const*>(get(index * sizeof(T))); // it is legal to cast pointer to char array to any type
        }

    private:
        size_t internalBufferSize() const; // TODO rename
        void swap(Buffer& rhs) noexcept;

    private:
        char* m_ptr = nullptr;
        size_t m_count = 0; // TODO rename to m_capacity or m_size
        size_t m_chunkSize = 0;

        size_t m_size = 0;

#if COIL_CONFIG_ENABLE_ASSERTS
        size_t m_constructedObjectsCount = 0;
#endif
    };
}