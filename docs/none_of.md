# `std::none_of`

`std::none_of` is a function template in the C++ Standard Library that checks if none of the elements in a range satisfy a certain condition. It returns `true` if none of the elements satisfy the condition, and `false` otherwise.

Here's an example of how to use `std::none_of`:

```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};

bool none_greater_than_six = std::none_of(numbers.begin(), numbers.end(), [](const int& n) {
    return n > 6;
});

if (none_greater_than_six) {
    std::cout << "There are no numbers greater than six in the vector.\n";
} else {
    std::cout << "There is at least one number greater than six in the vector.\n";
}
```

In this example, `std::none_of` checks if there are no numbers in the vector that are greater than six. Since the highest number in the vector is 5, `std::none_of` returns `true`, and the program outputs "There are no numbers greater than six in the vector."

Just like `std::all_of` and `std::any_of`, `std::none_of` takes a range (specified by a pair of iterators) and a predicate (a unary function or lambda that returns a `bool`). It applies the predicate to each element in the range until it finds an element that satisfies the predicate (i.e., for which the predicate returns `true`). If it finds such an element, it immediately returns `false`. If it doesn't find such an element after checking the entire range, it returns `true`.