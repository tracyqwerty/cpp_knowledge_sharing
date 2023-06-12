# `std::for_each`

`std::for_each` is a function template in the C++ Standard Library that applies a function to a range of elements. It's part of the `<algorithm>` header.

Here's a simple example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::for_each(numbers.begin(), numbers.end(), [](int num) {
        std::cout << num << " ";
    });

    return 0;
}
```

In this example, `std::for_each` applies a lambda function to each element in the `numbers` vector. The lambda function simply prints the number followed by a space. The output of this program would be:

```
1 2 3 4 5 
```

You can use `std::for_each` with any function that takes a single argument of the element type. The function can be a free function, a function object, or a lambda function. Here's an example using a free function:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void printNumber(int num) {
    std::cout << num << " ";
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::for_each(numbers.begin(), numbers.end(), printNumber);

    return 0;
}
```

This program does the same thing as the previous one, but it uses the `printNumber` free function instead of a lambda function.