# `nth_element`

`std::nth_element` is a function provided by the C++ Standard Library, included in the `<algorithm>` header, that rearranges elements in a range so that the element at the nth position is the element that would be in that position if the entire range were sorted. Additionally, it partitions the range into two groups: those less than the nth element and those greater than or equal to the nth element. **The order of the elements within these two groups is unspecified, making `std::nth_element` particularly useful for quickly finding the median, quartiles, or other order statistics without fully sorting the data.**

### Syntax

```cpp
template< class RandomIt >
void nth_element( RandomIt first, RandomIt nth, RandomIt last );

template< class RandomIt, class Compare >
void nth_element( RandomIt first, RandomIt nth, RandomIt last, Compare comp );
```

- **first**: The beginning of the range of elements to rearrange.
- **nth**: The position in the range which should contain the element that would be in that position in a sorted sequence.
- **last**: The end of the range of elements to rearrange.
- **comp**: A binary predicate that takes two elements as arguments and returns `true` if the first argument should come before the second in the sorted sequence and `false` otherwise. This parameter is optional.

### Behavior

`std::nth_element` partially sorts the range `[first, last)` such that:
- The element at the `nth` position is the one that would be in that position if the entire range were sorted.
- All elements before this `nth` element are less than or equal to the elements after it.
- The elements before and after the `nth` element are in unspecified order.

This function is particularly efficient for partitioning the data when only a specific element's position is required, as it performs better than a full sort when a complete order is unnecessary.

### Example

Here's an example demonstrating how to use `std::nth_element`:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {9, 1, 5, 3, 4, 8, 7, 2, 6};

    // Find the element that would be in the 4th position if the vector were sorted
    std::nth_element(v.begin(), v.begin() + 3, v.end());

    std::cout << "The fourth smallest element is " << v[3] << '\n';
    std::cout << "Elements less than the fourth smallest: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << "\nRemaining elements: ";
    for (size_t i = 4; i < v.size(); ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
```

### Output

```
The fourth smallest element is 4
Elements less than the fourth smallest: 1 2 3 
Remaining elements: 5 8 7 9 6 
```

The output demonstrates how `std::nth_element` reorganizes the elements so that the fourth **smallest element is placed in its correct sorted position, with all smaller elements moved before it and all larger elements placed after it**. The order of elements within those two partitions is unspecified. This function is a powerful tool for efficiently solving selection problems in C++.