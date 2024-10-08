/*
 -------------------------------------
 File:    graph.c
 Project: sing8282_a10
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-03-24
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "queue_stack.h"
#include <math.h>

//helper functions

static ADJNODE* newADJnode(int nid, int weight) {
	ADJNODE *newNode = malloc(sizeof(ADJNODE));
	newNode->nid = nid;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

/* create and return a new adjacent list graph of order n */
GRAPH* new_graph(int n) {
	GRAPH *g = malloc(sizeof(GRAPH));
	g->nodes = malloc(n * sizeof(GNODE*));

	if (g->nodes == NULL) {
		printf("malloc Failed");
	}

	for (int i = 0; i < n; i++) {
		g->nodes[i] = malloc(sizeof(GNODE));
		g->nodes[i]->nid = i;
		strcpy(g->nodes[i]->name, "null");
		g->nodes[i]->neighbor = NULL;
	}

	g->size = 0;
	g->order = n;
	return g;
}

/* Add edge (from, to, weight) to a graph. If edge (from, to) exists, update its weight by the new weight,
 * This indicates that if (from, to) does not exist, the new edge will be added to the end of the linked list.
 */
void insert_edge_graph(GRAPH *g, int from, int to, int weight) {

	if (g->nodes[from]->neighbor == NULL) {
		g->nodes[from]->neighbor = newADJnode(to, weight);
		g->size++;
	} else {

		ADJNODE *curr = g->nodes[from]->neighbor;
		ADJNODE *prev = NULL;
		while (curr != NULL && curr->nid != to) {
			prev = curr;
			curr = curr->next;
		}

		if (curr == NULL) {
			prev->next = newADJnode(to, weight);
			g->size++;
		} else {
			curr->weight = weight;
		}
	}

}

/* Delete edge (from, to)*/
void delete_edge_graph(GRAPH *g, int from, int to) {
	if (g->nodes[from]->neighbor != NULL) {
		ADJNODE *curr = g->nodes[from]->neighbor;
		ADJNODE *prev = NULL;
		while (curr != NULL && curr->nid != to) {
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL) {
			if (curr == g->nodes[from]->neighbor) {
				g->nodes[from]->neighbor = curr->next;
			} else {
				prev->next = curr->next;
			}
			g->size--;
		}

	}

}

/* Get and return the weight of edge (from, to) if exists, otherwise return INFINITY*/
int get_edge_weight(GRAPH *g, int from, int to) {
	int w = INFINITY;

	if (g->nodes[from]->neighbor != NULL) {
		ADJNODE *curr = g->nodes[from]->neighbor;
		while (curr != NULL) {
			if (curr->nid == to) {
				return curr->weight;
			}
			curr = curr->next;
		}

	}
	return w;
}

/* Travere graph nodes in breadth-first-order using auxiliary queue */
void traverse_bforder(GRAPH *g, int start) {
	QUEUE queue = { 0 };
	char visted[g->order];

	enqueue(&queue, *(g->nodes + start));
	visted[start] = 'Y';

	while (queue.front != NULL) {
		GNODE *curr = dequeue(&queue);
		ADJNODE *nextNode = curr->neighbor;
		printf("(%d %s)", curr->nid, curr->name);
		while (nextNode != NULL) {
			if (visted[nextNode->nid] != 'Y') {
				enqueue(&queue, (g->nodes[nextNode->nid]));
				visted[nextNode->nid] = 'Y';
			}
			nextNode = nextNode->next;
		}
	}
	clean_queue(&queue);
}

void traverse_dforder(GRAPH *g, int start) {

	STACK s = { 0 };
	char visited[g->order];

	push(&s, *(g->nodes[start]));
	visited[start] = 'Y';

	while (s.top) {
		GNODE *currNode = pop(&s);
		ADJNODE *neighbours = currNode->neighbor;
		printf("(%d %s)", currNode->nid, currNode->name);
		while (neighbours) {
			if (visited[neighbours->nid] != 'Y') {
				push(&s, neighbours);
				visited[neighbours->nid] = 'Y';
			}
			neighbours = neighbours->next;
		}
	}

}

/* Traverse graph in depth-first-order using auxiliary stack */
void traverse_dforder(GRAPH *g, int start) {
	STACK stack = { 0 };
	char visited[g->order];

	push(&stack, *(g->nodes + start));
	visited[start] = 'Y';

	while (stack.top != NULL) {
		GNODE *st = pop(&stack);
		ADJNODE *neghs = st->neighbor;
		printf("(%d %s)", st->nid, st->name);
		while (neghs != NULL) {
			if (visited[neghs->nid] != 'Y') {
				push(&stack, *(g->nodes + neghs->nid));
				*(visited + neghs->nid) = 'Y';
			}
			neghs = neghs->next;
		}

	}

}

/* Display the graph*/
void display_graph(GRAPH *g) {
	if (g) {
		printf("order %d ", g->order);
		printf("size %d ", g->size);
		printf("(from to weight) ");
		int i;
		ADJNODE *ptr;
		for (i = 0; i < g->order; i++) {
			//printf("\n%d:", g->nodes[i]->nid);
			ptr = g->nodes[i]->neighbor;
			while (ptr != NULL) {
				printf("(%d %d %d) ", i, ptr->nid, ptr->weight);
				ptr = ptr->next;
			}
		}
	}
}

void clean_graph(GRAPH **gp) {
	int i;
	GRAPH *g = *gp;
	ADJNODE *temp, *ptr;
	for (i = 0; i < g->order; i++) {
		ptr = g->nodes[i]->neighbor;
		while (ptr != NULL) {
			temp = ptr;
			ptr = ptr->next;
			free(temp);
		}
		free(g->nodes[i]);
	}
	free(g->nodes);
	free(g);
	*gp = NULL;
}
