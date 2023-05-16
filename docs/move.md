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

![img](assets/v2-a10e15ec0fef0b578d7bf794c4c8f6ac_1440w.webp)

![img](assets/v2-054c65836cb9dad817399a471386e154_1440w.webp)

## Another Way of Looking

`std::move` is a mechanism that can improve performance when dealing with objects that manage dynamic memory (i.e., memory on the heap), or other resources like file handles, network sockets, etc. The benefit comes from avoiding expensive deep-copy operations where all the data owned by an object is duplicated.

Consider a standard container like `std::vector` or `std::string`. When these objects are copied, all the elements they contain (which are stored on the heap) are also copied. This can be an expensive operation both in terms of time and memory usage, especially for large containers.

However, when these objects are moved using `std::move`, **the internal pointer to the heap memory is simply transferred from the source object to the destination object.** No actual copying of elements takes place. This is a very fast operation that doesn't depend on the size of the container.

**Objects that only contain data on the stack (like built-in types or small user-defined types with only stack data members) do not benefit from move semantics in the same way.** Copying such objects is already a cheap operation, since it just involves copying a small, fixed amount of stack memory.

Remember, however, that move semantics also mean that the moved-from object is left in a valid but unspecified state, and should not be used after the move except to assign it a new value, or to destroy it. This is a trade-off for the performance benefit.

In summary, `std::move` and move semantics in general are primarily a performance optimization for objects that manage dynamic memory or other resources. They allow costly deep-copy operations to be replaced with cheap move operations.

## Reference

https://www.zhihu.com/question/22111546/answer/2590209387
