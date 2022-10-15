#pragma once

#include "Expected.h"
#include "NamedArgs.h"
#include "detail/CallContext.h"
#include "detail/Utility.h"
#include "String.h"

namespace coil
{
    class Context
    {
    public:
        Context(detail::CallContext& callContext);

        void log(String const& str);
        void logline(String const& str);
        void logf(char const* format, ...);
        void loglinef(char const* format, ...);

        void reportError(String error);

        template<typename... Ts>
        void reportErrors(Ts&&... errors)
        {
            (reportError(Forward<Ts>(errors)), ...);
        }

        bool hasErrors() const;

        NamedArgs namedArgs();

    private:
        detail::CallContext& m_callContext;
    };
}
