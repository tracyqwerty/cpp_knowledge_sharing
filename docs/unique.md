# `std::unique`

`std::unique` is a function in the C++ Standard Library that is used to remove all but the first element from every consecutive group of equivalent elements in a range of values. It does not actually remove the duplicate elements from the container, but rather **it moves them to the end of the specified range and returns an iterator pointing to the first of these duplicates.** You can then use this iterator to erase the duplicates from the container.

Here's an example of how to use `std::unique`:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
		// std::vector<int>::iterator
    auto end_unique = std::unique(numbers.begin(), numbers.end());

    // Erase the duplicates from the vector
    numbers.erase(end_unique, numbers.end());

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
```

In this example, `std::unique` moves all the duplicate elements to the end of the vector and returns an iterator pointing to the first of these duplicates. The `erase` function is then used to remove these duplicates from the vector. The output of this program is `1 2 3 4`, which are the unique elements in the vector.

Note that `std::unique` only considers consecutive duplicate elements. If the duplicate elements are not next to each other, `std::unique` will not consider them as duplicates. Therefore, it's often a good idea to sort the range before calling `std::unique` if you want to remove all duplicates regardless of their position.