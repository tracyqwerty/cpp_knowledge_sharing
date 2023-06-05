# Cpp Knowledge Sharing
Cpp related knowledge, powered by ChatGPT4. Contents are all in English. >w< Enjoy!

## Keywords

* [`virtual`](docs/virtual.md)
* [`operator`](docs/operator.md)
* [`const & constexpr`](docs/const&constexpr.md)
* [`noexept`](docs/noexept.md)
* [`volatile`](docs/volatile.md)
* [`extern`](docs/extern.md)
* [`static`](docs/static.md)
* [`null`](docs/null.md)
* [`explicit`](docs/explicit.md)
* [`static/dynamic/const/reinterpret_cast`](./docs/cast.md)
* [`inline`](docs/inline.md)


## STL

- [`std::function`](docs/function.md)
- [`std::bind`](docs/bind.md)
- [`std::move`](docs/move.md)
- [`std::unique_ptr, std::shared_ptr & std::weak_ptr`](docs/smart_ptr.md)

## Template

Just some basic ideas. It doesn't cover Template Metaprogramming. 

For that please refer to: [CppTemplateTutorial](https://github.com/wuye9036/CppTemplateTutorial)

* [`template`](docs/template.md)
* [`specialization & partial specialization`](docs/specialization.md)
* [`two-phase name lookup`](docs/two_phase.md)

## Features and Techniques

- [`overload & override`](./docs/overload&ride.md)
- [`lambda expressions`](./docs/lambda.md)
- [`lvalue & rvalue`](docs/l&rvalue.md)
- [`move semantics`](docs/move_semantics.md)
- [`perfect forwarding`](docs/perfect_forwarding.md)
- [`memory management`](docs/memory.md)
- [`Resource Acquisition Is Initialization (RAII) & Last In, First Out (LIFO)`](docs/RAII&LIFO.md)
- [`Return Value Optimization (RVO) and Named Return Value Optimization (NRVO)`](docs/RVO&NRVO.md)
- [`overload resolution`](docs/overload_resolution.md)
- [`scope`](docs/scope.md)

## Interesting Questions

* [Why virtual member function can not be used with template?](ques/q1.md)
* [`vector<string> v = str_split("1,2,3");` The memory will be where, why?](ques/q2.md)
* [Can Constructors and Destructors be virtual?](ques/q3.md)
* [What is the difference between header files `#include <X.h>` and `#include <cX>`?](ques/q4.md)

## Courses Recommended

### [CS106L](CS106L)

This is the official website: http://web.stanford.edu/class/cs106l/

## References

https://learn.microsoft.com/en-us/cpp/cpp

https://github.com/Light-City/CPlusPlusThings



## TODO

IEEE 754

https://learn.microsoft.com/en-us/cpp/cpp/keywords-cpp?view=msvc-170

for_each, the default traversal algorithm (along with range-based for loops). 

transform, for not-in-place modification of container elements

find_if, the default search algorithm.



reading lastly left here：

https://learn.microsoft.com/en-us/cpp/cpp/temporary-objects?view=msvc-170
