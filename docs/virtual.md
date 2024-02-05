# Virtual

In C++, the `virtual` keyword is used to allow a member function of the base class to be **overridden** in a derived class. It's a key part of implementing "polymorphism", one of the primary principles of Object-Oriented Programming (OOP).

## Basic Usage of `virtual`

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

## Virtual Destructor

If you're creating a class hierarchy with base and derived classes, and you intend to manage objects of these classes through base class pointers, **it's important to make the base class destructor `virtual`.** This ensures that the correct destructors are called when an object is deleted.

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

## Mechanism: Virtual Table (vtable)

The mechanism that C++ uses to support dynamic dispatch (i.e., deciding at runtime which function to call, based on the type of the object) is the "Virtual Table", or "vtable". This is an automatically created table of pointers to virtual functions.

Each class with virtual functions (or which is derived from a class with virtual functions) gets its own vtable. When a virtual function is called, the call is resolved using the vtable to find the correct function for the actual type of the object.

This is all handled by the **C++ runtime system**, so you don't normally need to worry about the details of how the vtable works. However, it's useful to know about it when thinking about how virtual functions and dynamic dispatch work.

Please note that while the concept of the vtable is common to almost all C++ implementations, the exact details of how it's implemented can vary between different compilers and platforms.

**A more comprehensive explanation: https://zhuanlan.zhihu.com/p/75172640**

## Pure Virtual Function

In C++, a pure virtual function (or pure virtual method) is a virtual function for which we don't have implementation, we only declare it. It is declared by assigning 0 in its declaration.

Here's how you would declare a pure virtual function:

```cpp
class AbstractClass {
public:
    virtual void pureVirtualFunction() = 0; // Pure virtual function
};
```

**A class that has at least one pure virtual function is considered an abstract base class.** Abstract base classes **cannot be instantiated directly**; instead, they must be derived from. When you derive from an abstract base class, you must provide an implementation for any pure virtual functions.

The primary purpose of a pure virtual function (and abstract base classes in general) is to **define an interface that derived classes must implement**. This provides a way to ensure that a group of related classes all implement certain functions.

Here's an example:

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        // Implementation for drawing a circle
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        // Implementation for drawing a rectangle
    }
};
```

In this example, `Shape` is an abstract base class that defines a common interface for shapes. Any class that derives from `Shape` must provide an implementation for the `draw` function. This ensures that we can use a pointer or reference to `Shape` to call `draw` on any kind of shape, and the correct function will be invoked based on the actual type of the shape.

## Can virtual function be private?

**C++ has access control, but not visibility control.** This means that private functions are visible but not accessible. A private virtual function can be overridden by derived classes, but can only be called from within the base class. This is actually a useful construct when you want that effect.

```cpp
#include <iostream>
class Shape {
public:
  int getValuePublic() { return getValuePrivate(); }

private:
  virtual int getValuePrivate() = 0;
};
class Circle : public Shape {
private:
  int getValuePrivate() override { return 1; }
};

signed main() {
  Circle c;
  Shape *ptr = &c;
  // ptr->getValuePublic() is 0
  std::cout << ptr->getValuePublic() << std::endl;
  return 0;
}
```

Moreover, when a function is declared as virtual in a base class, derived classes can override it, even if the access level of the virtual function in the base class is private. The overriding function in the derived class must have the same signature as the base class function.

## Reference

https://root.cern/TaligentDocs/TaligentOnline/DocumentRoot/1.0/Docs/books/WM/WM_132.html#:~:text=This%20means%20that%20private%20functions,when%20you%20want%20that%20effect.

