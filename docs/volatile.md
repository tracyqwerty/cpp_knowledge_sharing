# `volatile`

`volatile` is a keyword in C++ (and also in C) that is intended to prevent the compiler from applying any optimizations on objects that can change in ways that cannot be determined by the compiler. It can:

* **Prevent the compiler from caching the variable in a register without writing it back immediately**.

* **Prevent the compiler from reordering instructions involving the variable**.

Objects declared as `volatile` are omitted from optimization because their values can be changed at any time without any action being taken by the code the compiler finds nearby. For example, a global variable can be marked `volatile` if it is modified by an interrupt service routine, or if it represents a hardware register in embedded systems.

Here's an example of `volatile`:

```cpp
volatile int x;

void foo() {
    x = 10;  // write to x
    int y = x;  // read from x
    // ...
}
```

In this code, even though it looks like `x` is written to and then immediately read from without being modified in between, **the compiler will not optimize the code to eliminate the read and use the value 10 directly.** This is because `x` is declared `volatile`, so the compiler acknowledges that `x` could be changed outside of the code it's analyzing.

```
x = 0;
Thread 1   |  Thread 2
lock();    |  lock();
x++;       |  x++;
unlock();  |  unlock();
```

Declaring a variable as `volatile` can prevent the compiler from keeping the variable's value in a register over its lifetime because the compiler is made aware that the value of the variable can change at any moment outside of the current execution context. Therefore, each read or write to a `volatile` variable will be directly performed to the memory address of that variable, ensuring that its latest value is always used or updated immediately, reflecting any external changes.

However, we don't need to worry about this these days. When you use locking mechanisms provided by most threading libraries (such as pthreads in C or std::mutex in C++), these operations include memory barriers or act as compiler barriers. A memory barrier prevents the compiler and the CPU from reordering memory operations across the barrier. This means that **all memory operations (reads and writes) that happened before the lock must be completed before the lock is acquired,** and all memory operations within the locked section must be completed before the lock is released.

```
x = y = 0;
Thread 1   |   Thread 2
x = 1;     |   y = 1;
r1 = y;    |   r2 = x;
```

But this is problematic. Without explicit synchronization, there's no guarantee that the write by one thread will be visible to the read by another thread in a timely manner. This is because CPUs and compilers may reorder instructions and cache values in ways that are not immediately visible to other threads.

- It is theoretically possible for `r1` to be `0` and `r2` to be `0` if both reads happen before the other thread's write.
- `r1` could be `1` (if Thread 1 reads `y` after Thread 2 writes to it) and `r2` could be `0` (if Thread 2 reads `x` before Thread 1 writes to it), or vice versa.
- Both `r1` and `r2` could be `1` if the reads happen after the other thread's writes.

Using `volatile` in this example doesn't help because it only instructs the compiler not to cache the variables in registers across accesses and to **always read from and write to memory directly**, however **it does not guarantee the order in which writes become visible to other threads**. Memory visibility issues can still occur due to the way modern CPUs use caches and how memory operations are ordered at the hardware level.

Keep in mind that **`volatile` does not replace the need for synchronization primitives like mutexes or atomic operations.** **While `volatile` can prevent certain types of optimizations, it does not provide any guarantees around visibility or ordering of operations in a multi-threaded context.** In most higher-level programming, especially **in multi-threaded context, `volatile` keyword is not enough to prevent all types of read/write reorderings done by the compiler and the hardware.** As such, use of `volatile` is often associated with low-level code such as implementing synchronization primitives, interacting with memory-mapped hardware, or writing interrupt handlers.