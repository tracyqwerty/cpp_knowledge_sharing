# `is_sorted, is_sorted_until`

## `is_sorted`

The `std::is_sorted` function is a part of the `<algorithm>` library in C++. It checks whether the elements in a range are sorted in non-descending order.

Here's an example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    if (std::is_sorted(numbers.begin(), numbers.end())) {
        std::cout << "The vector is sorted.\n";
    } else {
        std::cout << "The vector is not sorted.\n";
    }

    return 0;
}
```

In this example, `std::is_sorted` checks if the elements in the `numbers` vector are sorted in non-descending order. Since they are, the output of the program will be "The vector is sorted."

You can also provide a custom comparison function to `std::is_sorted` to check for a different kind of sorting. For example, you can check if the elements are sorted in non-ascending order:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 4, 3, 2, 1};

    if (std::is_sorted(numbers.begin(), numbers.end(), std::greater<int>())) {
        std::cout << "The vector is sorted in non-ascending order.\n";
    } else {
        std::cout << "The vector is not sorted in non-ascending order.\n";
    }

    return 0;
}
```

In this example, `std::is_sorted` checks if the elements in the `numbers` vector are sorted in non-ascending order. Since they are, the output of the program will be "The vector is sorted in non-ascending order."

## `is_sorted_until`

Here's a simple example to demonstrate how `is_sorted_until` can be used to find up to where a vector of integers is sorted:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> data = {1, 2, 3, 5, 4, 6, 7, 8};

    // Use is_sorted_until to find the subrange where data is sorted
    auto it = std::is_sorted_until(data.begin(), data.end());

    if (it != data.end()) {
        std::cout << "The range is sorted until element: " << *it << std::endl;
    } else {
        std::cout << "The entire range is sorted." << std::endl;
    }

    return 0;
}
```

You can also use `is_sorted_until` with a custom comparison function to check for different sorting orders, such as descending order. Here's how you might do that:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> data = {8, 7, 6, 5, 3, 4, 2, 1};

    // Check if the vector is sorted in descending order until a certain point
    auto it = std::is_sorted_until(data.begin(), data.end(), std::greater<int>());

    if (it != data.end()) {
        std::cout << "The range is sorted in descending order until element: " << *it << std::endl;
    } else {
        std::cout << "The entire range is sorted in descending order." << std::endl;
    }

    return 0;
}
```

In this case, `std::greater<int>()` is used to define a descending order. The function will return an iterator to the first element where this order is violated.

`is_sorted_until` is a useful tool for diagnosing sorting issues or for determining whether additional sorting is necessary for a part of a sequence.