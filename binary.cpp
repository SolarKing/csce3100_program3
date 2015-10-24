#include "binary.h"
#include <cstdlib>

Node::Node(int value)
{
  data = value;
  parentNode = NULL;
}

Node::Node(int value, Node *parent) {
  data = value;
  parentNode = parent;
}

void Node::setParent(Node *parent)
{
  parentNode = parent;
}

void Node::setLeftChild(Node *left)
{
  leftChild = left;
  leftChild->parentNode = this;
}

void Node::setRightChild(Node *right)
{
  rightChild = right;
  rightChild->parentNode = this;
}

Node* Node::getParent()
{
  return parentNode;
}

Node* Node::getLeftChild()
{
  return leftChild;
}

Node* Node::getRightChild()
{
  return rightChild;
}

int Node::getValue()
{
  return data;
}

void Node::setValue(int value)
{
  data = value;
}