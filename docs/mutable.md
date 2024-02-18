# `mutable`

The `mutable` keyword in C++ plays a specific role, particularly in the context of const correctness and lambda expressions, as well as traditional class member functions. Let's break down its usage and implications in different scenarios:

**Use in Class Member Functions**

In the context of a class, marking a member variable as `mutable` **allows it to be modified even if it's part of an object that is const**. This is useful when you **have variables that are meant to be changed regardless of the object's const status**, such as cache variables or counters that do not conceptually alter the observable state of the object.

Example:

```cpp
class Example {
public:
    mutable int cacheVar;

    void updateCache() const {
        cacheVar = /* some computation */;
    }
};
```

In this example, `updateCache` can modify `cacheVar` even if it's called on a const instance of `Example`, because `cacheVar` is declared `mutable`.

**Use in Lambda Expressions**

When you capture variables by value in a lambda expression, the copies of these variables inside the lambda are by default const, meaning you cannot modify them. However, if you want to modify these copies within the lambda, you can use the `mutable` keyword.

Your example demonstrates this use case:

```cpp
int i{3};
auto lambda = [=]() mutable { cout << i++; };
```

Here, `i` is captured by value. Without `mutable`, the lambda would not be able to modify its copy of `i`, since the copy would be const. With `mutable`, the lambda can modify its copy of `i`. It's important to understand that this modification does not affect the original `i` outside the lambda; it only affects the copy held by the lambda.

**Important Points to Remember**

- The `mutable` keyword only affects the constness of the lambda's captured variables or class member variables; it does not change the constness of the lambda itself or of member functions.
- Use `mutable` judiciously. While it can be powerful, especially for enabling certain kinds of stateful lambdas or for allowing "logical constness" in classes (where the object's observable state doesn't change even though its internal state might), overuse or misuse can lead to code that is harder to understand and maintain.
- `mutable` on lambda expressions is especially useful for **creating stateful lambdas that can change their captured variables across calls, enabling them to act somewhat like functors** (objects with operator() defined).

In summary, the `mutable` keyword provides flexibility in situations where you need to modify data that would otherwise be considered const, but it should be used with care to avoid introducing unintended side effects or complicating code logic.