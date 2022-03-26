#pragma once

extern template std::string coil::formatString<unsigned int, char const*>(char const*, unsigned int, char const*);
extern template std::string coil::formatString<unsigned int, char const*, unsigned int, char const*>(char const*, unsigned int, char const*, unsigned int, char const*);
extern template std::string coil::formatString<unsigned int, char const*, unsigned int, char const*, unsigned int, char const*>(char const*, unsigned int, char const*, unsigned int, char const*, unsigned int, char const*);
extern template std::string coil::formatString<char const*>(char const*, char const*);

extern template class std::optional<coil::AnyArgView>;
extern template class coil::Expected<coil::AnyArgView, coil::NamedArgs::Error>;

extern template class std::vector<coil::ArgValue>;
extern template class std::vector<std::pair<std::string_view, coil::ArgValue>>;

extern template class std::vector<std::string_view>;

extern template class coil::BasicStringWrapper<std::string>;
extern template struct std::hash<coil::BasicStringWrapper<std::string>>;
// extern template class std::vector<coil::detail::AnyFunctor>;
// extern template class std::unordered_map<coil::StringWrapper, std::vector<coil::detail::AnyFunctor>>;
extern template class coil::BindingProxy<coil::Bindings>;

extern template class std::basic_string_view<char>;
extern template class std::basic_string<char>;

extern template class coil::Unexpected<std::string>;
extern template coil::Unexpected<std::string> coil::makeUnexpected(std::string value);
extern template coil::Unexpected<std::string>&& std::move<coil::Unexpected<std::string>&>(coil::Unexpected<std::string>&) noexcept;

extern template coil::detail::AnyStorageBase*&& std::move<coil::detail::AnyStorageBase*&>(coil::detail::AnyStorageBase*&) noexcept;
extern template void std::swap<coil::detail::AnyStorageBase*, 0>(coil::detail::AnyStorageBase*&, coil::detail::AnyStorageBase*&) noexcept;

extern template std::string&& std::forward<std::string>(std::string&) noexcept;

#define COIL_EXTERN_TEMPLATE(T) \
    extern template auto coil::variable<T>(T* var); \
    \
    extern template class std::optional<T>; \
    extern template class coil::ExpectedBase<T, coil::NamedArgs::Error>; \
    extern template class coil::Expected<T, coil::NamedArgs::Error>; \
    extern template coil::Expected<T, coil::NamedArgs::Error> coil::NamedArgs::get<T>(std::string_view key) const; \
    extern template std::optional<T> coil::NamedArgs::getOrReport(std::string_view key, coil::NamedArgs::ArgType argType, std::optional<T> defaultValue) const; \
    \
    extern template void coil::detail::reportError<T>(coil::detail::CallContext& context, coil::Expected<T, std::string> const& result); \
    \
    extern template coil::Unexpected<std::string> coil::makeSerializationError<T>(coil::ArgValue const& input, std::string_view details); \
    extern template struct coil::TypeSerializer<T>; \
    extern template class coil::ExpectedBase<T, std::string>; \
    extern template class coil::Expected<T, std::string>; \
    extern template coil::ExpectedBase<bool, std::string>::ExpectedBase(coil::Unexpected<std::string>); \
    extern template coil::Expected<T, std::string>&& std::move<coil::Expected<T, std::string>&>(coil::Expected<T, std::string>&) noexcept; \
    extern template T&& std::move<T&>(T&) noexcept

#define COIL_TEMPLATE(T) \
    template auto coil::variable<T>(T* var); \
    \
    template class std::optional<T>; \
    template class coil::ExpectedBase<T, coil::NamedArgs::Error>; \
    template class coil::Expected<T, coil::NamedArgs::Error>; \
    template coil::Expected<T, coil::NamedArgs::Error> coil::NamedArgs::get<T>(std::string_view key) const; \
    template std::optional<T> coil::NamedArgs::getOrReport(std::string_view key, coil::NamedArgs::ArgType argType, std::optional<T> defaultValue) const; \
    \
    template void coil::detail::reportError<T>(coil::detail::CallContext& context, coil::Expected<T, std::string> const& result); \
    \
    template coil::Unexpected<std::string> coil::makeSerializationError<T>(coil::ArgValue const& input, std::string_view details); \
    template struct coil::TypeSerializer<T>; \
    template class coil::ExpectedBase<T, std::string>; \
    template class coil::Expected<T, std::string>; \
    template coil::ExpectedBase<bool, std::string>::ExpectedBase(coil::Unexpected<std::string>); \
    template coil::Expected<T, std::string>&& std::move<coil::Expected<T, std::string>&>(coil::Expected<T, std::string>&) noexcept; \
    template T&& std::move<T&>(T&) noexcept
