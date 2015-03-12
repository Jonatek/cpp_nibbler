# C++ Coding Standards

This document attempts to describe a few C++ coding standards that are being used.

Our goal is to write **uniform** (consistent, patterned), **simple**, **readable**, **manageable** (modular) and **effective** (for compiling and running) code!

The ultimate goal of these guidelines is the increase readability and maintainability of our common source base.

# C++ Source Code - General

Comments are one critical part of readability and maintainability. Everyone knows they should comment their code, and so should you. When writing comments, write them as English prose, which means they should use proper capitalization, punctuation, etc. Aim to describe what the code is trying to do and why, not how it does it at a micro level.

## Style

### Indentation and spacing
In all cases, indent C++ code by four SPACES... or tabs, but spaces is prefer.

### Comment Formatting
In general, prefer C++ style (//) comments. These nest properly and are better behaved in general than C style comments.

### Parameter ordering

First input, then output. You can wrap your parameters in the style like this:

    int calc_x(int x, float z,
                const my_namespace::MyClass::ConstPtr ptr_y
                float* w) {
      // Code goes here ...
    }

## C++ functionaities

### Define variables length

It's fine to use `int`, `float`, `double`, etc. if you just want to use some variables locally. Otherwise, when necessary, think about using `uint8_t`, `int16_t`, `float32_t`, etc. 

### Const

It protects data from being illegally modified by throwing an error to you. Using `const` where possible is strongly recommended. You may have bigger chance of getting compiler error, but you will have less time spent on debugging because the `const`, throwing the error, tells you exactly where the problem is.

**Const Correctness**: always do `const` the "right" way:

    int const x;

instead of

    const int x;

It makes more sense if you have something like

    int const * p;

which means the object the pointer points to is a `const`, while

    int * const p;

means the pointer itself is a `const`, while

    int const * const p;

means both. So you get the idea: `const` describes the things on its left; therefore, make it always `right`. For more information, please checkout http://www.parashift.com/c++-faq-lite/const-correctness.html.

### Explicit constructor

Use it when you feel necessary, especially for the case that the constructor has one or more class type varialbes as parameters.

### Static type

Do not declare dynamic type (vector, class, etc.) as static.

### Type casting

Use static_cast<TYPE> for simple type conversions, dynamic_cast<TYPE> for complex type conversions and interpret_cast<TYPE> for pointers and direct memory block reinterpretation (for example, get a float form char[4]). In other words,

    float f = 3.1415926;
    int i = static_cast<int>(f); // Good.
    A a; B b = dynamic_cast<A>(a); // Usually good.
           b = (A) a; // Bad.
    char[4] float_bytes = {...};
    f = *(interpret_cast<float*>(float_bytes)); // Good.
    f = *((float*) float_bytes); // Bad.

This will become clear when you start to work with more complex data types.

### Self-increment

Though `++i` is faster than `i++`, you can actually use either of them for primitive types (int, float, etc.) as you like; but for more complex tyes like iterators, preincrement is always favored.

    `++i`; // Good.
    `i++`; // Bad.

## File Headers

Every source file should have a header on it that recites the file name and the author who create it with creation date and last update etc... The standard header looks like this, it's the EPITECH header :

```
/*
** fileName.c for what in /home/login/rendu/....
**
** Made by ....
** Login ...
**
** Started on  date name
** Last update date name
*/
```
Why ? Because it looks like more pretty with it.

## \#include ordering

Immediately after the header file comment (and include guards if working on a header file), the minimal list of #includes required by the file should be listed. We prefer these \#includes to be listed in this order:

    1. Local/Private Headers
    2. System/Global #includes

## Header files

### Use “`.hpp`” please, otherwise emacs is doing shit with the syntax color and
indentation

Style 1: `.hpp` for definition; `.cpp` for implementation. (e.g. `my_class.hpp`)

### The #define Guard

    #ifndef _[FILE]_HPP_
    #define _[FILE]_HPP_

    // Your code goes here …
    
    #endif

Example: for file `bar.hpp`, the `#define` guard is: `_BAR_HPP_`.

## Naming

### In code

`ExampleName`: for class/struct/union names (not variables or class instances names), type names;

`exampleName`: for instances, variables names and functions (class methods) only, and, although allowed, is not recommended;

`isConditionSatisfied`: boolean variables;

`_example_name`: for function parameters (`int func(int _x, float _param)`);

`EXAMPLE_NAME`: for macros, enums and defines.

# Compiler Issues

## Treat Compiler Warning as Errors!
If your code has compiler warnings in it, something is wrong — you aren’t casting values correctly, you have “questionable” constructs in your code, or you are doing something legitimately wrong. Compiler warnings can cover up legitimate errors in output and make dealing with a translation unit difficult.

## Write Portable Code 
In almost all cases, it is possible and within reason to write completely portable code. If there are cases where it isn’t possible to write portable code, isolate it behind a well defined (and well documented) interface.

In practice, this means that you shouldn’t assume much about the host compiler.

***
Note: This is partially copied from the different coding standards that looks
good, feel free to improve it.
