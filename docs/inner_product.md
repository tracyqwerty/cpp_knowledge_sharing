# `std::inner_product`

`std::inner_product` calculates the inner product (or dot product) of two ranges of elements. It can also perform a generalized inner product by accepting custom addition and multiplication operations.

```cpp
#include <numeric>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {4, 5, 6};
    int product = std::inner_product(a.begin(), a.end(), b.begin(), 0);
    std::cout << "Inner product: " << product << std::endl; // Output: Inner product: 32
}
```

