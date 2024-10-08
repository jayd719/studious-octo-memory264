/*
 -------------------------------------
 File:    algorithm.c
 Project: sing8282_a10
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-03-26
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edgelist.h"
#include "graph.h"
#include "algorithm.h"
#include "heap.h"

/* Compute and return MST by Prim's algorithm using priority queue (min-heap)
 * @param g     - graph by reference
 * @param start - the root node of MST
 * @return      - pointer of edge list of shortest path tree
 */
EDGELIST* mst_prim(GRAPH *g, int start) {
	EDGELIST *newList = new_edgelist();
	char visited[g->order];

	HEAP *h = new_heap(g->order);

	GNODE *currNode = *(g->nodes + start);
	ADJNODE *neighbors = currNode->neighbor;

	visited[currNode->nid] = 'T';

	while (neighbors != NULL) {
		EDGENODE *edg = newNode(currNode->nid, neighbors->nid,
				neighbors->weight);
		HEAPDATA hd = { neighbors->weight, edg };
		heap_insert(h, hd);
		neighbors = neighbors->next;
	}

	while (h->size > 0) {
		EDGENODE *smallest = heap_extract_min(h).value;
		if (visited[smallest->to] != 'T') {
			visited[smallest->to] = 'T';
			insert_edge_end(newList, smallest->from, smallest->to,
					smallest->weight);

			currNode = *(g->nodes + smallest->to);
			neighbors = currNode->neighbor;
			while (neighbors != NULL) {
				EDGENODE *edg = newNode(currNode->nid, neighbors->nid,
						neighbors->weight);
				HEAPDATA hd = { neighbors->weight, edg };
				heap_insert(h, hd);
				neighbors = neighbors->next;
			}

		}
	}
	return newList;
}

/*
 * Compute shortest path tree as edge list by Dijkstra's algorithm using priority queue (min-heap)
 * @param g     - graph by reference
 * @param start - the root node of shortest path tree
 * @return      - pointer of edge list of shortest path tree
 */
EDGELIST* spt_dijkstra(GRAPH *g, int start) {
	EDGELIST *newList = new_edgelist();

	char visited[g->order];

	HEAP *h = new_heap(g->order);

	GNODE *currNode = *(g->nodes + start);
	ADJNODE *neighbors = currNode->neighbor;

	visited[currNode->nid] = 'T';

	while (neighbors != NULL) {
		EDGENODE *edg = newNode(currNode->nid, neighbors->nid,
				neighbors->weight);
		HEAPDATA hd = { neighbors->weight, edg };
		heap_insert(h, hd);
		neighbors = neighbors->next;
	}
	while (h->size > 0) {
		EDGENODE *smallest = heap_extract_min(h).value;
		if (visited[smallest->to] != 'T') {
			visited[smallest->to] = 'T';
			insert_edge_end(newList, smallest->from, smallest->to,
					smallest->weight);

			currNode = *(g->nodes + smallest->to);
			neighbors = currNode->neighbor;
			while (neighbors != NULL) {
				EDGENODE *edg = newNode(currNode->nid, neighbors->nid,
						neighbors->weight);
				int index = heap_search_data(h, edg);

				if (index == -1) {
					HEAPDATA hd = { neighbors->weight + newList->end->weight,
							edg };
					heap_insert(h, hd);
				} else {
					heap_change_key(h, index,
							neighbors->weight + newList->end->weight);
				}

				neighbors = neighbors->next;
			}

		}
	}

	return newList;
}

/*
 * Compute shortest path as edge list by Dijkstra's algorithm using priority queue (min-heap)
 * @param g     - graph by reference
 * @param start - the start node of shortest path
 * @param end   - the end node of shortest path
 * @return      - pointer of edge list of shortest path
 */
EDGELIST* sp_dijkstra(GRAPH *g, int start, int end) {

	EDGELIST *newList = new_edgelist();

	char visited[g->order];

	HEAP *h = new_heap(g->order);

	GNODE *currNode = *(g->nodes + start);
	ADJNODE *neighbors = currNode->neighbor;

	visited[currNode->nid] = 'T';

	while (neighbors != NULL) {
		EDGENODE *edg = newNode(currNode->nid, neighbors->nid,
				neighbors->weight);
		HEAPDATA hd = { neighbors->weight, edg };
		heap_insert(h, hd);
		neighbors = neighbors->next;
	}
	while (h->size > 0) {
		EDGENODE *smallest = heap_extract_min(h).value;
		if (visited[smallest->to] != 'T') {
			visited[smallest->to] = 'T';
			insert_edge_end(newList, smallest->from, smallest->to,
					smallest->weight);

			currNode = *(g->nodes + smallest->to);
			neighbors = currNode->neighbor;
			while (neighbors != NULL) {
				EDGENODE *edg = newNode(currNode->nid, neighbors->nid,
						neighbors->weight);
				int index = heap_search_data(h, edg);

				if (index == -1) {
					HEAPDATA hd = { neighbors->weight + newList->end->weight,
							edg };
					heap_insert(h, hd);
				} else {
					heap_change_key(h, index,
							neighbors->weight + newList->end->weight);
				}

				neighbors = neighbors->next;
			}

		}
	}

	return newList;
}
