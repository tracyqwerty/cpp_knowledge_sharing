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









Lambda函数是C++11中引入的一个新特性，它提供了一种方便的方式来定义匿名函数。Lambda函数的结构如下：

```cpp
[capture_list](parameters) -> return_type { function_body }
```

让我们详细解释一下这个结构：

1. **捕获列表（Capture List）**：捕获列表定义了在Lambda函数体内部可以访问的外部变量，并且规定了访问方式（以值传递或者引用传递）。捕获列表可以为空，这样就意味着Lambda函数体内部不能访问任何外部变量。

2. **参数列表（Parameter List）**：参数列表就像普通函数的参数列表，定义了Lambda函数的参数。如果Lambda函数不需要参数，那么这个列表可以为空。

3. **返回类型（Return Type）**：返回类型是可选的。如果Lambda函数体中包含返回语句，那么编译器可以自动推导出返回类型。如果Lambda函数体包含多个返回语句，那么这些返回语句必须返回相同类型的值。

4. **函数体（Function Body）**：函数体包含了Lambda函数的代码。

以下是一些Lambda函数的例子：

```cpp
// 无捕获，无参数，无返回值
auto f1 = []() { std::cout << "Hello, world!\n"; };

// 以值捕获，无参数，无返回值
int val = 0;
auto f2 = [val]() { std::cout << "Value: " << val << "\n"; };

// 以引用捕获，无参数，无返回值
auto f3 = [&val]() { val += 1; };

// 无捕获，有参数，无返回值
auto f4 = [](const std::string& msg) { std::cout << msg << "\n"; };

// 无捕获，有参数，有返回值
auto f5 = [](int a, int b) -> int { return a + b; };
```

在C++14以后，如果Lambda函数的函数体只包含一条return语句，那么返回类型可以省略，编译器会自动推导出返回类型。例如，上面的f5可以写成：

```cpp
auto f5 = [](int a, int b) { return a + b; };
```

上述定义的 Lambda 函数存储在变量 `f1`、`f2`、`f3`、`f4` 和 `f5` 中，你可以像调用普通函数一样调用它们。以下是如何调用这些函数的例子：

```cpp
f1(); // 输出 "Hello, world!"

std::string message = "Hello, Lambda!";
f4(message); // 输出 "Hello, Lambda!"

int result = f5(3, 4);
std::cout << result << std::endl; // 输出 "7"
```

对于 `f2` 和 `f3`，它们捕获了外部变量 `val`。你可以在修改 `val` 的值后再次调用这些函数来看看效果：

```cpp
val = 5;
f2(); // 输出 "Value: 0"

f3(); // val 的值增加 1
f2(); // 仍然输出 "Value: 0"

std::cout << val << std::endl; // 输出 "6"
```

注意，在 `f2` 中，`val` 是以值捕获的，所以即使外部的 `val` 变量的值改变了，`f2` 也不会受到影响，它依然保有 `val` 的原始值。而在 `f3` 中，`val` 是以引用捕获的，所以 `f3` 会修改外部的 `val` 变量的值。