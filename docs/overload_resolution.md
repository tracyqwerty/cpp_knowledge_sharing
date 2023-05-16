# overload resolution

In C++, when you call an overloaded function, the compiler performs a process called "overload resolution" to determine which function to call. This process involves comparing the arguments of the function call to the parameters of the overloaded functions to find the best match.

The steps for overload resolution are roughly as follows:

1. **Candidate functions**: The compiler identifies a set of candidate functions that could potentially be called. These include all functions with the same name as the function being called that are visible from the point of the call.

2. **Viable functions**: From the set of candidate functions, the compiler identifies a subset of viable functions whose parameters match the number and type of the arguments in the function call.

3. **Best viable function**: From the set of viable functions, the compiler chooses the "best viable function" based on a set of ranking rules. These rules favor functions that require the least amount of conversion (for example, an exact match is better than a match that requires a numeric conversion).

If there is exactly one best viable function, the compiler chooses that function to call. If there are multiple functions that are equally good matches, the call is considered ambiguous and the compiler will give an error.

For example, consider the following code:

```cpp
void foo(int x) { ... }
void foo(double x) { ... }

foo(10);  // Calls foo(int x)
foo(10.0);  // Calls foo(double x)
```

In this code, when you call `foo(10)`, the compiler will choose `foo(int x)` because it is an exact match. When you call `foo(10.0)`, the compiler will choose `foo(double x)` because it is an exact match.

But if you have two functions that could both be called with the same argument, like this:

```cpp
void bar(int x, double y) { ... }
void bar(double x, int y) { ... }

bar(10, 20);  // Error: call to 'bar' is ambiguous
```

In this case, when you call `bar(10, 20)`, the compiler can't decide whether to convert `10` to `double` and call `bar(double x, int y)`, or to convert `20` to `double` and call `bar(int x, double y)`. Since neither conversion is clearly better than the other, the call is ambiguous and the compiler gives an error.