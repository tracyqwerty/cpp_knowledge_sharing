# decltype

`decltype` is a keyword in C++ that queries the type of an expression. It's used to extract the type of a given expression, and that type can then be used in other parts of your code. This can be particularly useful in template programming or when using auto-typed variables.

Here's a brief overview of how `decltype` can be used:

1. **Determining the Type of an Expression**: You can use `decltype` to deduce the type of an expression without actually evaluating the expression.

   ```cpp
   int x = 10;
   decltype(x) y = 20; // y has the same type as x, i.e., int
   ```

2. **In Function Templates**: If you're writing a generic function and want to determine the type of an expression within that function (e.g., the result of adding two templated types), you can use `decltype`.

   ```cpp
   template <typename T, typename U>
   auto add(T t, U u) -> decltype(t + u) {
       return t + u; // return type is deduced from the type of t + u
   }
   ```

3. **In Lambda Functions**: In your original code snippet, `decltype` is used to define a custom comparator for a priority queue. It allows the compiler to understand the type of the lambda function without explicitly stating it.

   ```cpp
   auto cmp = [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
       return a.first > b.first;
   };
   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> heap;
   ```

   Here, `decltype(cmp)` extracts the type of the lambda function, and that type is then used as the third template argument for the priority queue.

In essence, `decltype` serves as a bridge that allows you to tell the compiler, "use the type of this expression." It can make code more maintainable and easier to write, particularly in generic or templated contexts.s