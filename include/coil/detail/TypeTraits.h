#pragma once

namespace coil
{
#if defined(__clang__) || defined(_MSC_VER)
    template<typename From, typename To>
    inline constexpr bool IsConvertibleV = __is_convertible_to(From, To);
#elif defined(__GNUC__)
    template<typename From, typename To>
    inline constexpr bool IsConvertibleV = __is_convertible(From, To);
#endif

    template<typename T>
    struct RemoveCv { using Type = T; };
    template<typename T>
    struct RemoveCv<T const> { using Type = T; };
    template<typename T>
    struct RemoveCv<T volatile> { using Type = T; };
    template<typename T>
    struct RemoveCv<T const volatile> { using Type = T; };
    template<typename T>
    using RemoveCvT = typename RemoveCv<T>::Type;

    template<typename T>
    struct RemoveReference { using Type = T; };
    template<typename T>
    struct RemoveReference<T&> { using Type = T; };
    template<typename T>
    struct RemoveReference<T&&> { using Type = T; };
    template<typename T>
    using RemoveReferenceT = typename RemoveReference<T>::Type;

#if defined(__clang__)
    template <typename T1, typename T2>
    inline constexpr bool IsSameV = __is_same(T1, T2);
#elif defined(_MSC_VER)
    template <typename T1, typename T2>
    inline constexpr bool IsSameV = false;
    template <typename T>
    inline constexpr bool IsSameV<T, T> = true;
#endif

    template<typename T>
    inline constexpr bool IsVoidV = IsSameV<RemoveCvT<T>, void>;
}
