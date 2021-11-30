#include<bits/stdc++.h>
using namespace std;

class minHeap {
public:
  vector<int> heap;

  void push(int x) {
    heap.push_back(x);
    int now = (int) heap.size() - 1;

    while (now > 0 && heap[now] < heap[(now - 1) / 2]) 
      swap(heap[(now - 1) / 2], heap[now]), now = (now - 1) / 2;
  }

  void pop() {
    heap[0] = heap.back();
    heap.pop_back();
    int now = 0;

    while (1) {
      int c1 = 2 * now + 1, c2 = 2 * now + 2;
      
      if (c1 < (int) heap.size() && c2 < (int) heap.size()) {
        if (heap[c1] < heap[c2] && heap[now] > heap[c1]) swap(heap[now], heap[c1]), now = c1;
        else if (heap[now] > heap[c2]) swap(heap[now], heap[c2]), now = c2;
        else break;
      } else if (c1 < (int) heap.size() && heap[now] > heap[c1]) {
        swap(heap[now], heap[c1]), now = c1;
      } else {
        break;
      }
    }
  }

  int top() {
    assert(!heap.empty());
    return heap[0];
  }
};
