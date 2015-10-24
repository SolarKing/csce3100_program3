#ifndef BINARY_H
#define BINARY_H

class Node
{
private:
  int data;
  Node *parentNode;
  Node *leftChild;
  Node *rightChild;
public:
  Node(int);
  Node(int, Node*);

  void setParent(Node*);
  void setLeftChild(Node*);
  void setRightChild(Node*);

  Node* getParent();
  Node* getLeftChild();
  Node* getRightChild();

  int getValue();
};

#endif