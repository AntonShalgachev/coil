#include "coil/StdLibCompat.h"



// std::string
coil::Expected<std::string, coil::String> coil::TypeSerializer<std::string>::fromString(coil::Value const& input)
{
    if (input.subvalues.size() != 1)
        return errors::createMismatchedSubvaluesError<std::string>(input, 1);

    return std::string{ input.subvalues[0].data(), input.subvalues[0].length() };
}

coil::String coil::TypeSerializer<std::string>::toString(std::string const& value)
{
    return coil::String{ value.c_str() };
}

COIL_CREATE_TYPE_NAME_DEFINITION(std::string, "string");

// std::string_view
coil::Expected<std::string_view, coil::String> coil::TypeSerializer<std::string_view>::fromString(coil::Value const& input)
{
    if (input.subvalues.size() != 1)
        return errors::createMismatchedSubvaluesError<std::string_view>(input, 1);

    return std::string_view{ input.subvalues[0].data(), input.subvalues[0].length() }; // WTF
}

coil::String coil::TypeSerializer<std::string_view>::toString(std::string_view const& value)
{
    if (value.empty())
        return coil::String{};

    return coil::String{ coil::StringView{value.data(), value.size()} };
}

COIL_CREATE_TYPE_NAME_DEFINITION(std::string_view, "string");

// stream operators
std::ostream& coil::operator<<(std::ostream& os, coil::String const& str)
{
    return os << coil::StringView{ str };
}

std::ostream& coil::operator<<(std::ostream& os, coil::StringView const& str)
{
    return os << std::string_view{ str.data(), str.length() };
}

// conversion helpers
std::string coil::toStdString(StringView str)
{
    return { str.data(), str.length() };
}

std::string_view coil::toStdStringView(StringView str)
{
    return { str.data(), str.length() };
}

coil::String coil::fromStdString(std::string_view str)
{
    return { str.data(), str.length() };
}

coil::StringView coil::fromStdStringView(std::string_view str)
{
    return { str.data(), str.length() };
}
