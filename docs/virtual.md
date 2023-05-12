# Virtual

In C++, the `virtual` keyword is used to allow a member function of the base class to be overridden in a derived class. It's a key part of implementing "polymorphism", one of the primary principles of Object-Oriented Programming (OOP).

**1. Basic usage of `virtual`:**

Here's a basic example of using `virtual`:

```cpp
class Base {
public:
    virtual void print() {
        std::cout << "This is Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override {  // Note: The `override` keyword is optional but recommended
        std::cout << "This is Derived class" << std::endl;
    }
};
```

In this code, if we call `print()` on a `Base` object, it will print "This is Base class". If we call `print()` on a `Derived` object, it will print "This is Derived class".

```cpp
Base b;
b.print();  // Prints "This is Base class"

Derived d;
d.print();  // Prints "This is Derived class"
```

But more importantly, if we call `print()` through a base class pointer or reference that's actually pointing to a derived class object, it will call the derived class's version of the function, because `print()` was declared `virtual` in the base class:

```cpp
Base* ptr = &d;
ptr->print();  // Prints "This is Derived class"
```

**2. Virtual destructor:**

If you're creating a class hierarchy with base and derived classes, and you intend to manage objects of these classes through base class pointers, it's important to make the base class destructor `virtual`. This ensures that the correct destructors are called when an object is deleted.

```cpp
class Base {
public:
    virtual ~Base() {
        std::cout << "Destructor of Base" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        std::cout << "Destructor of Derived" << std::endl;
    }
};

Base* ptr = new Derived();
delete ptr;  // Prints "Destructor of Derived" and then "Destructor of Base"
```

**3. Virtual Table (vtable):**

The mechanism that C++ uses to support dynamic dispatch (i.e., deciding at runtime which function to call, based on the type of the object) is the "Virtual Table", or "vtable". This is an automatically created table of pointers to virtual functions.

Each class with virtual functions (or which is derived from a class with virtual functions) gets its own vtable. When a virtual function is called, the call is resolved using the vtable to find the correct function for the actual type of the object.

This is all handled by the C++ runtime system, so you don't normally need to worry about the details of how the vtable works. However, it's useful to know about it when thinking about how virtual functions and dynamic dispatch work.

Please note that while the concept of the vtable is common to almost all C++ implementations, the exact details of how it's implemented can vary between different compilers and platforms.

**A more comprehensive explanation: https://zhuanlan.zhihu.com/p/75172640**