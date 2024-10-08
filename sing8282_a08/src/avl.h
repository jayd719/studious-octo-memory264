/*
 -------------------------------------
 File:    avl.h
 Project: sing8282_a08
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-03-14
 -------------------------------------
 */

#ifndef AVL_H_
#define AVL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
	char name[20];
	float score;
} RECORD;

typedef struct avlnode {
	RECORD data;
	int height;
	struct avlnode *left;
	struct avlnode *right;
} AVLNODE;

/* Insert a node of given record data into AVL tree.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param data  - record data for the new node.
 */
void avl_insert(AVLNODE **rootp, RECORD data);

/* Delete a node of data.name matched with given key from AVL tree.
 *
 * @param rootp - pointer of pointer to tree root.
 * @param key -   key to match with data.name for deletion.
 */
void avl_delete(AVLNODE **rootp, char *key);

/* Search AVL tree by key name
 * @param root - pointer to tree root.
 * @param key - key to match with data.name for search
 * @return - node pointer if found, otherwise NULL
 */
AVLNODE* avl_search(AVLNODE *root, char *name);

/* This function clean AVL tree.
 * @param rootp - pointer of pointer of tree root.
 */
void clean_avl(AVLNODE **rootp);

/* Get the height of AVL tree
 * @param np - pointer to the root of tree
 * @return - the the height value at root.
 */
int height(AVLNODE *root);

/* Return the balance factor at the given node
 * @param np - pointer to the node of tree
 * @return - the balance factor a the node,
 */
int balance_factor(AVLNODE *np);

/* This function does the left rotation at a given node
 * @param np - pointer to the rotation node.
 * @return - the pointer to the replaced node.
 */
AVLNODE* rotate_left(AVLNODE *np);

/* This function does the right rotation at a given node
 * @param np - pointer to the rotation node.
 * @return - the pointer to the replaced node.
 */
AVLNODE* rotate_right(AVLNODE *root);

AVLNODE* extract_smallest_node(AVLNODE **rootp);

#endif /* AVL_H_ */
