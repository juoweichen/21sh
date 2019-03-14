#ifndef PRINT_BTREE_H
# define PRINT_BTREE_H

#include "astree.h"

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
// void printBinaryTree(struct s_node * t); //print a binary tree

void printBinaryTree(t_astnode * t); //print a binary tree

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif