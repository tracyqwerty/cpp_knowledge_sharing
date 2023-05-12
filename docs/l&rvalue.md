# lvalue & rvalue

## Introduction

An **lvalue** (left value) is an expression that **refers to a memory location and allows us to take the address of that memory location via the & operator**. In other words, an lvalue is something that has an identifiable location in memory. For example, when you declare a variable, that variable is an lvalue. Here's an example:

```cpp
int x = 5;  // x is an lvalue
```

In this case, `x` is an lvalue because it has a specific, identifiable location in memory.

An **rvalue** (right value) is **a temporary value or a value that doesn't have a specific location in memory**. This typically includes literals (like 5, true, etc.) or the result of an expression or function that returns a non-reference type. Here's an example:

```cpp
int x = 5 + 3;  // 5 + 3 is an rvalue
```

In this case, the expression `5 + 3` is an rvalue because it's just a temporary value that doesn't have a specific location in memory.

**A key difference between lvalues and rvalues is that you can't have an lvalue on the right side of an assignment statement.** For example, the following code would be incorrect:

```cpp
5 = x;  // error: lvalue required as left operand of assignment
```

In this case, `5` is an rvalue, and it doesn't make sense to assign to it, hence the error.

## **Lvalue references and Rvalue references (C++11 and later)**:

C++11 introduced a new concept called rvalue references, allowing you to detect and handle rvalues in a particular way. 

An lvalue reference is declared using a single ampersand (&), and can only bind to an lvalue.

```cpp
int x = 5;
int& ref = x;  // correct
int& ref2 = 5;  // error: cannot bind lvalue reference to rvalue
```

An rvalue reference is declared using a double ampersand (&&), and can bind to an rvalue (it can also bind to an lvalue if it's const).

```cpp
int&& ref = 5;  // correct
```

Rvalue references are mainly used in move semantics and perfect forwarding, which are advanced C++ topics.

## Special Cases

The line of code `const int &ref_a = 5;` is creating a reference to a constant integer. This is allowed in C++. 

The `5` is a literal and it's an rvalue, which means it's a temporary value that doesn't have a specific memory location. Normally, you can't create a non-const lvalue reference to an rvalue. This would be illegal:

```cpp
int& ref_a = 5;  // error: cannot bind non-const lvalue reference to an rvalue
```

However, you can create a const lvalue reference to an rvalue:

```cpp
const int& ref_a = 5;  // okay
```

In this case, the lifetime of the rvalue is extended to match the lifetime of the reference. This is a special rule in C++ to allow const references to bind to temporary objects. 

What's happening under the hood is that the temporary value `5` is kept alive for as long as the reference `ref_a` exists. This can be very useful in some situations, for example when you want to avoid unnecessary copies.

Please note that although you can bind a const reference to a temporary object, you can't modify it (because it's const):

```cpp
const int& ref_a = 5;
ref_a = 10;  // error: assignment of read-only reference
```

Without this feature, `vec.push_back(5)` will cause compile error.

## Tips

1. **An rvalue reference can be either an lvalue or an rvalue. If it has a name, it is an lvalue; otherwise, it is an rvalue.**

```cpp
int a = 42;

// ref is an rvalue reference, but because it has a name, we can treat it as an lvalue.
int&& ref = std::move(a); 

// This is allowed, because ref is an lvalue.
int& ref2 = ref; 
```

2. **An `T &&` returned by std::move is an rvalue.**

```cpp
int a = 42;

// std::move(a) is an rvalue.
int&& ref = std::move(a);
```

3. **Both lvalue and rvalue references that are declared are lvalues.**

```cpp
int a = 42;

// lvalue reference is an lvalue.
int& lref = a; 

// NOTICE: rvalue reference is an lvalue.
int&& rref = std::move(a); 

// These are allowed, because both lref and rref are lvalues.
int& lref2 = lref; 
int& rref2 = rref; 
```

Remember, the key idea here is that if something has a name and a specific, identifiable location in memory, it's an lvalue. Even if it's an rvalue reference. And the result of a function, even if it's returning an rvalue reference, is an rvalue, because it's a temporary object.



For advanced learners: https://zhuanlan.zhihu.com/p/335994370



