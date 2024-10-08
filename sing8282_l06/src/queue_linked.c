/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author name, ID, email
 *
 * @version 2024-02-22
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"

// Functions

queue_linked* queue_initialize() {
	// allocate memory for queue
	queue_linked *source = malloc(sizeof *source);

	source->front = NULL;
	source->rear = NULL;
	return source;

}

void queue_free(queue_linked **source) {

	while ((*source)->front != NULL) {
		queue_node *curr = (*source)->front;
		data_free(&curr->item);
		(*source)->front = curr->next;
		free(curr);
	}
	(*source)->count = 0;
	free(*source);
	*source = NULL;

}

BOOLEAN queue_empty(const queue_linked *source) {
	return (source->front == NULL);
}

int queue_count(const queue_linked *source) {
	return source->count;
}

void queue_insert(queue_linked *source, data_ptr item) {

	queue_node *new_node = malloc(sizeof *new_node);
	new_node->item = malloc(sizeof *new_node->item);
	data_copy(new_node->item, item);

	if (source->front == NULL) {
		source->front = new_node;
		source->rear = new_node;
	} else {
		source->rear->next = new_node;
		source->rear = new_node;
	}
	source->count++;

}

BOOLEAN queue_peek(const queue_linked *source, data_ptr item) {
	BOOLEAN peeked = FALSE;
	if (source->front != NULL) {
		data_copy(item, source->front->item);
		peeked = TRUE;
	}
	return peeked;

}

BOOLEAN queue_remove(queue_linked *source, data_ptr *item) {
	BOOLEAN removed = FALSE;

	if (source->front != NULL) {
		queue_node *front = source->front;
		*item = front->item;

		source->front = front->next;
		source->count--;

		free(front);

		if (source->front == NULL) {
			source->rear = NULL;
		}
		removed = TRUE;
	}

	return removed;
}

void queue_print(const queue_linked *source) {
	char string[DATA_STRING_SIZE];
	queue_node *current = source->front;

	while (current != NULL) {
		printf("%s\n", data_string(string, sizeof string, current->item));
		current = current->next;
	}
	return;
}
