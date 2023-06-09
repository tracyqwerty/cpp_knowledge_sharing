# `std::all_of`

`std::all_of` is a function template in the C++ Standard Library that checks if a predicate is true for all of the elements in a range. It's part of the `<algorithm>` header.

Here's an example of how to use `std::all_of`:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    if (std::all_of(numbers.begin(), numbers.end(), [](const int& num)(return num > 0;))) {
        std::cout << "All numbers are positive." << std::endl;
    } else {
        std::cout << "Not all numbers are positive." << std::endl;
    }

    return 0;
}
```

In this example, the lambda function `[](int num){ return num > 0; }` is used as the predicate for `std::all_of`. This lambda function takes an integer as input and returns `true` if the integer is greater than 0 and `false` otherwise.

The `std::all_of` function returns `true` if the predicate returns `true` for all elements in the range, and `false` otherwise. If the range is empty, `std::all_of` returns `true`.