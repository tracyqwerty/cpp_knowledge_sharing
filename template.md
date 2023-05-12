https://zhuanlan.zhihu.com/p/346400616
C++ 模板 全特化与偏特化
模板
模板定义：模板就是实现代码重用机制的一种工具，它可以实现类型参数化，即把类型定义为参数， 从而实现了真正的代码可重用性。模版可以分为两类，一个是函数模版，另外一个是类模版。

大白话：C++是一门强类型语言，编写一段通用的逻辑，可以把任意类型的变量传进去处理，通过把通用逻辑设计为模板，摆脱了类型的限制，极大地提升了代码的可重用性。

**模板实例化：**模板定义本身不参与编译，而是编译器根据模板的用户使用模板时提供的类型参数生成代码，再进 行编译。用户提供不同的类型参数，就会实例化出不同的代码。

类模板
类模板描述了一组相关的类或数据类型，它们只能通过类型来区分：整数值、指向（或引用）具有全局链接的变量的指针、其他的组合。类模板尤其适用于描述通用但类型安全的数据结构。

类模板使用：

template <类型形式参数>
    class 类名
    {
     //类声明体;
    };
    
    template <类型形式参数>
    返回类型 类名 <类型> :: 成员函数名1(形式参数)
    {
     //成员函数定义体;
    }

    ... ...
    template <类型形式参数>
    返回类型 类名 <类型> :: 函数名N(形式参数)
    {
  //成员函数定义体;
    }
案例：

#include <iostream>

using namespace std;

template<class T>
class Compare
{
public:
 bool equal(T a,T b);
};

template<class T>
bool Compare<T>::equal(T a, T b)
{
 return a == b;
}

int main()
{
 Compare<int>C;
 C.equal(1,2);
 return 0;
}
类模板全特化
所谓模板全特化限定死模板实现的具体类型；

比如上述这个例子，我们比较int类型这种还可以，但是比较float这种类型就不行，这时候就需要进行模板特化；

#include <iostream>

using namespace std;

template<class T>
class Compare
{
public:
 bool equal(T a,T b);
};

template<class T>
bool Compare<T>::equal(T a, T b)
{
 return a == b;
}

//模板全特化
template<>
class Compare<float>
{
public:
 bool equal(float a, float b);
};

bool  Compare<float>::equal(float a, float b)
{
 return std::abs(a - b) < 10e-3;
}

int main()
{
 Compare<int>C;
 cout<<C.equal(1,2)<<endl;
 Compare<float>C2;
 cout<<C2.equal(1.001,1.001)<<endl;
 return 0;
}
类模板偏特化
偏特化是指提供另一份template定义式，而其本身仍为templatized，这是针对于template参数更进一步的条件限制所设计出来的一个特化版本。也就是如果这个模板有多个类型，那么只限定其中的一部分;

#include <iostream>

using namespace std;

template<class T1,class T2>
class Test
{
public:
 Test(T1 a, T2 b):_a(a),_b(b)
 {
  cout << "模板化" << endl;
 }
private:
 T1 _a;
 T2 _b;
};

//模板全特化
template<>
class Test<int,int>
{
public:
 Test(int a, int b) :_a(a), _b(b)
 {
  cout << "模板全特化" << endl;
 }
private:
 int _a;
 int _b;
};

//模板偏特化
template<class T>
class Test<int,T>
{
public:
 Test(int a, T b) :_a(a), _b(b)
 {
  cout << "模板偏特化" << endl;
 }
private:
 int _a;
 T _b;
};



int main()
{
 Test<double, double> t1(1.01, 1.01);
 Test<int, int> t2(1, 1);
 Test<int, char*> t3(1, "111");
 return 0;
}
函数模板
函数模板一般定义：

template <类型形式参数>      //类型形式参数即此格式：<typename  形式参数>  或 <class 形式参数>
返回类型  函数名 （形式参数）
{
 //函数定义体;
}

案例：

#include <iostream>

using namespace std;

//普通模板
template<class T1,class T2>
bool Compare(T1 a, T2 b)
{
 return a == b;
}


int main()
{
 cout << Compare(1, 2) << endl;
 return 0;
}
函数模板特化
函数模板特化和类模板特化本质是一样的，是对模板参数的特殊化处理：

#include <iostream>

using namespace std;

//普通模板
template<class T1,class T2>
bool Compare(T1 a, T2 b)
{
 cout << "普通模板" << endl;
 return a == b;
}

//函数模板特化
template<>
bool Compare(const char* a, const char* b)
{
 cout << "函数模板特化" << endl;
 return strcmp(a,b) == 0;
}

int main()
{
 cout << Compare(1, 2) << endl;
 cout << Compare("ab","ab") << endl;
 return 0;
}
总结
1、函数模板只有特化，没有偏特化；

2、模板、模板的特化和模板的偏特化都存在的情况下，编译器在编译阶段进行匹配，优先特殊的；

3、模板函数不能是虚函数；因为每个包含虚函数的类具有一个virtual table,包含该类的所有虚函数的地址，因此vtable的大小是确定的。模板只有被使用时才会被实例化，将其声明为虚函数会使vtable的大小不确定。所以，成员函数模板不能为虚函数。