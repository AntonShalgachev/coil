#pragma once

#include "coil/Bindings.h"
#include "CustomTypeName.h"
#include "EnumToString.h"

#include <string_view>

namespace coil { class Bindings; }

namespace common
{
    void printSectionHeader(std::string_view header);
    void executeCommand(coil::Bindings& bindings, std::string_view command);
}
