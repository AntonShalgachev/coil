#pragma once

namespace coil
{
    template<class InputIt, class T>
    constexpr InputIt find(InputIt first, InputIt last, T const& value)
    {
        for (; first != last; ++first)
            if (*first == value)
                return first;

        return last;
    }
}
