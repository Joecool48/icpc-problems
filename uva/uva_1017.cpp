#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<queue>
// Algorithm to find the min cost in addall
unsigned minimum(const std::vector<unsigned> & integers) {
    unsigned min_cost = 0;
    std::priority_queue<unsigned, std::vector<unsigned>, std::greater<unsigned> > q;
    unsigned integer1, integer2, integer_add;

    for (unsigned i : integers) {
      q.push(i);
    }
    while (q.size() > 1)  {
        // Pop 2, add them and record the cost, then push back and heapify
        integer1 = q.top();
        q.pop();
        integer2 = q.top();
        q.pop();
        integer_add = integer1 + integer2;
        min_cost += integer_add;
        q.push(integer_add);
    }
    return min_cost;
}

int main() {
    unsigned N;
    std::string input;
    do {
        scanf("%d", &N);
        if (N == 0) break;
        int i;
        std::vector<unsigned> integers;

        while (N > 0) {
          scanf("%d", &i);
          integers.push_back(i);
          N--;
        }
        unsigned res = minimum(integers);
        printf("%d\n", res);

    } while(true);
    return 0;
}
