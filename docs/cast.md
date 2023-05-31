# Type Casting

In C++, casting is a way of telling the compiler that you intend to treat an object of one type as though it were another type. There are several different types of casts in C++.

## Static Cast

`static_cast` is the most commonly used cast. It performs conversions between compatible types. It can also be used to perform any standard conversion, such as converting an integer into a float or a base class pointer into a derived class pointer.

Example:
```cpp
int i = 10;
float f = static_cast<float>(i);  // convert int to float
```

## Dynamic Cast

`dynamic_cast` is specifically used for handling **polymorphism**. You can use `dynamic_cast` to convert a base class pointer into a derived class pointer, or vice versa. **It uses RTTI (Run-time Type Identification) to ensure that the conversion is safe.** If the conversion is not possible, `dynamic_cast` will return a null pointer in case of pointers, or throw a `bad_cast` exception in case of references.

Example:
```cpp
class Base { virtual void dummy() {} };
class Derived : public Base { int a; };

Base* b1 = new Base;
if(Derived* d = dynamic_cast<Derived*>(b1)) {
    std::cout << "downcast from b1 to d successful";
} else {
    std::cout << "downcast from b1 to d not successful";
}
```

## Const Cast

`const_cast` is used to add or remove the `const` qualifier from a variable. It is the only C++ style that can do this.

Example:
```cpp
const int i = 10;
int* j = const_cast<int*>(&i);  // remove const-ness
*j = 11;  // now i is changed to 11
```

## Reinterpret Cast

`reinterpret_cast` converts any pointer type to any other pointer type. It also converts between pointers to functions and pointers to objects. **Unlike `static_cast`, it does not check if the conversion is valid.**

Example:
```cpp
int i = 10;
int* p = &i;
char* ch = reinterpret_cast<char*>(p);
```

## Concepts: Upcasting and Downcasting

Upcasting is converting a derived-class pointer or reference to the base class. It is always safe in C++, and implicit conversion is allowed.

Example:
```cpp
class Base {};
class Derived : public Base {};

Derived derived;
Base* basePtr = &derived;  // upcasting
```

Downcasting is converting a base-class pointer or reference to the derived class. This is generally not safe, because **the base class object might not be a full instance of the derived class.**

Example:
```cpp
Base* base = new Base;
Derived* derived = static_cast<Derived*>(base);  // unsafe downcasting
```
**For safe downcasting, `dynamic_cast` is used. If the downcast is not possible, `dynamic_cast` will return `nullptr`.**

Example:
```cpp
Base* base = new Derived;
Derived* derived = dynamic_cast<Derived*>(base);  // safe downcasting
if (derived != nullptr) {
    // base was pointing to a Derived object
}
```

Remember, casting should be used judiciously as it can potentially bypass the type system leading to hard-to-detect bugs. Always prefer safe casting methods (`static_cast`, `dynamic_cast`) over the unsafe ones (`reinterpret_cast`).

## Distinguish between static_cast and dynamic_cast

Choosing between `static_cast` and `dynamic_cast` depends on your specific needs:

1. **Use `static_cast` when:**

   - You're converting between numeric types (for example, float to int).
   - You're converting from a pointer (or reference) to a base class to a pointer (or reference) to a derived class (downcasting), and you're certain that the base class object is indeed a derived class object. In such cases, `static_cast` is faster than `dynamic_cast` **because it doesn't do any runtime type checking**.

2. **Use `dynamic_cast` when:**

   - You're converting from a pointer (or reference) to a base class to a pointer (or reference) to a derived class (downcasting), but you're not sure whether the base class object is a derived class object. `dynamic_cast` performs a runtime check to ensure the object is of the correct type, and returns `nullptr` (for pointers) or throws a `bad_cast` exception (for references) if the cast is not possible. This makes `dynamic_cast` safer than `static_cast` for downcasting.

It's important to note that `dynamic_cast` requires the type to have at least one virtual function, otherwise the compiler cannot perform the necessary runtime type identification (RTTI).

In general, avoid casting where possible. Good object-oriented design often eliminates the need for casting. If you find yourself frequently needing to perform downcasts, it might be a sign that your design could be improved. For example, you might be able to move the behavior you're accessing into the base class, either as a virtual function or as an implementation that's the same for all derived classes.