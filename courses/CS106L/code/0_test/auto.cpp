#include <vector>
using namespace std;
void shift(vector<pair<int, int>> &nums) {
  for (auto &[num1, num2] : nums) {
    num1++;
    num2++;
  }
}
int main() {
  auto my_nums = {{1, 1}};
  shift(my_nums);
  return 0;
}
/*
tracyqwerty@tracyqwertydezhuantou 0_test % g++ -std=c++20 -Wall -Werror auto.cpp -o auto 
auto.cpp:10:8: error: cannot deduce actual type for variable 'my_nums' with type 'auto' from initializer list
  auto my_nums = {{1, 1}};
       ^         ~~~~~~~~
1 error generated.
*/