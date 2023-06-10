# `std::priority_queue`

`std::priority_queue` is a container adapter that provides a restricted deque interface with the functionality to interact with the element of highest priority, which is always kept at the front of the queue. It is usually implemented using `std::vector` or `std::deque` as the underlying container and a binary heap as the data structure.

For example, the declaration 

````cpp
std::priority_queue<vector<string>, container, decltype(cmp_fn)> queue(cmp_fn);
````

 is specifying a priority queue where:

- The elements in the queue are of type `vector<string>`.
- The underlying container is of type `container` (which is not specified in the line you provided, but it's usually `std::vector` or `std::deque`). Here it can be `vector<vector<string>>`. 
- The comparison function for determining the priority of the elements is of type `decltype(cmp_fn)`, which is the type of the `cmp_fn` function.

The `cmp_fn` function is passed to the constructor of the `std::priority_queue` to initialize the comparison object of the queue. This function is used to order the elements in the queue. It should return `true` if the first argument is considered to go before the second in the strict weak ordering it defines, and `false` otherwise.

Here is a simple example of how to use `std::priority_queue` with a custom comparator:

```cpp
#include <iostream>
#include <queue>
#include <vector>

// Custom comparator function
bool cmp_fn(int left, int right) {
    return left > right;  // This will create a min-heap instead of the default max-heap
}

int main() {
    // Create a priority queue with the custom comparator
    std::priority_queue<int, std::vector<int>, decltype(cmp_fn)> queue(cmp_fn);

    // Add elements to the queue
    queue.push(3);
    queue.push(2);
    queue.push(5);

    // Print and remove the elements from the queue
    while (!queue.empty()) {
        std::cout << queue.top() << " ";
        queue.pop();
    }

    return 0;
}
```

In this example, the `cmp_fn` function is defined to return `true` if the left argument is greater than the right argument, which means that the smallest element will always be at the top of the queue. This is the opposite of the default behavior of `std::priority_queue`, which is a max-heap where the largest element is always at the top.

Also,  `std::priority_queue` can work with lambda functions as custom comparators. Here's an example:

```cpp
#include <iostream>
#include <queue>
#include <vector>

int main() {
    // Create a priority queue with a lambda function as the custom comparator
    auto cmp = [](int left, int right) { return left > right; }; // This will create a min-heap
    std::priority_queue<int, std::vector<int>, decltype(cmp)> queue(cmp);

    // Add elements to the queue
    queue.push(3);
    queue.push(2);
    queue.push(5);

    // Print and remove the elements from the queue
    while (!queue.empty()) {
        std::cout << queue.top() << " ";
        queue.pop();
    }

    return 0;
}
```

In this example, the lambda function `[](int left, int right) { return left > right; }` is used as the custom comparator for the priority queue. This lambda function returns `true` if the left argument is greater than the right argument, which means that the smallest element will always be at the top of the queue. This is the opposite of the default behavior of `std::priority_queue`, which is a max-heap where the largest element is always at the top.

Note that the type of `cmp` is a lambda function, which is a special type of function in C++. **The exact type of a lambda function is not directly expressible in C++ (it's an implementation-defined unique type)**, so we often use `auto` to let the compiler deduce the type for us.

In this case, `cmp` is a lambda function that takes two `int` parameters and returns a `bool`. It's used as a custom comparator for the priority queue. The lambda function `cmp` returns `true` if `left` is greater than `right`, which means the priority queue will be a min-heap (the smallest element has the highest priority).



For more info:
[Advantages of Setting priority_queue Container](https://stackoverflow.com/questions/9958180/advantages-of-setting-priority-queue-container)