# `std::min_element, std::max_element, std::minmax_element`

In C++, `std::min_element`, `std::max_element`, and `std::minmax_element` are algorithms provided by the `<algorithm>` header that find the smallest, largest, and both smallest and largest elements in a range, respectively. Unlike `std::min`, `std::max`, and `std::minmax` which work on given values, these functions search through iterators defining a range within containers like arrays, vectors, lists, etc.

### `std::min_element`

`std::min_element` searches a range and returns an iterator to the smallest element within that range. If there are multiple elements that are the smallest, it returns the first such element found.

- **Parameters**: A beginning iterator, an ending iterator, and optionally a comparison function.
- **Return Value**: An iterator to the smallest element in the range.

**Example**

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    auto minIt = std::min_element(v.begin(), v.end());
    if (minIt != v.end()) {
        std::cout << "The minimum element is " << *minIt << std::endl;
    }
}
```

### `std::max_element`

`std::max_element` searches a range and returns an iterator to the largest element within that range. Like `std::min_element`, if there are multiple largest elements, it returns the first one found.

- **Parameters**: A beginning iterator, an ending iterator, and optionally a comparison function.
- **Return Value**: An iterator to the largest element in the range.

**Example**

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    auto maxIt = std::max_element(v.begin(), v.end());
    if (maxIt != v.end()) {
        std::cout << "The maximum element is " << *maxIt << std::endl;
    }
}
```

### `std::minmax_element`

`std::minmax_element` searches a range for both the smallest and largest elements, returning a pair of iterators. The first element of the pair is an iterator to the smallest element, and the second is to the largest. If there are multiple smallest or largest elements, it returns the first of each found.

- **Parameters**: A beginning iterator, an ending iterator, and optionally a comparison function.
- **Return Value**: A pair of iterators, where the first is an iterator to the smallest element and the second is to the largest element in the range.

**Example**

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    auto result = std::minmax_element(v.begin(), v.end());
    if (result.first != v.end() && result.second != v.end()) {
        std::cout << "The minimum element is " << *result.first
                  << " and the maximum element is " << *result.second << std::endl;
    }
}
```

These functions are particularly useful for searching through containers when you need to find elements based on their values rather than needing to know their specific positions or when comparing elements directly. They offer a more flexible and idiomatic way to perform searches compared to iterating through containers manually, especially when used with custom comparison functions to define what "smallest" or "largest" means in a specific context.