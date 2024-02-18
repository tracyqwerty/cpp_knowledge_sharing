# `std::find, std::find_if, std::find_if_not`

In C++, `find`, `find_if`, and `find_if_not` are algorithms provided by the `<algorithm>` library that offer different ways to search for elements in a range (such as an array or container). Each of these functions has its own use case, depending on the criteria you want to use for the search.

### `find`
The `find` algorithm searches for an element that matches a specific value within a range. It takes three arguments:
- An iterator to the beginning of the range.
- An iterator to the end of the range.
- The value to search for.

It returns an iterator to **the first element in the range that matches the specified value**. If no such element is found, it returns the end iterator of the range.

**Example**

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto it = std::find(v.begin(), v.end(), 3);

    if (it != v.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
}
```

### `find_if`
The `find_if` algorithm searches for the first element that satisfies a specified predicate (a condition or unary function that returns `true` or `false`) within a range. It takes three arguments:
- An iterator to the beginning of the range.
- An iterator to the end of the range.
- The predicate function.

It returns an iterator to the first element for which the predicate returns `true`. If no such element is found, it returns the end iterator of the range.

**Example**

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

bool isOdd(int i) { return i % 2 != 0; }

int main() {
    std::vector<int> v = {2, 4, 6, 8, 9};
    auto it = std::find_if(v.begin(), v.end(), isOdd);

    if (it != v.end()) {
        std::cout << "First odd number: " << *it << std::endl;
    } else {
        std::cout << "No odd numbers found" << std::endl;
    }
}
```

### `find_if_not`
The `find_if_not` algorithm is the inverse of `find_if`. It searches for the first element that does *not* satisfy a specified predicate within a range. It takes the same types of arguments as `find_if`:
- An iterator to the beginning of the range.
- An iterator to the end of the range.
- The predicate function.

It returns an iterator to the first element for which the predicate returns `false`. If no such element is found, it returns the end iterator of the range.

**Example**

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

bool isOdd(int i) { return i % 2 != 0; }

int main() {
    std::vector<int> v = {1, 3, 5, 7, 8};
    auto it = std::find_if_not(v.begin(), v.end(), isOdd);

    if (it != v.end()) {
        std::cout << "First non-odd number: " << *it << std::endl;
    } else {
        std::cout << "All numbers are odd" << std::endl;
    }
}
```

These algorithms are particularly useful because they work with any container that supports iterators (like vectors, lists, and arrays) and can be used with lambda expressions for the predicate, making them very flexible for various search conditions.