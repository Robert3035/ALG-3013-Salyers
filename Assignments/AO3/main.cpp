/*****************************************************************************
*                    
*  Author:           Robert Salyers
*  Email:            roberthayssalyers@gmail.com
*  Label:            AO3
*  Title:            BST Delete
*  Course:           CMPS 3013
*  Semester:         Spring 2025
* 
*  Description:
*        This program will initialize and traverse a binary search tree to
*        find minimum values, insert, print, and delete nodes.
* 
* 
*  Files:            main.cpp
*****************************************************************************/
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

/**
 * BST
 * 
 * Description:
 *      BST 
 * 
 * Public Methods:
 *      - void insert 
 *      - void deleteNode
 *      - void print
 * 
 * Private Methods:
 *      - void _insert 
 *      - void _print
 *      - Node* _delete
 * 
 * Usage: 
 * 
 *      - use insert to add nodes with values to the tree
 *      - use print to show everything currently in the tree
 *      - use delete to take a node out of the tree
 */
class Bst {
private:
  Node *root;

  /**
   * private : _insert:
   *      Insert a node in the right place in the tree
   * 
   * Params:
   *      [Node*] &sub_root - pointer to a node
   * 
   * Returns
   *      [void]
   */
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

  /**
   * private : _print:
   *      Print the tree
   * 
   * Params:
   *      [Node*] root - pointer to the root node
   * 
   * Returns
   *      [void]
   */
  void _print(Node *root) {
    if (!root) {
      return;
    }

    _print(root->right);
    cout << root->data << " ";
    _print(root->left);
  }

/**
 * private : _delete:
 *      Delete a node from the tree
 * 
 * Params:
 *      [Node*] root - pointer to the root node
 *      [int]   x    - value of node to delete
 * 
 * Returns
 *      [Node*]     - to call recursively
 */
  Node* _delete(Node* root, int x) {
    if (root == nullptr) return root;

    //Search for the node to be deleted
    if (x < root->data) {
      root->left = _delete(root->left, x);
    } else if (x > root->data) {
      root->right = _delete(root->right, x);
    } else {
      //If the node is found
      if (root->left == nullptr) {
        Node* temp = root->right;
        delete root;
        return temp;
      } else if (root->right == nullptr) {
        Node* temp = root->left;
        delete root;
        return temp;
      }

      //If the node has two children, find the inorder successor
      Node* temp = _minValueNode(root->right);
      root->data = temp->data;
      root->right = _delete(root->right, temp->data);
    }
    return root;
  }

/**
 * private : _minValueNode:
 *      Find minimum value
 * 
 * Params:
 *      [Node*] node - pointer to a node
 * 
 * Returns
 *      [Node*]     - minimum node
 */
  Node* _minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
      current = current->left;
    }
    return current;
  }

public:
  Bst() { root = nullptr; }

/**
 * public : insert:
 *      Calls private _insert
 * 
 * Params:
 *      [int] x - Value to insert
 * 
 * Returns
 *      [void]
 */
  void insert(int x) {
    _insert(root, x);
  }

/**
 * public : deleteNode:
 *      Calls private _deleteNode
 * 
 * Params:
 *      [int] x - Value to delete
 * 
 * Returns
 *      [void]
 */
  void deleteNode(int x) {
    root = _delete(root, x);
  }

/**
 * public : print:
 *      Calls private _print
 * 
 * Params:
 *      none
 * 
 * Returns
 *      [void]
 */
  void print() {
    _print(root);
  }
};

int main() {
  Bst tree;
  tree.insert(8);
  tree.insert(3);
  tree.insert(1);
  tree.insert(11);
  tree.insert(7);
  tree.insert(15);

  cout << "Original tree: ";
  tree.print();
  cout << endl;

  //Delete a node
  tree.deleteNode(3); //Delete node with value 3
  cout << "After deleting 3: ";
  tree.print();
  cout << endl;

  tree.deleteNode(15); //Delete node with value 15
  cout << "After deleting 15: ";
  tree.print();
  cout << endl;

  tree.deleteNode(8); //Delete root node with value 8
  cout << "After deleting 8: ";
  tree.print();
  cout << endl;

  return 0;
}
