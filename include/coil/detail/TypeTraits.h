#pragma once

namespace coil
{
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

    template<typename T>
    struct RemovePointer { using Type = T; };
    template<typename T>
    struct RemovePointer<T*> { using Type = T; };
    template<typename T>
    struct RemovePointer<T* const> { using Type = T; };
    template<typename T>
    struct RemovePointer<T* volatile> { using Type = T; };
    template<typename T>
    struct RemovePointer<T* const volatile> { using Type = T; };
    template<typename T>
    using RemovePointerT = typename RemovePointer<T>::Type;

    template<typename T>
    using DecayT = RemoveCvT<RemoveReferenceT<T>>;

    template<bool B, class T = void>
    struct EnableIf {};
    template<class T>
    struct EnableIf<true, T> { using Type = T; };
    template<bool B, class T = void>
    using EnableIfT = typename EnableIf<B, T>::Type;

#if defined(__clang__)
    template <typename T1, typename T2>
    inline constexpr bool IsSameV = __is_same(T1, T2);
#else
    template <typename T1, typename T2>
    inline constexpr bool IsSameV = false;
    template <typename T>
    inline constexpr bool IsSameV<T, T> = true;
#endif

    template<typename T>
    inline constexpr bool IsVoidV = IsSameV<RemoveCvT<T>, void>;

    template <typename T>
    using VoidT = void;

    template <typename>
    constexpr bool IsConstV = false;
    template <typename T>
    constexpr bool IsConstV<const T> = true;
    
    template< class T >
    constexpr bool IsMemberPointerV = false;
    template< class T, class U >
    constexpr bool IsMemberPointerV<T U::*> = true;
}
