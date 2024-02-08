# `std::adjacent_difference`

`std::adjacent_difference` calculates the difference between each element and its predecessor, placing the result in another range. The first element is copied as is, or a custom binary operation can be applied.

**Example: Calculating adjacent differences**

```cpp
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>

int main() {
    std::vector<int> numbers = {1, 3, 6, 10, 15};
    std::vector<int> differences(numbers.size());

    std::adjacent_difference(numbers.begin(), numbers.end(), differences.begin());
    std::copy(differences.begin(), differences.end(), std::ostream_iterator<int>(std::cout, " ")); // Output: 1 2 3 4 5
}
```