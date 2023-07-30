#include <iostream>
template <int n> struct Factorial {
  static const int value = n * Factorial<n - 1>::value;
};

template <> struct Factorial<0> {
  static const int value = 1;
};

int main() {
  std::cout << Factorial<5>::value << std::endl;
  return 0;
}
// https://stackoverflow.com/questions/11916547/template-in-c-why-have-to-use-enum/