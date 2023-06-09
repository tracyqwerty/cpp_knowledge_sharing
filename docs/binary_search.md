# `binary_search`

`std::binary_search` is a function provided by the C++ Standard Library in the `<algorithm>` header. It is used to check if an element exists in a sorted sequence. The function uses the binary search algorithm for this purpose.

Here is the syntax of `std::binary_search`:

```cpp
bool std::binary_search(ForwardIt first, ForwardIt last, const T& value);
```

- `first`, `last`: Random-access iterators defining the range to examine. The range includes all the elements between `first` and `last`, including the element pointed by `first` but not the one pointed by `last`.
- `value`: Value to search for in the range.

The function returns `true` if an element equivalent to `value` is found, and `false` otherwise.

Here is an example of how to use `std::binary_search`:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 4, 4, 5, 6};
    std::sort(v.begin(), v.end());

    bool found = std::binary_search(v.begin(), v.end(), 4);

    if (found) {
        std::cout << "Number 4 is found in the vector.\n";
    } else {
        std::cout << "Number 4 is not found in the vector.\n";
    }

    return 0;
}
```

In this example, `std::binary_search` is used to check if the number 4 is present in the vector `v`. The vector is sorted before the search because `std::binary_search` requires the range `[first, last)` to be sorted in non-descending order.

Please note that `std::binary_search` only tells you whether an element exists in the container, it **does not return the position of the element**. If you need the position of the element, consider using `std::lower_bound`, `std::upper_bound` or `std::equal_range`.