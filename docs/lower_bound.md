# `std::lower_bound`

`std::lower_bound` is a function in the `<algorithm>` library in C++. It returns an iterator pointing to the first element in the range [first, last) that is not less than (i.e. greater or equal to) a certain value.

Here's an example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 5, 6, 7};

    auto it = std::lower_bound(numbers.begin(), numbers.end(), 5);

    std::cout << "The first number not less than 5 is: " << *it << '\n';

    return 0;
}
```

In this example, `std::lower_bound` returns an iterator pointing to the first number in `numbers` that is not less than 5. The output of the program will be "The first number not less than 5 is: 5".

