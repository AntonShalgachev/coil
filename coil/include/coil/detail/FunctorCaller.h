#pragma once

#include <string>
#include <vector>
#include <optional>

#include "CallContext.h"
#include "../utils/Types.h"
#include "coil/TypeSerializer.h"
#include "FuncTraitsEx.h"
#include "coil/utils/TrueIndices.h"

namespace coil::detail
{
    // TODO move to another file
    // TODO allow specialization
    template<typename T>
    struct VariadicConsumer
    {
        template<typename OnError>
        static T consume(std::vector<std::string_view> const& arguments, std::size_t index, OnError&& onError)
        {
            return TypeSerializer<T>::fromString(arguments[index], std::forward<OnError>(onError));
        }
    };

    template<typename T>
    struct VariadicConsumer<std::vector<T>>
    {
        template<typename OnError>
        static std::vector<T> consume(std::vector<std::string_view> const& arguments, std::size_t index, OnError&& onError)
        {
            std::vector<T> args;
            args.reserve(arguments.size() - index);

            for (auto i = index; i < arguments.size(); i++)
                args.push_back(TypeSerializer<T>::fromString(arguments[i], onError));

            return args;
        }
    };

    template<typename T>
    struct VariadicConsumer<std::optional<T>>
    {
        template<typename OnError>
        static std::optional<T> consume(std::vector<std::string_view> const& arguments, std::size_t index, OnError&& onError)
        {
            if (index >= arguments.size())
                return {};

            return TypeSerializer<T>::fromString(arguments[index], std::forward<OnError>(onError));
        }
    };

    // TODO move to another file
    // TODO allow specialization
    template<typename T>
    struct ArgCountTraits
    {
        static constexpr std::size_t min = 1;
        static constexpr bool isUnlimited = false;
        static constexpr std::size_t max = 1;
    };

    template<typename T>
    struct ArgCountTraits<std::vector<T>>
    {
        static constexpr std::size_t min = 0;
        static constexpr bool isUnlimited = true;
        static constexpr std::size_t max = 0;
    };

    template<typename T>
    struct ArgCountTraits<std::optional<T>>
    {
        static constexpr std::size_t min = 0;
        static constexpr bool isUnlimited = false;
        static constexpr std::size_t max = 1;
    };

    template<std::size_t currentMin, bool isUnlimited, std::size_t currentMax, typename... Args>
    struct VariadicArgsTraitsImpl;

    template<std::size_t currentMin, bool isUnlimited, std::size_t currentMax, typename Head, typename... Tail>
    struct VariadicArgsTraitsImpl<currentMin, isUnlimited, currentMax, Head, Tail...> : VariadicArgsTraitsImpl<currentMin + ArgCountTraits<std::decay_t<Head>>::min, isUnlimited || ArgCountTraits<std::decay_t<Head>>::isUnlimited, currentMax + ArgCountTraits<std::decay_t<Head>>::max, Tail...> {};

    template<std::size_t currentMin, bool currentIsUnlimited, std::size_t currentMax>
    struct VariadicArgsTraitsImpl<currentMin, currentIsUnlimited, currentMax>
    {
        static_assert(currentMax >= currentMin || currentIsUnlimited, "For unlimited arguments currentMax should not be less than currentMin");

        static constexpr std::size_t minArgs = currentMin;
        static constexpr bool isUnlimited = currentIsUnlimited;
        static constexpr std::size_t maxArgs = currentMax;

        static constexpr bool isVariadic = isUnlimited || (minArgs != maxArgs);
    };

    template<typename... Args>
    struct VariadicArgsTraits;

    template<typename... Args>
    struct VariadicArgsTraits<utils::Types<Args...>> : VariadicArgsTraitsImpl<0, false, 0, Args...> {};

    template<typename Func>
    struct FunctorCaller
    {
    public:
        template<typename T>
        static void call(Func& func, CallContext& context, T* target)
        {
            using UserArgTypes = typename Traits::UserArgumentTypes;
            using UserArgIndicesType = typename UserArgTypes::IndicesType;

            if (!validateArguments(context))
                return;

            if (!context.input.namedArguments.empty() && !Traits::hasNamedArgs)
            {
                context.result.errors.push_back("The function doesn't support named arguments");
                return;
            }

            static constexpr bool hasTarget = Traits::template isMethodOfType<T> || Traits::hasTarget;
            static constexpr bool hasContext = Traits::hasContext;
            static constexpr bool hasNamedArgs = Traits::hasNamedArgs;

            std::tuple<T*, Context, NamedArgs> nonUserArgs{ target, Context{context}, NamedArgs{context} };
            using NonUserArgIndices = utils::TrueIndicesT<hasTarget, hasContext, hasNamedArgs>;

            unpackAndInvoke(func, context, nonUserArgs, NonUserArgIndices{}, UserArgTypes{}, UserArgIndicesType{});
        }

    private:
        using Traits = detail::FuncTraitsEx<Func>;
        using R = typename Traits::ReturnType;

        template<typename NonUserArgsTuple, std::size_t... NonUserIndices, typename... UserArgs, std::size_t... UserIndices>
        static void unpackAndInvoke(Func& func, CallContext& context, NonUserArgsTuple& nonUserArgs, std::index_sequence<NonUserIndices...>, utils::Types<UserArgs...>, std::index_sequence<UserIndices...>)
        {
            auto onError = [&context](std::string error)
            {
                context.result.errors.push_back(std::move(error));
            };

            invoke(func, context.result, std::get<NonUserIndices>(nonUserArgs)..., VariadicConsumer<std::decay_t<UserArgs>>::consume(context.input.arguments, UserIndices, onError)...);
        }

        // Introduce fake R template parameter as a workaround to MSVC evaluating false 'if constexpr' branch
        template<typename... Args, typename R = R>
        static void invoke(Func& func, ExecutionResult& result, Args&&... args)
        {
            if (!result)
                return;

            try
            {
                if constexpr (std::is_void_v<R>)
                {
                    std::invoke(func, std::forward<Args>(args)...);
                }
                else
                {
                    auto&& returnValue = std::invoke(func, std::forward<Args>(args)...);
                    if (result)
                        result.returnValue = TypeSerializer<std::decay_t<R>>::toString(returnValue);
                }
            }
            catch (std::exception const& ex)
            {
                result.errors.push_back(utils::formatString("Exception caught during execution: %s", ex.what()));
            }
        }

        static bool validateArguments(CallContext& context)
        {
            using ArgTypes = typename Traits::UserArgumentTypes;

            auto const& arguments = context.input.arguments;
            std::size_t const actualArgsCount = arguments.size();

            auto constexpr minArgs = VariadicArgsTraits<ArgTypes>::minArgs;
            auto constexpr isUnlimited = VariadicArgsTraits<ArgTypes>::isUnlimited;
            auto constexpr maxArgs = VariadicArgsTraits<ArgTypes>::maxArgs;
            auto constexpr isVariadic = VariadicArgsTraits<ArgTypes>::isVariadic;

            auto const isCorrect = actualArgsCount >= minArgs && (isUnlimited || actualArgsCount <= maxArgs);

            if (isCorrect)
                return true;

            std::string expectedMessage;
            if constexpr (isVariadic && isUnlimited)
                expectedMessage = utils::formatString("at least %d", minArgs);
            else if constexpr (isVariadic && !isUnlimited)
                expectedMessage = utils::formatString("from %d to %d", minArgs, maxArgs);
            else
                expectedMessage = utils::formatString("%d", minArgs);

            std::string_view functionName = context.input.functionName;
            std::string typeNames = utils::flatten(ArgTypes::decayedNames());
            std::string actualArgsStr = utils::flatten(arguments, "'");
            auto errorMessage = utils::formatString("Wrong number of arguments to '%.*s': expected %s ([%s]), got %d (%s)", functionName.size(), functionName.data(), expectedMessage.c_str(), typeNames.c_str(), actualArgsCount, actualArgsStr.c_str());

            context.result.errors.push_back(std::move(errorMessage));

            return false;
        }
	};
}
