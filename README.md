# coil (COmmand Interpreter Library)

This is a modern C++17 library that allows you to call functions/methods using a simple object-oriented command-like scripting language. It has no dependencies and doesn't use any macros. Since `coil` relies heavily on the templates, it's header-only (optimized to reduce compile time).

> ⚠️ **The library is currently under development.** Major changes are to be expected, although the main branch is kept more or less stable

> ⚠️ This README file is also not up-to-date and might not reflect the most recent library changes

Table of contents:
- [Quick peek](#quick-peek)
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Quick examples](#quick-examples)
- [Extensibility](#extensibility)
- [Limitations](#limitations)
- [Applications](#applications)
- [Compilation time impact](#compilation-time-impact)
- [Runtime performance](#runtime-performance)
- [Known problems](#known-problems)

## Quick peek

<!-- TODO make sure the code compiles -->
<!-- Get rid of ugly OOP syntax when it's implemented -->
1. Have some regular C++ objects
```cpp
struct SomeSystem
{
    void update(float) {}
    void doSomething() {}
};

int foo = 0;
SomeSystem system1{};
SomeSystem system2{};
```

2. Define some bindings
```cpp
coil::Bindings bindings;
bindings["sum"] = [](int a, int b) { return a + b; };
bindings["foo"] = coil::variable(&foo);

auto systemBindings = bindings.createObjectBindings<SomeSystem>();
systemBindings["update"] = &SomeSystem::update;
systemBindings["do_something"] = &SomeSystem::doSomething;

bindings.addObject("system1", &system1);
bindings.addObject("system2", &system2);
```

3. Execute commands
```cpp
auto result1 = bindings.execute("sum 3 4");
assert(*result1.returnValue == "7");

bindings.execute("foo 42");
assert(foo == 42);

auto result3 = bindings.execute("foo");
assert(*result3.returnValue == "42");

bindings.execute("system1.update 0.16");
bindings.execute("system2.update 0.16");
bindings.execute("system1.do_something");
bindings.execute("system2.do_something");
```

For more examples check `examples` directory or [Quick examples](#quick-examples) section

## Introduction

`coil` allows you to bind a name string to any callable object (function, method, lambda, etc.) and then use that name to invoke it. Arguments are automatically converted to match the callable's signature.

The library is designed to hide the implementation detail from the end user: you don't have to inherit your objects from anything (or change them in any other way) to make the bindings work. That means that you can even bind methods of standard C++ objects (like `string`, `vector`, etc.):
```cpp
std::string str = "Hello, world!";
bindings.bind<std::string>("substr", &std::string::substr);
bindings.addObject("str", &str);
auto result = bindings.execute("str.substr 7 5");
assert(*result.returnValue == "world");
```

`coil` doesn't use any dependencies or macros: everything is implemented in pure C++ with the help of templates. The library is optimized to reduce compilation time as much as possible. Moreover, naive bindings implementation takes more time to compile (see [Compilation time impact](#compilation-time-impact)).

The priorities of the library:
* Low compilation time overhead
* User-friendly API
* Runtime performance

## Features

* Object-oriented syntax (`object.command arg1 arg2`, but global commands `command arg1 arg2` are also supported)
* Customizable syntax (see [Custom Lexer](#custom-lexer))
* Any callable objects: free functions, lambdas, member functions, objects with `operator()`
* Variables
* Enums (serialization has to be implemented in your code, e.g. with [magic_enum](https://github.com/Neargye/magic_enum))
* Optional arguments
* Variable amount of arguments (using vector-like containers)
* Any-like arguments (to allow the command handle several types)
* Named arguments (`object.command foo=3.14 bar=true`)
* Human-readable `bool` serialization
* Error handling
* Custom command syntax (with a custom Lexer)
* User-defined types
* Properties (getter/setter)
* Configurable use of exceptions
* No RTTI
* No unnecessary heap allocations (Lexer operates on `string_view`s)
* Modern C++ without dependencies

## Installation

`coil` is a header-only library, so all you have to do is to copy whole `coil/include/coil` to your include directory. If your project uses CMake, you can also copy `coil/CMakeLists.txt`.

<!-- Mention extern templates and moving implementation to cpp if it gets implemented -->

## Quick examples

- [Enums](#enums)
- [Commands with a variable arguments size](#commands-with-a-variable-arguments-size)
- [Any-like arguments](#any-like-arguments)

### Enums

For enums to work with bindings, all you need to do is to provide a specialization of `TypeSerializer` for that enum type. `TypeSerializer` has a second template parameter to allow `enable_if`; this makes it possible to define a single serializer for all enum types. The quickest way is to use `magic_enum`:

```cpp
namespace coil
{
    template<typename E>
    struct TypeSerializer<E, std::enable_if_t<std::is_enum_v<E>>>
    {
        template<typename OnError>
        static E fromString(std::string_view str, OnError&& onError)
        {
            std::optional<E> optionalValue = magic_enum::enum_cast<E>(str);
            if (optionalValue.has_value())
                return optionalValue.value();

            reportConversionError<E>(std::forward<OnError>(onError), str);
            return E{};
        }

        static auto toString(E const& value)
        {
            return magic_enum::enum_name(value);
        }
    };
}
```

After that you can use enums as any other objects:
```cpp
enum class Ability
{
    None,
    NoRecoil,
};
Ability ability = Ability::None;

bindings["ability"] = coil::variable(&ability);
bindings.execute("ability"); // returns "None"
bindings.execute("ability NoRecoil"); // sets the variable and returns "NoRecoil"
```

### Commands with a variable arguments size

Some types can consume more than 1 string argument. By default that's the case for `std::vector` and `std::optional`, but you can specialize `VariadicConsumer` for other types. Suppose you have the following function:

```cpp
long sumAll(std::vector<long> const& numbers)
{
    return std::accumulate(numbers.begin(), numbers.end(), 0l);
}
```

You can work with it as with any other function (i.e. just bind it to a name and call it)
```cpp
bindings["sum_all"] = &sumAll;
bindings.execute("sum_all"); // returns "0"
bindings.execute("sum_all 1"); // returns "1"
bindings.execute("sum_all 1 2 3 5 8"); // returns "19"
```

### Any-like arguments

You can use `AnyArgView` to represent an "any" argument. Internally it contains a string, which is parsed to a concrete type when needed inside the function

```cpp
void renameEntity(coil::Context context, coil::AnyArgView entity, std::string_view newName)
{
    Entity* target = nullptr;
    if (auto id = entity.get<std::uint64_t>())
        target = getEntityById(*id);
    else if (auto name = entity.get<std::string_view>())
        target = getEntityByName(*name);

    using namespace std::literals::string_literals;
    if (target)
        target->name = newName;
    else
        context.reportError("Failed to find entity '"s + std::string{ entity.getRaw() } + "'"s);
}
```

You can call this function then like this:

```cpp
bindings.execute("rename_entity 0 player0"); // finds an entity by the integer id
bindings.execute("rename_entity entity1 player1"); // finds an entity by the name
```

## Extensibility

The library allows you to specialize certain template structs to allow you to customize the behavior of `coil`.

### TypeSerializer

This struct is responsible for converting C++ types from/to strings. By default the following types are implemented:

* Any type with `operator<<` or `operator>>`
* Arithmetic types (integer and floating-point numbers)
* `bool` (special specialization to allow "true" and "false" values)
* `std::string`
* `std::string_view`
* `std::optional<T>`

You can specialize `TypeSerializer` for your type as follows:

```cpp
struct Entity
{
    std::size_t id = 0;
};

namespace coil
{
    template<>
    struct TypeSerializer<Entity>
    {
        template<typename OnError>
        static Entity fromString(std::string_view str, OnError&& onError)
        {
            std::size_t index = TypeSerializer<std::size_t>::fromString(str, std::move(onError));
            return Entity{ index };
        }

        static auto toString(Entity const& value)
        {
            return TypeSerializer<std::size_t>::toString(value.id);
        }
    };
}
```

There is also a second template parameter to `TypeSerializer`, to make it possible to use `std::enable_if`/`std::enable_if_t`:

```cpp
namespace coil
{
    template<typename T>
    struct TypeSerializer<T, std::enable_if_t<some_static_condition_v<T>>>
    {
        template<typename OnError>
        static T fromString(std::string_view str, OnError&& onError)
        {
            // implementation
        }

        static std::string toString(T value)
        {
            // implementation
        }
    };
}
```

See [Enums example](#enums) for more details.

### VariadicConsumer

If you have a type that can be used as a variadic container (which can hold 0 or more than 1 argument), you can specialize `VariadicConsumer`:

```cpp
namespace coil
{
    template<typename T, std::size_t N>
    struct VariadicConsumer<std::array<T, N>>
    {
        // arg constraints
        static constexpr std::size_t minArgs = N;
        static constexpr bool isUnlimitedArgs = false;
        static constexpr std::size_t maxArgs = N;

        template<typename OnError>
        static std::array<T, N> consume(std::vector<std::string_view> const& arguments, std::size_t index, OnError&& onError)
        {
            std::array<T, N> args;

            // arguments is guaranteed to contain N elements starting from `index` because of the specified arg constraints
            for (auto i = 0; i < N; i++)
                args[i] = TypeSerializer<T>::fromString(arguments[index + i], onError);

            return args;
        }
    };
}
```

### TypeName

Some errors display the type name to give a hint about the source of the error. For example, if the argument cannot be converted to a specified type, you may see the following error:
```
Error: Unable to convert 'forty-two' to type 'float'
```

By default all type names are `unknown` because it's impossible to get the type name with standard means without RTTI. However you can specialize `TypeName` for your type (or for any type):
```cpp
namespace coil
{
    template<typename T>
    struct TypeName<T>
    {
        static std::string_view name()
        {
            return typeid(T).name();
        }
    };

    template<>
    struct TypeName<std::string>
    {
        static std::string_view name()
        {
            return "std::string";
        }
    };
}
```

You can also chain calls to `TypeName` to get a type name for templated types:
```cpp
template<typename T>
struct SomeStruct {};

namespace coil
{
    template<typename T>
    struct TypeName<SomeStruct<T>>
    {
        static std::string_view name()
        {
            using namespace std::literals::string_literals;
            static std::string typeName = "SomeStruct<"s + std::string{ TypeName<T>::name() } + ">"s;
            return typeName;
        }
    };
}
```

### Custom lexer

The Lexer defines syntax for the commands. `coil` comes with a default Lexer, `DefaultLexer`, which implements the following syntax:
```
object.command arg1 arg2 foo=1 bar=baz
```

However if you want to have another syntax (e.g. `object:command(arg1, arg2, foo=1, bar=baz)`), you can provide a custom Lexer, which would convert an input string to `coil::ExecutionInput`.

To define a custom Lexer, you need to create a class with `operator()`. Then you can pass the Lexer object as a second argument to `coil::Bindings::execute`.

`operator()` is exected to have this form:
```cpp
coil::Expected<ExecutionInputConvertibleToRef, std::string> operator()(InputString str)
```

`ExecutionInputConvertibleToRef` is anything that can be converted to `coil::ExecutionInput const&`. You can use plain value, reference, `std::reference_wrapper` or anything else.

`InputString` doesn't have any restrictions, but the first argument to `coil::Bindings::execute` should be convertible to `InputString`. Usually this is a string type (`const char*`, `std::string_view`, `std::string`, etc.), but you are free to use any other type.

For example, the following declarations would be compatible:

```cpp
coil::Expected<coil::ExecutionInput, std::string> operator()(std::string_view str);
coil::Expected<coil::ExecutionInput const&, std::string> operator()(std::string str);
coil::Expected<std::reference_wrapper<coil::ExecutionInput>, std::string> operator()(const char* str);
```

## Limitations

## Applications

### Using as a debug console

One can easily implement a debug console in any C++ game engine using `coil`. For that you need to pass user input to `coil::Bindings::execute` when the command needs to be executed and store the returned object (`ExecutionResult`). You can report output, return value and/or errors of the command in the console UI with the help of `ExecutionResult::output`, `ExecutionResult::returnValue` and `ExecutionResult::errors`.

### Interactive command-line interface (CLI)

To implement an interactive CLI, you can execute `coil::Bindings::execute` in a simple loop. You can check the implementation of examples (see `examples` directory), they use interactive CLI

## Compilation time impact

## Runtime performance

## Known problems
