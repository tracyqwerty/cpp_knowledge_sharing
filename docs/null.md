# `NULL` & `nullptr`

`nullptr` and `NULL` are both used to indicate null pointers in C++, but they are not the same and have some important differences:

## `NULL`

In C++, `NULL` is a macro that is typically defined as either `0` or `(void *)0`. This means that **`NULL` is an integer, not a pointer**. **This can lead to some unexpected behavior.** For example, consider a function that has two overloaded versions, one that takes an integer and one that takes a pointer. If you call this function with `NULL`, the version that takes an integer will be called, not the version that takes a pointer. 

## `nullptr`

 `nullptr` is a keyword in C++11 and later that represents a null pointer value. It has its own type (`std::nullptr_t`), which can be implicitly converted to any pointer type, and it can't be converted to any type other than bool. This means that **`nullptr` is a true pointer, not an integer**. In the function overloading situation described above, **if you call the function with `nullptr`, the version that takes a pointer will be called**.

Here is an example that illustrates the difference:

```cpp
void f(int) {
    std::cout << "f(int) is called\n";
}

void f(char*) {
    std::cout << "f(char*) is called\n";
}

int main() {
    f(NULL);     // calls f(int), not f(char*)
    f(nullptr);  // calls f(char*), as expected
    return 0;
}
```

**In general, it's recommended to use `nullptr` instead of `NULL` in C++ code, because `nullptr` doesn't have the potential for causing the unexpected behavior that `NULL` does.**