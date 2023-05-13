# Template

## Introduction

Templates in C++ are a powerful feature that enables generic programming, or programming with generic types. They allow you to write a single piece of code that can work with different data types.

A template can be thought of as a kind of macro that the compiler uses to generate the actual code based on the specified type.

Here are the basics of C++ templates:

### **1. Function Templates**

A function template acts as a blueprint for creating functions. Here is an example of a function template:

```cpp
template <typename T>
T Max(T a, T b) {
    return (a > b) ? a : b;
}
```

In this example, `T` is a placeholder for a type. When you call the `Max` function with two integers, two doubles, or two of any other type that has the `>` operator defined, the compiler generates a version of the `Max` function for that type.

### **2. Class Templates**

Just like function templates, class templates allow you to define a blueprint for a class. Here is an example:

```cpp
template <typename T>
class MyArray {
public:
    MyArray() { /* ... */ }
    void insert(T value, int index) { /* ... */ }
    T get(int index) { /* ... */ }
    // ...
private:
    T data[100];
};
```

In this example, `MyArray` is a template for creating arrays of any type.

### **3. Template Specialization**

Sometimes, you might want to define a different implementation of a function or class for a specific type. This is called template specialization. Here's an example with our `Max` function:

```cpp
template <>
const char* Max(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}
```

In this case, we've defined a specialized version of `Max` that works with C-style strings.

### **4. Template Parameters**

Templates can take more than one parameter, and not all parameters have to be types. You can also have non-type parameters, like integers. For example:

```cpp
template <typename T, int size>
class MyArray {
    // ...
private:
    T data[size];
};
```

Here, `size` is a non-type parameter that determines the size of the array.

Templates are a complex topic, and there's a lot more to them, like variadic templates, member function templates, template aliases, etc. But this should give you a good basic understanding of what templates are and how they work.



## Tips

### Template Function Cannot be Virtual

A virtual function in C++ is a member function which is declared within a base class and is re-defined (Overriden) by a derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the function.

Templates, on the other hand, are expanded at compile time. This means that the compiler creates a new version of the function for each type (or set of types) you use with it. 

**These two features of C++—virtual functions and templates—don't play well together due to their nature:**

1. **Compile-Time vs Runtime:** Templates are a compile-time construct while virtual functions are a runtime concept. The compiler needs to know the exact type to generate the code for a template function, but in case of a virtual function, the exact type is not known until runtime.

2. **Declaration in Base Class:** A virtual function must be declared in the base class, and the base class should not have any knowledge about the derived classes. However, a template function in a base class would need to know about all the types that the derived classes might use, which is not possible or desirable.

Because of these reasons, you can't have virtual function templates in C++. Alternatively, you can have a virtual function that calls a template function. This way you can get some of the benefits of both features.