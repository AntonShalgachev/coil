#include "coil/Extern.h"

template class std::vector<std::string>;
template class std::optional<std::string>;

template class std::vector<coil::ArgValue>;
template class std::vector<std::pair<std::string_view, coil::ArgValue>>;

template class std::vector<std::string_view>;

template class std::optional<coil::AnyArgView>;
template class coil::Expected<coil::AnyArgView, coil::NamedArgs::Error>;

template class coil::BasicStringWrapper<std::string>;
template struct std::hash<coil::BasicStringWrapper<std::string>>;

template class coil::BindingProxy<coil::Bindings>;

template class std::basic_string_view<char>;
template class std::basic_string<char>;

template class coil::Unexpected<std::string>;
template coil::Unexpected<std::string> coil::makeUnexpected(std::string value);
template coil::Unexpected<std::string>&& std::move<coil::Unexpected<std::string>&>(coil::Unexpected<std::string>&) noexcept;

template coil::detail::AnyStorageBase*&& std::move<coil::detail::AnyStorageBase*&>(coil::detail::AnyStorageBase*&) noexcept;
template void std::swap<coil::detail::AnyStorageBase*>(coil::detail::AnyStorageBase*&, coil::detail::AnyStorageBase*&) noexcept;

template std::string&& std::forward<std::string>(std::string&) noexcept;

template std::vector<coil::detail::AnyFunctor>::~vector();

COIL_TYPE_SERIALIZER_TEMPLATE(signed short);
COIL_TYPE_SERIALIZER_TEMPLATE(unsigned short);
COIL_TYPE_SERIALIZER_TEMPLATE(signed int);
COIL_TYPE_SERIALIZER_TEMPLATE(unsigned int);
COIL_TYPE_SERIALIZER_TEMPLATE(signed long);
COIL_TYPE_SERIALIZER_TEMPLATE(unsigned long);
COIL_TYPE_SERIALIZER_TEMPLATE(signed long long);
COIL_TYPE_SERIALIZER_TEMPLATE(unsigned long long);
COIL_TYPE_SERIALIZER_TEMPLATE(float);
COIL_TYPE_SERIALIZER_TEMPLATE(double);
COIL_TYPE_SERIALIZER_TEMPLATE(long double);
