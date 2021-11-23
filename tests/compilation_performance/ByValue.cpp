#include "Common.h"

namespace
{
    template<typename R, typename... Args>
    R func(Args...)
    {
        return R{};
    }
}

void TestByValue()
{
    GeneralBindings bindings;

    bindings[""] = func<bool>;
    bindings[""] = func<int>;
    bindings[""] = func<float>;
    bindings[""] = func<double>;
    bindings[""] = func<std::string>;

    bindings[""] = func<bool, bool>;
    bindings[""] = func<int, bool>;
    bindings[""] = func<float, bool>;
    bindings[""] = func<double, bool>;
    bindings[""] = func<std::string, bool>;

    bindings[""] = func<bool, int>;
    bindings[""] = func<int, int>;
    bindings[""] = func<float, int>;
    bindings[""] = func<double, int>;
    bindings[""] = func<std::string, int>;

    bindings[""] = func<bool, float>;
    bindings[""] = func<int, float>;
    bindings[""] = func<float, float>;
    bindings[""] = func<double, float>;
    bindings[""] = func<std::string, float>;

    bindings[""] = func<bool, double>;
    bindings[""] = func<int, double>;
    bindings[""] = func<float, double>;
    bindings[""] = func<double, double>;
    bindings[""] = func<std::string, double>;

    bindings[""] = func<bool, std::string>;
    bindings[""] = func<int, std::string>;
    bindings[""] = func<float, std::string>;
    bindings[""] = func<double, std::string>;
    bindings[""] = func<std::string, std::string>;



    bindings[""] = func<bool, bool, bool>;
    bindings[""] = func<int, bool, bool>;
    bindings[""] = func<float, bool, bool>;
    bindings[""] = func<double, bool, bool>;
    bindings[""] = func<std::string, bool, bool>;

    bindings[""] = func<bool, int, bool>;
    bindings[""] = func<int, int, bool>;
    bindings[""] = func<float, int, bool>;
    bindings[""] = func<double, int, bool>;
    bindings[""] = func<std::string, int, bool>;

    bindings[""] = func<bool, float, bool>;
    bindings[""] = func<int, float, bool>;
    bindings[""] = func<float, float, bool>;
    bindings[""] = func<double, float, bool>;
    bindings[""] = func<std::string, float, bool>;

    bindings[""] = func<bool, double, bool>;
    bindings[""] = func<int, double, bool>;
    bindings[""] = func<float, double, bool>;
    bindings[""] = func<double, double, bool>;
    bindings[""] = func<std::string, double, bool>;

    bindings[""] = func<bool, std::string, bool>;
    bindings[""] = func<int, std::string, bool>;
    bindings[""] = func<float, std::string, bool>;
    bindings[""] = func<double, std::string, bool>;
    bindings[""] = func<std::string, std::string, bool>;



    bindings[""] = func<bool, bool, int>;
    bindings[""] = func<int, bool, int>;
    bindings[""] = func<float, bool, int>;
    bindings[""] = func<double, bool, int>;
    bindings[""] = func<std::string, bool, int>;

    bindings[""] = func<bool, int, int>;
    bindings[""] = func<int, int, int>;
    bindings[""] = func<float, int, int>;
    bindings[""] = func<double, int, int>;
    bindings[""] = func<std::string, int, int>;

    bindings[""] = func<bool, float, int>;
    bindings[""] = func<int, float, int>;
    bindings[""] = func<float, float, int>;
    bindings[""] = func<double, float, int>;
    bindings[""] = func<std::string, float, int>;

    bindings[""] = func<bool, double, int>;
    bindings[""] = func<int, double, int>;
    bindings[""] = func<float, double, int>;
    bindings[""] = func<double, double, int>;
    bindings[""] = func<std::string, double, int>;

    bindings[""] = func<bool, std::string, int>;
    bindings[""] = func<int, std::string, int>;
    bindings[""] = func<float, std::string, int>;
    bindings[""] = func<double, std::string, int>;
    bindings[""] = func<std::string, std::string, int>;



    bindings[""] = func<bool, bool, float>;
    bindings[""] = func<int, bool, float>;
    bindings[""] = func<float, bool, float>;
    bindings[""] = func<double, bool, float>;
    bindings[""] = func<std::string, bool, float>;

    bindings[""] = func<bool, int, float>;
    bindings[""] = func<int, int, float>;
    bindings[""] = func<float, int, float>;
    bindings[""] = func<double, int, float>;
    bindings[""] = func<std::string, int, float>;

    bindings[""] = func<bool, float, float>;
    bindings[""] = func<int, float, float>;
    bindings[""] = func<float, float, float>;
    bindings[""] = func<double, float, float>;
    bindings[""] = func<std::string, float, float>;

    bindings[""] = func<bool, double, float>;
    bindings[""] = func<int, double, float>;
    bindings[""] = func<float, double, float>;
    bindings[""] = func<double, double, float>;
    bindings[""] = func<std::string, double, float>;

    bindings[""] = func<bool, std::string, float>;
    bindings[""] = func<int, std::string, float>;
    bindings[""] = func<float, std::string, float>;
    bindings[""] = func<double, std::string, float>;
    bindings[""] = func<std::string, std::string, float>;



    bindings[""] = func<bool, bool, double>;
    bindings[""] = func<int, bool, double>;
    bindings[""] = func<float, bool, double>;
    bindings[""] = func<double, bool, double>;
    bindings[""] = func<std::string, bool, double>;

    bindings[""] = func<bool, int, double>;
    bindings[""] = func<int, int, double>;
    bindings[""] = func<float, int, double>;
    bindings[""] = func<double, int, double>;
    bindings[""] = func<std::string, int, double>;

    bindings[""] = func<bool, float, double>;
    bindings[""] = func<int, float, double>;
    bindings[""] = func<float, float, double>;
    bindings[""] = func<double, float, double>;
    bindings[""] = func<std::string, float, double>;

    bindings[""] = func<bool, double, double>;
    bindings[""] = func<int, double, double>;
    bindings[""] = func<float, double, double>;
    bindings[""] = func<double, double, double>;
    bindings[""] = func<std::string, double, double>;

    bindings[""] = func<bool, std::string, double>;
    bindings[""] = func<int, std::string, double>;
    bindings[""] = func<float, std::string, double>;
    bindings[""] = func<double, std::string, double>;
    bindings[""] = func<std::string, std::string, double>;



    bindings[""] = func<bool, bool, std::string>;
    bindings[""] = func<int, bool, std::string>;
    bindings[""] = func<float, bool, std::string>;
    bindings[""] = func<double, bool, std::string>;
    bindings[""] = func<std::string, bool, std::string>;

    bindings[""] = func<bool, int, std::string>;
    bindings[""] = func<int, int, std::string>;
    bindings[""] = func<float, int, std::string>;
    bindings[""] = func<double, int, std::string>;
    bindings[""] = func<std::string, int, std::string>;

    bindings[""] = func<bool, float, std::string>;
    bindings[""] = func<int, float, std::string>;
    bindings[""] = func<float, float, std::string>;
    bindings[""] = func<double, float, std::string>;
    bindings[""] = func<std::string, float, std::string>;

    bindings[""] = func<bool, double, std::string>;
    bindings[""] = func<int, double, std::string>;
    bindings[""] = func<float, double, std::string>;
    bindings[""] = func<double, double, std::string>;
    bindings[""] = func<std::string, double, std::string>;

    bindings[""] = func<bool, std::string, std::string>;
    bindings[""] = func<int, std::string, std::string>;
    bindings[""] = func<float, std::string, std::string>;
    bindings[""] = func<double, std::string, std::string>;
    bindings[""] = func<std::string, std::string, std::string>;



    bindings[""] = func<bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool>;
    bindings[""] = func<int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>;
    bindings[""] = func<float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float>;
    bindings[""] = func<double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double>;
    bindings[""] = func<std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string>;
}
