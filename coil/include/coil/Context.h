#pragma once

#include "detail/CallContext.h"
#include "Expected.h"
#include "NamedArgs.h"

namespace coil
{
    class Context
    {
    public:
        Context(detail::CallContext& callContext) : m_callContext(callContext), m_namedArgs(callContext) {}

        std::ostream& out() { return m_callContext.out(); }

        void reportError(std::string error)
        {
            m_callContext.reportError(std::move(error));
        }

        template<typename... Ts>
        void reportErrors(Ts&&... errors)
        {
            (reportError(std::forward<Ts>(errors)), ...);
        }

        bool hasErrors() const
        {
            return m_callContext.hasErrors();
        }

        NamedArgs const& namedArgs() { return m_namedArgs; }

    private:
        detail::CallContext& m_callContext;
        NamedArgs m_namedArgs;
    };
}
