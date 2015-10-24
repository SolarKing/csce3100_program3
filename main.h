#ifndef MAIN_H
#define MAIN_H

#include <iostream>

// https://www.youtube.com/watch?v=gcULXE7ViZw

// Todo
//
// find/search for node
// insert node
// delete node
// edit node

Node* deleteNode(Node* root, int data);
/**
 * To delete a (leaf) node from bst
 * 1) remove refeference of node from its parent so it will be detatched
 *     from the tree
 * 2) wipe the node object from memory
 */

/**
 * To delete a non-leaf (one child) node from bst
 * 1) link this.parent to this.child
 */

/**
 * To delete a non-leaf (two child) node from bst
 * 1) Find minimum in right subtree
 * 2) copy the value in targetted node
 * 3) delete duplicate from right subtree
 */



#endif