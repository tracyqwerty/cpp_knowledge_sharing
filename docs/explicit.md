# explicit

The `explicit` keyword in C++ is used to prevent implicit conversions or copy-initializations. It is mainly used with a class's constructor.

Let's take a simple example to illustrate this:

```cpp
class MyClass {
public:
    MyClass(int x) {
        // Constructor
    }
};

int main() {
    MyClass obj = 10;  // Implicit conversion from int to MyClass
    return 0;
}
```

In the code above, `MyClass obj = 10;` is allowed, which means the integer `10` is implicitly converted to `MyClass` using the `MyClass(int x)` constructor. This is known as an implicit conversion or copy-initialization.

Now, if we add the `explicit` keyword to the constructor:

```cpp
class MyClass {
public:
    explicit MyClass(int x) {
        // Constructor
    }
};

int main() {
    MyClass obj = 10;  // Error! implicit conversion not allowed
    MyClass obj2(10);  // This is fine
    return 0;
}
```

In this case, `MyClass obj = 10;` is not allowed because we added the `explicit` keyword to the constructor. This prevents the compiler from using this constructor for implicit conversions. The correct way to create an object would be `MyClass obj2(10);`.

The `explicit` keyword is a way to enforce code clarity and avoid unexpected results due to implicit conversions. It's generally a good idea to declare single-argument constructors as `explicit` (unless you specifically want to allow implicit conversions). 

Starting from C++11, the `explicit` keyword can also be used with conversion operators to prevent implicit conversions in that context.