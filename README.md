# coil (COmmand Interpreter Library)

## Invoke C++ functions at runtime with cmd-like interface!

---

[![codecov](https://codecov.io/gh/AntonShalgachev/coil/branch/master/graph/badge.svg?token=VFJT3W6568)](https://codecov.io/gh/AntonShalgachev/coil)
[![Windows](https://github.com/AntonShalgachev/coil/actions/workflows/windows.yml/badge.svg)](https://github.com/AntonShalgachev/coil/actions/workflows/windows.yml)
[![Ubuntu](https://github.com/AntonShalgachev/coil/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/AntonShalgachev/coil/actions/workflows/ubuntu.yml)

This is a C++17 library that allows you to call functions at runtime using a simple yet powerful command-like scripting language. It has no dependencies. `coil` relies on the templates, however it's optimized for compilation speed (see [Compilation time impact](#compilation-time-impact))

> ⚠️ **The library is currently under development.** Major changes are to be expected, although the main branch is kept more or less stable

> ⚠️ This README file is also not up-to-date and might not reflect the most recent library changes

Table of contents:
- [Quick peek](#quick-peek)
- [Features overview](#features-overview)
    - [Functions](#functions)
    - [Variables](#variables)
    - [Enums](#enums)
    - [Named arguments](#named-arguments)
- [Introduction](#introduction)
    - [Motivation](#motivation)
- [Features](#features)
- [Installation](#installation)
- [Quick examples](#quick-examples)
    - [Enums](#enums-1)
    - [Commands with a variable arguments size](#commands-with-a-variable-arguments-size)
    - [Any-like arguments](#any-like-arguments)
- [Extensibility](#extensibility)
- [Limitations](#limitations)
- [Applications](#applications)
- [Compilation time impact](#compilation-time-impact)
- [Runtime performance](#runtime-performance)
- [Known problems](#known-problems)

<!-- TODO make sure the code compiles -->
## Quick peek

1. Have any regular variable or any callable object:
```cpp
int sum(int a, int b) { return a + b; }
int variable = 42;
```

2. Create command bindings:
```cpp
coil::Bindings bindings;
bindings["sum"] = &sum;
bindings["var"] = coil::variable(&variable);
```
3. Execute the command when you need it:
```cpp
bindings.execute("sum 5 8"); // calls `sum`, returns "13" as a string
bindings.execute("var"); // returns "42"
bindings.execute("var 84"); // changes variable to 84, returns "84"
assert(variable == 84);
```

## Features overview

Here you'll find a brief overview of the features. You can check the examples (`examples` directory) for more details.

### Functions
Any C++ functor object can be used for the command:
```cpp
struct Functor
{
    double operator()(int val) { /*...*/ }
};
double func(int val) { /*...*/ }

bindings["functor"] = Functor{};
bindings["func"] = &func;
bindings["lambda"] = [](int val) { /*...*/ };
```

You can also bind member functions to a specific objects:
```cpp
struct InventoryManager
{
    void add(std::string const& id, std::size_t amount) { /*...*/ }
};
InventoryManager inventoryManager;

bindings["inventory.add"] = coil::bind(&InventoryManager::add, &inventoryManager);
```

> ⚠️ Make sure that `inventoryManager` isn't destroyed during the command lifetime

### Variables
You can create a command which gets/sets the value of a variable:
```cpp
int variable = 42;

bindings["var"] = coil::variable(&variable);

bindings.execute("var"); // returns variable value
bindings.execute("var 17"); // modifies the variable and returns its value
```

As with the functions, you can bind a member variable to a specific object:
```cpp
struct InventoryManager
{
    bool debugMode = false;
};

InventoryManager inventoryManager;

bindings["inventory.debug"] = coil::variable(&InventoryManager::debugMode, &inventoryManager);
```

> ⚠️ Make sure that `inventoryManager` isn't destroyed during the command lifetime

### Enums
As soon as there is a `TypeSerializer` specialization for your enum type, you can use it in your commands:

```cpp
enum class DebugMode { Off, Limited, Full };
DebugMode debugMode = DebugMode::Off;

class Widget
{
    enum class Anchor { TopLeft, TopRight, BottomLeft, BottomRight };
    void show(Anchor anchor) { /*...*/ }
}
Widget widget;

bindings["debugmode"] = coil::variable(&debugMode);
bindings["widget.show"] = coil::bind(&Widget::show, &widget);
```

One way to specialize `TypeSerializer` for enums is to use `magic_enum`. See `enums` example to see how it can be done

### Named arguments
`coil` allows you to create commands with the named arguments:
```
savegame save_tag type=Memory delay=0.5
```

Named arguments can be queried via a `coil::Context` object:
```cpp
enum class SaveGameType { Disk, Memory };
void saveGame(coil::Context context, std::string tag)
{
    auto& namedArgs = context.namedArgs();

    auto type = namedArgs.getOrReport<SaveGameType>("type", coil::NamedArgs::ArgType::Required);
    auto delay = namedArgs.getOrReport<float>("delay", coil::NamedArgs::ArgType::Optional, 0.0f);

    // use *type and *delay
}

bindings["savegame"] = &saveGame;

bindings.execute("savegame save_tag type=Memory");
bindings.execute("savegame save_tag type=Disk delay=0.5");
```

`coil::Context` is a transparent argument, which means it's passed automatically if it's the first function argument

See `named` example for more details (optional/required arguments, error handling, etc.)

### Command text output
### Error handling
### Any-like arguments
### Custom user types
### Properties
### Optional arguments
### Variadic arguments

## Introduction

`coil` allows you to bind a name string to any callable object (function, method, lambda, etc.) and then use that name to invoke it. Arguments are automatically converted to match the callable's signature.

The library doesn't use any dependencies or macros: everything is implemented in pure C++ with the help of templates. The library is optimized to reduce compilation time as much as possible. Moreover, naive bindings implementation takes more time to compile (see [Compilation time impact](#compilation-time-impact)).

The priorities of the library:
* Low compilation time overhead
* User-friendly API
* Runtime performance

## Features

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

## Motivation

It's very common to see a very simple debug console implementation in game engines, where you bind a command to a "command handler" taking an array of strings. The input string is then split by spaces and then the corresponding command handler is invoked with the array of raw user input.

For example to bind ths command `add_inventory_item` to this function

```cpp
void addInventoryItem(std::string const& item, std::size_t amount, std::size_t slot) {}
```

you would have to write the following wrapper:

```cpp
void addInventoryItemCommand(std::vector<std::string> const& args)
{
    // do a bunch of checks and call `addInventoryItem` after converting arguments to the given types
}
```

This approach has a lot of drawbacks:
- A lot of boilerplate code:
    - Check if the number of arguments is correct
    - ... report a readable error if it's wrong
    - Try to convert each string argument to a particular type
    - Check if the conversion succeeded
    - ... report a readable error if it didn't
    - Run the actual command logic
    - Convert the return value to the string and return it to the caller
- Easy to forget/ignore something from the abovementioned steps
    - Usually only the bare minimum is implemented with no feedback if the command arguments are wrong
- A lot of code duplication (string to type conversion for each argument)
- The code is usually copy-pasted, which can lead to the errors being multiplied
    - Some code uses atoi/strtol and alike without appropriate error handling
    - Some code might process arguments in a sophisticated way (e.g. split them by "=" to implement named arguments)
- Not clear which arguments does the command require without having to take a look at the function implementation

All this might discourage a programmer from adding a useful debug command

This library is an attempt to get rid of these problems by providing a straightforward way to implement these bindings with all the "validation" logic done by the library itself in a centralized and efficient manner

## Limitations

## Applications

### Using as a debug console

One can easily implement a debug console in any C++ game engine using `coil`. For that you need to pass user input to `coil::Bindings::execute` when the command needs to be executed and store the returned object (`ExecutionResult`). You can report output, return value and/or errors of the command in the console UI with the help of `ExecutionResult::output`, `ExecutionResult::returnValue` and `ExecutionResult::errors`.

### Interactive command-line interface (CLI)

To implement an interactive CLI, you can execute `coil::Bindings::execute` in a simple loop. You can check the implementation of examples (see `examples` directory), they use interactive CLI

## Compilation time impact

Compilation time is a number one priority of `coil`, so it's been optimized to have as little compilation overhead as possible. While the full compilation time analysis is still to be conducted, here are some preliminary metrics which have been used to improve the compilation performance.

### Test project structure
The test project contains 200 generated classes. Each class contains 12 member functions (4 with 0 arguments, 4 with 1 argument and 4 with 2 arguments), 12 member variables, 12 static member functions (4 with 0 arguments, 4 with 1 argument and 4 with 2 arguments) and 12 static member variables. Each member function contains some dummy logic to make the compiler do some measurable work.

All of these classes have optional debug bindings for each member function, member variable, static member function and static member variable. Based on the `#define` value, these debug bindings could be either disabled or could be implemented in 2 ways:
- Using `coil`: each function/variabls is bound directly to a string via `coil::Bindings`
- Using naive implementation. In this implementation only specific functions can be bound, specifically with this signature: `std::string(std::vector<std::string> const&)`. The function should parse all arguments from strings by itself and should return the result as a string. If the debug bindings are implemented this way, these 200 classes add an additional wrapper function per functions/variable (the wrapper function would manually check number of arguments, convert them to the target type, invoke original function and then convert its return value to string). This implementation is added to the test because it's frequently seen in the game engines I worked on.

### Test procedure

The test is performed for 3 configurations:
- "Base": debug bindings disabled completely, only the class logic is compiled
- "Coil": debug bindings are implemented using `coil`
- "Naive": debug bindings are implemented in a naive way, where a dedicated wrapper function has to be written for each function/variable

For each configuration project is generated using `cmake` (Ninja generator), then a build is performed once, discarding the compilation duration, and then the project is rebuilt 10 times (cleaning before each iteration). The durations of these 10 builds are analyzed to compute the median, average, minimum and maximum time

You can see the test script here: [scripts/test_compilation/run.ps1](scripts/test_compilation/run.ps1).

### Results

These are the numbers I've got on my machine:

| Configuration | Clang (seconds)    | MSVC (seconds)     |
| ------------- | ------------------ | ------------------ |
| Base          | 13.738365411758423 | 7.671312928199768  |
| Coil          | 16.172605514526367 | 12.114667296409607 |
| Naive         | 20.63681662082672  | 17.464430809020996 |

## Runtime performance

## Known problems
