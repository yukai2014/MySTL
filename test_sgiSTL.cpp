//============================================================================
// Name        : test_sgiSTL.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include "./stl_list.h"
#include "./stl_vector.h"
#include "./stl_queue.h"
#include "./stl_heap_func_aux.h"

using std::for_each;
using std::cout;
using std::endl;
// using std::less;
// using std::greater;

void PrintElement(int i, int j) { std::cout << i << " "; }
void PrintElement(int i) { std::cout << i << " "; }

struct EchoElement {
  void operator()(int i, int j) { std::cout << i << " ij "; }
  void operator()(int i) { std::cout << i << "i "; }
  void operator()(float i) { std::cout << i << "f "; }
};

int main() {
  {
    list<int> l(5, 1);

    list<int> l2;
    l2.splice(l2.begin(), l, l.begin());
    std::cout << "l2:" << std::endl;
    for_each(l2.begin(), l2.end(), EchoElement());  // succeed
    std::cout << std::endl;

    for_each(l2.begin(), l2.end(),
             [](int i) { std::cout << i << " "; });  // succeed
    std::cout << std::endl;

    {
      /*  ERROR: no matching function for call to ‘for_each(list<int>::iterator,
       * list<int>::iterator, <unresolved overloaded function type>)’ */

      //      for_each(l2.begin(), l2.end(), PrintElement);
      //      std::cout << std::endl;
    }

    std::cout << "------------------" << std::endl;

    l.insert(l.begin(), 3);
    l.insert(l.end(), 1);
    l.insert(l.end(), 2);
    l.insert(l.end(), 5);
    l.sort();
    for_each(l.begin(), l.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
  }
  {
    //  queue<int, vector<int>> q; // error: ‘class vector<int>’ has no member
    //  named ‘pop_front’
    queue<int, list<int>> q;
    q.push(1);
    q.push(2);
    q.pop();
  }
  {
    srandom(time(NULL));
    vector<int> v;
    int num = 10000000;
    for (int i = 0; i < num; ++i) {
      v.push_back(random() % num);
    }
    //    v.push_back(9);
    //    v.push_back(7);
    //    v.push_back(6);
    //    v.push_back(1);
    //    v.push_back(2);
    //    v.push_back(3);
    //    v.push_back(4);
    //    for_each(v.begin(), v.end(), [](int i) { cout << i << " "; });
    //    cout << endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "perf test in random array" << std::endl;
    priority_queue<int> pq1(v.begin(), v.end());  //  232.366 ms used
    priority_queue<int, light_heap> pq2(v.begin(), v.end());  // 231.565 ms used
    //    for_each(pq1.c.begin(), pq1.c.end(), [](int i) { cout << i << " "; });
    //    cout << endl;
    std::cout << "--------------------" << std::endl
              << "perf test when construct max heap on a max heap "
              << std::endl;
    priority_queue<int> less_pq1(pq1.c.begin(),
                                 pq1.c.end());  //  231.505 ms used
    priority_queue<int, light_heap> less_pq2(pq1.c.begin(),
                                             pq1.c.end());  // 105.931 ms used

    std::cout << "--------------------" << std::endl
              << "perf test when construct min heap on a max heap "
              << std::endl;
    priority_queue<int, default_heap_func, vector<int>, greater<int>>
        greater_pq1(pq1.c.begin(), pq1.c.end());  //  192.249 ms used
    priority_queue<int, light_heap, vector<int>, greater<int>> greater_pq2(
        pq1.c.begin(),
        pq1.c.end());  // 221.712 ms used

    std::cout << "--------------------" << std::endl;
    std::cout << "correction test1" << std::endl;

    int index = 0;
    int no_match = 0;
    while (!pq1.empty() && !pq2.empty()) {
      if (pq1.top() != pq2.top()) {
        cout << "index:" << index << ", value in pq1 is:" << pq1.top()
             << ", value in pq2 is:" << pq2.top() << endl;
        if (++no_match > 20) break;
      }
      ++index;
      pq1.pop();
      pq2.pop();
    }
    if (no_match)
      cout << "total " << no_match << " pairs not matched " << endl;
    else
      cout << "all matched!" << endl;

    std::cout << "--------------------" << std::endl;
    std::cout << "correction test2" << std::endl;
    priority_queue<int> correct_pq1;
    priority_queue<int, light_heap> correct_pq2;
    num = 10000;
    index = 0;
    no_match = 0;
    for (int i = 0; i < num; ++i) {
      int key = random() % num;
      correct_pq1.push(key);
      correct_pq2.push(key);
      if (!(correct_pq1.c == correct_pq2.c)) {
        no_match++;
        break;
      }
    }
    if (no_match)
      cout << "ERROR: not matched " << endl;
    else
      cout << "all matched!" << endl;
  }
  return 0;
}
