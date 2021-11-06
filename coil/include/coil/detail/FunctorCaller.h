#pragma once

#include <string>
#include <vector>
#include <optional>

#include "CallContext.h"
#include "../utils/Types.h"
#include "Converter.h"
#include "../utils/FuncTraits.h"
#include "../utils/FilterTypes.h"
#include "FuncTraitsEx.h"
#include "../utils/ElementSelector.h"

namespace coil
{
	namespace detail
    {
        // TODO think of a better name and move to another file
        template<typename T>
        struct VariadicConverter
        {
            template<typename OnError>
            static T fromString(std::vector<std::string> const& arguments, std::size_t index, OnError&& onError)
            {
                return Converter<T>::fromString(arguments.at(index), std::forward<OnError>(onError));
            }
        };

        template<typename T>
        struct VariadicConverter<std::vector<T>>
        {
            template<typename OnError>
            static std::vector<T> fromString(std::vector<std::string> const& arguments, std::size_t index, OnError&& onError)
            {
                std::vector<T> args;

                for (auto i = index; i < arguments.size(); i++)
                    args.push_back(Converter<T>::fromString(arguments.at(i), onError));

                return args;
            }
        };

        template<typename T>
        struct VariadicConverter<std::optional<T>>
        {
            template<typename OnError>
            static std::optional<T> fromString(std::vector<std::string> const& arguments, std::size_t index, OnError&& onError)
            {
                if (index >= arguments.size())
                    return {};

                return Converter<T>::fromString(arguments.at(index), std::forward<OnError>(onError));
            }
        };

        // TODO think of a better name and move to another file
        template<typename T>
        struct SwallowAmount
        {
            static constexpr std::size_t count = 1;
            static constexpr bool variadic = false;
        };

        template<typename T>
        struct SwallowAmount<std::vector<T>>
        {
            static constexpr std::size_t count = 0;
            static constexpr bool variadic = true;
        };

        template<typename T>
        struct SwallowAmount<std::optional<T>>
        {
            static constexpr std::size_t count = 0;
            static constexpr bool variadic = true;
        };

        template<std::size_t min, bool variadic, typename... Args>
        struct SwallowTraitsImpl
        {

        };

        template<std::size_t min, bool variadic, typename Head, typename... Tail>
        struct SwallowTraitsImpl<min, variadic, Head, Tail...> : SwallowTraitsImpl<min + SwallowAmount<std::decay_t<Head>>::count, variadic || SwallowAmount<std::decay_t<Head>>::variadic, Tail...>
        {

        };
        template<std::size_t min, bool variadic>
        struct SwallowTraitsImpl<min, variadic>
        {
            static constexpr std::size_t min = min;
            static constexpr bool variadic = variadic;
        };

        template<typename... Args>
        struct SwallowTraits : SwallowTraitsImpl<0, false, Args...>
        {

        };

        template<typename... Args>
        struct SwallowTraits<utils::Types<Args...>> : SwallowTraits<Args...>
        {

        };

		template<typename Func>
		struct FunctorCaller
		{
		public:
            template<typename T>
            static void call(Func& func, CallContext& context, T* target)
            {
                using UserArgTypes = typename Traits::UserArgumentTypes;
                using UserArgIndicesType = typename UserArgTypes::IndicesType;

                if (!validateArguments<UserArgTypes>(context))
                    return;

                Context contextArg{ context };
                std::tuple<T*, Context&> nonUserArgOptions{ target, contextArg };

                static constexpr bool b1 = Traits::template isMethodOfType<T> || Traits::ExplicitTargetTraits::isPresent;
                static constexpr bool b2 = Traits::ContextTraits::isPresent;

                auto nonUserArgs = utils::ElementSelector<b1, b2>::select(nonUserArgOptions);
                using NonUserArgIndices = std::make_index_sequence<std::tuple_size_v<decltype(nonUserArgs)>>;

                unpackAndInvoke(func, context, nonUserArgs, NonUserArgIndices{}, UserArgTypes{}, UserArgIndicesType{});
            }

		private:
			using Traits = detail::FuncTraitsEx<Func>;
            using R = typename Traits::ReturnType;

            template<typename NonUserArgsTuple, std::size_t... NonUserIndices, typename... UserArgs, std::size_t... UserIndices>
            static void unpackAndInvoke(Func& func, CallContext& context, NonUserArgsTuple const& nonUserArgs, std::index_sequence<NonUserIndices...>, utils::Types<UserArgs...>, std::index_sequence<UserIndices...>)
            {
                auto onError = [&context](std::string error)
                {
                    context.result.errors.push_back(std::move(error));
                };

                invoke(func, context.result, std::get<NonUserIndices>(nonUserArgs)..., VariadicConverter<std::decay_t<UserArgs>>::fromString(context.input.arguments, UserIndices, onError)...);
            }

            // Introduce fake R template parameter as a workaround to MSVC evaluating false 'if constexpr' branch
            template<typename... Args, typename R = R>
            static void invoke(Func& func, ExecutionResult& result, Args&&... args)
            {
                if (!result)
                    return;

                try
                {
                    static_assert(std::is_invocable_v<Func, Args...>, "Cannot invoke Func with given arguments");

                    if constexpr (std::is_void_v<R>)
                    {
                        std::invoke(func, std::forward<Args>(args)...);
                    }
                    else
                    {
                        auto returnValue = std::invoke(func, std::forward<Args>(args)...);
                        if (result)
                            result.output = Converter<R>::toString(returnValue);
                    }
                }
                catch (std::exception const& ex)
                {
                    result.errors.push_back(utils::formatString("Exception caught during execution: %s", ex.what()));
                }
            }

            template<typename ArgTypes>
            static bool validateArguments(CallContext& context)
            {
                auto const& arguments = context.input.arguments;

                auto constexpr minArgs = SwallowTraits<ArgTypes>::min;
                auto constexpr isVariadic = SwallowTraits<ArgTypes>::variadic;

                bool result = false;

                if constexpr (isVariadic)
                    result = arguments.size() >= minArgs;
                else
                    result = arguments.size() == minArgs;

                if (result)
                    return true;

                char const* errorFormat = nullptr;
                if constexpr (isVariadic)
                    errorFormat = "Wrong number of arguments to variadic '%s': expected at least %d (%s), got %d (%s)";
                else
                    errorFormat = "Wrong number of arguments to '%s': expected %d (%s), got %d (%s)";

                std::string typeNames = ArgTypes::name();
                std::string actualArguments = utils::flatten(arguments, "'");
                context.result.errors.push_back(utils::formatString(errorFormat, context.input.name.c_str(), minArgs, typeNames.c_str(), arguments.size(), actualArguments.c_str()));

                return false;
            }
		};
	}
}
