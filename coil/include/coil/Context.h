#pragma once

namespace coil
{
    // TODO rename to Context

    class Context
    {
    public:
        Context(detail::CallContext& callContext) : m_callContext(callContext) {}

        void reportError(std::string error)
        {
            m_callContext.result.errors.push_back(std::move(error));
        }

    private:
        detail::CallContext& m_callContext;
    };
}
