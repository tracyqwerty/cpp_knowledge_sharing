# `std::back_inserter`

The `back_inserter` is a convenience function template that creates a back-insert iterator, which is a type of output iterator designed to allow algorithms that usually overwrite elements (such as `copy` or `transform`) to instead insert new elements at the end of a container. This is particularly useful when you want to append elements to a container **without pre-sizing it or worrying about its current size**.

- **Container Types**: `back_inserter` works with containers that support back insertion, such as `std::vector`, `std::list`, `std::deque`, etc.
- **Operation**: When an element is assigned to a back-insert iterator, the iterator uses the container's `push_back` member function to add the element to the end of the container.
- **Usage**: It's commonly used with standard algorithms that copy or transform elements from one range to another. Instead of overwriting existing elements, these algorithms can insert new elements at the end of the destination container.

Here's a simple example demonstrating how to use `back_inserter` with the `std::copy` algorithm to copy elements from one vector to another, appending them to the end:

```cpp
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> destination;

    // Copy elements from source to destination, appending them
    std::copy(source.begin(), source.end(), std::back_inserter(destination));

    // Output the contents of the destination vector
    for (int elem : destination) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    return 0;
}
```

In this example, `back_inserter(destination)` creates a back-insert iterator for the `destination` vector. As `std::copy` processes each element of the `source` vector, it uses the back-insert iterator to append these elements to `destination`, effectively duplicating the contents of `source` into `destination`.

When using `back_inserter`, it's not strictly necessary to pre-reserve space in the container because `back_inserter` automatically handles inserting elements at the end of the container, expanding its size as needed. However, **reserving space beforehand can be beneficial for performance reasons, especially for containers like `std::vector`**, where resizing can involve allocating new memory and copying or moving existing elements to the new storage.