# If and switch with initializers

You can now initialize a variable in an if statement or switch statement, and its scope is the respective statement.

```c++
if (auto itr = myMap.find("apple"); itr != myMap.end()) {
    // ...
}
```

