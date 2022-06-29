#pragma once

#include "Expected.h"
#include "NamedArgs.h"
#include "TypeSerializer.h"
#include "Value.h"
#include "Variable.h"
#include "detail/StringWrapper.h"

#include <optional>
#include <string>
#include <string_view>
#include <vector>

extern template class std::vector<std::string>;
extern template class std::optional<std::string>;
extern template std::optional<std::string>::optional(std::string&&);

extern template class std::vector<coil::Value>;
extern template class std::vector<std::pair<std::string_view, coil::Value>>;

extern template class std::vector<std::string_view>;

extern template class std::optional<coil::Value>;
extern template class coil::Expected<coil::Value, coil::NamedArgs::Error>;

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

extern template std::vector<coil::AnyFunctor>::~vector();

#define COIL_TYPE_SERIALIZER_TEMPLATE_BASE(T, SPECIFIER) SPECIFIER template struct coil::TypeSerializer<T>

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

#define COIL_VARIABLE_TEMPLATE_BASE(SPECIFIER, T) SPECIFIER template std::vector<coil::AnyFunctor> coil::variable<T>(T * var)

#define COIL_ARGUMENT_TEMPLATE_BASE(SPECIFIER, T)                                                                                             \
    SPECIFIER template class coil::ExpectedBase<T, std::string>;                                                                              \
    SPECIFIER template class coil::Expected<T, std::string>;                                                                                  \
    SPECIFIER template coil::ExpectedBase<bool, std::string>::ExpectedBase(coil::Unexpected<std::string>);                                    \
    SPECIFIER template void coil::detail::reportError<T>(coil::detail::CallContext & context, coil::Expected<T, std::string> const& result);  \
    SPECIFIER template coil::Expected<T, std::string>&& std::move<coil::Expected<T, std::string>&>(coil::Expected<T, std::string>&) noexcept; \
    SPECIFIER template T&& std::forward<T>(T&) noexcept;                                                                                      \
    SPECIFIER template T&& std::move<T&>(T&) noexcept

#define COIL_NAMED_ARGS_TEMPLATE_BASE(SPECIFIER, T)                                                                   \
    SPECIFIER template class std::optional<T>;                                                                        \
    SPECIFIER template class coil::ExpectedBase<T, coil::NamedArgs::Error>;                                           \
    SPECIFIER template class coil::Expected<T, coil::NamedArgs::Error>;                                               \
    SPECIFIER template coil::Expected<T, coil::NamedArgs::Error> coil::NamedArgs::get<T>(std::string_view key) const; \
    SPECIFIER template std::optional<T> coil::NamedArgs::getOrReport<T>(std::string_view key, coil::NamedArgs::ArgType argType, std::optional<T> defaultValue) const

#define COIL_FUNCTION_ARGS_TEMPLATE_BASE(SPECIFIER, ...)                                         \
    SPECIFIER template coil::AnyFunctor::AnyFunctor(coil::detail::FunctionWrapper<__VA_ARGS__>); \
    SPECIFIER template class coil::detail::FunctionWrapper<__VA_ARGS__>;                         \
    SPECIFIER template class coil::detail::AnyStorage<coil::detail::FunctionWrapper<__VA_ARGS__>>

#define COIL_VARIABLE_EXTERN_TEMPLATE(T) COIL_VARIABLE_TEMPLATE_BASE(extern, T)
#define COIL_ARGUMENT_EXTERN_TEMPLATE(T) COIL_ARGUMENT_TEMPLATE_BASE(extern, T)
#define COIL_NAMED_ARGS_EXTERN_TEMPLATE(T) COIL_NAMED_ARGS_TEMPLATE_BASE(extern, T)
#define COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(...) COIL_FUNCTION_ARGS_TEMPLATE_BASE(extern, __VA_ARGS__)

#define COIL_VARIABLE_TEMPLATE(T) COIL_VARIABLE_TEMPLATE_BASE(, T)
#define COIL_ARGUMENT_TEMPLATE(T) COIL_ARGUMENT_TEMPLATE_BASE(, T)
#define COIL_NAMED_ARGS_TEMPLATE(T) COIL_NAMED_ARGS_TEMPLATE_BASE(, T)
#define COIL_FUNCTION_ARGS_TEMPLATE(...) COIL_FUNCTION_ARGS_TEMPLATE_BASE(, __VA_ARGS__)
