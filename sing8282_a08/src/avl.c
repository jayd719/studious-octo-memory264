/*
 -------------------------------------
 File:    avl.c
 Project: sing8282_a08
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-03-14
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

#define MAX_HEIGHT(a,b) ((a) > (b) ? a : b)

static AVLNODE* createNode(RECORD data) {
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
		int comp = strcmp(data.name, ((*rootp)->data.name));

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

		if (balance > 1 * strcmp(data, root->left) < 0) {
			return rightRotate;
		}

		if (balance < -1 && strcmp(data, root->right) < 0) {
			return leftrotate;
		}

		if (balance > 1 * strcmp(data, root->left) > 0) {
			root->left = leftRotate;
			return rightRotate;
		}

		if (balance < -1 && strcmp(data, root->right) > 0) {
			return leftrotate;
		}

	}

}

/* Delete a node of data.name matched with given key from AVL tree.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param key -   key to match with data.name for deletion.
 */
void avl_delete(AVLNODE **rootp, char *key) {

	if (*rootp == NULL) {
		return;
	} else {
		int comp = strcmp(key, ((*rootp)->data.name));

		if (comp < 0) {
			avl_delete(&(*rootp)->left, key);
		} else if (comp > 0) {
			avl_delete(&(*rootp)->right, key);
		} else {

			AVLNODE *tempNode;

			if ((*rootp)->left == NULL && (*rootp)->right == NULL) {
				free((*rootp));
				*rootp = NULL;
			} else if ((*rootp)->left != NULL && (*rootp)->right == NULL) {
				tempNode = (*rootp)->left;
				free((*rootp));
				*rootp = tempNode;

			} else if ((*rootp)->left == NULL && (*rootp)->right != NULL) {
				tempNode = (*rootp)->right;
				free((*rootp));
				*rootp = tempNode;
			} else {
				tempNode = extract_smallest_node(&(*rootp)->right);
				tempNode->left = (*rootp)->left;
				tempNode->right = (*rootp)->right;
				free((*rootp));
				*rootp = tempNode;
			}

		}

		if (*rootp == NULL) {
			return;
		}

		(*rootp)->height = height(*rootp);

		int balance = balance_factor(*rootp);

		if (balance > 1) {
			if (balance_factor((*rootp)->left) >= 0) {
				*rootp = rotate_right(*rootp);
			} else {
				(*rootp)->left = rotate_left((*rootp)->left);
				*rootp = rotate_right(*rootp);
			}

		} else if (balance < -1) {
			if (balance_factor((*rootp)->right) <= 0) {
				*rootp = rotate_left(*rootp);
			} else {
				(*rootp)->left = rotate_left((*rootp)->left);
				*rootp = rotate_right(*rootp);
			}

		}

	}

}

/* Search AVL tree by key name
 * @param root - pointer to tree root.
 * @param key - key to match with data.name for search
 * @return - node pointer if found, otherwise NULL
 */
AVLNODE* avl_search(AVLNODE *root, char *name) {
	AVLNODE *node = NULL;
	AVLNODE *curr = root;

	while (curr != NULL && node == NULL) {
		int comp = strcmp(name, curr->data.name);

		if (comp < 0) {
			curr = curr->left;
		} else if (comp > 0) {
			curr = curr->right;
		} else {
			node = curr;
		}

	}

	return node;
}

AVLNODE* extract_smallest_node(AVLNODE **rootp) {
	AVLNODE *p = *rootp, *parent = NULL;
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

/* This function clean AVL tree.
 * @param rootp - pointer of pointer of tree root.
 */
void clean_avl(AVLNODE **rootp) {
	AVLNODE *root = *rootp;
	if (root) {
		if (root->left)
			clean_avl(&root->left);
		if (root->right)
			clean_avl(&root->right);
		free(root);
	}
	*rootp = NULL;
}

static int height_aux(AVLNODE *node) {
	if (node == NULL) {
		return 0;
	}
	return MAX_HEIGHT(height_aux(node->left), height_aux(node->right)) + 1;
}

/* Get the height of AVL tree
 * @param np - pointer to the root of tree
 * @return - the the height value at root.
 */
int height(AVLNODE *root) {
	return height_aux(root);
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
	AVLNODE *NODE1 = np->right;
	AVLNODE *NODE2 = NODE1->left;

	NODE1->left = np;
	np->right = NODE2;

	np->height = height(np);
	NODE1->height = height(NODE1);

	return NODE1;

}

/* This function does the right rotation at a given node
 * @param np - pointer to the rotation node.
 * @return - the pointer to the replaced node.
 */
AVLNODE* rotate_right(AVLNODE *root) {
	AVLNODE *NODE1 = root->left;
	AVLNODE *NODE2 = NODE1->right;

	NODE1->right = root;
	root->left = NODE2;

	root->height = height(root);
	NODE1->height = height(NODE1);

	return NODE1;

}

