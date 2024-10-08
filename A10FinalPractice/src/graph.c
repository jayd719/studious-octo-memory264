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

}

/* create and return a new adjacent list graph of order n */
GRAPH* new_graph(int n) {
	GRAPH *newGraph = (GRAPH*) malloc(sizeof(GRAPH));
	if (newGraph == NULL) {
		printf("malloc Failed");
		return NULL;
	}

	newGraph->order = n;
	newGraph->size = 0;

	newGraph->nodes = (GNODE*) malloc(sizeof(GNODE) * n);
	for (int i = 0; i < n; i++) {
		(newGraph->nodes + i) = (GNODE*) malloc(sizeof(GNODE));
		(newGraph->nodes + i)->nid = i;
	}

	return newGraph;

}

/* Add edge (from, to, weight) to a graph. If edge (from, to) exists, update its weight by the new weight,
 * This indicates that if (from, to) does not exist, the new edge will be added to the end of the linked list.
 */
void insert_edge_graph(GRAPH *g, int from, int to, int weight) {

}

/* Delete edge (from, to)*/
void delete_edge_graph(GRAPH *g, int from, int to) {

}

/* Get and return the weight of edge (from, to) if exists, otherwise return INFINITY*/
int get_edge_weight(GRAPH *g, int from, int to) {

}

/* Travere graph nodes in breadth-first-order using auxiliary queue */
void traverse_bforder(GRAPH *g, int start) {

}

void traverse_dforder(GRAPH *g, int start) {

}

/* Display the graph*/
void display_graph(GRAPH *g) {

}

void clean_graph(GRAPH **gp) {

}
