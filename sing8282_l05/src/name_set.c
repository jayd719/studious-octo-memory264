/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-02-09
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
	// Allocate memory to the data structure
	name_set *set = malloc(sizeof *set);
	// Initialize the header fields.
	set->front = NULL;
	set->rear = NULL;
	return set;
}

int name_set_free(name_set **set) {

	int count = 0;
	name_set_node *node = (*set)->front;

	while (node != NULL) {
		name_set_node *curr = node;
		free(curr);
		node = node->next;
		count++;
	}
	free(*set);
	*set = NULL;

	return count;
}

BOOLEAN name_set_append(name_set *set, const char *first_name,
		const char *last_name) {

	BOOLEAN appended = FALSE;

	if (!name_set_contains(set, first_name, last_name)) {

		name_set_node *new_node = (name_set_node*) malloc(
				sizeof(name_set_node));

		if (new_node == NULL) {
			return appended;
		}

		strcpy(new_node->first_name, first_name);
		strcpy(new_node->last_name, last_name);
		new_node->next = NULL;

		// case I: if set is already empty
		if (set->front == NULL) {
			set->front = new_node;
			set->rear = new_node;
		} else {

			set->rear->next = new_node;
			set->rear = new_node;

		}

	}

	return appended;
}

BOOLEAN name_set_contains(const name_set *set, const char *first_name,
		const char *last_name) {

	BOOLEAN contains = FALSE;

	name_set_node *node = set->front;
	while (node != NULL) {
		if (strcmp(node->first_name, first_name) == 0
				&& strcmp(node->last_name, last_name) == 0) {
			contains = TRUE;
		}
		node = node->next;
	}

	return contains;

}

void name_set_print(const name_set *set) {
	name_set_node *node = set->front;
	while (node != NULL) {
		printf("%s, %s", node->last_name, node->first_name);
		node = node->next;
	}

}
