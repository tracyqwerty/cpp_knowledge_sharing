# `std::min, std::max, std::minmax`

In C++, `std::min`, `std::max`, and `std::minmax` are utility functions provided by the `<algorithm>` header. They are used to compare two or more values or elements to find the minimum, maximum, or both minimum and maximum values, respectively. These functions can greatly simplify the process of determining extreme values from a set of arguments or elements in a container.

### `std::min`
`std::min` returns the smaller of its arguments. It can be used in two main forms:
- Comparing two values with an optional comparison function.
- Finding the minimum element in an initializer list.

**Examples**

```cpp
#include <algorithm>
#include <iostream>

int main() {
    int a = 5, b = 10;
    std::cout << "Min of " << a << " and " << b << " is " << std::min(a, b) << std::endl;

    // With a custom comparison function
    std::cout << "Min (custom comparison) of " << a << " and " << b << " is " << std::min(a, b, [](int x, int y) { return x > y; }) << std::endl;
}
```

### `std::max`
`std::max` returns the larger of its arguments, similar to `std::min` but for finding the maximum value. It also supports comparing two values directly or using a custom comparison function, as well as operating on an initializer list.

**Examples**

```cpp
#include <algorithm>
#include <iostream>

int main() {
    int a = 5, b = 10;
    std::cout << "Max of " << a << " and " << b << " is " << std::max(a, b) << std::endl;

    // With a custom comparison function
    std::cout << "Max (custom comparison) of " << a << " and " << b << " is " << std::max(a, b, [](int x, int y) { return x < y; }) << std::endl;
}
```

### `std::minmax`
`std::minmax` is used to find both the minimum and maximum values among its arguments. It returns a pair, with the first element being the minimum and the second the maximum. Like `std::min` and `std::max`, it can work with two arguments or an initializer list and supports custom comparison functions.

**Example**

```cpp
#include <algorithm>
#include <iostream>

int main() {
    int a = 5, b = 10;
    auto result = std::minmax(a, b);
    std::cout << "Minmax of " << a << " and " << b << ": min = " << result.first << ", max = " << result.second << std::endl;

    // With a custom comparison function
    auto customResult = std::minmax({a, b, -1, 15, 7}, [](int x, int y) { return x < y; });
    std::cout << "Minmax (custom comparison): min = " << customResult.first << ", max = " << customResult.second << std::endl;
}
```

These functions are versatile and can be used with not just integers but any type that has the `<` operator defined or for which a custom comparison function is provided. This makes them incredibly useful for generic programming, where the specific types of values being compared may not be known in advance.