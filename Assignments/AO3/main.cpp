#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int x) {
    data = x;
    left = right = nullptr;
  }
};

class Bst {
private:
  Node *root;
  void _insert(Node *&sub_root, int x) {
    if (sub_root == nullptr) {
      sub_root = new Node(x);
    } else {
      if (x < sub_root->data) {
        _insert(sub_root->left, x);
      } else {
        _insert(sub_root->right, x);
      }
    }
  }
  void _print(Node *root) {
    if (!root) {
      return;
    }

    _print(root->right);
    cout << root->data << " ";
    _print(root->left);

  }

public:
  Bst() { root = nullptr; }
  void insert(int x) {
    _insert(root, x);
  }
  bool search() { return 0; }
  void print() { _print(root); }
};

int main() {
  Bst tree;
  tree.insert(8);
  tree.insert(3);
  tree.insert(1);
  tree.insert(11);
  tree.insert(7);
  tree.insert(15);
  // for(int i=0;i<1000;i++){
  //    tree.insert(rand()%1000);
  // }
  tree.print();
}
