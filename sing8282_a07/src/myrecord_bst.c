/*
 -------------------------------------
 File:    myrecord_bst.c
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
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"

static int getCount(BSTNODE *node) {
	if (node == NULL) {
		return 0.0;
	}
	return getCount(node->left) + getCount(node->right) + 1;
}

static float getSum(BSTNODE *node) {
	if (node == NULL) {
		return 0.0;
	}
	return getSum(node->left) + getSum(node->right) + node->data.score;
}

static void updateStats(BSTDS *ds) {
	ds->count = getCount(ds->root);
	ds->mean = getSum(ds->root) / ds->count;

}

/* Add a record data into the BSTDS and update its statistic fields
 * using increamental algorithm.
 * @parame ds - pointer to the BSTDS.
 * @parama record - RECORD data to be added.
 */
void add_record(BSTDS *ds, RECORD record) {
	bst_insert(&(ds->root), record);
	updateStats(ds);

}

/* Delete a node from BSTDA with data.name matching with the given name
 * and stats fields using increamental algorithm.
 * @parame ds - pointer to the BSTDS.
 * @parama name - node data.name to be removed.
 */
void remove_record(BSTDS *ds, char *name) {
	bst_delete(&(ds->root), name);
	updateStats(ds);

}

/* Clean the BST of BSTDS and reset count, mean, stddev
 * @parame ds - pointer to the BSTDS.
 */
void clean_bstds(BSTDS *ds) {

}
