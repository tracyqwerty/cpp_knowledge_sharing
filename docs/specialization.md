# Specialization & Partial Specialization

In C++, you can specialize templates to provide different code for specific types or values. This is done with template specialization. If you want to specialize for a specific set of types or values, but not for all arguments, you use partial specialization.

## **Template Specialization**

Template specialization allows you to define a different implementation for a specific type or value. Here's an example with a function template:

```cpp
template <typename T>
void print(T value) {
    std::cout << "General template: " << value << '\n';
}

template <>
void print<int>(int value) {
    std::cout << "Specialized template for int: " << value << '\n';
}
```

In this case, we've defined a specialized version of `print` that is used when the argument is an `int`. When you call `print(42)`, it will use the specialized template, and when you call `print(3.14)`, it will use the general template.

## **Partial Specialization**

Partial specialization allows you to specialize a template for a subset of the possible types or values, but not all of them. This is only possible with class templates (not with function templates). Here's an example:

```cpp
template <typename T1, typename T2>
class MyPair {
public:
    MyPair(T1 first, T2 second) : first(first), second(second) {}
    T1 first;
    T2 second;
};

template <typename T>
class MyPair<T, T> {
public:
    MyPair(T first, T second) : first(first), second(second) {}
    T first;
    T second;
    // This version might have additional methods that only make sense when both types are the same
};
```

In this example, we've defined a general template for a pair of values of any two types, and a partial specialization for a pair of values of the same type. When you create a `MyPair<int, double>`, it will use the general template, and when you create a `MyPair<int, int>`, it will use the specialized template.

Partial specialization can be quite complex, as it allows for a lot of flexibility. You can partially specialize for any number of type or non-type arguments, and you can use any combination of specific types, type categories, or even template template parameters.

## Requirements

The ability to partially specialize function templates would create ambiguity in many cases, and it would make function template resolution more complex. The designers of C++ decided not to allow it for simplicity and consistency.

Consider an example where partial function template specialization might be desirable:

```cpp
template <typename T1, typename T2>
void foo(T1 a, T2 b) { /* general implementation */ }

template <typename T>
void foo(T a, T b) { /* specialization for two arguments of the same type */ }
```

Here, it's clear what you want: the first version of `foo` should be used for arguments of different types, and the second version should be used for arguments of the same type. However, this is not how C++ function template resolution works.

In C++, function templates are not chosen based on the "best match" like function overloads are. Instead, they are chosen based on the first match found by the compiler. If partial specialization were allowed, it would be ambiguous which version of `foo` to use when you call it with two arguments of the same type.

To achieve the desired effect, you can use function overloading and template specialization:

```cpp
template <typename T1, typename T2>
void foo(T1 a, T2 b) { /* general implementation */ }

template <typename T>
void foo(T a, T b) { /* overload for two arguments of the same type */ }
```

In this case, `foo(T a, T b)` is not a specialization of `foo(T1 a, T2 b)`, but a separate function template. When you call `foo` with two arguments of the same type, the compiler will choose the second version because it's a better match.