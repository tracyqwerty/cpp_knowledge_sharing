#include <bits/stdc++.h>
using namespace std;
// 禁用warning
// g++ -std=c++11 -w fun1.cpp -o fun1
signed main() {
  int* a = new int[10000000];
  for (int i = 0; i < 10000000; ++i) {
    a[i] = i;
  }
  delete a;
  a[0] = 10;
  for (int i = 0; i < 10; ++i) {
    cout << a[i] << endl;
  }
  /*
  fun1(93015,0x10f8f3600) malloc: *** error for object 0x7f8752800000: pointer
  being freed was not allocated
  fun1(93015,0x10f8f3600) malloc: *** set a breakpoint in malloc_error_break to
  debug
  */
  delete[] a;
  // for (int i = 0; i < 10; ++i) {
  //   cout << a[i] << endl;
  // }
  return 0;
}