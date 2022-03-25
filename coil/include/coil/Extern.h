#pragma once

extern template std::string coil::formatString<unsigned int, char const*>(char const*, unsigned int, char const*);
extern template std::string coil::formatString<unsigned int, char const*, unsigned int, char const*>(char const*, unsigned int, char const*, unsigned int, char const*);
extern template std::string coil::formatString<unsigned int, char const*, unsigned int, char const*, unsigned int, char const*>(char const*, unsigned int, char const*, unsigned int, char const*, unsigned int, char const*);
extern template std::string coil::formatString<char const*>(char const*, char const*);

extern template class std::optional<coil::AnyArgView>;
extern template class coil::Expected<coil::AnyArgView, coil::NamedArgs::Error>;

extern template class std::vector<coil::ArgValue>;
extern template class std::vector<std::pair<std::string_view, coil::ArgValue>>;

extern template class coil::BasicStringWrapper<std::string>;
extern template struct std::hash<coil::BasicStringWrapper<std::string>>;
// extern template class std::vector<coil::detail::AnyFunctor>;
// extern template class std::unordered_map<coil::StringWrapper, std::vector<coil::detail::AnyFunctor>>;
extern template class coil::BindingProxy<coil::Bindings>;

extern template class std::vector<std::string_view>;

#define EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(T) \
    extern template class std::optional<T>; \
    extern template class coil::ExpectedBase<T, coil::NamedArgs::Error>; \
    extern template class coil::Expected<T, coil::NamedArgs::Error>; \
    extern template coil::Expected<T, coil::NamedArgs::Error> coil::NamedArgs::get<T>(std::string_view key) const; \
    extern template std::optional<T> coil::NamedArgs::getOrReport(std::string_view key, coil::NamedArgs::ArgType argType, std::optional<T> defaultValue) const

#define EXPLICIT_NAMED_ARGS_TEMPLATE(T) \
    template class std::optional<T>; \
    template class coil::ExpectedBase<T, coil::NamedArgs::Error>; \
    template class coil::Expected<T, coil::NamedArgs::Error>; \
    template coil::Expected<T, coil::NamedArgs::Error> coil::NamedArgs::get<T>(std::string_view key) const; \
    template std::optional<T> coil::NamedArgs::getOrReport(std::string_view key, coil::NamedArgs::ArgType argType, std::optional<T> defaultValue) const

#define EXTERN_EXPLICIT_FUNCTOR_CALLER_TEMPLATE(T) \
    extern template void coil::detail::reportError<T>(coil::detail::CallContext& context, coil::Expected<T, std::string> const& result)

#define EXPLICIT_FUNCTOR_CALLER_TEMPLATE(T) \
    template void coil::detail::reportError<T>(coil::detail::CallContext& context, coil::Expected<T, std::string> const& result)

#define EXTERN_EXPLICIT_TYPE_SERIALIZER_TEMPLATE(T) \
    extern template struct coil::TypeSerializer<T>; \
    extern template class coil::ExpectedBase<T, std::string>; \
    extern template class coil::Expected<T, std::string>

#define EXPLICIT_TYPE_SERIALIZER_TEMPLATE(T) \
    template struct coil::TypeSerializer<T>; \
    template class coil::ExpectedBase<T, std::string>; \
    template class coil::Expected<T, std::string>
