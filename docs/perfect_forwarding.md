# Perfect Forwarding

Perfect forwarding in C++ is a technique used to pass function arguments to another function while retaining the original lvalue or rvalue nature of the arguments. This is accomplished through the use of templated functions and special type deductions known as "forwarding references" (or "universal references" in some literature).

To understand perfect forwarding, it's crucial to first understand move semantics and rvalue references. Move semantics allow resources owned by an rvalue to be moved into an lvalue without making a copy. This is useful for optimizing performance, especially with large data.

Now, let's consider a situation where you have a function that takes some arguments, and you want to write a wrapper function that forwards those arguments to the original function. The simplest way might be like this:

```cpp
void original(int& x) { /*...*/ }

void wrapper(int& x) {
    original(x);
}
```

But what if you also want to call the original function with rvalues? You'd have to write another overload of the wrapper:

```cpp
void wrapper(int&& x) {
    original(std::move(x));
}
```

And what if the original function has multiple parameters, each of which can be an lvalue or rvalue? You'd need to write 2^n overloads of the wrapper, where n is the number of parameters. This quickly becomes unmanageable.

This is where perfect forwarding comes in. **With perfect forwarding, you can write a single function template that can forward any number of arguments of any type, preserving their lvalue or rvalue nature:**

```cpp
template<typename T>
void wrapper(T&& x) {
    original(std::forward<T>(x));
}
```

Here's how it works:

- The argument `x` to the wrapper function is a forwarding reference. **Despite the `&&`, it can bind to either an lvalue or an rvalue, depending on how the wrapper function is called.**
- Inside the wrapper function, `std::forward<T>(x)` casts `x` back to the original type it had when the function was called. **If `x` was originally an lvalue, it becomes an lvalue again; if it was originally an rvalue, it becomes an rvalue again.**

This allows the wrapper function to perfectly forward its arguments to the original function, preserving their lvalue or rvalue nature, and you **only need to write one version of the wrapper**. This technique is used extensively in the C++ Standard Library, especially in template functions that need to forward arguments to a constructor or other function.
