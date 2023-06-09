# `std::sort`

The `std::sort` function in C++ is used to sort elements in a range into ascending order. Here's a simple example:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {5, 3, 1, 4, 2};

    std::sort(numbers.begin(), numbers.end());

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
```

In this example, the `std::sort` function is called with two arguments: `numbers.begin()` and `numbers.end()`. These arguments represent the range of elements to sort. In this case, the entire `numbers` vector is sorted.

After the call to `std::sort`, the `numbers` vector contains the elements `{1, 2, 3, 4, 5}`. The elements have been sorted into ascending order.

The `std::sort` function works with any type of random-access iterator, so you can use it with other types of containers as well, such as `std::deque` and arrays. Note that `std::list` does not support random-access iterators, so you cannot use `std::sort` with `std::list`. Instead, `std::list` has its own `sort` member function.

By default, `std::sort` sorts elements into ascending order. If you want to sort elements into descending order, you can provide a custom comparison function as a third argument to `std::sort`. For example:

```cpp
std::sort(numbers.begin(), numbers.end(), std::greater<int>());
```

This will sort the elements in `numbers` into descending order. The `std::greater<int>()` argument is a function object (also known as a functor) that returns `true` if its first argument is greater than its second argument.

