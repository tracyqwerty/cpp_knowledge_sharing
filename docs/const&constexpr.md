# const & constexpr

`const` and `constexpr` are both keywords in C++ used to define constant values, but they are used in different contexts and have different implications.

## `const`

This keyword is used to declare a variable whose value cannot be changed after initialization. This means once a `const` variable is assigned a value, it cannot be changed thereafter. This is useful for defining values that you want to prevent from being modified, either accidentally or intentionally, anywhere else in the code. 

Here is an example of using `const`:

```cpp
const int daysInWeek = 7;
daysInWeek = 8; // Error, daysInWeek is const and cannot be changed
```

## `constexpr`

This keyword is used to specify that the value of a variable, or the return value of a function, is a compile-time constant. `constexpr` variables are evaluated at compile time, which can lead to more efficient code because the compiler knows the value of the variable in advance.

A `constexpr` function can be used where a constant expression is required, such as in template arguments, array lengths, and so on. It must satisfy certain requirements, like having a literal type, being `return`-statement-only, and the expression in the `return` statement must be a constant expression.

Here is an example of using `constexpr`:

```cpp
constexpr int square(int num) {
    return num * num;
}

int arr[square(5)]; // OK, square(5) is a constant expression evaluated at compile time
```

The `const` and `constexpr` keywords can also be used together:

```cpp
constexpr const int val = 10; // This declares val as a constant integer that is evaluated at compile time
```

**This declares `val` as a compile-time constant integer.** **The `const` keyword ensures that `val` cannot be modified, and the `constexpr` keyword ensures that its value is computed at compile time.** 

### Insights

##### **Floatingpoint `constexpr`**

 When a `constexpr` contains a floating-point number, the precision of the computation could vary between compile-time and run-time due to different system environments. To ensure consistency and prevent unexpected behavior, C++11 requires that the precision of a floating-point `constexpr` computation at compile-time be at least as accurate as it would be at run-time.

##### Function Declarations and Definitions 

For regular functions, it's enough to have a declaration before the point of use (the call). However, for `constexpr` functions, the definition must be available before the point of use. This is because `constexpr` functions may be evaluated at compile-time, and the compiler needs to know the function's definition to do this.



In general, you use `const` when you want to prevent a variable from being modified, and you use `constexpr` when you want to perform computations at compile time for efficiency.

## Reference

https://yuhao0102.github.io/2020/09/14/cpp%E4%B8%ADconstexpr%E4%BD%9C%E7%94%A8/