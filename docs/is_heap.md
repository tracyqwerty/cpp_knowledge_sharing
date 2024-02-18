# `std::is_heap, std::is_heap_until`

The C++ Standard Library provides algorithms for working with heaps within the `<algorithm>` header. Among these, `is_heap` and `is_heap_until` are used to check properties of heaps within a range of elements. Heaps are a form of binary tree where each parent node is ordered with respect to its children according to a comparison criteria, typically used to implement priority queues.

### `is_heap`

The `is_heap` algorithm checks if a range of elements forms a heap according to a given comparison function. By default, it checks for a max heap (where each parent node is greater than or equal to its children), but you can pass a custom comparison function to check for a min heap or some other order.

- **Parameters**:
  - A beginning iterator and an ending iterator of the range to check.
  - Optionally, a comparison function that takes two elements and returns `true` if the first element should come before the second in the heap.

- **Return Value**: `is_heap` returns `true` if the range forms a heap according to the comparison criteria; otherwise, it returns `false`.

**Example**

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    if (std::is_heap(v.begin(), v.end())) {
        std::cout << "The vector is a heap.\n";
    } else {
        std::cout << "The vector is not a heap.\n";
    }
}
```

### `is_heap_until`

While `is_heap` checks if the entire range is a heap, `is_heap_until` finds the largest subrange beginning at the start of the range that forms a heap. This can be useful to determine how much of the range is organized as a heap.

- **Parameters**:
  - A beginning iterator and an ending iterator of the range to check.
  - Optionally, a comparison function.

- **Return Value**: An iterator to the first element in the range that is not within the heap. If the entire range forms a heap, this will be the ending iterator of the range.

**Example**

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1};

    auto until = std::is_heap_until(v.begin(), v.end());
    std::cout << "The vector is a heap until element: " 
              << std::distance(v.begin(), until) << std::endl;
}
```

Both `is_heap` and `is_heap_until` can be used with custom comparison functions to check for different types of heaps (e.g., min heaps). For example, to check for a min heap, you could pass `std::greater<>()` as the comparison function, which would reverse the default max heap criteria.

### Custom Condition: Min Heap with Odd Numbers Prioritized

Let's use a lambda expression as a custom comparison function with `std::is_heap` to check if a given range forms a specific ordering based on a custom condition. In this example, we'll check if a vector of integers forms a heap based on a custom condition defined by our lambda expression.

Let's say our custom condition for the heap is that odd numbers should come before even numbers, and within the odd and even groups, the numbers should be arranged as a min heap. This is a bit unconventional but serves well to demonstrate the flexibility of using a lambda with `std::is_heap`.

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // A vector that, according to our custom condition, should form a heap
    std::vector<int> heap = {1, 3, 2, 5, 7, 4, 6};

    // Check if the vector forms a heap based on our custom condition
    bool isCustomHeap = std::is_heap(heap.begin(), heap.end(), 
        [](int left, int right) {
            // Prioritize odd numbers over even numbers
            bool leftIsOdd = left % 2 != 0;
            bool rightIsOdd = right % 2 != 0;

            if (leftIsOdd != rightIsOdd) {
                return rightIsOdd; // If one is odd and the other is even, the odd one should come first
            } else {
                // If both are odd or both are even, compare their values (min heap)
                return left > right;
            }
        });

    std::cout << "The vector is ";
    if (!isCustomHeap) {
        std::cout << "not ";
    }
    std::cout << "a custom heap according to the lambda condition.\n";

    return 0;
}
```

**Explanation**

- The lambda expression used for comparison in `std::is_heap` does the following:
  - It first determines if each of the two compared integers (`left` and `right`) is odd.
  - If one number is odd and the other is even, the lambda prioritizes the odd number by returning `true` if the right number is odd (since in a max heap, which is the default perspective of `std::is_heap`, the "greater" element comes first, and our custom condition treats odd numbers as "greater").
  - If both numbers are either odd or even, it compares them based on their values to ensure that, within the odd and even groups, the numbers are arranged as a min heap (smaller numbers come first).
- This setup allows us to apply a complex, custom sorting condition for heap validation, demonstrating the versatility of lambda expressions in C++ algorithms.

