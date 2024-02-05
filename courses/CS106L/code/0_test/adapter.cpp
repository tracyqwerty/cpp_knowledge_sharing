#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;
signed main() {
  // queue is acturally an adapter
  queue<int, deque<int>> queue_deque;
  queue<int, list<int>> queue_list;
  queue<int, vector<int>> queue_vector;

  // time calculate
  chrono::steady_clock::time_point start = chrono::steady_clock::now();
  for (int i = 0; i < 10; i++) {
    queue_deque.push(i);
  }
  //   for (int i = 0; i < 10; i++) {
  //     queue_deque.pop();
  //   }
  chrono::steady_clock::time_point end = chrono::steady_clock::now();
  cout << "queue_deque time: "
       << chrono::duration_cast<chrono::microseconds>(end - start).count()
       << "us" << endl;

  start = chrono::steady_clock::now();
  for (int i = 0; i < 10; i++) {
    queue_list.push(i);
  }
  //   for (int i = 0; i < 10; i++) {
  //     queue_list.pop();
  //   }
  end = chrono::steady_clock::now();
  cout << "queue_list time: "
       << chrono::duration_cast<chrono::microseconds>(end - start).count()
       << "us" << endl;

  start = chrono::steady_clock::now();
  for (int i = 0; i < 10; i++) {
    queue_vector.push(i);
  }
  //   for (int i = 0; i < 10; i++) {
  //     queue_vector.pop();
  //   }
  end = chrono::steady_clock::now();
  cout << "queue_vector time: "
       << chrono::duration_cast<chrono::microseconds>(end - start).count()
       << "us" << endl;

  return 0;
}