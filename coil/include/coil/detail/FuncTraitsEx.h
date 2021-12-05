#pragma once
#include "coil/utils/TypeListTraits.h"
#include "ArgumentTraits.h"
#include "coil/utils/FilterTypes.h"

namespace coil::detail
{
    template<typename Func>
    struct FuncTraitsEx : public utils::FuncTraits<Func>
    {
    private:
        using Base = utils::FuncTraits<Func>;
        using ArgTypes = typename Base::ArgumentTypes;

    public:
        using UserArgumentTypes = utils::FilterTypesT<IsUserArgument, ArgTypes>;
        using ExplicitTargetTraits = utils::TypeListTraits<IsExplicitTargetArgument, ArgTypes>;
        using ContextTraits = utils::TypeListTraits<IsContextArgument, ArgTypes>;
        using NamedArgsTraits = utils::TypeListTraits<IsNamedArgsArgument, ArgTypes>;
    };
}