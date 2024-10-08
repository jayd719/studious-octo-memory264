/*
 -------------------------------------
 File:    hash.c
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
#include <string.h>
#include <stdlib.h>
#include "hash.h"

static HASHNODE* createNewNode(char *key, int value) {
	HASHNODE *newNode = (HASHNODE*) malloc(sizeof(HASHNODE));
	if (newNode == NULL) {
		printf("malloc Failed");
		return NULL;
	}

	memcpy(newNode->key, key, sizeof(newNode->key));
	newNode->value = value;
	return newNode;
}

/* Hash function that hash key string to an integer of modular of hash table size
 * @param key - input key string
 * @param size - modular value
 * @return  - sum of ASCII code value the key string modular % size
 */

int hash(char *key, int size) {
	int sum = 0;
	char *p = key;
	while (*p) {
		sum += *p;
		p++;
	}
	return sum % size;
}

/* Create dynamically a chained hash table of the given size
 * @param size  --  hash table size, i.e., the length of index array.
 */
HASHTABLE* new_hashtable(int size) {
	HASHTABLE *table = (HASHTABLE*) malloc(sizeof(HASHTABLE));
	if (table == NULL) {
		printf("malloc failed");
		return NULL;
	}

	table->count = 0;
	table->size = size;

	table->hna = (HASHNODE**) malloc(sizeof(HASHNODE) * size);
	if (table->hna == NULL) {
		printf("malloc failed");
	}

	int i = 0;
	while (i < size) {
		*(table->hna + i) = NULL;
		i++;
	}

	return table;

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

	if (*(ht->hna + h) == NULL) {
		*(ht->hna + h) = createNewNode(key, value);
	} else {
		HASHNODE *curr = *(ht->hna + h);
		HASHNODE *prev = NULL;

		while (curr != NULL && strcmp(key, curr->key) > 0) {
			prev = curr;
			curr = curr->next;
		}

		if (curr != NULL && strcmp(key, curr->key) == 0) {
			curr->value = value;
			return 0;
		}
		HASHNODE *newNode = createNewNode(key, value);
		if (prev == NULL) {
			*(ht->hna + h) = newNode;
			newNode->next = curr;
		} else {
			prev->next = newNode;
			newNode->next = curr;
		}

	}
	ht->count++;
	return 1;
}

/* Search the hash table and return the pointer of found hashnode
 * @param ht - pointer to a HASHTABLE
 * @param key - input search key string
 * @return - pointer to the found HASHNODE, otherwise NULL
 */
HASHNODE* hashtable_search(HASHTABLE *ht, char *key) {

}

/* Delete hashnode by key.
 * @param ht - pointer to a HASHTABLE
 * @param key - delete key string
 * @return - if the named hash node exists, delete it and return 1; otherwise return 0.
 */
int hashtable_delete(HASHTABLE *ht, char *key) {

}

/* Delete all linked lists and reset the count to 0
 * @param ht - pointer to a HASHTABLE
 */
void hashtable_clean(HASHTABLE **ht) {

}
