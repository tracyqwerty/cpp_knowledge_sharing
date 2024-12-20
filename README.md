# Cpp Knowledge Sharing
Cpp related knowledge, powered by ChatGPT4. Contents are all in English. >w< Enjoy!

## Keywords

* [`virtual`](docs/virtual.md)
* [`static`](docs/static.md)
* [`inline`](docs/inline.md)
* [`static/dynamic/const/reinterpret_cast`](./docs/cast.md)
* [`const & constexpr`](docs/const&constexpr.md)
* [`NULL & nullptr`](docs/null.md)
* [`extern`](docs/extern.md)
* [`using`](docs/using.md)
* [`typedef`](docs/typedef.md)
* [`operator`](docs/operator.md)
* [`noexept`](docs/noexept.md)
* [`volatile`](docs/volatile.md)
* [`explicit`](docs/explicit.md)
* [`decltype`](docs/decltype.md)
* [`mutable`](docs/mutable.md)


## STL 

These are very powerful when trying to write efficient programs. Know their existence and use them when in handy, and this will save us lots of efforts. 

Note that here's just the tip of the iceberg. For more information, you may refer to here: https://en.cppreference.com

- [`std::function`](docs/function.md)
- [`std::bind`](docs/bind.md)
- [`std::unique_ptr, std::shared_ptr, std::weak_ptr & std::make_unique, std::make_shared`](docs/smart_ptr.md)
- [`std::back_inserter`](docs/back_inserter.md)
- [`std::copy`](docs/copy.md)
- [`std::transform`](docs/tramsform.md)
- [`std::accumulate`](docs/accumulate.md) 
- [`std::partial_sum`](docs/partial_sum.md)
- [`std::sort`](docs/sort.md)
- [`std::partial_sort`](docs/partial_sort.md)
- [`std::nth_element`](docs/nth_element.md)
- [`std::adjacent_difference`](docs/adjacent_diff.md)
- [`std::inner_product`](docs/inner_product.md)
- [`std::itoa`](docs/itoa.md)
- [`std::initializer_list`](docs/initializer_list.md)
- [`std::for_each`](docs/for_each.md)
- [`std::all_of(c++11)`](docs/all_of.md) 
- [`std::any_of(c++11)`](docs/any_of.md) 
- [`std::none_of(c++11)`](docs/none_of.md) 
- [`std::copy_n`](docs/copy_n.md)
- [`std::find, std::find_if, std::find_if_not`](docs/find.md) 
- [`std::partition, std::stable_partition, std::partition_copy`](docs/partition.md)
- [`std::min, std::max, std::minmax`](docs/min_max.md) 
- [`std::min_element, std::max_element, std::minmax_element`](docs/min_max_element.md) 
- [`std::lower_bound, std::upper_bound`](docs/lower_bound.md) 
- [`std::is_heap, std::is_heap_until`](docs/is_heap.md)
- [`std::is_sorted, std::is_sorted_until`](docs/is_sorted.md)

for mathematic functions in  <cmath>,  see: https://en.cppreference.com/w/cpp/header/cmath

### std::execution

* [`std::execution::seq, std::execution::unseq, std::execution::par, std::execution::par_unseq`](docs/execution.md)













[`std::move`](docs/move.md)





* [`priority_queue`](docs/priority_queue.md)

- 

- [**find_end**](https://cplusplus.com/reference/algorithm/find_end/)

  Find last subsequence in range (function template)

- [**find_first_of**](https://cplusplus.com/reference/algorithm/find_first_of/)

  Find element from set in range (function template)

- [**adjacent_find**](https://cplusplus.com/reference/algorithm/adjacent_find/)

  Find equal adjacent elements in range (function template)

- [**count**](https://cplusplus.com/reference/algorithm/count/)

  Count appearances of value in range (function template)

- [`count_if`](docs/count_if.md) Return number of elements in range satisfying condition (function template)

- [**mismatch**](https://cplusplus.com/reference/algorithm/mismatch/)

  Return first position where two ranges differ (function template)

- [**equal**](https://cplusplus.com/reference/algorithm/equal/)

  Test whether the elements in two ranges are equal (function template)

- [**is_permutation**](https://cplusplus.com/reference/algorithm/is_permutation/)

  Test whether range is permutation of another (function template)

- [**search**](https://cplusplus.com/reference/algorithm/search/)

  Search range for subsequence (function template)

- [**search_n**](https://cplusplus.com/reference/algorithm/search_n/)

  Search range for elements (function template)

- [**copy_if**](https://cplusplus.com/reference/algorithm/copy_if/)

- [**copy_backward**](https://cplusplus.com/reference/algorithm/copy_backward/)

- [**move_backward**](https://cplusplus.com/reference/algorithm/move_backward/)

  Move range of elements backward (function template)

- [**swap**](https://cplusplus.com/reference/algorithm/swap/)

  Exchange values of two objects (function template)

- [**swap_ranges**](https://cplusplus.com/reference/algorithm/swap_ranges/)

  Exchange values of two ranges (function template)

- [**iter_swap**](https://cplusplus.com/reference/algorithm/iter_swap/)

  Exchange values of objects pointed to by two iterators (function template)

- [**replace**](https://cplusplus.com/reference/algorithm/replace/)

  Replace value in range (function template)

- [**replace_if**](https://cplusplus.com/reference/algorithm/replace_if/)

  Replace values in range (function template)

- [**replace_copy**](https://cplusplus.com/reference/algorithm/replace_copy/)

  Copy range replacing value (function template)

- [**replace_copy_if**](https://cplusplus.com/reference/algorithm/replace_copy_if/)

  Copy range replacing value (function template)

- [**fill**](https://cplusplus.com/reference/algorithm/fill/)

  Fill range with value (function template)

- [**fill_n**](https://cplusplus.com/reference/algorithm/fill_n/)

  Fill sequence with value (function template)

- [**generate**](https://cplusplus.com/reference/algorithm/generate/)

  Generate values for range with function (function template)

- [**generate_n**](https://cplusplus.com/reference/algorithm/generate_n/)

  Generate values for sequence with function (function template)

- [**remove**](https://cplusplus.com/reference/algorithm/remove/)

  Remove value from range (function template)

- [**remove_if**](https://cplusplus.com/reference/algorithm/remove_if/)

  Remove elements from range (function template)

- [**remove_copy**](https://cplusplus.com/reference/algorithm/remove_copy/)

  Copy range removing value (function template)

- [**remove_copy_if**](https://cplusplus.com/reference/algorithm/remove_copy_if/)

  Copy range removing values (function template)

- [`unique`](docs/unique.md) Remove consecutive duplicates in range (function template)

- [**unique_copy**](https://cplusplus.com/reference/algorithm/unique_copy/)

  Copy range removing duplicates (function template)

- [`reverse`](docs/reverse.md) Reverse range (function template)

- [**reverse_copy**](https://cplusplus.com/reference/algorithm/reverse_copy/)

  Copy range reversed (function template)

- [**rotate**](https://cplusplus.com/reference/algorithm/rotate/)

  Rotate left the elements in range (function template)

- [**rotate_copy**](https://cplusplus.com/reference/algorithm/rotate_copy/)

  Copy range rotated left (function template)

- [**random_shuffle**](https://cplusplus.com/reference/algorithm/random_shuffle/)

  Randomly rearrange elements in range (function template)

- [**shuffle**](https://cplusplus.com/reference/algorithm/shuffle/)

  Randomly rearrange elements in range using generator (function template)

- [**is_partitioned**](https://cplusplus.com/reference/algorithm/is_partitioned/)

  Test whether range is partitioned (function template)

- [**partition_point**](https://cplusplus.com/reference/algorithm/partition_point/)

  Get partition point (function template)

- [`equal_range`](docs/equal_range.md) Get subrange of equal elements (function template)

- [`binary_search`](docs/binary_search.md) 

- [**merge**](https://cplusplus.com/reference/algorithm/merge/)

  Merge sorted ranges (function template)

- [**inplace_merge**](https://cplusplus.com/reference/algorithm/inplace_merge/)

  Merge consecutive sorted ranges (function template)

- [**includes**](https://cplusplus.com/reference/algorithm/includes/)

  Test whether sorted range includes another sorted range (function template)

- [**set_union**](https://cplusplus.com/reference/algorithm/set_union/)

  Union of two sorted ranges (function template)

- [**set_intersection**](https://cplusplus.com/reference/algorithm/set_intersection/)

  Intersection of two sorted ranges (function template)

- [**set_difference**](https://cplusplus.com/reference/algorithm/set_difference/)

  Difference of two sorted ranges (function template)

- [**set_symmetric_difference**](https://cplusplus.com/reference/algorithm/set_symmetric_difference/)

  Symmetric difference of two sorted ranges (function template)

- [**lexicographical_compare**](https://cplusplus.com/reference/algorithm/lexicographical_compare/)

  Lexicographical less-than comparison (function template)

- [**next_permutation**](https://cplusplus.com/reference/algorithm/next_permutation/)

  Transform range to next permutation (function template)

- [**prev_permutation**](https://cplusplus.com/reference/algorithm/prev_permutation/)

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
- [`list initialization`](docs/list_initialization.md)
- [`structured binding(c++17)`](docs/structured_binding.md)
- [`if and switch with initializers`](docs/if_and_switch.md)
- [template aliasing](docs/template_aliasing.md)
- [private/public/protected inheritance](docs/inheritance.md)
- [initializer list and uniform initialization](docs/initialize.md)

## Interesting Questions

* [Why virtual member function can not be used with template?](ques/q1.md)
* [`vector<string> v = str_split("1,2,3");` The memory will be where, why?](ques/q2.md)
* [Can Constructors and Destructors be virtual?](ques/q3.md)
* [What is the difference between header files `#include <X.h>` and `#include <cX>`?](ques/q4.md)
* [Why do we have to include vector.cpp in vector.h since it's a template class?](ques/q5.md)
* [Is there a reason to use std::distance() over iterator::operator-()?](ques/q6.md)
* [What is the difference between 'typedef' and 'using' in C++11?](ques/q7.md)
* [What is string::npos in C++?](ques/q8.md)
* [Can a static member function be const? ](ques/q9.md)
* [What is a lambda expression under the hood?](ques/q10.md)

## Courses

### CS106L

Official website: http://web.stanford.edu/class/cs106l/

[And also my implementation](courses/CS106L)

CS106L includes just basic C++ knowledge. >w<

Think the mannual's great. Haven't read it though(.

### MPCS 51044&5

Official website: https://mpcs-courses.cs.uchicago.edu/2022-23/spring/courses/mpcs-51045-1

Advanced cpp course from Uchicago.

Password: [mac login]

## References

https://learn.microsoft.com/en-us/cpp/cpp

https://github.com/Light-City/CPlusPlusThings

https://en.cppreference.com

https://github.com/wuye9036/CppTemplateTutorial

## TODO

IEEE 754

https://learn.microsoft.com/en-us/cpp/cpp/keywords-cpp?view=msvc-170

for_each, the default traversal algorithm (along with range-based for loops). 

find_if, the default search algorithm.

functors

reading lastly left here：

https://learn.microsoft.com/en-us/cpp/cpp/temporary-objects?view=msvc-170

STL: group functions by headers

pod:https://zhuanlan.zhihu.com/p/45545035
