// 让我们看一个使用 `std::shared_ptr` 和 `std::weak_ptr`
// 来防止内存泄漏的例子。在这个例子中，我们将创建两个相互引用的类：`Parent` 和
// `Child`。如果不使用智能指针，这种相互引用可能导致内存泄漏。

#include <iostream>
#include <memory>

class Child;

class Parent {
 public:
  Parent() { std::cout << "Parent::Parent()" << std::endl; }
  ~Parent() { std::cout << "Parent::~Parent()" << std::endl; }

  void setChild(std::shared_ptr<Child> child) { child_ = child; }

 private:
  std::shared_ptr<Child> child_;
};

class Child {
 public:
  Child() { std::cout << "Child::Child()" << std::endl; }
  ~Child() { std::cout << "Child::~Child()" << std::endl; }
  // 不能直接将 std::weak_ptr 初始化为 std::make_shared 的结果，因为
  // std::make_shared 返回一个 std::shared_ptr。将 std::shared_ptr 赋值给
  // std::weak_ptr 时，需要进行隐式转换。这是因为 std::weak_ptr
  // 的设计目的是作为对 std::shared_ptr 的补充，而不是替代。
  void setParent(std::weak_ptr<Parent> parent) { parent_ = parent; }

 private:
  std::weak_ptr<Parent> parent_;
};

int main() {
  {
    std::shared_ptr<Parent> parent = std::make_shared<Parent>();
    std::shared_ptr<Child> child = std::make_shared<Child>();

    parent->setChild(child);
    child->setParent(parent);
  }  // 当离开作用域时，所有 shared_ptr 都会被销毁，从而释放内存

  std::cout << "End of main()" << std::endl;
  return 0;
}

// 在这个例子中，我们使用 `std::shared_ptr` 来管理 `Parent` 和 `Child`
// 对象的生命周期。为了避免循环引用导致的内存泄漏，我们使用 `std::weak_ptr` 存储
// `Child` 对象对 `Parent` 对象的引用。当 `main` 函数的作用域结束时，所有的
// `std::shared_ptr`
// 都会被销毁，从而释放它们管理的内存。通过这种方式，我们避免了因循环引用导致的内存泄漏。

// `std::weak_ptr` 的滥用可能会导致以下几个问题：

// 1. 过度使用：在不需要解决循环引用问题的情况下使用 `std::weak_ptr`
// 可能会导致不必要的复杂性。在大多数情况下，`std::shared_ptr` 和
// `std::unique_ptr` 足够满足需求。

// 2. 非线程安全：`std::weak_ptr` 本身并不保证线程安全。在多线程环境下，当你从
// `std::weak_ptr` 创建一个 `std::shared_ptr` 实例时（通过调用
// `std::weak_ptr::lock()` 或者
// `std::weak_ptr::expired()`），可能存在竞争条件。例如，在检查 `std::weak_ptr`
// 是否过期并创建 `std::shared_ptr`
// 期间，其他线程可能会导致原始对象被销毁。要确保线程安全，你需要在适当的地方添加互斥锁或其他同步机制。

// 3. 潜在的空指针解引用：`std::weak_ptr`
// 不会自动延长对象的生命周期，所以在使用前需要检查它是否过期。如果不注意检查
// `std::weak_ptr` 的有效性，就可能导致空指针解引用错误。

// 4. 性能问题：由于 `std::weak_ptr`
// 需要额外的引用计数(需要维护一个单独的弱引用计数)以及从 `std::weak_ptr` 到
// `std::shared_ptr` 的转换，滥用 `std::weak_ptr` 可能会导致性能下降。

// 总之，应该根据具体需求选择合适的智能指针类型。`std::weak_ptr`
// 在解决循环引用问题时非常有用，但是在其他情况下，使用 `std::shared_ptr` 或
// `std::unique_ptr` 通常更为简单且高效。