# `std::partial_sum`

`std::partial_sum` computes the partial sums of the elements in a range, storing the result in another range. It can also apply a custom binary operation instead of addition.

```cpp
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> result(numbers.size());

    std::partial_sum(numbers.begin(), numbers.end(), result.begin());
  
  	// a more comlexed example: compute the running product
    // std::partial_sum(numbers.begin(), numbers.end(), runningProduct.begin(), std::multiplies<int>());

    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " ")); // Output: 1 3 6 10 15
}
```