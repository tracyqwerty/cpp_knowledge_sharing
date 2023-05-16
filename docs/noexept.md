# `noexept`

The `noexcept` keyword is a part of the function declaration in C++ which tells the compiler that the function does not throw any exceptions. This information can be used by the compiler to optimize the code. 

Here are some points to remember about `noexcept`:

- If a function is marked with `noexcept` and it does throw an exception, then `std::terminate()` is called which usually results in program termination.

- The `noexcept` keyword can be followed by a boolean constant expression, for example, `noexcept(true)` or `noexcept(false)`. If the expression is `true`, it means the function is declared not to throw exceptions. If the expression is `false`, it means that the function may or may not throw an exception.

- `noexcept` without an expression is equivalent to `noexcept(true)`.

- The `const`, `volatile`, `noexcept`, and return type of a function are not part of the function signature for the purpose of overloading.

Here is an example:

```cpp
void foo() { } // Function 1
void foo() noexcept { } // Error: redefinition of Function 1
```

- `noexcept` is particularly important in move constructors and move assignment operators. If these operations are `noexcept`, certain functions like `std::vector::resize()` can operate more efficiently. 

- You can use `noexcept` operator to check if an expression is declared to not throw any exceptions. It returns `true` for such expressions and `false` otherwise.

Here's an example:

```cpp
void may_throw() {
  throw true;
}

auto non_block_throw = []{
  may_throw();
};

void no_throw() noexcept {
  return;
}

auto block_throw = []() noexcept {
  no_throw();
};

int main() {
  std::cout << std::boolalpha
            << "may_throw() noexcept? " << noexcept(may_throw()) << '\n'
            << "no_throw() noexcept? " << noexcept(no_throw()) << '\n'
            << "lmay_throw() noexcept? " << noexcept(non_block_throw()) << '\n'
            << "lno_throw() noexcept? " << noexcept(block_throw()) << '\n';
}
```
In this example, `may_throw()` is not marked `noexcept` so `noexcept(may_throw())` returns `false`. `no_throw()` is marked `noexcept` so `noexcept(no_throw())` returns `true`.

In case of lambdas, the `noexcept` specification of the lambda's function call operator is deduced from its body for non-capturing lambdas, and is `noexcept(false)` for all capturing lambdas. That's why `noexcept(non_block_throw())` returns `true` and `noexcept(block_throw())` returns `false`.