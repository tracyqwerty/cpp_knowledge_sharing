# `std::reverse`

The `std::reverse` function in C++ is used to reverse the order of elements in a range. Here's a simple example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
	  // returns void
    std::reverse(numbers.begin(), numbers.end());

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
```

In this example, the `std::reverse` function is called with two arguments: `numbers.begin()` and `numbers.end()`. These arguments represent the range of elements to reverse. In this case, the entire `numbers` vector is reversed.

After the call to `std::reverse`, the `numbers` vector contains the elements `{5, 4, 3, 2, 1}`. The order of the elements has been reversed.

The `std::reverse` function works with any type of bidirectional iterator, so you can use it with other types of containers as well, such as `std::list`, `std::deque`, and arrays.