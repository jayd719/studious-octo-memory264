/*
 -------------------------------------
 File:    queue.c
 Project: sing8282_a06
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-25
 -------------------------------------
 */

#include"queue.h"

void enqueue(QUEUE *qp, NODE *np) {
	if (qp->front == NULL) {
		qp->front = np;
		qp->rear = np;
	} else {
		qp->rear->next = np;
		qp->rear = np;
	}
	qp->length++;

}

NODE* dequeue(QUEUE *qp) {
	NODE *node = NULL;

	if (qp->front != NULL) {
		node = qp->front;
		qp->front = node->next;
		if (qp->front == NULL) {
			qp->rear = NULL;
		}
		qp->length--;
	}

	return node;
}

void queue_clean(QUEUE *qp) {
	clean(&qp->front);
	qp = NULL;
}

