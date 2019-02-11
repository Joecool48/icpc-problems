#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
// Algorithm to find the min cost in addall
unsigned minimum(std::vector<unsigned> integers) {
    unsigned min_cost = 0;
    std::make_heap(integers.begin(), integers.end(), std::greater<unsigned>());
    unsigned integer1, integer2, integer_add;
 
    while (integers.size() > 1)  {
        // Pop 2, add them and record the cost, then push back and heapify
        integer1 = integers.front();
        std::pop_heap(integers.begin(), integers.end());
        integers.pop_back();
        integer2 = integers.front();
        std::pop_heap(integers.begin(), integers.end());
        integers.pop_back();
        integer_add = integer1 + integer2;
        min_cost += integer_add;
        integers.push_back(integer_add);
        std::push_heap(integers.begin(), integers.end());
    }
    return min_cost;
}

std::vector<std::string> split(std::string & str, char delim) {
    std::stringstream s;
    std::vector<std::string> results;
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (*it == ' ') {
            results.push_back(s.str());
            s.str("");
        }
        else s << *it;
    }
    if (s.str().size() != 0) results.push_back(s.str());
    return results;
}

int main() {
    unsigned N;
    std::string input;
    do {
        std::getline(std::cin, input);
        N = atoi(input.c_str());
        if (N == 0) break;
        // Go through rest of the line
        std::getline(std::cin, input);
        std::vector<unsigned> integers;
        for (std::string str : split(input, ' ')) {
            integers.push_back(atoi(str.c_str()));
        }
        unsigned res = minimum(integers);
        std::cout << res << std::endl;

    } while(N != 0);
    return 0;
}
