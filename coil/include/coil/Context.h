#pragma once

#include "detail/CallContext.h"
#include "Expected.h"

namespace coil
{
    class Context
    {
    public:
        Context(detail::CallContext& callContext) : m_callContext(callContext) {}

        std::ostream& out() { return m_callContext.result.output; }

        void reportError(std::string error)
        {
            m_callContext.result.errors.push_back(std::move(error));
        }

        template<typename T, typename E>
        void reportError(coil::Expected<T, E> expected)
        {
            static_assert(std::is_convertible_v<decltype(expected.error()), std::string>, "Expected's error should be convertible to std::string");

            if (!expected)
                reportError(std::move(expected).error());
        }

        template<typename... Ts>
        void reportErrors(Ts&&... errors)
        {
            (reportError(std::forward<Ts>(errors)), ...);
        }

        bool hasErrors() const
        {
            return !m_callContext.result.errors.empty();
        }

    private:
        detail::CallContext& m_callContext;
    };
}
