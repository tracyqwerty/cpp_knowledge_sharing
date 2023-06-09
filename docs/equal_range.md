# `std::equal_range`

`std::equal_range` is a function provided by the C++ Standard Library in the `<algorithm>` header. It is used to find the range of elements that are equivalent to a given value in a sorted sequence. The function returns a pair of iterators defining the range where the elements are equivalent to the given value.

Here is the syntax of `std::equal_range`:

```cpp
std::pair<ForwardIt, ForwardIt> std::equal_range(ForwardIt first, ForwardIt last, const T& value);
```

- `first`, `last`: Random-access iterators defining the range to examine. The range includes all the elements between `first` and `last`, including the element pointed by `first` but not the one pointed by `last`.
- `value`: Value to search for in the range.

The function returns a pair of iterators defining the range where the elements are equivalent to `value`. The first iterator points to the first element that is not less than `value`, and the second iterator points to the first element that is greater than `value`.

Here is an example of how to use `std::equal_range`:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 4, 4, 5, 6};
    std::sort(v.begin(), v.end());

    auto range = std::equal_range(v.begin(), v.end(), 4);

    std::cout << "The range of number 4 is from index " << (range.first - v.begin())
              << " to index " << (range.second - v.begin()) << ".\n";

    return 0;
}
```

In this example, `std::equal_range` is used to find the range of the number 4 in the vector `v`. The vector is sorted before the search because `std::equal_range` requires the range `[first, last)` to be sorted in non-descending order.

Please note that if no elements equivalent to `value` are found, the range returned by `std::equal_range` is empty, and both iterators point to the position where `value` should be inserted to maintain the sorted order.

Also, you can use structured bindings (introduced in C++17) to unpack the pair returned by `std::equal_range`. Here's how you can do it:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 4, 4, 5, 6};
    std::sort(v.begin(), v.end());

    auto [left, right] = std::equal_range(v.begin(), v.end(), 4);

    std::cout << "The range of number 4 is from index " << (left - v.begin())
              << " to index " << (right - v.begin()) << ".\n";

    return 0;
}
```

In this code, `left` and `right` are automatically deduced to be of type `std::vector<int>::iterator`, and they are assigned the values of the first and second elements of the pair returned by `std::equal_range`, respectively. This makes the code more concise and easier to read.