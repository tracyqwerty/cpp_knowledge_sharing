# Move semantics

Move semantics is a feature introduced in C++11, providing a way to transfer resources (like memory) from one object to another without making a copy. This can significantly improve performance when dealing with "heavy" objects, like large vectors or strings, or with user-defined types that manage their own memory.

To understand move semantics, it's helpful to first understand what rvalue references are, since they're the fundamental building block of move semantics.

## **1. Rvalue references:**

An rvalue reference is a type of reference that can bind to temporary objects (rvalues). You declare an rvalue reference with two ampersands (`&&`). For example:

```cpp
int&& rvalue_ref = 5;
```

## **2. Move constructor and move assignment operator:**

Move semantics are implemented through two special member functions: the move constructor and the move assignment operator. Here's a simple example:

```cpp
class MyClass {
    int* data;

public:
    // Move constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Move assignment operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};
```

In both the move constructor and the move assignment operator, we "steal" the resource (in this case, the `data` pointer) from the other object, and then make sure to leave the other object in a valid state (by setting its `data` pointer to `nullptr`).

## **3. std::move:**

**`std::move` is a standard library function that can be used to convert a value to an rvalue. It doesn't actually move anything, but it allows move semantics to be used, if possible.** Here's an example:

```cpp
MyClass obj1;
MyClass obj2(std::move(obj1));  // Calls move constructor
```

In this example, `std::move(obj1)` is an rvalue, so it binds to the move constructor, allowing the resources of `obj1` to be moved into `obj2`.

Remember that after `std::move` has been called on an object, the state of that object is valid but unspecified. That means you shouldn't use it again, unless you first reset its state (like by assigning a new value to it).

Another example:

```cpp
int a = 5;
int &ref_a_left = a;
int &&ref_a_right = std::move(a);
```

The `std::move(a)` doesn't move the value of `a` into `ref_a_right`. **It simply allows `a` to be treated as an rvalue, and thus bound to the rvalue reference `ref_a_right`. The original variable `a` still holds its value, 5.**  Here `std::move(a)`is  the same as `static_cast<int&&>(a)`.

Note that **move semantics generally come into play with operations that could benefit from resource transfer rather than resource copying**, like the copy constructor or copy assignment operator in classes that manage dynamic memory. **The performance gain is not from the use of `std::move` itself, but from the move operations that it enables.**

## **4. Use cases for move semantics:**

Move semantics are useful whenever you have a resource that's expensive to copy but can be easily transferred from one object to another. This includes:

- Dynamically-allocated memory, like in the `MyClass` example above.
- File handles or network connections.
- Large containers, like `std::vector` or `std::string`.

By using move semantics, you can avoid unnecessary copies and significantly improve performance in these situations.
