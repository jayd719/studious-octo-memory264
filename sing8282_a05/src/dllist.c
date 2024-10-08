/*
 -------------------------------------
 File:    dllist.c
 Project: sing8282_a05
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-12
 -------------------------------------
 */

#include"dllist.h"

/*
 * Create and return a new node using malloc() with passed data value and returns pointer of the node.
 */
NODE* new_node(char value) {
	NODE *new_node = (NODE*) malloc(sizeof(NODE));

	if (new_node == NULL) {
		printf("malloc Failed");
		return NULL;
	}

	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

/*
 * Insert a given node at the beginning the of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 * @param NODE *np  -  reference of a NODE node to be inserted
 */
void dll_insert_start(DLL *dllp, NODE *np) {

	// CASE I

	if (dllp->start == NULL) {
		dllp->start = np;
		dllp->end = np;
	} else {
		dllp->start->prev = np;
		np->next = dllp->start;
		dllp->start = np;
	}
	dllp->length++;

}

/*
 * Insert a node at the end of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 * @param NODE *np  -  reference of a NODE node to be inserted
 */
void dll_insert_end(DLL *dllp, NODE *np) {

	if (dllp->end == NULL) {
		dllp->start = np;
		dllp->end = np;
	} else {
		np->prev = dllp->end;
		dllp->end->next = np;
		dllp->end = np;
	}
	dllp->length++;
}

/*
 * This deletes the first node of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 */
void dll_delete_start(DLL *dllp) {

	if (dllp->start != dllp->end) {
		NODE *front = dllp->start;
		NODE *second = front->next;
		second->prev = NULL;
		dllp->start = second;
		free(front);
	} else {
		free(dllp->end);
		dllp->end = NULL;
		dllp->start = NULL;

	}
	dllp->length--;
}

/*
 * Delete the end node of a doubly linked list.
 * @param DLL *dllp -  reference to input DLL variable
 */
void dll_delete_end(DLL *dllp) {
	if (dllp->start != dllp->end) {
		NODE *end = dllp->end;
		NODE *prev = end->prev;
		prev->next = NULL;
		dllp->end = prev;
		free(end);
	} else {
		free(dllp->end);
		dllp->end = NULL;
		dllp->start = NULL;
	}
	dllp->length--;
}

/*
 * Clean and free the nodes of a doubly linked list and reset start and length.
 * @param DLL *dllp -  reference to input DLL variable
 */
void dll_clean(DLL *dllp) {

	while (dllp->length > 0) {
		NODE *curr = dllp->start;
		dllp->start = curr->next;
		free(curr);
		dllp->length--;
	}
	dllp->start = NULL;
	dllp->end = NULL;

}
