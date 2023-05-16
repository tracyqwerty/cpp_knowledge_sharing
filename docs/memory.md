# memory management

In C++, memory is divided into several regions, each with its own specific purpose and lifetime. These regions are:

## **Stack Memory**(stack)

 This is where local variables are stored. These are the variables defined in a function (including the main function). The memory for these variables is automatically allocated when the function in which they are defined is called, and is automatically deallocated when the function exits. Because **the size of the stack is determined when the program starts, it is not suitable for storing large amounts of data**. Stack memory is also used to keep track of the program's execution, by pushing and popping function call information (like parameters and return addresses) in what's called a "call stack".

## **Heap Memory**(heap)

Also known as **dynamic memory**, this is where data is stored when you explicitly allocate memory using `new` (or `malloc` in C). The memory remains allocated until you explicitly deallocate it using `delete` (or `free` in C). Because **it's not automatically managed like stack memory, failing to deallocate memory when you're done with it can lead to memory leaks.**

## **Static Memory**(data)

**This is where global variables and static variables are stored.** These variables are allocated when the program starts and deallocated when the program ends, so they exist for the lifetime of the program. This includes variables declared `static` inside functions, which maintain their values between function calls.

## **Code Memory**(text)

 Also known as text segment, this is where the actual compiled program code resides. This is typically **read-only memory to prevent the program from accidentally modifying its own instructions**.

## **Constant Memory**

This is often grouped with code memory, and it's where string literals and other constant data are stored.

Managing memory correctly is one of the main challenges of programming in C++. Memory leaks (forgetting to deallocate memory), dangling pointers (pointers to deallocated memory), and stack overflows (using up all the stack space) are common problems. The use of smart pointers, introduced in C++11, can help manage dynamic memory and prevent leaks. 

In modern operating systems, the actual memory locations used by a program are **virtual addresses**, which the operating system maps to physical memory. This provides isolation between different programs and allows the operating system to move memory around as needed.

## A more concrete comparison between stack and heap

In C++, as in many other programming languages, memory is divided into two primary sections: the stack and the heap. Each section is used for different purposes and has different characteristics.

### **Stack**

The stack is a region of memory that grows and shrinks automatically as functions are called and return. It's organized as a stack data structure, where the "top" of the stack is the current location in memory where data can be stored. 

When a function is called, a block of memory is reserved at the top of the stack. This block of memory, called a stack frame, contains:

- The function's local variables
- The function's parameters
- The return address, indicating where in the program to return after the function completes

The local variables and parameters of a function are created on the stack when the function is called, and they are automatically destroyed when the function returns. This is a key characteristic of the stack: it automatically manages the lifetime of the data stored in it.

Here's a simple example in C++:

```cpp
void foo(int x) {
    int y = 10;
    // x and y are stored on the stack
}

int main() {
    foo(20);
    return 0;
}
```

In this example, when `foo` is called, a stack frame is created that contains `x` and `y`. When `foo` returns, the stack frame is destroyed, and `x` and `y` are automatically cleaned up.

**Heap**

The heap, also known as free store in C++, is a region of memory used for **dynamic memory allocation**. Unlike the stack, the heap does not grow and shrink automatically. Instead, you have to manually allocate and deallocate memory on the heap using the `new` and `delete` operators (or `malloc` and `free` in C).

**The heap is used when you need to allocate memory dynamically, such as when you don't know at compile time how much memory you need or when you need to allocate a large amount of memory.**

Here's a simple example in C++:

```cpp
int* create_array(int size) {
    int* arr = new int[size];  // Allocates memory on the heap
    return arr;
}

void destroy_array(int* arr) {
    delete[] arr;  // Deallocates memory on the heap
}

int main() {
    int* arr = create_array(100);
    // Use arr...
    destroy_array(arr);
    return 0;
}
```

In this example, `create_array` allocates an array of integers on the heap, and `destroy_array` deallocates the array. The memory for the array persists until it is manually deallocated, even across function calls.

**Stack vs Heap**

The stack is fast and automatically manages memory, but it's also limited in size. If you try to allocate too much memory on the stack, such as a large array, you can overflow the stack and cause a program crash.

The heap is more flexible and can handle large, dynamic allocations, but it's slower and requires manual memory management. If you forget to deallocate memory when you're done with it, you can cause a memory leak, where the memory is wasted until the program ends.

In general, you should prefer to use the stack when possible because it's faster and safer. Use the heap when you need to allocate large amounts of memory or when you need memory that persists beyond a single function call.x

## Reference

For more information, see also: https://courses.engr.illinois.edu/cs225/fa2022/resources/stack-heap/