# Scope

In C++, the concept of scope refers to the region or section of code where a variable or a function can be accessed. There are mainly four types of scopes in C++:

1. **Local or Block Scope**: The variables declared inside a function or a block have block scope. These variables are also known as local variables and can't be accessed from outside the block or function. They exist only as long as the block is executing.

```cpp
void myFunction() {
    int x = 10;  // x has block scope
    // x can be accessed here
}
// x cannot be accessed here
```

2. **Function Scope**: This applies to labels (identifiers preceded by a colon). Such labels can be used as targets of `goto` statements. They can be used anywhere in the function.

```cpp
void myFunction() {
    myLabel: // has function scope
    //...
    goto myLabel;
}
```

3. **File or Global Scope**: A variable declared outside all functions or classes, can be accessed from any part of the code, even inside functions or classes, has a global scope. These variables are also known as global variables.

```cpp
int x = 10; // x has global scope
void myFunction() {
    // x can be accessed here
}
```

4. **Namespace Scope**: Variables, functions, and types defined in a namespace have namespace scope. They can be used outside the namespace by using the fully qualified name or by using a using-directive (`using namespace NamespaceName;`).

```cpp
namespace MyNamespace {
    int x = 10; // x has namespace scope
}
// x can be accessed as MyNamespace::x here
```

5. **Class Scope**: Variables, functions, and types declared inside a class have class scope. These are accessible anywhere within the class.

```cpp
class MyClass {
public:
    int x; // x has class scope
    void myMethod() {
        x = 10; // x can be accessed here
    }
};
```

In addition to these, there's also the concept of **scope resolution operator (::)**, which is used to define a function outside a class or to access a global variable inside a local scope. This operator allows us to move up the scope hierarchy.

```cpp
::x; // access the global variable x even if a local variable with the same name exists
```

Remember, understanding scopes is crucial for managing variable lifetimes and avoiding naming collisions in your programs.