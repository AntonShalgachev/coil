#include "Common.h"

namespace
{
	template<typename... Args>
	class Object
	{
	public:
		template<typename R, typename... Args>
		R func()
		{
			return R{};
		}
	};
}

void TestObjectByValue()
{
	GeneralBindings bindings;

	bind<Object<bool>>(bindings, &Object<bool>::func<bool>);
	bind<Object<bool>>(bindings, &Object<bool>::func<int>);
	bind<Object<bool>>(bindings, &Object<bool>::func<float>);
	bind<Object<bool>>(bindings, &Object<bool>::func<double>);
	bind<Object<bool>>(bindings, &Object<bool>::func<std::string>);

	bind<Object<int>>(bindings, &Object<int>::func<bool, bool>);
	bind<Object<int>>(bindings, &Object<int>::func<int, bool>);
	bind<Object<int>>(bindings, &Object<int>::func<float, bool>);
	bind<Object<int>>(bindings, &Object<int>::func<double, bool>);
	bind<Object<int>>(bindings, &Object<int>::func<std::string, bool>);

	bind<Object<float>>(bindings, &Object<float>::func<bool, int>);
	bind<Object<float>>(bindings, &Object<float>::func<int, int>);
	bind<Object<float>>(bindings, &Object<float>::func<float, int>);
	bind<Object<float>>(bindings, &Object<float>::func<double, int>);
	bind<Object<float>>(bindings, &Object<float>::func<std::string, int>);

	bind<Object<double>>(bindings, &Object<double>::func<bool, float>);
	bind<Object<double>>(bindings, &Object<double>::func<int, float>);
	bind<Object<double>>(bindings, &Object<double>::func<float, float>);
	bind<Object<double>>(bindings, &Object<double>::func<double, float>);
	bind<Object<double>>(bindings, &Object<double>::func<std::string, float>);

	bind<Object<std::string>>(bindings, &Object<std::string>::func<bool, double>);
	bind<Object<std::string>>(bindings, &Object<std::string>::func<int, double>);
	bind<Object<std::string>>(bindings, &Object<std::string>::func<float, double>);
	bind<Object<std::string>>(bindings, &Object<std::string>::func<double, double>);
	bind<Object<std::string>>(bindings, &Object<std::string>::func<std::string, double>);



	bind<Object<bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool>>(bindings, &Object<bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool>::func<bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool>);
	bind<Object<int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>>(bindings, &Object<int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>::func<int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>);
	bind<Object<float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float>>(bindings, &Object<float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float>::func<float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float>);
	bind<Object<double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double>>(bindings, &Object<double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double>::func<double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double>);
	bind<Object<std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string>>(bindings, &Object<std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string>::func<std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string>);
}
