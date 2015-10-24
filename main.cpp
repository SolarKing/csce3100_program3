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

#include "main.h"
#include "binary.h"

int main(int argc, char const *argv[])
{
  std::cout << "Hello World" << std::endl;
  Node *root = new Node(0);
  std::cout << root.getValue() << std::endl;
  root.setLeftChild(new Node(1));
  std::cout << root.getLeftChild()->getParent()->getValue() << std::endl;

  return 0;
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
			root->getValue()
		}
	}
	return root;
}