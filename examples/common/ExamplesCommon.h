#pragma once

#include "CustomTypeName.h"
#include "EnumTypeSerializer.h"
#include "coil/Coil.h"

#include <string_view>

namespace common
{
    void printSectionHeader(std::string_view header);
    void executeCommand(coil::Bindings& bindings, std::string_view command);
}
