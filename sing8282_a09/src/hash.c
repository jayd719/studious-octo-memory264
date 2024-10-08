/*
 -------------------------------------
 File:    hash.c
 Project: sing8282_a09
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-03-19
 -------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

// helper functions

static HASHNODE* get_new_node(char *key, int value) {
	HASHNODE *new_node = (HASHNODE*) malloc(sizeof(HASHNODE));
	memcpy(new_node->key, key, sizeof(new_node->key));
	new_node->value = value;
	new_node->next = NULL;

	return new_node;
}

/* Hash function that hash key string to an integer of modular of hash table size
 * @param key - input key string
 * @param size - modular value
 * @return  - sum of ASCII code value the key string modular % size
 */
int hash(char *key, int size) {

	// if key is null
	if (key == NULL) {
		return -1;
	} else {

		unsigned int sum = 0;
		char *p = key;
		while (*p) {
			sum += *p;
			p++;
		}
		return sum % size;
	}

}

/* Create dynamically a chained hash table of the given size
 * @param size  --  hash table size, i.e., the length of index array.
 */
HASHTABLE* new_hashtable(int size) {

	HASHTABLE *newHashTable = (HASHTABLE*) malloc(sizeof(newHashTable));

	// check for failure
	if (newHashTable == NULL) {
		printf("malloc failed");
		return NULL;
	}

	newHashTable->size = size;
	newHashTable->count = 0;

	newHashTable->hna = (HASHNODE**) malloc(size * sizeof(HASHNODE**));

	if (newHashTable->hna == NULL) {
		printf("malloc for array Failed");
		return NULL;
	}
	int i = 0;
	while (i < newHashTable->count) {
		*(newHashTable->hna + i) = NULL;
		i++;
	}
	return newHashTable;

}

/* Insert key value data into HASHTABLE, so that each linked list maintains the increasing order of keys.
 * @param ht - pointer to a HASHTABLE
 * @param key - key string
 * @param value - int value
 * #return - when the HASHNODE of the key exists, update its value and return 0;
 * otherwise insert into the hash table and return 1
 */
int hashtable_insert(HASHTABLE *ht, char *key, int value) {
	int h = hash(key, ht->size);
	int inserted = 1;

	HASHNODE *newNode = get_new_node(key, value);
	if (*(ht->hna + h) == NULL) {
		*(ht->hna + h) = newNode;
	} else {
		HASHNODE *curr = *(ht->hna + h);
		HASHNODE *prev = NULL;

		while (curr != NULL && strcmp(key, (curr->key)) > 0) {
			prev = curr;
			curr = curr->next;
		}

		if (curr != NULL && strcmp(key, curr->key) == 0) {
			curr->value = value;
			free(newNode);
			return 0;
		}

		if (prev == NULL) {
			// Insert at the beginning
			newNode->next = curr;
			*(ht->hna + h) = newNode;
		} else {
			// Insert in the middle or at the end
			prev->next = newNode;
			newNode->next = curr;
		}
	}
	ht->count++;

	return inserted;

}

/* Search the hash table and return the pointer of found hashnode
 * @param ht - pointer to a HASHTABLE
 * @param key - input search key string
 * @return - pointer to the found HASHNODE, otherwise NULL
 */
HASHNODE* hashtable_search(HASHTABLE *ht, char *key) {
	HASHNODE *node = NULL;

	HASHNODE *curr = *(ht->hna + hash(key, ht->size));
	while (curr != NULL && node == NULL) {
		if (strcmp(key, curr->key) == 0) {
			node = curr;
		}
		curr = curr->next;
	}

	return node;

}

/* Delete hashnode by key.
 * @param ht - pointer to a HASHTABLE
 * @param key - delete key string
 * @return - if the named hash node exists, delete it and return 1; otherwise return 0.
 */
int hashtable_delete(HASHTABLE *ht, char *key) {

	HASHNODE *curr = *(ht->hna + hash(key, ht->size));
	HASHNODE *prev = NULL;
	int found = 0;
	while (curr != NULL && found == 0 && strcmp(key, curr->key) >= 0) {
		if (strcmp(key, curr->key) == 0) {
			found = 1;
		}
		prev = curr;
		curr = curr->next;
	}

	if (found == 1) {

		if (prev == NULL) {
			*(ht->hna + hash(key, ht->size)) = curr;
		} else {
			prev->next = curr->next;
		}
		free(curr);
		ht->count--;
	}

	return found;
}

/* Delete all linked lists and reset the count to 0
 * @param ht - pointer to a HASHTABLE
 */
void hashtable_clean(HASHTABLE **htp) {
	if (*htp == NULL)
		return;
	HASHTABLE *ht = *htp;
	HASHNODE *p, *temp;
	int i;
	for (i = 0; i < ht->size; i++) {
		p = ht->hna[i];
		while (p) {
			temp = p;
			p = p->next;
			free(temp);
		}
		ht->hna[i] = NULL;
	}
	free(ht->hna);
	ht->hna = NULL;
	*htp = NULL;
}
