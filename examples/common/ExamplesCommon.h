#pragma once

#include "CustomTypeName.h"

#include <string_view>

namespace coil { class Bindings; }

namespace common
{
    void printSectionHeader(std::string_view header);
    void executeCommand(coil::Bindings& bindings, std::string_view command);
}
