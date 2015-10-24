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

void printTree(Node* node);

int main(int argc, char const *argv[])
{
  std::cout << "Hello World" << std::endl;

  Node *root = new Node(12);

  
  int input[14] = {5,7,15,17,3,7,13,20,1,9,14,18,8,11};

  for (int i = 0; i < 14; i++)
  {
  	insertNode(new Node(input[i]), root);
  }

  std::cout << root->getValue() << std::endl;

  if (root->getLeftChild() == NULL) {
  	std::cout << "Left Child is NULL" << std::endl;
  }
  else
  {
  	std::cout << "Left Child is: " << root->getLeftChild()->getValue() << std::endl;
  }

  if (root->getRightChild() == NULL) {
  	std::cout << "Right Child is NULL" << std::endl;
  }
  else
  {
  	std::cout << "Right Child is: " << root->getRightChild()->getValue() << std::endl;
  }

  printTree(root);


  Node *temp = deleteNode_A(root, 15);
  std::cout << "Deleted node with value of " << temp->getValue() << std::endl;
  
  printTree(root);


  return 0;
}

void printTree(Node* node)
{
	std::cout << "Parent value is: " << node->getValue();
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