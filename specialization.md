当然可以。以下是一个使用这两个函数的示例：

```cpp
#include <iostream>

template <class T1, class T2>
void f(T1, T2) {
    std::cout << "Generic version" << std::endl;
}

template <class T2>
void f(int, T2) {
    std::cout << "Overload for T1 = int" << std::endl;
}

//错误的：函数模版不支持偏特化
//template <class T2>
//void f<int, T2>(){}

int main() {
    int a = 42;
    double b = 3.14;

    f(a, b); // 调用 f<int, double>(int, double)，输出 "Overload for T1 = int"

    std::string c = "hello";
    f(c, b); // 调用 f<std::string, double>(std::string, double)，输出 "Generic version"

    return 0;
}
```

在这个示例中，我们定义了两个重载版本的 `f` 函数。当 `T1` 类型为 `int` 时，将调用针对 `T1 = int` 类型的重载版本。其他情况将调用通用版本的 `f` 函数。在 `main` 函数中，我们展示了如何根据不同的参数类型调用这两个重载版本。