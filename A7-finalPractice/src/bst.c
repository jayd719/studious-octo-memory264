/*
 -------------------------------------
 File:    bst.c
 Project: A7-finalPractice
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
#include "bst.h"

void clean_bst(BSTNODE **rootp) {

}
/* Search the BST by search key matching with data.name
 *
 * @param root - pointer to tree root.
 * @param key - string of search key
 *
 * @return - pointer to matched node if found, otherwise NULL
 */
BSTNODE* bst_search(BSTNODE *root, char *key) {
	BSTNODE *foundNode = NULL;

	BSTNODE *currNode = root;
	while (currNode != NULL) {
		if (strcmp(currNode->data.name, key) == 0) {
			return currNode;
		} else if (strcmp(key, currNode->data.name) < 0) {
			currNode = currNode->left;
		} else {
			currNode = currNode->right;
		}
	}

	return foundNode;
}

/* Insert a node of given record data into BST.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param data  -  record data for the new node.
 *
 */
static void bst_insert_aux(BSTNODE **node, RECORD data) {

	if (*node == NULL) {
		*node = new_node(data);
	} else {
		int comp = strcmp((*node)->data.name, data.name);
		if (comp > 0) {
			bst_insert_aux(&(*node)->left, data);
		} else if (comp < 0) {
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

BSTNODE* bst_delete_aux(BSTNODE *node, char *key) {
	if (node != NULL) {
		int comp = strcmp(key, node->data.name);
		if (comp < 0) {
			node->left = bst_delete_aux(node->left, key);
		} else if (comp > 0) {
			node->right = bst_delete_aux(node->right, key);
		} else {
			if (node->left == NULL && node->right == NULL) {
				return NULL;
			} else if (node->left == NULL) {
				return node->right;
			} else if (node->right == NULL) {
				return node->left;
			} else {

				BSTNODE *smallest = extract_smallest_node(&(node->right));
				node->data = smallest->data;
				node->right = bst_delete_aux(node->right, smallest->data.name);

			}

		}

	}

	return node;
}
/* Delete a node of data.name matched with given key.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param key -   key to match with data.name for deletion.
 */
void bst_delete(BSTNODE **rootp, char *key) {
	bst_delete_aux(*rootp, key);
}

// Following functions are given in a7 help.

/* This function creates BSTNODE node with given RECORD data
 * using malloc() and return the new node pointer.
 */
BSTNODE* new_node(RECORD data) {
	BSTNODE *newNode = (BSTNODE*) malloc(sizeof(BSTNODE));
	if (newNode == NULL) {
		printf("malloc Failed");
	} else {
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	return newNode;
}

/* Get and return and remove the smallest data.name node from the BST.
 *
 * @param rootp - pointer of pointer to BST root.
 * @return - node pointer of the extracted smallest node with NULL childern.
 */
BSTNODE* extract_smallest_node(BSTNODE **rootp) {
	BSTNODE *currNode = *rootp;
	while (currNode != NULL) {
		currNode = currNode->left;

	}
	return currNode;
}

