# coil (COmmand Interpreter Library)

This is a modern C++17 library that allows you to call functions or object methods using a simple object-oriented command-like scripting language. It has no dependencies and doesn't use any macros. Since `coil` relies heavily on the templates, it's header-only (optimized to reduce compile time).

This library was initially thought as a building block for the debug console (developer console) in a C++ game engine, but it can be used for other purposes (e.g. providing a command-line interface for the application).

Sample usage:

<!-- TODO make usre the code compiles -->
<!-- Get rid of ugly OOP syntax when it's implemented -->
```cpp
struct SomeSystem
{
    bool update(float) { return true; }
}

int foo = 0;
SomeSystem system{};

coil::Bindings bindings;
bindings["sum"] = [](int a, int b) { return a + b; };
bindings["foo"] = &foo;
bindings.bind<SomeSystem>("update", &SomeSystem::update);

bindings.addObject("system", &system);

auto result1 = bindings.execute("sum 3 4");
assert(*result1.returnValue == "7");

bindings.execute("foo 42");
assert(foo == 42);

auto result3 = bindings.execute("foo");
assert(*result3.returnValue == "42");

auto result4 = bindings.execute("system.update 0.16");
assert(*result4.returnValue == "true");
```

## Introduction

The library allows you to bind a name string to any callable object (function, method, lambda, etc.) and then use that name to invoke it. Arguments are automatically converted to match the callable's signature.

This library doesn't use any dependencies or macros: everything is implemented in pure C++ with the help of templates. Although the templates are used extensivly, the library was optimized to reduce compilation time as much as possible.

The priorities of this library (in order):
* Low compilation time overhead
* User-friendly API
* Runtime performance

## Features

* Variables
* Object-oriented syntax
* Enums (serialization has to be implemented in your code, e.g. with `magic_enum`)
* Optional arguments
* Variable amount of arguments (using vector-like containers)
* Named arguments
* Human-readable `bool` serialization
* Error handling
* Custom command syntax (with a custom Lexer)
* User-defined types
* Properties (getter/setter)
* Configurable use of exceptions
* No RTTI
* Modern C++ without dependencies

## Installation

## Examples

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
