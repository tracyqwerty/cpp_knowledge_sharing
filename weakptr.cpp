// `std::weak_ptr` 是 C++11 标准库提供的一种弱引用智能指针。它用于解决
// `std::shared_ptr` 循环引用导致的内存泄漏问题。`std::weak_ptr`
// 不会增加指向的对象的引用计数，因此它对所指向对象的生命周期不产生直接影响。当一个对象仅被
// `std::weak_ptr` 引用时，该对象仍然可以被正确地销毁和释放。

// `std::weak_ptr` 通常与 `std::shared_ptr` 配合使用。当需要访问 `std::weak_ptr`
// 所指向的对象时，可以通过 `lock()` 成员函数将其临时升级为一个
// `std::shared_ptr`。这样，在访问对象时，对象的引用计数会增加，确保对象不会被意外销毁。
// 访问完成后，临时创建的 `std::shared_ptr`
// 会离开作用域并销毁，引用计数会相应减少。

// 下面是一个 `std::weak_ptr` 的简单示例：

#include <iostream>
#include <memory>

struct Foo {
  Foo() { std::cout << "Foo::Foo()" << std::endl; }
  ~Foo() { std::cout << "Foo::~Foo()" << std::endl; }
};

int main() {
  std::shared_ptr<Foo> shared_ptr1 = std::make_shared<Foo>();
  std::weak_ptr<Foo> weak_ptr = shared_ptr1;

  {
    std::shared_ptr<Foo> shared_ptr2 =
        weak_ptr.lock();  // 通过 lock() 获取 shared_ptr
    if (shared_ptr2) {
      std::cout << "Accessing object through weak_ptr" << std::endl;
    }
  }  // shared_ptr2 离开作用域，引用计数减少

  shared_ptr1.reset();  // 手动释放 shared_ptr1 的资源

  if (weak_ptr.expired()) {
    std::cout << "Object has been destroyed" << std::endl;
  }
  return 0;
}

// 输出：
// Foo::Foo()
// Accessing object through weak_ptr
// Foo::~Foo()
// Object has been destroyed

// 在这个示例中，`std::weak_ptr` 用于临时访问 `Foo` 对象。当所有的 `std::
// shared_ptr`
// 都释放了对对象的引用时，对象会被正确地销毁。这个示例展示了如何使用 `std::
// weak_ptr` 避免循环引用和内存泄漏的问题。