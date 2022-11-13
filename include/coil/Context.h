#pragma once

#include "Config.h"
#include "Expected.h"
#include "NamedArgs.h"
#include "String.h"
#include "detail/CallContext.h"
#include "detail/Utility.h"

namespace coil
{
    class Context
    {
    public:
        Context(detail::CallContext& callContext);

        void log(String const& str);
        void logline(String const& str);
        COIL_PRINTF_LIKE(2, 3) void logf(char const* format, ...);
        COIL_PRINTF_LIKE(2, 3) void loglinef(char const* format, ...);

        void reportError(String error);

        template<typename... Ts>
        void reportErrors(Ts&&... errors)
        {
            (reportError(coil::forward<Ts>(errors)), ...);
        }

        bool hasErrors() const;

        NamedArgs namedArgs();

    private:
        detail::CallContext& m_callContext;
    };
}
