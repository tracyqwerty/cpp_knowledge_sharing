# `std::min_element`

 `std::min_element` and `std::max_element` are algorithms provided by the C++ Standard Library to find the smallest and largest element in a range, respectively.

`std::min_element`: This function returns an iterator pointing to the smallest element in the range `[first, last)`. If more than one element fulfills this condition, the iterator to the first one is returned. If the range is empty, the function returns `last`.

Here's an example of how to use `std::min_element`:

```cpp
std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
auto result = std::min_element(v.begin(), v.end());
std::cout << "The smallest element is " << *result << " at position " << std::distance(v.begin(), result);
```

Also, you can provide a custom comparison function or lambda if you want to change the way elements are compared.

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};

    // Find the minimum element in the vector, but treat even numbers as if they were larger
    auto min_element = *std::min_element(v.begin(), v.end(), [](int a, int b) {
        if (a % 2 == 0) a += 100;
        if (b % 2 == 0) b += 100;
        return a < b;
    });

    std::cout << "The minimum element (considering even numbers as larger) is: " << min_element << "\n";

    return 0;
}
```

In this example, the lambda function modifies the comparison operation so that even numbers are treated as if they were larger than they actually are. This means that the minimum element found will be an odd number, even if there are smaller even numbers in the vector.

However, if you're just comparing simple data types (like `int`, `double`, etc.) and you're using the standard less-than comparison, you don't need to provide a lambda function. You can just use `std::min(a, b)` or `std::min_element(begin, end)`.