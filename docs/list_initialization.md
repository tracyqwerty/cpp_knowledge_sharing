# List Initialization

Examples are taken from [Stanford CS106L](http://web.stanford.edu/class/cs106l/index.html#calendar).

```cpp
std::vector<int> vec{1,3,5};
std::pair<int, string> numSuffix1{1,"st"};
Student s{"Sarah", "CA", 21};
// less common/nice for primitive types, but
possible!
int x{5};
string f{"Sarah"};
```

The syntax you are seeing with the brackets, { }, is called list initialization (also known as uniform or brace initialization) and was introduced in C++11. It provides a more consistent syntax for initializing objects.

Let's look at how this works for the different examples you provided:

1. `std::vector<int> vec{1,3,5};`: This syntax is calling a constructor of std::vector that takes an initializer list as a parameter. The values inside the braces are used to create this initializer list.

2. `std::pair<int, string> numSuffix1{1,"st"};`: Similarly, this syntax is calling a constructor of std::pair that takes two parameters. The values inside the braces are used to call this constructor.

3. `Student s{"Sarah", "CA", 21};`: This syntax is calling a constructor of Student that takes three parameters. Again, the values inside the braces are used to call this constructor.

4. `int x{5};` and `string f{"Sarah"};`: These are examples of direct initialization, where the value inside the braces is used to directly initialize the variable.

List initialization has several advantages:

- It prevents narrowing conversions. For example, double x{1.3}; would be okay, but int y{1.3}; would result in a compiler error because the fractional part would be lost in the conversion from double to int.

- It can be used with auto keyword when you want the compiler to determine the type.

- It provides a consistent method of initialization for all types.

So to answer your question, the reason brackets are always acceptable is because this syntax was specifically designed to provide a consistent way to initialize objects in C++. The compiler will call the appropriate constructor based on the values inside the braces. If no suitable constructor can be found, the compiler will produce an error.