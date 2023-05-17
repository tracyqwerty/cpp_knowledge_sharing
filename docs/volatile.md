# `volatile`

`volatile` is a keyword in C++ (and also in C) that is intended to prevent the compiler from applying any optimizations on objects that can change in ways that cannot be determined by the compiler.

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

This is especially important in systems programming and embedded systems where certain memory locations correspond to input/output ports, and reading/writing from/to these locations have side effects. `volatile` tells the compiler not to optimize away these operations because they're critical to the program's operation.

However, keep in mind that **`volatile` does not replace the need for synchronization primitives like mutexes or atomic operations.** **While `volatile` can prevent certain types of optimizations, it does not provide any guarantees around visibility or ordering of operations in a multi-threaded context.** In most higher-level programming, especially **in multi-threaded context, `volatile` keyword is not enough to prevent all types of read/write reorderings done by the compiler and the hardware.** As such, use of `volatile` is often associated with low-level code such as implementing synchronization primitives, interacting with memory-mapped hardware, or writing interrupt handlers.