#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;


template <typename T>
class Node {
public:
  Node<T> * next;
  T data;
  Node(T d) {
    this->data = d;
    this->next = nullptr;
  }
};


class LetterNumber {

  Node<char> * head;
public:
  LetterNumber() {
    head = nullptr;
  }

  string stringify() {
    stringstream s;
    Node<char> * current = head;
    while (current != nullptr)  {
      s << current->data;
      current = current->next;
    }
    string str = s.str();
    reverse(str.begin(), str.end());
    return str;
  }
  bool same() {
    if (head == nullptr) return false;
    char letter = head->data;
    Node<char> * current = head->next;
    while (current != nullptr)  {
      if (current->data >= letter) return true;
      letter = current->data;
      current = current->next;
    }
    return false;
  }

  void increment() {
    Node<char> * current = head;
    if (head == nullptr) {
      head = new Node<char>('a');
    }
    else {
      bool carry = 0;
      current->data += 1;
      do {
        current->data += carry;
        carry = 0;
        if (current->data > 'z') {
          carry = 1;
          current->data = 'a';
        }
        if (carry != 0 && current->next == nullptr) {
          current->next = new Node<char>('a');
          break;
        }
        else {
          current = current->next;
        }
      } while (carry != 0 && current != nullptr);
    }
    if (same()) increment();
  }
};


int main() {
  LetterNumber ln;
  ln.increment(); // sets to 'a'
  unordered_map<string, unsigned> m;
  for (unsigned i = 1; i <= 83681; i++) {
    m[ln.stringify()] = i;
    ln.increment();
  }

  string in;
  while (cin >> in) {
    if (m.find(in) != m.end()) cout << m[in];
    else cout << 0;
  }
  return 0;
}
