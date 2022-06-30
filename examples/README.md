# Examples

This folder contains various examples. They are organized as a single shell-like application, where you are prompted to type the name of the example

## Building
Just set the `COIL_EXAMPLES` option before generating the CMake project. See the details in the root [README.md](../README.md#installation)

## List of examples

### Basic
This examples touches the basics:
* Various functors with various arguments
* Return values
* Capturing log output
* Binding member functions
* Basic error output

### Variables
This example explains how to bind variables, as well as how to create your own variable-like commands which wrap a variable

### Enums
This example describes how to use enums in your commands. The example uses [magic_enum](https://github.com/Neargye/magic_enum), but that can be implemented using any other means

### Flags
This example demonstrates how to implement enum flags, so that functions taking those flags can be invoked by listing individual flags separately:
```
entities.debug_flags DrawOrigin|DrawWireframe
```

### Variadic
This example shows how to use typeless arguments (`coil::Value`, which can be dynamically converted to a desired type) as well as how to report conversion errors of such arguments

### Named
This example showcases the usage of named arguments, which can be used to make some arguments optional (e.g. if they have a default value), or to increase the readability of the command if the amount of command parameters is large
```
inventory.add dollar type=Currency amount=10
save_game type=Memory delay=150
```

### Usertypes
This example demonstrates how to use various user types with the `coil` library. Among others you'll find here an example of a `Vec2` struct (2D point)and a `DynamicArray` class (similar to `std::vector`), all of which can be used with `coil`

### Errors
This example explains how to report errors in your commands to the user. One example of that is `sqrt` function, which reports an error if the passed argument is negative. Another example is error handling if you use variadic arguments or named arguments and the conversion to a specific type has failed

### Compound

### Overloading
This examples gives an overview of binding several function to a single command (i.e. overloading them). This example also shows a way to bind a C++ overloaded function to a command

### Properties
This example demonstrates how to create a "property": a variable-like command which use a setter and a getter to set/get its value. It also gives an example of read-only properies

### Encapsulation
This example shows how to organize the commands inside an object so that:
* The commands would be automatically unregistered when the object is destroyed
* The commands would be completely removed in the Release build

### Advanced
This example lists a couple of advanced applications:
* How to wrap functions which take pointers
* How to create variables dynamically from another command
