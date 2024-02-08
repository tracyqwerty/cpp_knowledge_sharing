# `std::copy`

`std::copy` is a function template from the C++ Standard Library that copies elements from one range to another. It is part of the `<algorithm>` header and is used for copying elements between containers or within the same container. `std::copy` works with iterators to specify the source range and the beginning of the destination range.

### Syntax

```cpp
template< class InputIt, class OutputIt >
OutputIt copy(InputIt first, InputIt last, OutputIt d_first);
```

- **InputIt first, last**: Iterators specifying the beginning and end of the source range. The range includes `first` and excludes `last`.
- **OutputIt d_first**: An iterator to the beginning of the destination range.

### Return Value

`std::copy` returns an iterator to the element past the last element copied in the destination range.

### Example Usage

Here's a basic example that demonstrates how to use `std::copy` to copy elements from one vector to another:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> destination(source.size()); // Ensure destination has enough space

    std::copy(source.begin(), source.end(), destination.begin());

    for(int n : destination) {
        std::cout << n << ' ';
    }
    // Output: 1 2 3 4 5
}
```

### Notes

- The destination range must have enough space to hold all copied elements. If it does not, the behavior is undefined. For dynamically-sized containers like `std::vector`, you can resize the destination container, use `std::back_inserter` to automatically append elements, or ensure it's pre-sized correctly.
- `std::copy` performs element-wise copying and does not allocate storage. The responsibility for managing the size and capacity of the destination container lies with the programmer.
- For types with non-trivial copy constructors, `std::copy` can be less efficient than methods provided by the container itself (like the assignment operator or the `assign` method for `std::vector`). However, it is a versatile tool that works across different container types and for raw arrays.
- When copying between overlapping ranges, `std::copy` behavior is undefined. For such cases, `std::copy_backward` should be used.

`std::copy` is a fundamental algorithm in C++ for straightforward, type-safe copying of elements, providing a basis for a variety of data manipulation tasks.