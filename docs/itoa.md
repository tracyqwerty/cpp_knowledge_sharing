# `std::iota`

`std::iota` fills a range with sequentially increasing values, starting with a value and repetitively incrementing it.

```cpp
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>

int main() {
    std::vector<int> sequence(5);
    std::iota(sequence.begin(), sequence.end(), 1);
    std::copy(sequence.begin(), sequence.end(), std::ostream_iterator<int>(std::cout, " ")); // Output: 1 2 3 4 5
}
```