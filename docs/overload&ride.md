# Overload & Override 

## **Overloading**

Function overloading in C++ occurs when two or more functions in the same scope have the same name but different parameters. Overloading can be done by change in the number of arguments or/and change in the type of arguments. Return type of the functions do not play any role in function overloading, which means, functions can't be overloaded if they differ only in their return type. Here's an example:

```cpp
void print(int i) {
  std::cout << " Here is int " << i << std::endl;
}
void print(double  f) {
  std::cout << " Here is float " << f << std::endl;
}
void print(char const *c) {
  std::cout << " Here is char* " << c << std::endl;
}
```

## **Overriding**

Overriding is a feature that occurs in the context of inheritance, when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden. The function in the base class is called overridden function and the function in the derived class is called overriding function. Here's an example:

```cpp
class Base {
public:
   virtual void print() {
      std::cout << "This is base class's print function" << std::endl;
   }
};

class Derived : public Base {
public:
   void print() override {  // override keyword is optional but good for code clarity
      std::cout << "This is derived class's print function" << std::endl;
   }
};
```

## Comparison between Overload & Override 

Here are the key differences:

**Function Overloading:**

- **Function overloading is a compile-time polymorphism.**
- In overloading, functions must have the same name but either the number of arguments or the type of arguments must be different.
- Return types can be different.
- It's within the same class or namespace.
- Overloaded functions must have different function signatures (i.e., the number and type of parameters).

**Function Overriding:**

- **Function overriding is a run-time polymorphism.**
- Functions with the **same name, same parameters, and same return type** are considered overriding. The base class method is overridden by the derived class method.
- It's across two classes (parent class and child class relationship).
- Overridden functions must have the same function signature (i.e., the same number and type of parameters).
- The functions are invoked based on the type of the object.
- **Return types must be the same or covariant (a derived type). Example:**

```cpp
class Base {
public:
    virtual Base* clone() { 
        return new Base(*this); 
    }
};

class Derived : public Base {
public:
    Derived* clone() override {  // Here the return type is Derived*, not Base*.
        return new Derived(*this);
    }
};
```

In this example, `Base::clone` returns a `Base*`, but `Derived::clone` returns a `Derived*`. Since `Derived` is a subclass of `Base`, this is allowed in C++. The `Derived::clone` method is still considered to override `Base::clone`.

## What will happen without using override

**If you don't override a function in a derived class, then the derived class will inherit the base class's function.** This means that if you have an object of the derived class and you call the function, the base class's version of the function will be executed.

Here's an example:

```cpp
class Base {
public:
    void display() {
        std::cout << "Display Base" << std::endl;
    }
};

class Derived : public Base {
    // No display function here, so Base's display is used
};

int main() {
    Derived d;
    d.display();  // prints "Display Base"
    return 0;
}
```

In this example, because `Derived` does not provide its own `display` function, the `display` function from `Base` is used.

But note that if a function in the base class is declared as `virtual`, and you call this function on an object through a pointer or a reference to the base class, then the most derived version of the function will be called, even if there's no override in the intermediate class in the hierarchy.

```cpp
class Base {
public:
    virtual void display() {
        std::cout << "Display Base" << std::endl;
    }
};

class Intermediate : public Base {
    // No display function here
};

class Derived : public Intermediate {
public:
    void display() override {
        std::cout << "Display Derived" << std::endl;
    }
};

int main() {
    std::unique_ptr<Base> ptr = std::make_unique<Derived>();
    ptr->display();  // prints "Display Derived"
    return 0;
}
```

In this example, even though `Intermediate` does not override `display`, `Derived` does, so `ptr->display()` calls `Derived::display()`.

This example shows that the keyword `override` is not necessary for the function in the derived class to actually override the base class's function. The `override` keyword is a feature introduced in C++11 to provide better compile-time checking and avoid mistakes.

**If you declare a function in a derived class with the same name and the same parameter list as a `virtual` function in the base class, it will override the base function, whether you use the `override` keyword or not.**

The `override` keyword is useful because it tells the compiler to check that this function is indeed overriding a virtual function in the base class. If it's not (for example, because you made a typo in the function name, or the parameter list doesn't match), the compiler will give an error. This helps prevent bugs.

So, **even if there is no `override` in the intermediate class, as long as the function is declared as `virtual` in the base class, the most derived version of the function will be called**. This is because **the function call is resolved dynamically (at runtime) rather than statically (at compile time), which is the essence of polymorphism in object-oriented programming.**
