/*
 -------------------------------------
 File:    stack.c
 Project: sing8282_a06
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-26
 -------------------------------------
 */
#include"stack.h"

void push(STACK *sp, NODE *np) {
	np->next = sp->top;
	sp->top = np;
	sp->length++;

}

NODE* pop(STACK *sp) {
	NODE *node = sp->top;

	if (sp->top != NULL) {
		sp->top = node->next;
		sp->length--;
	}

	return node;
}

void stack_clean(STACK *sp) {
	clean(&sp->top);
}
