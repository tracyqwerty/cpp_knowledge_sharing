# `std::partition, std::stable_partition, std::partition_copy`

The `partition`, `stable_partition`, and `partition_copy` algorithms are part of the C++ Standard Library's `<algorithm>` header and are used to rearrange elements in a range based on a given predicate (a function that returns `true` or `false`). These algorithms are particularly useful for organizing data into two groups based on a specific condition.

### `partition`
The `partition` algorithm rearranges the elements in a range such that all elements for which the predicate returns `true` precede those for which it returns `false`. **The relative order of elements within each group is not necessarily preserved.**

- **Parameters**: It takes a beginning iterator, an ending iterator, and a predicate function.
- **Return Value**: It returns an iterator that points to the first element of the second group (the first element for which the predicate returns `false`).

#### Example:
```cpp
#include <algorithm>
#include <vector>
#include <iostream>

bool isOdd(int i) { return i % 2 != 0; }

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    auto partitionPoint = std::partition(v.begin(), v.end(), isOdd);

    std::cout << "Odd numbers:";
    for (auto it = v.begin(); it != partitionPoint; ++it)
        std::cout << ' ' << *it;
    std::cout << "\nEven numbers:";
    for (auto it = partitionPoint; it != v.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}
```

### `stable_partition`
The `stable_partition` algorithm works similarly to `partition` but preserves the relative order of elements within each group. **This stability comes at the cost of additional time and/or space complexity.**

- **Parameters**: Like `partition`, it takes a beginning iterator, an ending iterator, and a predicate function.
- **Return Value**: An iterator to the first element of the second group.

#### Example:
```cpp
#include <algorithm>
#include <vector>
#include <iostream>

bool isOdd(int i) { return i % 2 != 0; }

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    auto partitionPoint = std::stable_partition(v.begin(), v.end(), isOdd);

    std::cout << "Odd numbers:";
    for (auto it = v.begin(); it != partitionPoint; ++it)
        std::cout << ' ' << *it;
    std::cout << "\nEven numbers:";
    for (auto it = partitionPoint; it != v.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}
```

### `partition_copy`
The `partition_copy` algorithm copies elements into two different destinations based on a predicate. **Elements for which the predicate returns `true` are copied to the first destination, while those for which it returns `false` are copied to the second destination.**

- **Parameters**: It takes a beginning iterator, an ending iterator, two output iterators (one for each destination), and a predicate function.
- **Return Value**: A pair of iterators representing the end of the sequences generated in both destinations.

#### Example:
```cpp
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

bool isOdd(int i) { return i % 2 != 0; }

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    std::vector<int> odds, evens;

    std::partition_copy(v.begin(), v.end(), std::back_inserter(odds),
                        std::back_inserter(evens), isOdd);

    std::cout << "Odd numbers:";
    for (int n : odds)
        std::cout << ' ' << n;
    std::cout << "\nEven numbers:";
    for (int n : evens)
        std::cout << ' ' << n;
    std::cout << '\n';
}
```

Each of these algorithms serves a specific purpose in data manipulation and organization, allowing developers to efficiently partition data based on custom conditions.