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

int main(int argc, char const *argv[])
{
  std::cout << "Hello World" << std::endl;

  Node *root = new Node(12);

  
  int input[13] = {5,7,17,3,7,13,20,1,9,14,18,8,11};

  for (int i = 0; i < 13; i++)
  {
  	insertNode(new Node(i), root);
  }
  

  return 0;
}

