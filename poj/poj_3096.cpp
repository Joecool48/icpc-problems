#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<sstream>
#include<set>

using namespace std;

bool isSurprising(const string & str) {
  int D = 1;
  stringstream stream;
  set<string> strings;
  while (D < str.length()) {
    for (int i = 0; i < str.length() - D; i += 1) {
      stream << str[i] << str[i + D];
      if (strings.find(stream.str()) != strings.end()) return false;
      strings.insert(stream.str());
      stream.str(""); // clear stream
    }
    strings = set<string>();
    D++;
  }
  return true;
}

int main() {
  string in;
  do {
    cin >> in;
    if (in == "*") break;
    bool surp = isSurprising(in);
    if (surp) cout << in << " is surprising." << endl;
    else cout << in << " is NOT surprising." << endl;
  } while (in != "*");
}
