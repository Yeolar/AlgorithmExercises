/*
 * Copyright (C) 2017, Yeolar
 */

#include <sstream>

namespace ae {

template <class T>
struct BinaryTreeNode {
  T value;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
};

template <class T>
BinaryTreeNode<T>* createTreeNode(const T& value,
                                  BinaryTreeNode<T>* left,
                                  BinaryTreeNode<T>* right) {
  BinaryTreeNode<T>* node = new BinaryTreeNode<T>();
  node->value = value;
  node->left = left;
  node->right = right;
  return node;
}

template <class T>
void destroyTree(BinaryTreeNode<T>* node) {
  if (node != nullptr) {
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
    node = nullptr;
  }
}

template <class T>
void printTree(BinaryTreeNode<T>* node, std::stringstream& out) {
  if (node != nullptr) {
    out << node->value << " ";
    printTree(node->left, out);
    printTree(node->right, out);
  }
}

} // namespace ae
