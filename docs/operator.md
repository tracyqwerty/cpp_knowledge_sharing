# `operator`

The keyword `operator` in C++ is used in the context of **operator overloading**. Operator overloading allows C++ operators to have user-defined meanings on user-defined types (classes and enumerations).

Here's a brief explanation:

1. **Operator Functions**: These are regular functions, but their names are reserved keywords. They are used to define the operations of operators on class objects. They can be member functions if they modify the state of the object, and they should be non-member (friend) functions if they do not modify the object but need access to its private or protected members.

2. **Syntax**: `return_type className::operator op(argument_list)`

Here is an example where we overload the `+` operator for a class `AddComplex`:

```cpp
class AddComplex {
public:
    int a, b;
    AddComplex(int a = 0, int b = 0) : a(a), b(b) {}

    AddComplex operator + (const AddComplex &obj) {
        AddComplex res;
        res.a = this->a + obj.a;
        res.b = this->b + obj.b;
        return res;
    }
};

int main() {
    AddComplex obj1(3, 7), obj2(1, 2);
    AddComplex res = obj1 + obj2;
    cout << res.a << " + " << res.b << "i" << endl;
    return 0;
}
```

In this case, we have a class `AddComplex` to represent complex numbers. We define a `+` operator function that adds two complex numbers and returns a new complex number. Now, we can use the `+` operator to add two complex numbers in a natural way, just like we add integers or other basic types.

Apart from binary operators like `+`, `-`, `*`, `/`, you can also overload unary operators like `++`, `--`, etc., and other operators like comparison operators (`==`, `!=`, `<`, `>`, `<=`, `>=`), assignment operators, etc.

Just be aware that some operators cannot be overloaded: `::`, `.`, `.*`, `?:`, and `sizeof`.

Also, while operator overloading can make your code more intuitive and easier to read, it can also lead to confusion if not used carefully, since it allows you to give operators entirely new meanings when applied to objects of a certain class.

#  `operator new`

In C++, **`operator new` is a function that is automatically called when you use the `new` keyword to dynamically allocate memory**. By default, `operator new` allocates memory from the heap and returns a pointer to the start of it. This is the standard behavior of `new`:

```cpp
int* p = new int; // allocate an int on the heap
```

Under the hood, this is calling `operator new` to perform the allocation:

```cpp
void* operator new(std::size_t size);
```

also `operator delete`:

```cpp
void operator delete(void* ptr)
```

This function takes as an argument the size of the memory to allocate (in bytes), and returns a pointer to the allocated memory. If the allocation fails, it throws a `std::bad_alloc` exception.

You can override `operator new` in your own classes if you want to provide a custom behavior for memory allocation. For example, you might want to use a custom memory pool, or add some logging or debug checks. Here's an example:

```cpp
class MyClass {
public:
    // Overload operator new for MyClass
    static void* operator new(std::size_t size) {
        std::cout << "Custom operator new for MyClass\n";
        void* p = std::malloc(size);
        if (!p) throw std::bad_alloc();
        return p;
    }

    // Don't forget to also overload operator delete
    static void operator delete(void* p) {
        std::cout << "Custom operator delete for MyClass\n";
        std::free(p);
    }
};
```

In this example, we override `operator new` and `operator delete` to add some logging and to use `std::malloc` and `std::free` directly for memory management. Now, when you create and delete objects of type `MyClass` with `new` and `delete`, it will call these custom functions:

```cpp
MyClass* p = new MyClass; // prints "Custom operator new for MyClass"
delete p;                 // prints "Custom operator delete for MyClass"
```

This gives you a lot of control over memory management in your programs. However, you should be careful when doing this, because it can make your code harder to understand and maintain, and it can be difficult to get right. In general, you should only override `operator new` and `operator delete` when you have a specific reason to do so.
