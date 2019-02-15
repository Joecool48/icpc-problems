#include<stdlib.h>
#include<stdio.h>
#include<stdexcept>
#include<string>
#include<sstream>
#include<iostream>

// V is value type
template <typename K, typename V>
class Treap {
  class Node {
  public:
    Node * left;
    Node * right;
    Node * parent;
    K key;
    V value;
    uint64_t priority;
    Node() : left(nullptr), right(nullptr), parent(nullptr) {}
    Node(K k, V val) : key(key), value(val), left(nullptr), right(nullptr), parent(nullptr) {}
  };
  template <typename E>
  void throw_exception(std::string msg, std::string file, int line) {
    std::stringstream stream;
    stream << msg << " at " << file << ":" << line << std::endl;
    throw E(stream.str());
  }

  Node * root;

public:
  Treap() : root(nullptr) {}

  void rotateRight(Node * u) {
    Node * w = u->left;
    if (w == nullptr) return;
    w->parent = u->parent;
    if (w->parent != nullptr) {
    if (w->parent->left == u) {
        w->parent->left = w;
    } else {
        w->parent->right = w;
    }
  }
  u->left = w->right;
  if (u->left != nullptr) {
    u->left->parent = u;
  }
  u->parent = w;
  w->right = u;
  if (u == this->root) { this->root = w; this->root->parent = nullptr; }
  }
  void rotateLeft(Node * u) {
    Node * w = u->right;
    if (w == nullptr) return;
    w->parent = u->parent;
    if (w->parent != nullptr) {
        if (w->parent->left == u) {
            w->parent->left = w;
        } else {
            w->parent->right = w;
        }
    }
    u->right = w->left;
    if (u->right != nullptr) {
      u->right->parent = u;
    }
    u->parent = w;
    w->left = u;
    if (u == this->root) { this->root = w; this->root->parent = nullptr; }
  }

  uint64_t genTreapRand() {
    return (long) rand();
  }

  void propigateUp(Node * current) {
    // While we havent reached the top and the heap property isnt satisfied...
    while (current != nullptr && current->parent->priority > current->priority) {
      // If I'm the right child, rotateLeft
      if (current->parent->right == current) rotateLeft(current);
      else rotateRight(current);
      current = current->parent;
    }
    // If the root was reached change it out for the new top guy
    if (current->parent == nullptr) this->root = current;
  }

  void add(K key, V value) {
    Node * currentNode = root;
    Node * insertNode = new Node(key, value);
    insertNode->priority = genTreapRand();
    if (this->root == nullptr) {
      this->root = insertNode;
      this->root->parent = nullptr;
      return;
    }
    while(true) {
      if (key < currentNode->key) {
        if (currentNode->left == nullptr) {
          currentNode->left = insertNode;
          insertNode->parent = currentNode;
          break;
        }
        else {
          currentNode = currentNode->left;
        }
      }
      else {
        if (currentNode->right == nullptr) {
          currentNode->right = insertNode;
          insertNode->parent = currentNode;
          break;
        }
        else {
          currentNode = currentNode->right;
        }
      }
    }
    propigateUp(insertNode);
  }

  V find(K key) {
    Node * current = this->root;
    while (current != nullptr) {
      if (current->key == key) return current->value;
      if (key > current->key) {
        current = current->right;
        std::cout << "Go right" << std::endl;
      }

      else {
        current = current->left;
        std::cout << "Go left" << std::endl;
      }
    }
    if (current == nullptr) return V();
    return current->value;
  }

};

int main() {
  Treap<long, long> t;
  long i = 0;
  while (i < 10000) {
    t.add(i, i);
    std::cout << t.find(i) << std::endl;
    i++;
  }
}
