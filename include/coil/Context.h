#pragma once

#include "Expected.h"
#include "NamedArgs.h"
#include "detail/CallContext.h"
#include "detail/Utility.h"

namespace coil
{
    class Context
    {
    public:
        Context(detail::CallContext& callContext);

        std::ostream& log();
        void log(std::string_view str);

        void reportError(std::string error);

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
