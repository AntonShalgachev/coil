#pragma once

#include "coil/Coil.h"
#include "CustomTypeName.h"
#include "EnumToString.h"

#include <string_view>

namespace common
{
    void printSectionHeader(std::string_view header);
    void executeCommand(coil::Bindings& bindings, std::string_view command);
}
