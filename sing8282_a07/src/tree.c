/*
 -------------------------------------
 File:    tree.c
 Project: sing8282_a07
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-03-08
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "queue_stack.h"
#include "tree.h"

// Macro for comparing node heights
#define MAX_HEIGHT(a,b) ((a) > (b) ? a : b)

// time complexity = O(n)
static int numberOfNodes(TNODE *node) {
	if (node == NULL) {
		return 0;
	}
	return numberOfNodes(node->left) + numberOfNodes(node->right) + 1;
}

static int heigthOfTree(TNODE *node) {
	if (node == NULL) {
		return 0;
	}
	return MAX_HEIGHT(heigthOfTree(node->left), heigthOfTree(node->right)) + 1;
}

TPROPS tree_property(TNODE *root) {
	TPROPS stats = { numberOfNodes(root), heigthOfTree(root) };
	return stats;
}

/* Display the node data of the tree in pre-order and format "%c ".
 *
 *  @param root - pointer to the root of a tree
 */
void preorder(TNODE *root) {
	if (root != NULL) {
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}

}

/* Display the node data of the tree in in-order and format "%c".
 *
 *  @param root - pointer to the root of a tree
 */
void inorder(TNODE *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}

}

/* Display the node data of the tree in post-order and format "%c ".
 *
 *  @param root - pointer to the root of a tree
 */
void postorder(TNODE *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%c ", root->data);
	}

}

/* Display the node data of the tree in breadth-first-order and format "%c ".
 * Required to use auxiliary queue and iterative algorithm.
 *
 *  @param root - pointer to the root of a tree
 */
void bforder(TNODE *root) {
	if (root != NULL) {
		QUEUE q = { 0 };
		TNODE *p;
		enqueue(&q, root);
		while (q.front) {
			p = dequeue(&q);
			enqueue(&q, p->left);
			enqueue(&q, p->right);
			printf("%c ", p->data);
		}
		clean_queue(&q);
	}

}

/* Search by key using breadth-first-search algorithm
 * Required to use auxiliary queue and iterative algorithm.
 *
 *  @param root - pointer to the root of a tree
 *  @param key -  search key
 *
 *  @return  - the found node pointer if fount, otherwise NULL
 */
TNODE* bfs(TNODE *root, char key) {
	TNODE *p = NULL;

	if (root != NULL) {
		QUEUE q = { 0 };
		TNODE *m;
		enqueue(&q, root);
		while (q.front) {
			m = dequeue(&q);
			enqueue(&q, m->left);
			enqueue(&q, m->right);
			if (strcmp(&(m->data), &key) == 0) {
				p = m;
				break;
			}
		}
		clean_queue(&q);
	}
	return p;

}

/* Search by key using depth-first-search algorithm.
 * Required to use auxiliary queue and iterative algorithm.
 *
 *  @param root - pointer to the root of a tree
 *  @param key -  search key
 *
 *  @return  - the found node pointer if fount, otherwise NULL
 */
TNODE* dfs(TNODE *root, char key) {
	TNODE *p = NULL;

	if (root != NULL) {
		STACK sp = { 0 };
		push(&sp, root);

		TNODE *m;
		while (sp.top) {
			m = pop(&sp);
			push(&sp, m->left);
			push(&sp, m->right);

			if (strcmp(&key, &(m->data)) == 0) {
				p = m;
				break;
			}
		}
		clean_stack(&sp);
	}
	return p;

}

// The following functions are given in a7 help.

/* Create a TNODE node and sets the data to value and returns the pointer.
 * Use malloc()
 */
TNODE* new_node(char val) {
	TNODE *newNode = malloc(sizeof *newNode);
	if (newNode != NULL) {
		newNode->data = val;
		newNode->left = NULL;
		newNode->right = NULL;
	} else {
		printf("malloc failed");
	}

	return newNode;
}

/* This function cleans a tree.
 * @param rootp - pointer of pointer to the tree root
 */
void clean_tree(TNODE **rootp) {
	TNODE *p = *rootp;

	if (p) {

		if (p->left) {
			clean_tree(&(p->left));
		}

		if (p->right) {
			clean_tree(&(p->right));
		}

		free(p);

	}
	*rootp = NULL;
}

/* This function creates a new node of given value and inserts it into a tree
 * at the first available position in order of breadth-first and left to right.
 *
 * @param rootp - pointer of pointer to the tree node.
 * @param val - data for the new node.
 */
void insert_tree(TNODE **rootp, char val) {
	TNODE *newNode = new_node(val);

	if (*rootp == NULL) {
		*(rootp) = newNode;
	} else {
		QUEUE q = { 0 };
		enqueue(&q, *rootp);
		TNODE *p;
		while (q.front) {
			p = dequeue(&q);

			if (p->left == NULL) {
				p->left = newNode;
				break;
			} else {
				enqueue(&q, p->left);
			}

			if (p->right == NULL) {
				p->right = newNode;
				break;
			} else {
				enqueue(&q, p->right);
			}
		}

	}

}
