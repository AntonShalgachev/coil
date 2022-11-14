#pragma once

#include "coil/Coil.h"

#include "CustomTypeName.h"

#include <string_view>

namespace common
{
    void printSectionHeader(std::string_view header);
    void executeCommand(coil::Bindings& bindings, coil::StringView command);
}
