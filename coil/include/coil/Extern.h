#pragma once

#include <optional>
#include <vector>
#include <string_view>
#include <string>

#include "coil/AnyArgView.h"
#include "coil/ArgValue.h"
#include "coil/Expected.h"
#include "coil/NamedArgs.h"
#include "coil/TypeSerializer.h"
#include "coil/Variable.h"

#include "coil/detail/StringWrapper.h"

extern template class std::optional<coil::AnyArgView>;
extern template class coil::Expected<coil::AnyArgView, coil::NamedArgs::Error>;

extern template class std::vector<coil::ArgValue>;
extern template class std::vector<std::pair<std::string_view, coil::ArgValue>>;

extern template class std::vector<std::string_view>;

extern template class coil::BasicStringWrapper<std::string>;
extern template struct std::hash<coil::BasicStringWrapper<std::string>>;

extern template class coil::BindingProxy<coil::Bindings>;

extern template class std::basic_string_view<char>;
extern template class std::basic_string<char>;

extern template class coil::Unexpected<std::string>;
extern template coil::Unexpected<std::string> coil::makeUnexpected(std::string value);
extern template coil::Unexpected<std::string>&& std::move<coil::Unexpected<std::string>&>(coil::Unexpected<std::string>&) noexcept;

extern template coil::detail::AnyStorageBase*&& std::move<coil::detail::AnyStorageBase*&>(coil::detail::AnyStorageBase*&) noexcept;
extern template void std::swap<coil::detail::AnyStorageBase*>(coil::detail::AnyStorageBase*&, coil::detail::AnyStorageBase*&) noexcept;

extern template std::string&& std::forward<std::string>(std::string&) noexcept;

#define COIL_TYPE_SERIALIZER_TEMPLATE_BASE(T, SPECIFIER) \
    SPECIFIER template struct coil::TypeSerializer<T>; \
    SPECIFIER template coil::Expected<T, std::string> coil::TypeSerializer<T>::fromString(coil::ArgValue const& input); \
    SPECIFIER template std::string coil::TypeSerializer<T>::toString(T const& value)

#define COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(T) COIL_TYPE_SERIALIZER_TEMPLATE_BASE(T, extern)
#define COIL_TYPE_SERIALIZER_TEMPLATE(T) COIL_TYPE_SERIALIZER_TEMPLATE_BASE(T, )

COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(signed short);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(unsigned short);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(signed int);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(unsigned int);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(signed long);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(unsigned long);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(signed long long);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(unsigned long long);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(float);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(double);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(long double);

///////////////////////////////////////////////////////////////////////////////////////////

#define COIL_VARIABLE_TEMPLATE_BASE(T, SPECIFIER) \
    SPECIFIER template std::vector<coil::detail::AnyFunctor> coil::variable<T>(T* var)

#define COIL_ARGUMENT_TEMPLATE_BASE(T, SPECIFIER) \
    SPECIFIER template class coil::ExpectedBase<T, std::string>; \
    SPECIFIER template class coil::Expected<T, std::string>; \
    SPECIFIER template coil::ExpectedBase<bool, std::string>::ExpectedBase(coil::Unexpected<std::string>); \
    SPECIFIER template void coil::detail::reportError<T>(coil::detail::CallContext& context, coil::Expected<T, std::string> const& result); \
    SPECIFIER template coil::Expected<T, std::string>&& std::move<coil::Expected<T, std::string>&>(coil::Expected<T, std::string>&) noexcept; \
    SPECIFIER template T&& std::move<T&>(T&) noexcept

#define COIL_NAMED_ARGS_TEMPLATE_BASE(T, SPECIFIER) \
    SPECIFIER template class std::optional<T>; \
    SPECIFIER template class coil::ExpectedBase<T, coil::NamedArgs::Error>; \
    SPECIFIER template class coil::Expected<T, coil::NamedArgs::Error>; \
    SPECIFIER template coil::Expected<T, coil::NamedArgs::Error> coil::NamedArgs::get<T>(std::string_view key) const; \
    SPECIFIER template std::optional<T> coil::NamedArgs::getOrReport<T>(std::string_view key, coil::NamedArgs::ArgType argType, std::optional<T> defaultValue) const

#define COIL_VARIABLE_EXTERN_TEMPLATE(T) COIL_VARIABLE_TEMPLATE_BASE(T, extern)
#define COIL_ARGUMENT_EXTERN_TEMPLATE(T) COIL_ARGUMENT_TEMPLATE_BASE(T, extern)
#define COIL_NAMED_ARGS_EXTERN_TEMPLATE(T) COIL_NAMED_ARGS_TEMPLATE_BASE(T, extern)

#define COIL_VARIABLE_TEMPLATE(T) COIL_VARIABLE_TEMPLATE_BASE(T, )
#define COIL_ARGUMENT_TEMPLATE(T) COIL_ARGUMENT_TEMPLATE_BASE(T, )
#define COIL_NAMED_ARGS_TEMPLATE(T) COIL_NAMED_ARGS_TEMPLATE_BASE(T, )
