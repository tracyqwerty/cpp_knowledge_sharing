# `partial_sort`

`std::partial_sort` is a function provided by the C++ Standard Library `<algorithm>` header that rearranges elements in a range such that a subset of them appears in sorted order. Specifically, it sorts the first `N` elements into their final positions in the sorted sequence, leaving the remaining elements in an unspecified but valid state. This function is particularly useful when you only need the first `N` smallest elements sorted, and the order of the remaining elements is not important.

### Syntax

```cpp
template< class RandomIt >
void partial_sort( RandomIt first, RandomIt middle, RandomIt last );

template< class RandomIt, class Compare >
void partial_sort( RandomIt first, RandomIt middle, RandomIt last, Compare comp );
```

- **first**: The beginning of the range of elements to sort.
- **middle**: The point in the range up to which the elements should be sorted. The range `[first, middle)` will contain the sorted elements.
- **last**: The end of the range of elements to sort.
- **comp**: A binary predicate that takes two elements as arguments and returns `true` if the first argument should come before the second in the sorted sequence and `false` otherwise. This parameter is optional.

### Behavior

`std::partial_sort` sorts the elements in the range `[first, middle)` such that any element in this range is less than or equal to any element in the range `[middle, last)`, according to the specified comparison function `comp` (or `<` if no comparison function is provided). After the function completes, the elements in `[first, middle)` are sorted in ascending order, while the order of the elements in `[middle, last)` is unspecified.

### Example

Here's an example demonstrating how to use `std::partial_sort` to sort the first three elements in a vector of integers:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {9, 1, 5, 3, 4, 8, 7, 2, 6};

    // Sort the first three elements
    std::partial_sort(v.begin(), v.begin() + 3, v.end());

    // Print the partially sorted vector
    std::cout << "The first three elements are sorted: ";
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
}
```

### Output

```
The first three elements are sorted: 1 2 3 9 4 8 7 5 6 
```

In this example, the first three elements of the vector `v` are sorted in ascending order, while the order of the remaining elements is unspecified but valid so that the first three elements are less than or equal to all other elements in the vector. This demonstrates how `std::partial_sort` can be used to efficiently sort a subset of a range when only part of the sequence needs to be sorted.