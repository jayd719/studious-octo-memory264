/*
 -------------------------------------
 File:    bst.c
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
#include <string.h>
#include "bst.h"
/* Search the BST by search key matching with data.name
 *
 * @param root - pointer to tree root.
 * @param key - string of search key
 *
 * @return - pointer to matched node if found, otherwise NULL
 */
BSTNODE* bst_search(BSTNODE *root, char *key) {
	BSTNODE *node = NULL;
	BSTNODE *curr = root;

	while (curr != NULL) {

		int comp = strcmp(key, curr->data.name);
		if (comp < 0) {
			curr = curr->left;
		} else if (comp > 0) {
			curr = curr->right;
		} else {
			return curr;
		}

	}
	return node;

}

static void bst_insert_aux(BSTNODE **node, RECORD data) {

	if (*node == NULL) {
		*node = new_node(data);
	} else {
		int comp = strcmp((data.name), (*node)->data.name);

		if (comp < 0) {
			bst_insert_aux(&(*node)->left, data);
		} else if (comp > 0) {
			bst_insert_aux(&(*node)->right, data);
		}
	}

}
/* Insert a node of given record data into BST.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param data  -  record data for the new node.
 *
 */
void bst_insert(BSTNODE **rootp, RECORD data) {
	bst_insert_aux(rootp, data);
}

static BSTNODE* bst_delete_aux(BSTNODE **node, char *key) {
	if (*node != NULL) {
		int comp = strcmp(key, (*node)->data.name);

		if (comp < 0) {
			(*node)->left = bst_delete_aux(&(*node)->left, key);
		} else if (comp > 0) {
			(*node)->right = bst_delete_aux(&(*node)->right, key);
		} else {

			if ((*node)->left == NULL && (*node)->right == NULL) {
				return NULL;
			}

			if ((*node)->left == NULL) {
				return (*node)->right;
			} else if ((*node)->right == NULL) {
				return (*node)->left;
			} else {

				BSTNODE *IS = extract_smallest_node(&(*node)->right);
				(*node)->data = IS->data;
				(*node)->right = bst_delete_aux(&(*node)->right, IS->data.name);
			}

		}

	}
	return *node;
}
/* Delete a node of data.name matched with given key.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param key -   key to match with data.name for deletion.
 */
void bst_delete(BSTNODE **rootp, char *key) {
	bst_delete_aux(rootp, key);

}

// Following functions are given in a7 help.

/* This function creates BSTNODE node with given RECORD data
 * using malloc() and return the new node pointer.
 */
BSTNODE* new_node(RECORD data) {
	BSTNODE *np = (BSTNODE*) malloc(sizeof(BSTNODE));
	if (np) {
		memcpy(np, &data, sizeof(BSTNODE));
		np->left = NULL;
		np->right = NULL;
	} else {
		printf("malloc Falied");
	}
	return np;

}

/* Get and return and remove the smallest data.name node from the BST.
 *
 * @param rootp - pointer of pointer to BST root.
 * @return - node pointer of the extracted smallest node with NULL childern.
 */
BSTNODE* extract_smallest_node(BSTNODE **rootp) {
	BSTNODE *p = *rootp, *parent = NULL;
	if (p) {
		while (p->left) {
			parent = p;
			p = p->left;
		}

		if (parent == NULL)
			*rootp = p->right;
		else
			parent->left = p->right;

		p->left = NULL;
		p->right = NULL;
	}

	return p;
}

/* This function cleans the BST passed by pointer of root pointer.
 * @param rootp - pointer to pointer of a tree node.
 */
void clean_bst(BSTNODE **rootp) {
	BSTNODE *root = *rootp;
	if (root) {
		if (root->left)
			clean_bst(&root->left);
		if (root->right)
			clean_bst(&root->right);
		free(root);
	}
	*rootp = NULL;

}
