#pragma once
#include "coil/utils/TypeListTraits.h"
#include "ArgumentTraits.h"

namespace coil
{
    namespace detail
    {
        template<typename Func>
        struct FuncTraitsEx : public utils::FuncTraits<Func>
        {
        private:
            using Base = utils::FuncTraits<Func>;
            using ArgTypes = typename Base::ArgumentTypes;

        public:
            template<typename TargetT>
            static constexpr bool needToPassTarget = !std::is_void_v<TargetT> && std::is_same_v<TargetT, Base::ObjectType>;

            using UserArgumentTypes = utils::FilterTypesT<IsUserArgument, ArgTypes>;
            using ExplicitTargetTraits = utils::TypeListTraits<IsExplicitTargetArgument, ArgTypes>;
            using ContextTraits = utils::TypeListTraits<IsContextArgument, ArgTypes>;
            using NamedArgsTraits = utils::TypeListTraits<IsNamedArgsArgument, ArgTypes>;
        };
    }
}