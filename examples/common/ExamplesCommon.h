#pragma once

#include "coil/Coil.h"
#include "coil/StdLibCompat.h" // TODO should be included here?

#include "CustomTypeName.h"
#include "EnumTypeSerializer.h"

#include <string_view>

namespace common
{
    void printSectionHeader(std::string_view header);
    void executeCommand(coil::Bindings& bindings, coil::StringView command);
}
