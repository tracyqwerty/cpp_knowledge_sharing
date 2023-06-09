# `std::min_element`

`std::max_element`: This function works similarly to `std::min_element`, but it returns an iterator pointing to the largest element in the range `[first, last)`. If more than one element fulfills this condition, the iterator to the first one is returned. If the range is empty, the function returns `last`.

Here's an example of how to use `std::max_element`:

```cpp
std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
auto result = std::max_element(v.begin(), v.end());
std::cout << "The largest element is " << *result << " at position " << std::distance(v.begin(), result);
```

