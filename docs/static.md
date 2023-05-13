# static

In C++, the `static` keyword has a few different meanings depending on the context in which it's used. Here are the main usages:

## **Static Local Variables**

If `static` is used on a variable inside a function, that variable is initialized only once, and its value persists between function calls. This is unlike a typical local variable, which is reinitialized every time the function is called. Here's an example:

```cpp
void myFunction() {
    static int x = 0;
    x++;
    std::cout << x << std::endl;
}

int main() {
    myFunction();  // prints "1"
    myFunction();  // prints "2"
    return 0;
}
```

## **Static Class Members** 

`static` can also be used inside a class definition. If a member variable is declared as `static`, **there is only one instance of that variable shared by all objects of the class.** **A `static` member function can be called even without an instance of the class and can only access `static` member variables.** Here's an example:

```cpp
class MyClass {
public:
    static int x;

    static void incrementX() {
        x++;
    }
};

int MyClass::x = 0;  // definition of the static member outside the class

int main() {
    MyClass::incrementX();  // call static member function
    std::cout << MyClass::x << std::endl;  // prints "1"
    return 0;
}
```

## **Static Global Variables and Functions** 

**If `static` is used on a global variable or function, that variable or function is only visible within the file it's declared in, rather than being visible to the entire program.** This is a way to create "private" global variables and functions.

```cpp
// File: myfile.cpp

static int myVariable = 0;  // can only be accessed within myfile.cpp

static void myFunction() {  // can only be accessed within myfile.cpp
    myVariable++;
}
```

These are the most common uses of `static` in C++. **The keyword is essentially about defining the lifespan and visibility of a variable or function.**