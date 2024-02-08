# `std::transform`

`std::transform` is a versatile algorithm in the C++ Standard Library that applies a given function to a range of elements and stores the result in a destination range. It is part of the `<algorithm>` header. `std::transform` can be used for a wide range of operations, such as modifying elements in-place, converting elements from one type to another, or applying a specific operation to elements of a container. There are two main versions of `std::transform`.

### Version 1: Unary Operation
Applies a unary operation to each element in the source range and stores the result in the destination range.

```cpp
template< class InputIt, class OutputIt, class UnaryOperation >
OutputIt transform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op);
```

- **InputIt first1, last1**: Iterators to the beginning and end of the source range.
- **OutputIt d_first**: An iterator to the beginning of the destination range.
- **UnaryOperation unary_op**: The unary operation to apply to each element.

### Version 2: Binary Operation
Applies a binary operation to pairs of elements from two source ranges and stores the result in the destination range.

```cpp
template< class InputIt1, class InputIt2, class OutputIt, class BinaryOperation >
OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryOperation binary_op);
```

- **InputIt1 first1, last1**: Iterators to the beginning and end of the first source range.
- **InputIt2 first2**: An iterator to the beginning of the second source range.
- **OutputIt d_first**: An iterator to the beginning of the destination range.
- **BinaryOperation binary_op**: The binary operation to apply to each pair of elements.

### Example: Unary Operation
Here's a simple example that squares each number in a vector:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> squared(nums.size());

    std::transform(nums.begin(), nums.end(), squared.begin(), [](int n) { return n * n; });

    for(int n : squared) {
        std::cout << n << ' ';
    }
    // Output: 1 4 9 16
}
```

### Example: Binary Operation
This example adds elements from two vectors and stores the result in a third vector:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {4, 5, 6};
    std::vector<int> result(a.size());

    std::transform(a.begin(), a.end(), b.begin(), result.begin(), std::plus<int>());

    for(int n : result) {
        std::cout << n << ' ';
    }
    // Output: 5 7 9
}
```

`std::transform` is a powerful tool for performing element-wise operations on containers, enabling both simple and complex transformations with minimal code.