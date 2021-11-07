#pragma once
#include <utility>
#include "TrueIndices.h"

namespace coil::utils
{
    template<bool... Bs>
    struct ElementSelector
    {
    public:
        template<typename SourceTuple>
        static auto select(SourceTuple const& source)
        {
            static_assert(sizeof...(Bs) == std::tuple_size_v<SourceTuple>, "SourceTuple size should match the size of Bs");

            return createTuple(source, TrueIndicesT<Bs...>{});
        }

    private:
        template<typename SourceTuple, std::size_t... Is>
        static auto createTuple(SourceTuple const& source, std::index_sequence<Is...>)
        {
            using ResultTuple = std::tuple<std::tuple_element_t<Is, SourceTuple>...>;
            return ResultTuple{ std::get<Is>(source)... };
        }
    };
}
