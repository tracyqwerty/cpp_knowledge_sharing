# Lambda Expressions

Lambda expressions, also known as lambda functions, are a feature in C++11 and onwards that allow you to write anonymous functions inline in your code. They can be used in places where you would normally use a function pointer or a function object.

## Syntax

Here is a basic syntax for lambda functions in C++:

```cpp
[capture](parameters) -> return_type { body }
```

Let's break down each part of this syntax:

- **Capture**: This defines what from the outside of the lambda should be available inside the function body and how. It can be empty `[]`, capture one or more variables by value `[x, &y]` or capture all local variables by value `[=]` or by reference `[&]`.
- **Parameters**: These are same as normal function parameters and are optional.
- **Return_type**: This is optional if your lambda is simple, the compiler can deduce the type on its own. But for more complex cases, you can specify the return type like `-> int`.
- **Body**: The actual content of the function.

Here's an example of a simple lambda function:

```cpp
int main() {
    auto f = []() { std::cout << "Hello, World!"; };
    f();  // prints "Hello, World!"
}
```

In this example, the lambda function takes no arguments and returns no value. The `auto` keyword is used to let the compiler deduce the type of the lambda function.

Lambdas can also take parameters and return a value:

```cpp
int main() {
    auto add = [](int a, int b) -> int { return a + b; };
    std::cout << add(1, 2);  // prints "3"
}
```

The capture list allows the lambda function to access variables from the surrounding scope:

```cpp
int main() {
    int x = 10;
    auto add_x = [x](int a) { return a + x; };
    std::cout << add_x(5);  // prints "15"
}
```

In this example, `x` is captured by value, which means that the lambda function gets a copy of `x` at the point where the lambda function is defined. 

**If we want to modify `x` inside the lambda, or if we want the lambda to always reflect the current value of `x`, we can capture `x` by reference instead:**

```cpp
int main() {
    int x = 10;
    auto add_to_x = [&x](int a) { x += a; };
    add_to_x(5);
    std::cout << x;  // prints "15"
}
```

In this example, `x` is captured by reference, so when `x` is modified inside the lambda function, the change affects the original variable `x`.



## Examples

1. **Sorting using lambda functions**:

    Lambdas can be used to define custom comparison functions for sorting.

    ```cpp
    std::vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    std::sort(v.begin(), v.end(), [](int a, int b) -> bool { return a > b; }); // descending order
    ```

2. **Using lambdas with standard algorithms**:

    `std::for_each` is a standard algorithm which applies a given function object to every item in a range. We can pass a lambda to this function.

    ```cpp
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::for_each(v.begin(), v.end(), [](int n) { std::cout << n << '\n'; });
    ```

3. **Capturing variables by value or reference**:

    ```cpp
    int x = 5;
    auto f1 = [x]() { std::cout << x << '\n'; }; // capture by value
    auto f2 = [&x]() { std::cout << x << '\n'; }; // capture by reference
    
    x = 10;
    f1(); // prints "5"
    f2(); // prints "10"
    ```

**Always remember that `[x]`will capture `x` by value, which means a copy of `x` is made when the lambda is defined. This copy is not affected by changes to the original `x`.**

So that when you define the lambda function `f1` and capture `x` by value, the current value of `x` (which is `5`) is copied into the lambda function. This means `f1` has its own separate copy of `x` that is not affected by changes to the `x` variable in the surrounding code.

## Lambda in C++14

1. **Generalized capture**: C++14 allows you to capture variables in the surrounding scope by moving them into the lambda using `std::move`. This is useful for capturing unique_ptrs or other move-only types.

    ```cpp
    auto p = std::make_unique<int>(1);
    auto lambda = [p = std::move(p)] { /* uses p */ };
    ```

2. **Auto return type**: In C++14, you don't have to specify the return type of the lambda even if you have multiple return statements.

    ```cpp
    auto lambda = [](int x, int y) {
        if(x > y)
            return x;
        else
            return y;
    };
    ```

3. **Generic lambdas**: C++14 supports lambdas with auto type parameters, effectively allowing templated lambdas.

    ```cpp
    auto identity = [](auto x) { return x; };
    int three = identity(3);  // OK: calls identity<int>
    std::string foo = identity(std::string("foo"));  // OK: calls identity<std::string>
    ```

**4. Lambdas with mutable keyword:**

Sometimes you may want to modify a value captured by value (not by reference). The `mutable` keyword allows you to do so.

```cpp
int x = 0;
auto f = [x]() mutable { x++; std::cout << x << '\n'; };
f();  // prints "1"
f();  // prints "2"
```

**Note that the `mutable` keyword only affects the copy of `x` inside the lambda. The original `x` remains unchanged.**

**5. Lambdas with standard functions like transform:**

`std::transform` is a standard library function that applies a given function to a range and stores the result in another range.

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
std::vector<int> v2(v.size());
std::transform(v.begin(), v.end(), v2.begin(), [](int n) { return n * n; });

// v2 now holds {1, 4, 9, 16, 25}
```

**6. Lambdas in place of function pointers:**

Lambda functions can also be used wherever function pointers are expected.

```cpp
void foo(void (*func)()) {
    func();
}

int main() {
    foo([]() { std::cout << "Hello from lambda!"; });
    return 0;
}
```

**7. Recursive lambdas:**

Lambda functions can even be recursive, although doing so requires a little bit of extra work because the lambda needs to capture itself.

```cpp
std::function<int(int)> factorial = [&factorial](int i) {
    return i == 0 ? 1 : i * factorial(i - 1);
};

std::cout << factorial(5);  // prints "120"
```

In this example, `std::function` is used to allow the lambda to capture itself by reference. The lambda calculates the factorial of a number recursively.

Lambda expressions are a powerful feature in C++, and they can make your code more concise and easier to understand, especially when used with standard library algorithms. However, like all powerful tools, they should be used judiciously. Overuse of lambdas can make code difficult to understand and debug.
