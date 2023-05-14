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



For more information, see also: https://courses.engr.illinois.edu/cs225/fa2022/resources/stack-heap/