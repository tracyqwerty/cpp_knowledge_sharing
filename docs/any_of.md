# `std::any_of`

The `std::any_of` function is a template function in the C++ Standard Library. It checks if any element in a range satisfies a specified condition. It returns `true` if at least one element satisfies the condition and `false` otherwise.

Here's an example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Check if any number in the vector is greater than 3
    bool any_greater_than_three = std::any_of(numbers.begin(), numbers.end(), [](const int& num) {
        return num > 3;
    });

    if (any_greater_than_three) {
        std::cout << "There is at least one number greater than 3 in the vector.\n";
    } else {
        std::cout << "There are no numbers greater than 3 in the vector.\n";
    }

    return 0;
}
```

In this example, `std::any_of` checks each number in the `numbers` vector to see if it's greater than 3. Since the vector contains the numbers 4 and 5, which are greater than 3, `std::any_of` returns `true` and the program outputs "There is at least one number greater than 3 in the vector."