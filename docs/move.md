# std::move

## Intro

In C++, `std::move` is a standard library function template that is used to indicate that an object may be "moved from", i.e., allowing the efficient transfer of resources from one object (source) to another (destination). 

It does not actually move anything itself but merely casts its argument to an rvalue, which then makes it possible to move from it. This is where the concept of "move semantics" comes into play.

In C++, there are two types of expressions:
1. Lvalue: An expression that represents **a memory location and can appear either on the left-hand side or the right-hand side** of an assignment operation. Named variables are lvalues.
2. Rvalue: An expression that represents **a temporary object or a value not associated with a memory location**. **They can only appear on the right-hand side of an assignment operation.**

Before C++11, copying was the only option when dealing with function return values or when an object was passed to a function. However, copying can be an expensive operation in terms of performance when the objects are large.

C++11 introduced move semantics, which allows resources to be moved rather than copied in such scenarios. This is where `std::move` comes into play. It's basically a type-casting utility that **transforms its argument into an rvalue**, thereby allowing the compiler to invoke the move constructor or move assignment operator, which usually results in more efficient code.

Here's an example:

```cpp
std::vector<int> v1 = {1, 2, 3, 4, 5};

// Copy constructor is called
std::vector<int> v2 = v1; 

// Move constructor is called
std::vector<int> v3 = std::move(v1);
```

In this example, when initializing `v2`, the copy constructor of `std::vector` is called, which means the entire data of `v1` is copied to `v2`. However, when initializing `v3`, **the move constructor of `std::vector` is called because of `std::move(v1)`**. **This means the data of `v1` is moved to `v3` without copying. The vector `v1` is now in a valid but unspecified state, and its content should no longer be accessed.**

It's important to understand when to use `std::move`. Misuse can lead to subtle bugs, especially because after `std::move` is called on an object, the object is in a valid but unspecified state. You should only use `std::move` when you're sure you won't need the source object again, or you're sure you'll reassign or destroy it before you do.

## One More Word

`std::move(x)` generates an xvalue (expiring value) expression to represent its argument x. It is completely equivalent to `static_cast<T&&>(x)`."

In more detail:

- The `std::move` function in C++ does not actually move anything. Instead, it merely casts its argument to an rvalue reference, indicating that the object may be moved from.
- An xvalue, or "expiring value", is a type of rvalue which represents an object that is nearing the end of its lifecycle. This means it can safely have its resources taken (or "moved") by another object.
- The expression `static_cast<T&&>(x)` is indeed equivalent to `std::move(x)`. It's a cast to an rvalue reference of type `T`, which allows `x` to be passed to a move constructor or move assignment operator that accepts an rvalue reference of type `T`.

So in summary, `std::move` is a way to tell the compiler that an object's resources can be safely moved from, without actually performing the move operation itself. The actual move is done by the move constructor or move assignment operator of the class.
