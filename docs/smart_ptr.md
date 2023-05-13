# std::unique_ptr, std::shared_ptr & std::weak_ptr

C++11 introduced smart pointers to help manage dynamically allocated memory resources and prevent memory leaks. There are three types of smart pointers in C++11: `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`.

## std::unique_ptr

This is a smart pointer which exclusively owns the object it points to. It provides strict ownership, i.e., once a `unique_ptr` takes ownership of an object, no other pointer can own the same object. The object will be automatically destroyed when the `unique_ptr` goes out of scope or is explicitly reset.

```cpp
std::unique_ptr<int> ptr1(new int(5)); // ptr1 now owns the memory
std::unique_ptr<int> ptr2 = ptr1; // Error! Can't copy unique_ptr
std::unique_ptr<int> ptr3 = std::move(ptr1); // OK, ownership transferred to ptr3
```

## std::shared_ptr

A `shared_ptr` is a reference counting smart pointer which can be shared among multiple pointers. The object to which `shared_ptr` points will only be destroyed when the last `shared_ptr` pointing to it is out of scope or reset. This is useful in scenarios where you need multiple owners, such as in data structures like linked lists and trees.

```cpp
std::shared_ptr<int> ptr1(new int(5)); // ptr1 now owns the memory
std::shared_ptr<int> ptr2 = ptr1; // OK, both now own the memory
// Both pointers are destroyed, and then the memory is freed
```

## std::weak_ptr

A `weak_ptr` is a smart pointer that holds a non-owning ("weak") reference to an object that is managed by `std::shared_ptr`. It must be converted to `std::shared_ptr` in order to access the referenced object. `weak_ptr` models temporary ownership: when an object needs to be accessed only if it exists, and it may be deleted at any time by someone else. `std::weak_ptr` is used to break circular references of `std::shared_ptr`.

```cpp
std::shared_ptr<int> ptr1(new int(5));
std::weak_ptr<int> weak1 = ptr1; // weak1 is pointing to memory owned by ptr1
// To access the memory weak1 points to, we must create a shared_ptr from it
if (std::shared_ptr<int> ptr2 = weak1.lock()) {
    // Now ptr2 owns the memory and we can safely use it
}
```

**In most cases, you should prefer using smart pointers over raw pointers.** They're a powerful tool that, when used correctly, can help you write safer and more efficient code. However, they're not a silver bullet, and there are still cases where raw pointers or `std::unique_ptr` with custom deleters are more appropriate. 

Remember, `std::unique_ptr` and `std::shared_ptr` will call `delete` on the owned memory when they're destroyed. **If you allocated the memory with something other than `new`, or if you're managing a resource other than memory, you'll need to provide a custom deleter.**

## Example

`std::weak_ptr` is primarily used to avoid circular references that `std::shared_ptr` could create. Let's illustrate this with an example. Assume you have a class `Person` that can have children and also has a pointer to their mother:

```cpp
class Person {
public:
    std::string name;
    std::shared_ptr<Person> mother;
    std::vector<std::shared_ptr<Person>> children;
    
    Person(const std::string &name) : name(name) {}

    ~Person() {
        std::cout << "delete " << name << "\n";
    }
};
```
Now, let's create a family:

```cpp
std::shared_ptr<Person> mother(new Person("mother"));
std::shared_ptr<Person> child(new Person("child"));

mother->children.push_back(child);
child->mother = mother;
```

**In this setup, we have a circular reference.** The `mother` has a `shared_ptr` to the `child` and vice versa. So when the `shared_ptr` of `mother` and `child` go out of scope, **the destructors of `mother` and `child` will not be called because their use count will not be zero.** This is because each of them is still being referenced by a `shared_ptr` (from their relatives), causing a memory leak.

Now, let's use `std::weak_ptr` to solve this issue:

```cpp
class Person {
public:
    std::string name;
    std::weak_ptr<Person> mother;
    std::vector<std::shared_ptr<Person>> children;
    
    Person(const std::string &name) : name(name) {}

    ~Person() {
        std::cout << "delete " << name << "\n";
    }
};
```

By changing `std::shared_ptr<Person> mother` to `std::weak_ptr<Person> mother`, we break the circular reference. Now, when the `shared_ptr` of `mother` and `child` go out of scope, their destructors will be called and their memory will be released, because `std::weak_ptr` doesn't contribute to the reference count.

This is the main use case of `std::weak_ptr`: it allows you to hold a reference to an object managed by a `std::shared_ptr`, but without increasing the reference count. This is particularly useful when you want to avoid circular references.