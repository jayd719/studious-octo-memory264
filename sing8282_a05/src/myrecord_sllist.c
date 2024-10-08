/*
 -------------------------------------
 File:    myrecord_sllist.c
 Project: sing8282_a05
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-12
 -------------------------------------
 */

#include"myrecord_sllist.h"
/**
 * Search singly linked list by the key name.
 *
 * @param SLL *sllp - provides the address of a singly linked list structure.
 * @param char *name - key to search
 * @return Pointer to found node if found; otherwise NULL
 */
NODE* sll_search(SLL *sllp, char *name) {
	NODE *curr = (sllp->start);
	while (curr != NULL) {
		if (strcmp(curr->data.name, name) == 0)
			return curr;
		curr = curr->next;
	}
	return NULL;

}

/**
 * Insert a new record to linked list at the position sorted by record name field.
 *
 * @param SLL *sllp - provides the address of a singly linked list structure.
 * @param char *name - name field of the new record.
 * @param float score - the score data of the new record.
 */
void sll_insert(SLL *sllp, char *name, float score) {

	NODE *curr = sllp->start;

	NODE *new_node = (NODE*) malloc(sizeof(NODE));

	NODE *prev = NULL;

	strcpy(new_node->data.name, name);
	new_node->data.score = score;

	// Case I

	if (curr == NULL) {
		sllp->start = new_node;
	} else {
		// Case II
		while (curr != NULL && strcmp(curr->data.name, name) < 0) {
			prev = curr;
			curr = curr->next;
		}
		if (prev == NULL) {
			new_node->next = sllp->start;
			sllp->start = new_node;
		} else {
			new_node->next = curr;
			prev->next = new_node;
		}
	}

	sllp->length++;
}

/**
 * Delete a node of record matched by the name key from linked list.
 *
 * @param SLL *sllp provides the address of a singly linked list structure.
 * @param name - key used to find the node for deletion.
 * @return 1 if deleted a matched node, 0 otherwise.
 */
int sll_delete(SLL *sllp, char *name) {

	NODE *curr = sllp->start;
	NODE *prev = NULL;

	while (curr != NULL) {
		if (strcmp(curr->data.name, name) == 0) {

			if (prev == NULL) {
				sllp->start = curr->next;

			} else {
				prev->next = curr->next;

			}
			free(curr);
			sllp->length--;

		}
		prev = curr;
		curr = curr->next;
	}

	return 0;
}

/**
 * Clean singly linked list, delete all nodes.
 * @param @param SLL *sllp provides the address of a singly linked list structure.
 */
void sll_clean(SLL *sllp) {
	NODE *curr;
	while (sllp->start != NULL) {
		curr = sllp->start;
		sllp->start = curr->next;
		free(curr);
		sllp->length--;
	}
}
