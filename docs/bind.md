# std::bind

`std::bind` is a standard library function in C++ that allows you to easily bind arguments to a function. The result is a function object (a functor) which can be invoked later.

Here's the basic usage of `std::bind`:

```cpp
auto bound_function = std::bind(&function_name, _1, _2, ..., _n);
```

In this line, `function_name` is the function you want to bind, and `_1`, `_2`, etc., are placeholders for the arguments of the function you want to bind.

You can also bind specific values:

```cpp
auto bound_function = std::bind(&function_name, arg1, arg2, ..., argn);
```

In this line, `arg1`, `arg2`, etc., are actual values you want to bind to the arguments of the function.

Here's an example:

```cpp
void print_sum(int a, int b, int c) {
    std::cout << a + b + c << "\n";
}

auto bound_print_sum = std::bind(print_sum, 1, 2, 3);
bound_print_sum();  // Prints "6"
```

In this example, `std::bind` creates a new function object that calls `print_sum` with the arguments `1`, `2`, and `3`.

`std::bind` also works with function objects, member functions, and functions with placeholders.

```cpp
using namespace std::placeholders;  // for _1, _2, _3...

auto bound_print_sum = std::bind(print_sum, _1, _2, 3);
bound_print_sum(1, 2);  // Prints "6"
```

In this example, `_1` and `_2` are placeholders that get filled in when you call `bound_print_sum`.

**Please note that since C++11, many C++ programmers prefer to use lambda functions instead of `std::bind` because lambdas are often easier to read and understand.** However, `std::bind` still has its uses, particularly when working with older codebases or libraries.