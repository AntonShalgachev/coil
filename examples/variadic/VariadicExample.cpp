#include "VariadicExample.h"

#include "common/ExamplesCommon.h"
#include "coil/VariadicArg.h"

#include <vector>
#include <numeric>

namespace
{
    float sumAll(std::vector<float> const& numbers)
    {
        return std::accumulate(numbers.begin(), numbers.end(), 0.0f);
    }

    float scale(float value, std::optional<float> multiplier)
    {
        return value * multiplier.value_or(1.0f);
    }

    std::string half(coil::VariadicArg value)
    {
        if (std::optional<int> optionalValue = value.tryGet<int>())
            return std::to_string(*optionalValue / 2);

        if (std::optional<float> optionalValue = value.tryGet<float>())
            return std::to_string(*optionalValue * 0.5f);

        return "<unknown type>";
    }
}

void VariadicExample::run()
{
    coil::Bindings bindings;

    bindings["sum_all"] = &sumAll;
    bindings["scale"] = &scale;
    bindings["half"] = &half;

    common::printSectionHeader("std::vector consumes all remaining arguments:");
    common::executeCommand(bindings, "sum_all");
    common::executeCommand(bindings, "sum_all 1");
    common::executeCommand(bindings, "sum_all 1 2 3 5 8");

    common::printSectionHeader("std::optional consumes 0 or 1 argument:");
    common::executeCommand(bindings, "scale 3.14");
    common::executeCommand(bindings, "scale 3.14 2.0");

    common::printSectionHeader("coil also catches invalid number or type of variadic arguments:");
    common::executeCommand(bindings, "scale");
    common::executeCommand(bindings, "scale 3.14 2.0 3.0");
    common::executeCommand(bindings, "scale 3.14 two");

    common::printSectionHeader("VariadicArg can be used with any type:");
    common::executeCommand(bindings, "half 13");
    common::executeCommand(bindings, "half 13.0");
    common::executeCommand(bindings, "half thirteen");
}
