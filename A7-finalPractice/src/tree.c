///*
// -------------------------------------
// File:    tree.c
// Project: A7-finalPractice
// file description
// -------------------------------------
// Author:  Jashandeep Singh
// ID:      169018282
// Email:   sing8282@mylaurier.ca
// Version  2024-04-12
// -------------------------------------
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#include "queue_stack.h"
//#include "tree.h"
//
//#define MAX1(a,b) ((a)> (b) ? a:b)
//static int tree_order(TNODE *node) {
//	if (node == NULL) {
//		return 0;
//	} else {
//		return tree_order(node->left) + tree_order(node->right) + 1;
//	}
//}
//
//static int tree_height(TNODE *node) {
//	if (node == NULL) {
//		return 0;
//	} else {
//		return MAX1(tree_height(node->left), tree_height(node->right)) + 1;
//	}
//
//}
///* Compute and return the TPROPS value of a tree.
// * @param root - pointer to the root of a tree
// * @return - number of nodes and height in TPROPS type.
// */
//TPROPS tree_property(TNODE *root) {
//	TPROPS stats = { 0 };
//	stats.height = tree_height(root);
//	stats.order = tree_order(root);
//	return stats;
//}
//
///* Display the node data of the tree in pre-order and format "%c ".
// *
// *  @param root - pointer to the root of a tree
// */
//void preorder(TNODE *root) {
//	if (root == NULL)
//		return;
//
//	printf("%c", root->data);
//	preorder(root->left);
//	preorder(root->right);
//	return;
//
//}
//
///* Display the node data of the tree in in-order and format "%c".
// *
// *  @param root - pointer to the root of a tree
// */
//void inorder(TNODE *root) {
//	if (root == NULL)
//		return;
//	inorder(root->left);
//	printf("%c", root->data);
//	inorder(root->right);
//
//}
//
///* Display the node data of the tree in post-order and format "%c ".
// *
// *  @param root - pointer to the root of a tree
// */
//void postorder(TNODE *root) {
//	if (root == NULL)
//		return;
//	postorder(root->left);
//	postorder(root->right);
//	printf("%c", root->data);
//}
//
///* Display the node data of the tree in breadth-first-order and format "%c ".
// * Required to use auxiliary queue and iterative algorithm.
// *
// *  @param root - pointer to the root of a tree
// */
//void bforder(TNODE *root) {
//	QUEUE q = { 0 };
//	enqueue(&q, root);
//	while (q.front) {
//		TNODE *currNode = dequeue(&q);
//		printf("%c", currNode->data);
//
//		if (currNode->left != NULL) {
//			enqueue(&q, currNode->left);
//		}
//
//		if (currNode->right != NULL) {
//			enqueue(&q, currNode->right);
//		}
//
//	}
//
//	clean_queue(&q);
//}
//
///* Search by key using breadth-first-search algorithm
// * Required to use auxiliary queue and iterative algorithm.
// *
// *  @param root - pointer to the root of a tree
// *  @param key -  search key
// *
// *  @return  - the found node pointer if fount, otherwise NULL
// */
//TNODE* bfs(TNODE *root, char key) {
//	TNODE *foundNode = NULL;
//
//	QUEUE q = { 0 };
//	enqueue(&q, root);
//	while (q.front) {
//		TNODE *currNode = dequeue(&q);
//		if (currNode->data == key) {
//			return currNode;
//		}
//
//		if (currNode->left != NULL) {
//			enqueue(&q, currNode->left);
//		}
//
//		if (currNode->right != NULL) {
//			enqueue(&q, currNode->right);
//		}
//
//	}
//
//	return foundNode;
//
//}
//
///* Search by key using depth-first-search algorithm.
// * Required to use auxiliary queue and iterative algorithm.
// *
// *  @param root - pointer to the root of a tree
// *  @param key -  search key
// *
// *  @return  - the found node pointer if fount, otherwise NULL
// */
//TNODE* dfs(TNODE *root, char key) {
//	TNODE *foundNode = NULL;
//	TNODE *currNode;
//	STACK s = { 0 };
//	push(&s, root);
//
//	while (s.top) {
//		currNode = pop(&s);
//		if (currNode->data == key) {
//			return currNode;
//		}
//
//		if (currNode->left != NULL) {
//			push(&s, currNode->left);
//		}
//
//		if (currNode->right != NULL) {
//			push(&s, currNode->right);
//		}
//
//	}
//
//	return foundNode;
//
//}
//
//// The following functions are given in a7 help.
//
///* Create a TNODE node and sets the data to value and returns the pointer.
// * Use malloc()
// */
//TNODE* new_node(char val) {
//	TNODE *newNode = (TNODE*) malloc(sizeof(TNODE));
//	if (newNode == NULL) {
//		printf("malloc Failed");
//		return 0;
//	}
//
//	newNode->data = val;
//	newNode->left = NULL;
//	newNode->right = NULL;
//	return newNode;
//
//}
//
///* This function cleans a tree.
// * @param rootp - pointer of pointer to the tree root
// */
//void clean_tree(TNODE **rootp) {
//
//}
//
///* This function creates a new node of given value and inserts it into a tree
// * at the first available position in order of breadth-first and left to right.
// *
// * @param rootp - pointer of pointer to the tree node.
// * @param val - data for the new node.
// */
//
//void insert_tree(TNODE **rootp, char val) {
//	if (*rootp == NULL) {
//		*rootp = new_node(val);
//	} else {
//		QUEUE q = { 0 };
//		enqueue(&q, *rootp);
//		while (q.front) {
//			TNODE *currNode = dequeue(&q);
//			if (currNode->left == NULL) {
//				currNode->left = new_node(val);
//				break;
//			} else {
//				enqueue(&q, currNode->left);
//			}
//
//			if (currNode->right == NULL) {
//				currNode->right = new_node(val);
//				break;
//			} else {
//				enqueue(&q, currNode->right);
//			}
//		}
//
//	}
//
//}
