/**
* Name: Charles Bido
* Course: CSCE 3110
* Assignment: Program 3 - Binary Search Trees
* Due Date: October 24, 2015, 11:59 PM
*/

/**
* Write a program to evaluate empirically the following strategies for
* removing nodes with two children:
* a. Replace with the largest node, X, in TL and recursively remove X.
* b. Alternately replace with the largest node in TL and the smallest node
* in TR, and recursively remove the appropriate node.
* c. Replace with either the largest node in TL or the smallest node in
* TR (recursively removing the appropriate node), making the choice randomly.
*/

#include <iostream>
#include "binary.h"
#include <ctime>

void printTree(Node* node);

int main(int argc, char const *argv[])
{
  std::clock_t start;

  Node *rootB = new Node(12);

  // populating the binary tree
  int input[13] = {5,15,3,7,13,17, 20,1,9,14,18,8,11};
  for (int i = 0; i < 13; i++)
  {
    insertNode(new Node(input[i]), rootB);
  }

  std::cout << "\n\nMETHOD B" << std::endl;
  std::cout << "\nBefore deletion:" << std::endl;
  printTree(rootB);
  std::cout << "\nDeleting..." << std::endl;

  start=std::clock();

  deleteNode_B(rootB, 9);
  deleteNode_B(rootB, 15);
  deleteNode_B(rootB, 12);

  std::clock_t end = std::clock() - start;

  std::cout << "\nAfter deletion:" << std::endl;
  printTree(rootB);

  std::cout << "\n\nDeleting 9, 15, and 12 ran for ";
  std::cout << (end) / (double)(CLOCKS_PER_SEC / 1000);
  std::cout << " ms (" << end << " clicks)" << std::endl;


  return 0;
}

void printTree(Node* node)
{
  std::cout << "Subtree " << node->getValue() << " => ";
  if (node->getLeftChild() == NULL)
  {
    std::cout << "(NULL, ";
  }
  else
  {
    std::cout << "(" << node->getLeftChild()->getValue() << ", ";
  }
  if (node->getRightChild() == NULL)
  {
    std::cout << "NULL)" << std::endl;
  }
  else
  {
    std::cout << node->getRightChild()->getValue() << ")" << std::endl;
  }
  if (node->getLeftChild() != NULL)
  {
    printTree(node->getLeftChild());
  }
  if (node->getRightChild() != NULL)
  {
    printTree(node->getRightChild());
  }
}