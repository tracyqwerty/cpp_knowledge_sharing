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