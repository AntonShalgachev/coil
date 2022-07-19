# coil (COmmand Interpreter Library)

## Invoke C++ functions at runtime with cmd-like interface!

---

[![GitHub](https://img.shields.io/github/license/AntonShalgachev/coil?color=brightgreen&label=License&logo=github)](LICENSE)
[![codecov](https://codecov.io/gh/AntonShalgachev/coil/branch/master/graph/badge.svg?token=VFJT3W6568)](https://codecov.io/gh/AntonShalgachev/coil)
[![Windows](https://github.com/AntonShalgachev/coil/actions/workflows/windows.yml/badge.svg)](https://github.com/AntonShalgachev/coil/actions/workflows/windows.yml)
[![Ubuntu](https://github.com/AntonShalgachev/coil/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/AntonShalgachev/coil/actions/workflows/ubuntu.yml)

This is a C++17 library that allows you to call functions at runtime using a simple yet powerful command-like scripting language. It has no dependencies. `coil` relies on the templates, however it's optimized for compilation speed (see [Compilation time impact](#compilation-time-impact))

Table of contents:
- [Quick peek](#quick-peek)
- [Introduction](#introduction)
- [Features](#features)
- [Examples](#examples)
- [Building](#building)
- [Integration](#integration)
- [Motivation](#motivation)
- [Limitations](#limitations)
- [Applications](#applications)
- [Compilation time impact](#compilation-time-impact)
- [Roadmap](#roadmap)
- [Known problems](#known-problems)

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

## Introduction

`coil` allows you to bind a name string to any callable object (function, method, lambda, etc.) and then use that name to invoke it. Arguments are automatically converted to match the callable's signature.

The library doesn't use any dependencies or macros: everything is implemented in pure C++ with the help of templates. The library is optimized to reduce compilation time as much as possible. Moreover, naive bindings implementation takes more time to compile (see [Compilation time impact](#compilation-time-impact)).

The priorities of the library (in the order of importance):
* Low compilation time overhead
* User-friendly API
* Runtime performance

## Features

* Customizable syntax (see [Custom Lexer](#custom-lexer))
* Any callable objects: free functions, lambdas, member functions, custom functors with `operator()`
* Variables (e.g. `camera.fov` to get and `camera.fov 90` to set)
* Enums (serialization has to be implemented in your code, e.g. with [magic_enum](https://github.com/Neargye/magic_enum))
* Compound arguments (e.g. 3D point: `particles.spawn resource_id (10, 1, 5)`)
* Any-like arguments (to allow the command handle several types)
* Named arguments (`object.command foo=3.14 bar=true`)
* Human-readable `bool` serialization
* Customizable error messages
* Customizable command syntax (with a custom Lexer)
* User-defined types
* Properties (getter/setter)
* Configurable use of exceptions
* No RTTI
* No unnecessary heap allocations (Lexer operates on `string_view`s)
* Modern C++ without dependencies

## Examples
See [examples](examples) directory and the corresponding [README.md](examples/README.md) for information about the available examples

## Building

The project contains the following CMake options:
* Library configuration:
    * `COIL_CATCH_EXCEPTIONS` (`OFF` by default): catch and report exceptions thrown in the command
    * `COIL_BASIC_TYPENAME` (`ON` by default): include the implementation of `coil::TypeName` for the basic types
* Project options (all `OFF` by default):
    * `COIL_EXAMPLES`: adds examples
    * `COIL_RUNTIME_TESTS`: adds runtime tests
    * `COIL_COMPILATION_TESTS`: performs compilation test during CMake project generation
    * `COIL_COMPILATION_TIME_BENCHMARK`: adds compilation time benchmark
    * `COIL_COMPILATION_TIME_BENCHMARK_TRACE`: tells the Clang to generate trace file to profile compilation
    * `COIL_COMPILATION_TIME_BENCHMARK_WITH_COIL`: tells the compilation time benchmark to use `coil` (this library) as the command bindings
    * `COIL_COMPILATION_TIME_BENCHMARK_WITH_MANUAL`: tells the compilation time benchmark to use naively implemented command bindings

### Building examples
Run the following command to generate the project: `cmake -B build -DCOIL_EXAMPLES=ON`. This will add the `examples` target to the project, which is an executable you'll want to run

### Building tests
Run the following command to generate the project: `cmake -B build -DCOIL_RUNTIME_TESTS=ON`. This will add the `cmake_tests` target to the project. Run this executable to execute all the tests

### Performing compilation tests
Add `-DCOIL_COMPILATION_TESTS=ON` to the CMake arguments to perform the compilation test during the project generation. This utilizes CMake's `try_compile` command

## Integration

### CMake FetchContent

```cmake
FetchContent_Declare(
    coil
    GIT_REPOSITORY https://github.com/AntonShalgachev/coil # or use URL
)

# Configure coil if necessary:
# set(COIL_CATCH_EXCEPTIONS ON CACHE INTERNAL "")
# set(COIL_BASIC_TYPENAME OFF CACHE INTERNAL "")

FetchContent_MakeAvailable(coil)
```

Then later in your target:
```cmake
target_link_libraries(app PRIVATE coil::coil)
```

You don't need to explicitly set anything if you only want to import the library without examples/tests

### CMake add_subdirectory

Copy the entire source tree into your project, then in your `CMakeLists.txt` call:
```cmake
# Configure coil if necessary:
# set(COIL_CATCH_EXCEPTIONS ON CACHE INTERNAL "")
# set(COIL_BASIC_TYPENAME OFF CACHE INTERNAL "")

add_subdirectory(path/to/coil)
target_link_libraries(app PRIVATE coil::coil)
```

You don't need to explicitly set anything if you only want to import the library without examples/tests

## Motivation

It's very common to see a very simple debug console implementation in game engines, where you bind a command to a "command handler" taking an array of strings. The input string is then split by spaces and then the corresponding command handler is invoked with the array of raw user input.

For example to bind the command `inventory.add_item` to this function

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

## Roadmap
- [ ] Do more research on the compilation time
- [ ] Clean up the code with the help of clang-tidy and IWYU
- [ ] Remove heavy files from the repository
- [ ] Simplify DefaultLexer
- [ ] Reorganize tests (make them more modular)
- [ ] Test `coil` in the actual project
- [ ] Research if C++20 features would decrease compilation time
- [ ] Proper documentation
    - [ ] How to decrease compilation time
    - [ ] Which parts can be customized and how
- [ ] More features (if useful)
    - [ ] Callback when variable changes

## Known problems
