/**
 * -------------------------------------
 * @file  min_heap.c
 * Minimum Heap Source Code File
 * -------------------------------------
 * Author:  Jashandeep Singh
 * ID:      169018282
 * Email:   sing8282@mylaurier.ca
 * Version  2024-03-19
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "min_heap.h"

#define STRING_SIZE 80

// local functions
/**
 * Swaps two data values.
 *
 * @param a pointer to data.
 * @param b pointer to data.
 */
static void heap_swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

/**
 * Moves the last value in source until it is in its correct location
 * in source.
 *
 * @param source - pointer to a heap
 */
static void heapify_up(min_heap *source) {

	int currNode = source->count - 1;
	int parentNode = floor((currNode - 1) / 2);

	while (currNode > 0 && source->values[parentNode] > source->values[currNode]) {
		heap_swap(&source->values[parentNode], &source->values[currNode]);
		currNode = parentNode;
		parentNode = (currNode - 1) / 2;

	}

	return;
}

/**
 * Moves a value down source to its correct position.
 *
 * @param source - pointer to a heap
 */
static void heapify_down(min_heap *source) {

	int i = 0;
	while (i < source->count) {
		int leftChild = 2 * i + 1;
		int rightChild = 2 * i + 2;
		int smallest = i;

		if (leftChild < source->count
				&& source->values[leftChild] < source->values[i]) {
			smallest = leftChild;
		} else if (rightChild < source->count
				&& source->values[rightChild] < source->values[i]) {
			smallest = rightChild;
		}

		if (smallest != i) {
			heap_swap(&(source->values[i]), &(source->values[smallest]));
			heapify_down(source);
		}

		i++;

	}

	return;
}

// Public minimum heap functions

min_heap* min_heap_initialize(int capacity) {
	min_heap *source = malloc(sizeof *source);
	source->values = malloc(capacity * sizeof *source->values);
	source->capacity = capacity;
	source->count = 0;
	return source;
}

void min_heap_free(min_heap **source) {
	free((*source)->values);
	(*source)->values = NULL;
	free(*source);
	*source = NULL;
	return;
}

void min_heap_heapify(min_heap *source, int *keys, int count) {

	for (int i = 0; i < count; i++) {
		min_heap_insert(source, keys[i]);
	}
	return;
}

int min_heap_empty(const min_heap *source) {
	return (source->count == 0);
}

int min_heap_full(const min_heap *source) {
	return (source->count == source->capacity);
}

int min_heap_count(const min_heap *source) {
	return (source->count);
}

void min_heap_insert(min_heap *source, const int value) {
// Add new value to end of the heap.
	source->values[source->count] = value;
	source->count++;
// Fix the heap.
	heapify_up(source);
	return;
}

int min_heap_peek(const min_heap *source) {
	return (source->values[0]);
}

int min_heap_remove(min_heap *source) {
	int value = source->values[0];
	source->count--;

	if (source->count > 0) {
		// Move last value to top of heap.
		source->values[0] = source->values[source->count];
		// Fix the heap.
		heapify_down(source);
	}

	return value;
}

int min_heap_valid(const min_heap *source) {

	int isValid = 1;

	int i = 0;
	while (isValid == 1 && i < source->count) {

		int leftChild = 2 * i + 1;
		int rightChild = 2 * i + 2;

		if (leftChild < source->count
				&& source->values[i] > source->values[leftChild]) {
			isValid = 0;
		}

		if (rightChild < source->count
				&& source->values[i] > source->values[rightChild]) {
			isValid = 0;
		}
		i++;

	}

	return isValid;
}

static int check_contains(min_heap *source, int replacement) {
	int contains = 0;

	int i = 0;
	while (contains == 0 && i < source->count) {
		if (source->values[i] == replacement) {
			contains = 1;
		}
		i++;
	}
	return contains;
}

int min_heap_replace(min_heap *source, int replacement) {

	if (check_contains(source, replacement) == 0) {
		int value = source->values[0];
		source->values[0] = replacement;
		heapify_down(source);
		return value;
	} else {
		int value = source->values[0];
		source->values[0] = replacement;
		min_heap_remove(source);
		return value;
	}

}

void heap_sort(int *values, int count) {

	min_heap *s = min_heap_initialize(count);

	int i = 0;
	while (i < count) {
		min_heap_insert(s, values[i]);
		i++;
	}

	i = 0;
	while (!min_heap_empty(s)) {
		values[i] = min_heap_remove(s);
		i++;
	}
	min_heap_free(&s);
	return;
}

// for testing
void min_heap_print(const min_heap *source) {
	printf("{");

	for (int i = 0; i < source->count; i++) {
		printf("%d, ", source->values[i]);
	}
	printf("}\n");
	return;
}
