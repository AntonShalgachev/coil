#pragma once

#include "CustomTypeName.h"
#include "EnumTypeSerializer.h"
#include "coil/Coil.h"

#include <string_view>
#include <ostream>

namespace coil
{
    template<class Elem, class Traits, class Alloc>
    struct TypeSerializer<std::basic_string<Elem, Traits, Alloc>>
    {
        static Expected<std::basic_string<Elem, Traits, Alloc>, String> fromString(Value const& input);

        static String toString(std::basic_string<Elem, Traits, Alloc> const& value);
    };

    template<class Elem, class Traits, class Alloc>
    coil::Expected<std::basic_string<Elem, Traits, Alloc>, String> coil::TypeSerializer<std::basic_string<Elem, Traits, Alloc>>::fromString(Value const& input)
    {
        if (input.subvalues.size() != 1)
            return errors::createMismatchedSubvaluesError<std::basic_string<Elem, Traits, Alloc>>(input, 1);

        return std::basic_string<Elem, Traits, Alloc>{ input.subvalues[0].data(), input.subvalues[0].length() };
    }

    template<class Elem, class Traits, class Alloc>
    coil::String coil::TypeSerializer<std::basic_string<Elem, Traits, Alloc>>::toString(std::basic_string<Elem, Traits, Alloc> const& value)
    {
        return String{ value.c_str() };
    }

    //////////////////////////////////////

    template<class Elem, class Traits>
    struct TypeSerializer<std::basic_string_view<Elem, Traits>>
    {
        static Expected<std::basic_string_view<Elem, Traits>, String> fromString(Value const& input);

        static String toString(std::basic_string_view<Elem, Traits> const& value);
    };

    template<class Elem, class Traits>
    coil::Expected<std::basic_string_view<Elem, Traits>, String> coil::TypeSerializer<std::basic_string_view<Elem, Traits>>::fromString(Value const& input)
    {
        if (input.subvalues.size() != 1)
            return errors::createMismatchedSubvaluesError<std::basic_string_view<Elem, Traits>>(input, 1);

        return std::string_view{ input.subvalues[0].data(), input.subvalues[0].length() }; // WTF
    }

    template<class Elem, class Traits>
    coil::String coil::TypeSerializer<std::basic_string_view<Elem, Traits>>::toString(std::basic_string_view<Elem, Traits> const& value)
    {
        return String{ StringView{value.data(), value.size()} };
    }
}

namespace common
{
    void printSectionHeader(std::string_view header);
    void executeCommand(coil::Bindings& bindings, coil::StringView command);
}

std::ostream& operator<<(std::ostream& os, coil::String const& str);
std::ostream& operator<<(std::ostream& os, coil::StringView const& str);
