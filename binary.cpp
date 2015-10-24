#include "binary.h"
#include <cstdlib>
#include <iostream>

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

Node* deleteNode(Node* root, int data)
{
  if (root == NULL)
  {
    std::cout << "debug: there was no child found..." << std::endl;
    return root;
  }

  else if (data < root->getValue())
  {
    root->setLeftChild(deleteNode(root->getLeftChild(), data)); 
  }

  else if (data > root->getValue())
  {
    root->setRightChild(deleteNode(root->getRightChild(), data)); 
  }

  else
  {
    if (root->getLeftChild() == NULL && root->getRightChild() == NULL)
    {
      delete root;
      root = NULL;
    } 

    else if (root->getLeftChild() == NULL)
    {
      Node *temp = root;
      root = root->getRightChild();
      delete temp;
    }

    else if (root->getRightChild() == NULL)
    {
      Node *temp = root;
      root = root->getLeftChild();
      delete temp;
    }

    else
    {
      Node *temp = findMin(root->getRightChild());
      root->setValue(temp->getValue());
      root->setRightChild(deleteNode(root->getRightChild(), temp->getValue()));
    }
  }
  return root;
}

Node* findMin(Node* node)
{
  if (node->getLeftChild() == NULL)
  {
    return node;
  }
  else
  {
    return findMin(node->getLeftChild());
  }
}

int insertNode(Node* child, Node* parent)
{
  if (parent->getValue() < child->getValue())
  {
    if (parent->getRightChild() == NULL)
    {
      parent->setRightChild(child);
      return 1;
    } 
    else
    {
      return insertNode(child, parent->getRightChild);
    }
  }
  else if (parent->getValue() < child->getValue())
  {
    if (parent->getLeftChild() == NULL)
    {
      parent->setLeftChild(child);
      return -1;
    } 
    else
    {
      return insertNode(child, parent->getLeftChild);
    }
  }
  else
  {
    if (parent->getLeftChild() == NULL)
    {
      parent->setLeftChild(child);
      return 0;
    } 
    else
    {
      return insertNode(child, parent->getLeftChild);
    }
  }
}