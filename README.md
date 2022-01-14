# coil (COmmand Interpreter Library)

This is a modern C++17 library that allows you to call functions/methods using a simple object-oriented command-like scripting language. It has no dependencies and doesn't use any macros. Since `coil` relies heavily on the templates, it's header-only (optimized to reduce compile time).

## Quick peek

<!-- TODO make sure the code compiles -->
<!-- Get rid of ugly OOP syntax when it's implemented -->
1. Have some regular C++ objects
```cpp
struct SomeSystem
{
    void update(float) {}
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
bindings.bind<SomeSystem>("update", &SomeSystem::update);

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
```

For more examples check `examples` directory or [Examples section](#examples)

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
* Any callable objects: free functions, lambdas, member functions, objects with `operator()`
* Variables
* Enums (serialization has to be implemented in your code, e.g. with [magic_enum](https://github.com/Neargye/magic_enum))
* Optional arguments
* Variable amount of arguments (using vector-like containers)
* Type-less arguments (to allow the command handle several types)
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

## Examples

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

## Extensibility

## Limitations

## Applications

### Using as a debug console

One can easily implement a debug console in any C++ game engine using `coil`. For that you need to pass user input to `coil::Bindings::execute` when the command needs to be executed and store the returned object (`ExecutionResult`). You can report output, return value and/or errors of the command in the console UI with the help of `ExecutionResult::output`, `ExecutionResult::returnValue` and `ExecutionResult::errors`.

### Interactive command-line interface (CLI)

To implement an interactive CLI, you can execute `coil::Bindings::execute` in a simple loop. You can check the implementation of examples (see `examples` directory), they use interactive CLI

## Compilation time impact

## Runtime performance

## Known problems
