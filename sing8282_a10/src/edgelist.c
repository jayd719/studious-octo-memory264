/*
 -------------------------------------
 File:    edgelist.c
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
#include "edgelist.h"

// helper functions

EDGENODE* newNode(int from, int to, int weight) {
	EDGENODE *np = malloc(sizeof(EDGENODE));
	np->from = from;
	np->to = to;
	np->weight = weight;
	np->next = NULL;
	return np;
}

EDGELIST* new_edgelist() {
	EDGELIST *tp = malloc(sizeof(EDGELIST));
	tp->size = 0;
	tp->start = NULL;
	tp->end = NULL;
	return tp;
}

void insert_edge_end(EDGELIST *g, int from, int to, int weight) {
	EDGENODE *new_node = newNode(from, to, weight);
	if (g->start == NULL && g->end == NULL) {
		g->start = new_node;
	} else {
		g->end->next = new_node;
	}
	g->end = new_node;
	g->size++;

}

void insert_edge_start(EDGELIST *g, int from, int to, int weight) {
	EDGENODE *new_node = newNode(from, to, weight);

	if (g->start == NULL && g->end == NULL) {
		g->end = new_node;
	} else {
		new_node->next = g->start;
	}
	g->start = new_node;
	g->size++;
}

void delete_edge(EDGELIST *g, int from, int to) {
	EDGENODE *curr = g->start;
	EDGENODE *prev = NULL;
	int found = 0;
	while (curr != NULL && found == 0) {
		if (curr->from == from && curr->to == to) {
			found = 1;
		} else {
			prev = curr;
			curr = curr->next;
		}

	}

	if (found != 0) {
		if (prev == NULL) {
			g->start = g->start->next;
		} else if (curr == g->end) {
			prev->next = NULL;
			g->end = prev;
		} else {
			prev->next = curr->next;
		}

		g->size--;
	}

}

int getW(EDGENODE *node) {
	if (node == NULL)
		return 0;
	return node->weight + getW(node->next);
}
int weight_edgelist(EDGELIST *g) {
	return getW(g->start);
}

void clean_edgelist(EDGELIST **gp) {
	EDGELIST *g = *gp;
	EDGENODE *temp, *p = g->start;
	while (p) {
		temp = p;
		p = p->next;
		free(temp);
	}
	free(g);
	*gp = NULL;
}

void display_edgelist(EDGELIST *g) {
	if (g == NULL)
		return;
	printf("size %d ", g->size);
	printf("(from to weight) ");
	EDGENODE *p = g->start;
	while (p) {
		printf("(%d %d %d) ", p->from, p->to, p->weight);
		p = p->next;
	}
}
