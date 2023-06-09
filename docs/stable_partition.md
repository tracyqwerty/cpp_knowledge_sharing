# `std::stable_partition`

`std::stable_partition` is a function in the C++ Standard Library that rearranges elements in a range [first, last) in such a way that all elements for which a certain condition is true precede all those for which the condition is false. The relative order of the elements in each group is preserved, hence the term "stable".

Here's a simple example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Partition the vector into even and odd numbers
    std::stable_partition(v.begin(), v.end(), [](int i){return i % 2 == 0;});

    for(int i : v) {
        std::cout << i << " ";
    }

    return 0;
}
```

In this example, `std::stable_partition` partitions the vector into two groups: even numbers and odd numbers. The even numbers (for which the lambda function returns true) are moved to the front of the vector, and the odd numbers are moved to the back. **The relative order within each group is preserved**, so the even numbers are still in ascending order, and the odd numbers are still in ascending order.

The output of this program would be:

```
2 4 6 8 10 1 3 5 7 9
```

As you can see, all the even numbers come before the odd numbers, and the relative order within each group is preserved.

The time complexity of `std::stable_partition` is linear in the distance between `first` and `last` (i.e., O(n)), but it performs approximately twice as many element moves as `std::partition`.