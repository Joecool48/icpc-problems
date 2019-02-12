#include<iostream>

template <typename T>
class Node {
public:
  Node * next;
  T data;
  Node(T d) {
    this->data = d;
  }
};


class LetterNumber {

  Node<char> * head;

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
    return s.str();
  }
  void add(char num) {
    Node * current = head;
    if (head == nullptr) {
      head = new Node(num);
    }
  }
}
