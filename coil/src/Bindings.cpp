#include "Bindings.h"

bool coil::Bindings::removeObject(std::string const& name)
{
	if (name.empty())
		return false;

    m_objects.erase(name);

	return true;
}

void coil::Bindings::execute(detail::CallContext& context)
{
	if (context.input.name.empty())
    {
        context.result.errors.push_back("No command name is specified");
        return;
    }

    if (context.input.target.empty())
        return objectTrampoline<void>({}, context);

    auto it = m_objects.find(context.input.target);
    if (it == m_objects.end())
    {
        context.result.errors.push_back(utils::formatString("Object '%s' is not registered", context.input.target.c_str()));
        return;
    }

    AnyObject& obj = it->second;
    obj.invokeTrampoline(this, context);
}
