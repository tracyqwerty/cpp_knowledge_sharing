# `extern`

In C++, "external" and "internal" are terms used to describe the linkage of a variable, function, or object. "Linkage" refers to the visibility of an identifier (that is, a variable or function name) across different translation units (typically .cpp source files).

## **External linkage**

Variables and functions with external linkage are visible to all translation units in a program. By default, non-`const` global variables and functions have external linkage. You can also use the `extern` keyword to explicitly declare a variable or function with external linkage. 

For example, suppose you define a global variable in one .cpp file:

```cpp
// File1.cpp
int myVar = 10;  // has external linkage by default
```

You can then declare and use that same variable in another .cpp file:

```cpp
// File2.cpp
extern int myVar;  // declares a variable with external linkage

void foo() {
    std::cout << myVar;  // prints the value of myVar from File1.cpp
}
```

## **Internal linkage**

Variables and functions with internal linkage are only visible within the same translation unit. By default, `const` global variables, `static` global variables, `static` functions, and unnamed namespaces have internal linkage. 

For example, consider a `static` global variable:

```cpp
// File1.cpp
static int myVar = 10;  // has internal linkage
```

This `myVar` variable is not accessible from other .cpp files. **Even if you try to declare it with `extern` in another file, you'll get a linker error**:

```cpp
// File2.cpp
extern int myVar;  // linker error: myVar from File1.cpp isn't accessible here

void foo() {
    std::cout << myVar;  // won't compile
}
```

The following objects have internal linkage by default:

- **`const`** objects
- **`constexpr`** objects
- **`typedef`** objects
- **`static`** objects in namespace scope

To give a **`const`** object external linkage, declare it as **`extern`** and assign it a value:

```cpp
extern const int value = 42;
```

## Reference

For more information, see https://learn.microsoft.com/en-us/cpp/cpp/program-and-linkage-cpp?view=msvc-170