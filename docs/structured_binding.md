# Structured Binding

Structured bindings, introduced in C++17, is a feature that enables you to define multiple variables that are initialized from the members of a tuple or struct. 

Here is a simple example:

```cpp
std::pair<int, float> p = std::make_pair(1, 2.0);
auto [i, f] = p; // i is an int, f is a float
```

In the above code, `i` and `f` are now new variables whose values are taken from the elements of the pair `p`. `i` is the first member of the pair, and `f` is the second.

Here's another example using structs:

```cpp
struct MyStruct {
    int id;
    string name;
};

MyStruct s = {123, "Bob"};

auto [id, name] = s;
```

In this example, `id` is assigned the value of `s.id`, and `name` is assigned the value of `s.name`.

Structured bindings work by creating aliases (references) to the members of the aggregate object, rather than copying them. So, in the examples above, `i` and `f` are references to `p.first` and `p.second`, respectively, and `id` and `name` are references to `s.id` and `s.name`.

You can also specify the types of the variables in the structured binding, like so:

```cpp
std::pair<int, float> p = std::make_pair(1, 2.0);
auto [i, f] = p; // i is an int, f is a float
```

Finally, if you don't want to use certain values, you can ignore them using a placeholder:

```cpp
std::tuple<int, float, string> t = {1, 2.0, "example"};

auto [i, _, s] = t; // i is an int, s is a string, the float is ignored
```

In this last example, the underscore `_` is often used as a **placeholder** for values we don't care about. **Note that `_` isn't a language feature; it's just a valid variable name that by convention signals "we're not using this value".** You cannot use `auto [i, , s]` in C++. The syntax for structured bindings requires a name (or a placeholder) for every element. If you want to ignore certain values, you can use a placeholder, such as `_`.

So to sum up, structured bindings are a convenient way to unpack values from tuples, pairs, and structs. They can simplify code and make it more readable, especially when working with complex data structures.