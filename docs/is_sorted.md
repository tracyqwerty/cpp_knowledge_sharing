# `std::is_sorted`

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