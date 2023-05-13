# Two-phase Name Lookup

## Introduction

Two-phase name lookup is a concept in C++ that refers to the way names are looked up (i.e., associated with their declarations) in template code. This process is called "two-phase" because the lookup happens in two distinct phases: during the template definition and during the template instantiation.

Here's a more detailed explanation:

### **Phase 1 - At Template Definition**

This is the point when the compiler first sees and parses the template definition. The compiler will do its best to check for syntax errors and look up any names it can. However, because the exact type of template parameters isn't known at this point, **the compiler can't look up names that depend on these parameters**. These names are called dependent names. 

For example, consider the following code:

```cpp
template <typename T>
void foo(T t) {
    bar(t);
}
```

In this case, `bar(t)` is a dependent name because `bar` depends on the type `T`. The compiler can't look up `bar` at this point because it doesn't know what `T` is.

### **Phase 2 - At Template Instantiation**

This is the point when the compiler sees a use of the template with specific types (i.e., when the template is instantiated). Now that the compiler knows the exact type of the template parameters, it can look up the dependent names.

Continuing with the previous example, if we later have:

```cpp
void bar(int) { /* ... */ }

int main() {
    foo(42);  // Now the compiler knows T is int
}
```

At this point, during the instantiation of `foo(42)`, the compiler knows that `T` is `int`, so it can look up `bar(int)`. 

This two-phase process helps make templates more flexible and type-safe. But it can also lead to some tricky situations. For example, if a name is not dependent and is not found during the first phase, it's an error even if a suitable declaration is available at the point of instantiation.

**This is also why you sometimes need to use the `typename` keyword to tell the compiler that a dependent name refers to a type, or the `template` keyword to tell the compiler that a dependent name refers to a template.** The compiler can't figure this out on its own during the first phase of lookup because it doesn't know the exact types of the template parameters.

As a side note, not all compilers strictly adhere to two-phase name lookup due to historical reasons and the complexity of implementing it fully. For example, older versions of GCC use a more relaxed model. However, modern and standards-conforming C++ compilers, like recent versions of GCC, Clang, and MSVC, do support two-phase name lookup.

## Scenarios

### 1. Call a member function of a base class template from a derived class template

When programming with templates in C++, you sometimes encounter a situation where you need to call a function that is a member of a base class template from a derived class template. The Clang compiler can flag an issue here with dependent names. You can solve this by using the `this` pointer and adding the `template` keyword when accessing the `setEnd` member function to remove ambiguity:

```cpp
template<typename T>
class SmallVectorTemplateCommon {
protected:
  void setEnd(T *P);
};

template<typename T>
class SmallVectorImpl : public SmallVectorTemplateCommon<T> {
public:
  void push_back(const T& value) {
    // ...
    this->template setEnd(this->end() + 1);
  }
};
```

In this case, the base class is dependent on the template parameter. Hence, the compiler needs to be explicitly informed that you are accessing a member of the base class, not something else. By using `this->template` syntax, you are explicitly telling the compiler that you are accessing the `setEnd` member function in the base class template `SmallVectorTemplateCommon<T>`. This removes the ambiguity and allows the Clang compiler to accept your code.

In the statement `this->template setEnd(this->end() + 1);`:

1. `this` pointer: Refers to the current object. Here, it points to the instance of the `SmallVectorImpl` class.
2. `->` operator: Used to access the members of an object pointed to by a pointer.
3. `template` keyword: This is a hint telling the compiler that the member you're accessing is a template member from a base class that depends on the template parameter (in this case, a member of `SmallVectorTemplateCommon<T>`). This is necessary because, in this context, the compiler can't tell if `setEnd` is a template member or something else, so you need to use the `template` keyword to remove this ambiguity.
4. `setEnd(this->end() + 1);`: Calls the `setEnd` member function, passing `this->end() + 1` as the argument.

So, the whole expression is telling the compiler to call the `setEnd` member function of the base class template `SmallVectorTemplateCommon<T>` of the current object, passing `this->end() + 1` as the argument.

This syntax is primarily used in template programming, especially when dealing with derived class templates where the base class depends on the template parameter. It allows the compiler to correctly identify and call the member functions of the base class template.

When you have a multi-level class inheritance structure, things get a bit more complex, but the basic concept remains the same. Consider the following class hierarchy:

```cpp
template <typename T>
class Base {
protected:
  void someMethod(T value) { /* ... */ }
};

template <typename T>
class Derived1 : public Base<T> {
  // ...
};

template <typename T>
class Derived2 : public Derived1<T> {
public:
  void anotherMethod() {
    // ...
    this->template someMethod(42);  // Here, 'this->template' might be needed
  }
};
```

In this example, `Derived2` is derived from `Derived1`, and `Derived1` is derived from `Base`. If you need to access the `someMethod` member function of `Base` from `Derived2`, you might need to use `this->template` syntax to remove ambiguity because `someMethod` is a template member of a base class that depends on the template parameter.

In the `anotherMethod` member function of the `Derived2` class, the call to `someMethod` might look like this:

```cpp
this->template someMethod(42);
```

This ensures that the compiler correctly identifies and calls the `someMethod` member function in the `Base<T>` class. It's worth noting that if the compiler can resolve the code correctly without the `template` keyword, then you can forgo the `this->template` syntax. However, in certain situations, using the `this->template` syntax can prevent compile-time errors. 

This concept is known as the "two-phase name lookup" in C++. In the first phase, non-dependent names are looked up and bound to their declarations when the template is initially parsed. In the second phase, dependent names are looked up when the template is instantiated. The `this->template` syntax is needed when you have dependent names (i.e., names that depend on the template parameters) that the compiler cannot resolve during the first phase.

### 2.Name is not dependent and is not found during the first phase

```cpp
template <typename T>
void foo(T t) {
    baz(t);  // baz is a non-dependent name
}

void baz(int) { /* ... */ }

int main() {
    foo(42);  // template instantiation
}
```

In this code, `baz(t)` inside the template function `foo` is a non-dependent name because `baz` doesn't depend on the template parameter `T`. During the first phase of name lookup, when the compiler sees the template definition, it tries to look up `baz` but can't find it, because `baz` is declared after `foo`.

Even though a suitable declaration for `baz` is available at the point of template instantiation in `main`, it's too late. The compiler has already decided that `baz` doesn't exist during the first phase of lookup, and it reports an error.

If you want this code to work, you need to make sure that `baz` is declared before `foo`:

```cpp
void baz(int) { /* ... */ }

template <typename T>
void foo(T t) {
    baz(t);  // baz is a non-dependent name
}

int main() {
    foo(42);  // template instantiation
}
```

Now `baz` is declared before `foo`, so the compiler can find `baz` during the first phase of name lookup, and the code compiles successfully.

## Reference

https://stackoverflow.com/questions/39667599/template-inheritance-there-are-no-arguments-that-depend-on-a-template-parameter/39667832#39667832