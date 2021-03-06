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
  if (left != NULL)
  {
    leftChild->parentNode = this;
  }
}

void Node::setRightChild(Node *right)
{
  rightChild = right;
  if (right != NULL)
  {
    rightChild->parentNode = this;
  }

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

Node* deleteNode_A(Node* root, int data)
{
  // std::cout << root << std::endl;
  if (root == NULL)
  {
    // std::cout << "debug: there was no child found..." << std::endl;
    return root;
  }

  else if (data < root->getValue())
  {
    // std::cout << "debug: setting left child" << std::endl;
    root->setLeftChild(deleteNode_A(root->getLeftChild(), data));
  }

  else if (data > root->getValue())
  {
    // std::cout << "debug: setting right child" << std::endl;
    root->setRightChild(deleteNode_A(root->getRightChild(), data));
  }

  else
  {
    if (root->getLeftChild() == NULL && root->getRightChild() == NULL)
    {
      // std::cout << "c1" << std::endl;
      delete root;
      return NULL;
    }

    else if (root->getLeftChild() == NULL)
    {
      // std::cout << "c2" << std::endl;
      Node *temp = root;
      root = root->getRightChild();
      delete temp;
    }

    else if (root->getRightChild() == NULL)
    {
      // std::cout << "c3" << std::endl;
      Node *temp = root;
      root = root->getLeftChild();
      delete temp;
    }

    else
    {
      // std::cout << "c4" << std::endl;
      Node *temp = findMin(root->getRightChild());
      root->setValue(temp->getValue());
      root->setRightChild(deleteNode_A(root->getRightChild(), temp->getValue()));
    }
  }
  // std::cout << "reached return statement" << std::endl;
  return root;
}

Node* deleteNode_B(Node* root, int data)
{
  // std::cout << root << std::endl;
  if (root == NULL)
  {
    // std::cout << "debug: there was no child found..." << std::endl;
    return root;
  }

  else if (data < root->getValue())
  {
    // std::cout << "debug: setting left child" << std::endl;
    root->setLeftChild(deleteNode_B(root->getLeftChild(), data));
  }

  else if (data > root->getValue())
  {
    // std::cout << "debug: setting right child" << std::endl;
    root->setRightChild(deleteNode_B(root->getRightChild(), data));
  }

  else
  {
    if (root->getLeftChild() == NULL && root->getRightChild() == NULL)
    {
      // std::cout << "c1" << std::endl;
      delete root;
      return NULL;
    }

    else if (root->getLeftChild() == NULL)
    {
      // std::cout << "c2" << std::endl;
      Node *temp = root;
      root = root->getRightChild();
      delete temp;
    }

    else if (root->getRightChild() == NULL)
    {
      // std::cout << "c3" << std::endl;
      Node *temp = root;
      root = root->getLeftChild();
      delete temp;
    }

    else
    {
      // std::cout << "c4" << std::endl;
      Node *temp = findMax(root->getLeftChild());
      root->setValue(temp->getValue());
      root->setLeftChild(deleteNode_B(root->getLeftChild(), temp->getValue()));
    }
  }
  // std::cout << "reached return statement" << std::endl;
  return root;
}

Node* deleteNode_C(Node* root, int data)
{
  if (rand() % 1 == 0) { // do method A

  }
  // std::cout << root << std::endl;
  if (root == NULL)
  {
    // std::cout << "debug: there was no child found..." << std::endl;
    return root;
  }

  else if (data < root->getValue())
  {
    // std::cout << "debug: setting left child" << std::endl;
    root->setLeftChild(deleteNode_C(root->getLeftChild(), data));
  }

  else if (data > root->getValue())
  {
    // std::cout << "debug: setting right child" << std::endl;
    root->setRightChild(deleteNode_C(root->getRightChild(), data));
  }

  else
  {
    if (root->getLeftChild() == NULL && root->getRightChild() == NULL)
    {
      // std::cout << "c1" << std::endl;
      delete root;
      return NULL;
    }

    else if (root->getLeftChild() == NULL)
    {
      // std::cout << "c2" << std::endl;
      Node *temp = root;
      root = root->getRightChild();
      delete temp;
    }

    else if (root->getRightChild() == NULL)
    {
      // std::cout << "c3" << std::endl;
      Node *temp = root;
      root = root->getLeftChild();
      delete temp;
    }

    else
    {
      srand(time(NULL));
      int random = rand() % 10;
      // std::cout << "Randeom = " << random << std::endl;
      if (random < 5) { // do MIN
        Node *temp = findMin(root->getRightChild());
        root->setValue(temp->getValue());
        root->setRightChild(deleteNode_A(root->getRightChild(), temp->getValue()));
      } else { // do MAX
        Node *temp = findMax(root->getLeftChild());
        root->setValue(temp->getValue());
        root->setLeftChild(deleteNode_B(root->getLeftChild(), temp->getValue()));
      }

    }
  }
  // std::cout << "reached return statement" << std::endl;
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


Node* findMax(Node* node)
{
  if (node->getRightChild() == NULL)
  {
    return node;
  }
  else
  {
    return findMax(node->getRightChild());
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
      return insertNode(child, parent->getRightChild());
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
      return insertNode(child, parent->getLeftChild());
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
      return insertNode(child, parent->getLeftChild());
    }
  }
}