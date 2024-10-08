/*
 -------------------------------------
 File:    avl.c
 Project: A8-finalPractice
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-04-12
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

static* createNode(RECORD data) {
	AVLNODE *node = malloc(sizeof *node);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;

}

/* Insert a node of given record data into AVL tree.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param data  - record data for the new node.
 */
void avl_insert(AVLNODE **rootp, RECORD data) {
	if (*rootp == NULL) {
		*rootp = createNode(data);
	} else {
		int comp = strcmp(data.name, (*rootp)->data.name);
		if (comp < 0) {
			avl_insert(&(*rootp)->left, data);
		} else if (comp > 0) {
			avl_insert(&(*rootp)->right, data);
		} else {
			return;
		}

		(*rootp)->height = height(*rootp);
		int balance = balance_factor(*rootp);
		if (balance > 1 && strcmp(data.name, (*rootp)->left->data.name) < 0) {
			*rootp = rotate_right(*rootp);
		}
		if (balance < -1 && strcmp(data.name, (*rootp)->right->data.name) > 0) {
			*rootp = rotate_left(*rootp);
		}
		if (balance > 1 && strcmp(data.name, (*rootp)->left->data.name) > 0) {
			(*rootp)->left = rotate_left((*rootp)->left);
			*rootp = rotate_right(*rootp);
		}
		if (balance < -1 && strcmp(data.name, (*rootp)->right->data.name) < 0) {
			(*rootp)->right = rotate_right((*rootp)->right);
			*rootp = rotate_left(*rootp);
		}

	}

}

/* Delete a node of data.name matched with given key from AVL tree.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param key -   key to match with data.name for deletion.
 */
void avl_delete(AVLNODE **rootp, char *key) {

}

/* Search AVL tree by key name
 * @param root - pointer to tree root.
 * @param key - key to match with data.name for search
 * @return - node pointer if found, otherwise NULL
 */
AVLNODE* avl_search(AVLNODE *root, char *name) {
	AVLNODE *returnNode = NULL;
	AVLNODE *currNode = root;
	while (currNode != NULL) {
		int comp = strcmp(name, currNode->data.name);
		if (comp < 0) {
			currNode = currNode->left;
		} else if (comp > 0) {
			currNode = currNode->right;
		} else {
			return currNode;
		}
	}
	return returnNode;
}

/* This function clean AVL tree.
 * @param rootp - pointer of pointer of tree root.
 */
void clean_avl(AVLNODE **rootp) {

}

/* Get the height of AVL tree
 * @param np - pointer to the root of tree
 * @return - the the height value at root.
 */

#define max(a,b) ((a)> (b)? a:b)

int height(AVLNODE *root) {
	if (root == NULL)
		return 0;
	return max(height(root->left), height(root->right)) + 1;
}

/* Return the balance factor at the given node
 * @param np - pointer to the node of tree
 * @return - the balance factor a the node,
 */
int balance_factor(AVLNODE *np) {
	return height(np->left) - height(np->right);
}

/* This function does the left rotation at a given node
 * @param np - pointer to the rotation node.
 * @return - the pointer to the replaced node.
 */
AVLNODE* rotate_left(AVLNODE *np) {
	AVLNODE *node1 = np->right;
	AVLNODE *node2 = node1->left;

	node1->left = np;
	np->right = node2;

	node1->height = height(node1);
	np->height = height(np);
	return node1;

}

/* This function does the right rotation at a given node
 * @param np - pointer to the rotation node.
 * @return - the pointer to the replaced node.
 */
AVLNODE* rotate_right(AVLNODE *root) {
	AVLNODE *node1 = root->left;
	AVLNODE *node2 = node1->right;

	node1->right = root;
	root->left = node2;
	node1->height = height(node1);
	root->height = height(root);

	return node1;

}
