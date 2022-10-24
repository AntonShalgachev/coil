#pragma once

#include "Bindings.h"
#include "Expected.h"
#include "NamedArgs.h"
#include "TypeSerializer.h"
#include "Value.h"
#include "Variable.h"
#include "String.h"
#include "StringView.h"
#include "detail/Utility.h"

// TODO review these extern templates

extern template class coil::Vector<coil::String>;
extern template class coil::Optional<coil::String>;

extern template class coil::Vector<coil::Value>;
extern template class coil::Vector<coil::NamedValue>;

extern template class coil::Vector<coil::StringView>;

extern template class coil::Expected<coil::Value, coil::NamedArgs::Error>;

extern template class coil::UniquePtr<coil::Lexer>;

extern template class coil::Unexpected<coil::String>;
extern template coil::Unexpected<coil::String> coil::makeUnexpected(coil::String value);
extern template coil::Unexpected<coil::String>&& coil::Move<coil::Unexpected<coil::String>&>(coil::Unexpected<coil::String>&) noexcept; // TODO remove?

extern template coil::detail::AnyStorageBase*&& coil::Move<coil::detail::AnyStorageBase*&>(coil::detail::AnyStorageBase*&) noexcept; // TODO remove?
extern template void coil::exchange<coil::detail::AnyStorageBase*>(coil::detail::AnyStorageBase*&, coil::detail::AnyStorageBase*&) noexcept;

extern template coil::String&& coil::Forward<coil::String>(coil::String&) noexcept; // TODO remove?

#define COIL_TYPE_SERIALIZER_TEMPLATE_BASE(T, SPECIFIER) SPECIFIER template struct coil::TypeSerializer<T>

#define COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(T) COIL_TYPE_SERIALIZER_TEMPLATE_BASE(T, extern)
#define COIL_TYPE_SERIALIZER_TEMPLATE(T) COIL_TYPE_SERIALIZER_TEMPLATE_BASE(T, )

///////////////////////////////////////////////////////////////////////////////////////////

#define COIL_VARIABLE_TEMPLATE_BASE(SPECIFIER, T) SPECIFIER template coil::Vector<coil::AnyFunctor> coil::variable<T>(T * var)

#define COIL_ARGUMENT_TEMPLATE_BASE(SPECIFIER, T)                                                                                             \
    SPECIFIER template class coil::Expected<T, coil::String>;                                                                                  \
    SPECIFIER template coil::Expected<T, coil::String>::Expected(coil::Unexpected<coil::String>);                                    \
    SPECIFIER template void coil::detail::reportError<T>(coil::detail::CallContext & context, coil::Expected<T, coil::String> const& result);  \
    SPECIFIER template coil::Expected<T, coil::String>&& coil::Move<coil::Expected<T, coil::String>&>(coil::Expected<T, coil::String>&) noexcept; \
    SPECIFIER template T&& coil::Forward<T>(T&) noexcept;                                                                                      \
    SPECIFIER template T&& coil::Move<T&>(T&) noexcept

#define COIL_NAMED_ARGS_TEMPLATE_BASE(SPECIFIER, T)                                                                   \
    SPECIFIER template class coil::Optional<T>;                                                                        \
    SPECIFIER template class coil::Expected<T, coil::NamedArgs::Error>;                                               \
    SPECIFIER template coil::Expected<T, coil::NamedArgs::Error> coil::NamedArgs::get<T>(coil::StringView key) const; \
    SPECIFIER template coil::Optional<T> coil::NamedArgs::getOrReport<T>(coil::StringView key, coil::NamedArgs::ArgType argType, coil::Optional<T> defaultValue) const

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
