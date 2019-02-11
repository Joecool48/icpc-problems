#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<queue>

using namespace std;

void print_res(priority_queue<int, vector<int>, less<int> > & q) {
  int total = 0;
  int time = 1;
  while (!q.empty()) {
    total += 2 * pow(q.top(), time);
    q.pop();
    time++;
  }
  if (total > 5000000) cout << "Too expensive" << endl;
  else cout << total << endl;
}

int main() {
  priority_queue<int, vector<int>, less<int> > q;
  int c;
  while (true) {
    do {
      cin >> c;
      if (c <= 0) break;
      q.push(c);
    } while (c != 0);
    if (c < 0) break;
    print_res(q);
  }
  return 0;
}
