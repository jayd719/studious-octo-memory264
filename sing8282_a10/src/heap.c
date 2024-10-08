/*
 -------------------------------------
 File:    heap.c
 Project: sing8282_a09
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "heap.h"

// hepler functions

static void change_size(HEAP *heap) {
	HEAPDATA *nData = (HEAPDATA*) malloc(sizeof(HEAPDATA) * heap->capacity * 2);

	for (int i = 0; i < heap->capacity; i++) {
		nData[i] = heap->hda[i];
	}

	heap->hda = nData;
	heap->capacity = heap->capacity * 2;

}

static void heap_swap(HEAPDATA *a, HEAPDATA *b) {
	HEAPDATA temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int cmp(KEYTYPE a, KEYTYPE b) {
	int r = 0;
	if (a < b)
		r = -1;
	else if (a > b)
		r = 1;
	return r;
}

HEAP* new_heap(int capacity) {
	HEAP *hp = (HEAP*) malloc(sizeof(HEAP));
	if (hp == NULL)
		return NULL;
	hp->hda = (HEAPDATA*) malloc(sizeof(HEAPDATA) * capacity);
	if (hp->hda == NULL) {
		free(hp);
		return NULL;
	};
	hp->capacity = capacity;
	hp->size = 0;
	return hp;
}

void heapify_up(HEAP *heap, int index) {
	int parentNode = floor((index - 1) / 2);

	if (index <= 0) {
		return;
	}

	if (cmp(heap->hda[parentNode].key, heap->hda[index].key) > 0) {
		heap_swap(&heap->hda[parentNode], &heap->hda[index]);
		heapify_up(heap, parentNode);
	}

}

// you may add this function to be used other functions.
void heapify_down(HEAP *heap, int index) {
	if (index >= heap->size) {
		return;
	}

	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	int smallest = index;

	if (leftChild < heap->size
			&& cmp(heap->hda[leftChild].key, heap->hda[smallest].key) < 0) {
		smallest = leftChild;
	}
	if (rightChild < heap->size
			&& cmp(heap->hda[rightChild].key, heap->hda[smallest].key) < 0) {
		smallest = rightChild;
	}

	if (smallest != index) {
		heap_swap(&heap->hda[smallest], &heap->hda[index]);
		heapify_down(heap, smallest);
	}

}
void heap_insert(HEAP *heap, HEAPDATA new_node) {
	if (heap->size == heap->capacity) {
		change_size(heap);
	}

	heap->hda[heap->size] = new_node;
	heap->size++;
	heapify_up(heap, heap->size - 1);

}

HEAPDATA heap_find_min(HEAP *heap) {
	return heap->hda[0];
}

HEAPDATA heap_extract_min(HEAP *heap) {
	HEAPDATA node = heap->hda[0];

	heap->size--;
	heap->hda[0] = heap->hda[heap->size];
	heapify_down(heap, 0);

	return node;
}

int heap_change_key(HEAP *heap, int index, KEYTYPE new_key) {
	heap->hda[index].key = new_key;
	heapify_down(heap, index);
	heapify_up(heap, index);

	return heap_search_data(heap, new_key);
}

int heap_search_data(HEAP *heap, VALUETYPE data) {
	int value = -1;
	int i = 0;

	while (i < heap->size && value == -1) {
		if (heap->hda[i].value == data) {
			value = i;
		}
		i++;
	}

	return value;
}

void heap_clean(HEAP **heapp) {
	if (heapp) {
		HEAP *heap = *heapp;
		if (heap->capacity > 0) {
			heap->capacity = 0;
			heap->size = 0;
			free(heap->hda);
			free(heap);
		}
		*heapp = NULL;
	}
}
