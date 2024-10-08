/*
 -------------------------------------
 File:    heap.c
 Project: a9-finalPractice
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
#include <math.h>

#include "heap.h"

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
/*


 /* Use malloc to create HEAP type object, set its size 0, capacity 4,
 * then create an array of HEAPDATA elements of length equal to the capacity
 * and let hda point to the array. Return the pointer of the HEAP object.
 * @param capacity - the capacity of the binary heap, i.e. the length of the heap array.
 * @return - pointer to the HEAP object.
 */
HEAP* new_heap(int capacity) {

	HEAP *newHeap = (HEAP*) malloc(sizeof(HEAP));
	if (newHeap == NULL) {
		printf('malloc failed');
		return 0;
	}

	newHeap->capacity = capacity;
	newHeap->size = 0;

	newHeap->hda = (HEAPDATA*) malloc(sizeof(HEAPDATA) * capacity);

	return newHeap;
}

static void heapify_up(HEAP *heap, int index) {
	int parentNode = floor((index - 1) / 2);

	if (index <= 0)
		return;

if(cmp(heap->hda[parentNoe].))

}

/* Insert the given HEAPDADA data into a heap. When the heap size is equal to the capacity,
 * expand data array by doubling its length and copy the data of old array to the new array in case of need,
 * then insert the data into the heap array.
 * @param heap - pointer to the heap.
 * @param data - data to be inserted.
 */
void heap_insert(HEAP *heap, HEAPDATA data) {
if (heap->size == heap->capacity) {
	change_size(heap);
}

heap->hda[heap->size] = data;
heap->size++;
heapify_up(heap, heap->size - 1);

}

/* Get the HEAPDADA data of minimum key.
 * @param heap - pointer to the heap.
 * @return - the minimum key HEAPDATA
 */
HEAPDATA heap_find_min(HEAP *heap) {

}

/* Get the minimum key HEAPDADA data and delete it from the heap.
 * When the heap->size <= (heap->capacity)/4 and heap->capacity>4, shrink the HEAPDATA array by half.
 * @param heap - pointer to the heap.
 * @return - the minimum key HEAPDATA
 */
HEAPDATA heap_extract_min(HEAP *heap) {

}

/* Changes heap->hda[index].key to new_key, heapify, return the index of new position of the new_key element.
 * @param heap - pointer to the heap.
 * @param index - index of HEAPDATA for key changing.
 * @param new_kay - key value to to be changed.
 * @return - position index of the new_key element.
 */
int heap_change_key(HEAP *heap, int index, KEYTYPE new_key) {

}

/* Find and return the index of the first HEAPDATA data such that data.value == val.
 * @param heap - pointer to the heap.
 * @param val -  match value for search.
 * @return - position index of HEAPDATA data if found, otherwise -1.
 */
int heap_search_data(HEAP *heap, VALUETYPE val) {

}

/* Free dynamically allocated memory of the given heap, and set its pointer to NULL.
 * @param heapp - pointer of pointer to the heap.
 */
void heap_clean(HEAP **heapp) {

}
