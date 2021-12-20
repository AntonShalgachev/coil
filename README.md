# coil (COmmand Interpreter Library)

This is a modern C++17 library that allows you to call functions/methods or change variables using a simple command-like scripting language. It has no dependencies and doesn't use any macros. Since `coil` relies heavily on the templates, it's header-only.

This library was initially thought as a building block for the debug console (developer console) in a C++ game engine, but of course it can be used for other purposes (e.g. providing a command-line interface for the application)

Sample use:

```cpp
int foo = 0;
coil::Bindings bindings;
bindings["sum"] = [](int a, int b) { return a + b; };
bindings["foo"] = &foo;

auto result = bindings.execute("sum 3 4");
assert(*result.returnValue == "7");

bindings.execute("foo 42");
assert(foo == 42);
```

## Introduction

The library allows you to bind a name string to any callable object (function, method, lambda, etc.) and then use that name to invoke it. Arguments are automatically converted to match the object's signature

## Features

## Examples

## Extensibility

## Limitations

## Applications

### Using as a debug console

## Runtime performance

## Compilation time impact
