# Template Aliasing

Template aliasing in C++ allows you to create a shorthand or alias for a templated type, simplifying the use of complex templates and making code more readable. This feature, introduced in C++11, is particularly useful for templates that take multiple parameters or are used frequently throughout your code. Here's an example to illustrate template aliasing using the `using` keyword:

First, let's define a basic template class as a starting point:

```cpp
template<typename T>
class MyContainer {
public:
    T value;
    MyContainer(T v) : value(v) {}
    // Additional functionality
};
```

Without template aliasing, if you want to refer to this templated type for a specific type, you would have to use the full template syntax each time:

```cpp
MyContainer<int> intContainer(42);
MyContainer<std::string> stringContainer("Hello");
```

Template aliasing simplifies the syntax needed to use `MyContainer` with specific types.

```cpp
// Alias for MyContainer with int
using IntContainer = MyContainer<int>;

// Alias for MyContainer with std::string
using StringContainer = MyContainer<std::string>;
```

```cpp
IntContainer intContainer(42);      // Simpler than writing MyContainer<int>
StringContainer stringContainer("Hello"); // Simpler than writing MyContainer<std::string>
```

You can also create a templated alias that can be used with any type, further enhancing the flexibility of your code.

```cpp
template<typename T>
using Container = MyContainer<T>;
```

```cpp
Container<int> intContainer(42);           // Equivalent to MyContainer<int>
Container<std::string> stringContainer("World"); // Equivalent to MyContainer<std::string>
```

or even:

```cpp
template<typename T, typename U>
class MyContainer {
public:
    T value1;
    U value2;
    MyContainer(T v1, U v2) : value1(v1), value2(v2) {}
    // Additional functionality
};
```

```cpp
template<typename T>
using Container = MyContainer<T, int>;
```

```cpp
Container<std::string> stringAndIntContainer("Hello", 42);
```

In this example, `Container<std::string>` is an alias for `MyContainer<std::string, int>`. This means `stringAndIntContainer` is an instance of `MyContainer` with `T` as `std::string` and `U` as `int`. 

By fixing one of the template parameters (`U` as `int`) through a template alias, you make the `MyContainer` template class more specific and easier to use for cases where the second type parameter is consistently an `int`. 