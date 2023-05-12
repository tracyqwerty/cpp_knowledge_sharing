# std::function

## Introduction

`std::function` is a general-purpose polymorphic function wrapper. The instances of `std::function` can **store, copy, and invoke any callable target** -- functions, lambda expressions, bind expressions, or other function objects, as well as pointers to member functions and pointers to data members.

Here's the basic syntax:

```cpp
std::function<return_type(arg_types)>
```

Here, `return_type` is the return type of the function and `arg_types` are the argument types.

## Examples

Let's look at a few examples of using `std::function`.

1. **Storing simple function:**

```cpp
void print_num(int num) {
    std::cout << num << '\n';
}

std::function<void(int)> func = print_num;
func(10);  // prints "10"
```

In this example, we define a simple function `print_num` that takes an integer and prints it. We then create a `std::function` that can hold a function taking an integer and returning nothing (`void`). We assign `print_num` to this `std::function` and then call it.

2. **Storing lambda function:**

```cpp
std::function<int(int, int)> add = [](int a, int b) {
    return a + b;
};

std::cout << add(2, 3) << '\n';  // prints "5"
```

Here, we define a `std::function` that can hold a function taking two integers and returning an integer. We assign a lambda function to this `std::function` and then call it.

3. **Storing the result of `std::bind`:**

```cpp
void print_num(int num) {
    std::cout << num << '\n';
}

auto bind_func = std::bind(print_num, 5);
std::function<void()> func = bind_func;
func();  // prints "5"
```

In this example, we use `std::bind` to bind an argument to the `print_num` function, and assign the result to a `std::function`.

4. **Storing callable objects:**

```cpp
struct Functor {
    void operator()(int num) {
        std::cout << num << '\n';
    }
};

std::function<void(int)> func = Functor();
func(10);  // prints "10"
```

Here, we define **a callable object (an object that can be called as if it were a function)** and assign it to a `std::function`.

`std::function` is really powerful and versatile because it can store anything callable. It also has some other useful features, like checking if it is empty (using the `bool` conversion operator), swapping the targets of two `std::function` instances (using the `swap` member function), and getting the target type at runtime (using the `target_type` and `target` member functions).