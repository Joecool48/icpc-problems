#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
class Running_Median {
    priority_queue<int, vector<int>, greater<int> > min_priority_queue;
    priority_queue<int, vector<int>, less<int> > max_priority_queue;
    int effective_median;
  public:

    void add_number(int num) {
      if (min_priority_queue.size() == 0 && max_priority_queue.size() == 0) {
        max_priority_queue.push(num);
        effective_median = num;
      }
      else if (num > effective_median) {
        min_priority_queue.push(num);
      }
      else {
        max_priority_queue.push(num);
      }
      // Make sure the disparity between both is not more than one
      if ((int)min_priority_queue.size() - (int)max_priority_queue.size() > 1) {
        max_priority_queue.push(min_priority_queue.top());
        min_priority_queue.pop();
      }
      else if ((int)max_priority_queue.size() - (int)min_priority_queue.size() > 1) {
        min_priority_queue.push(max_priority_queue.top());
        max_priority_queue.pop();
      }
      if ((min_priority_queue.size() + max_priority_queue.size()) % 2 == 0)
        effective_median = (min_priority_queue.top() + max_priority_queue.top()) / 2;
      else
        effective_median = (min_priority_queue.size() > max_priority_queue.size()) ? min_priority_queue.top() : max_priority_queue.top();
    }
    int get_median() {
      return effective_median;
    }
};


int main() {
  int number;
  Running_Median rm;
  while (cin >> number) {
    rm.add_number(number);
    cout << rm.get_median() << endl;
  }
  return 0;
}
