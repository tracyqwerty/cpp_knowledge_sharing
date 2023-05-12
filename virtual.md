虚函数（Virtual Function）是 C++ 语言中实现运行时多态（动态多态）的一种机制。它们主要用于基类和派生类之间的函数调用。当基类指针或引用指向派生类对象时，可以通过虚函数调用派生类中的实现，而不是基类中的实现。这就是动态多态性，它使得我们能够在程序运行时根据对象的实际类型来调用适当的函数实现。

虚函数的声明在基类中，使用关键字 `virtual` 进行标记。当派生类覆盖（override）了基类的虚函数时，派生类中的函数会自动成为虚函数。一旦一个类有了虚函数，它的大小将增加一个指向虚函数表（vtable）的指针。虚函数表是一个包含类中虚函数地址的数组。当我们使用基类指针或引用调用虚函数时，编译器会根据指针或引用指向的对象的虚函数表来确定调用哪个函数实现。这就实现了运行时多态。

以下是一个虚函数的简单示例：

```cpp
#include <iostream>

class Base {
public:
    virtual void print() {
        std::cout << "Base class print" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override {  // 使用关键字 override 显式地表明我们要覆盖基类的虚函数
        std::cout << "Derived class print" << std::endl;
    }
};

int main() {
    Base* base_ptr = new Derived();  // 基类指针指向派生类对象
    base_ptr->print();  // 输出 "Derived class print"
    delete base_ptr;
    return 0;
}
```

注意，虚函数应该在基类中定义为公共（public）或受保护（protected），以便派生类可以访问和覆盖它们。在派生类中，如果要覆盖基类的虚函数，可以使用关键字 `override` 来显式地表明这一点。这不是强制性的，但强烈建议这么做，因为这可以帮助编译器检查派生类是否正确地覆盖了基类的虚函数。


虚函数&虚表：
https://zhuanlan.zhihu.com/p/75172640