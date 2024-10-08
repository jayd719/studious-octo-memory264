/*
 -------------------------------------
 File:    stack.h
 Project: sing8282_a06
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-26
 -------------------------------------
 */
#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include"common.h"
/*
 * Define a structure STACK containing the length and pointer of the top node.
 * int length - maintains the length of stack.
 * NODE *top - pointer to the top node of linked list stack
 */
typedef struct stack {
	int length;
	NODE *top;
} STACK;

/*
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack
 * @param NODE *np - pointer to the node.
 */
void push(STACK *sp, NODE *np);

/*
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack
 */
NODE* pop(STACK *sp);

/*
 * clean the linked list stack
 */
void stack_clean(STACK *sp);

#endif /* STACK_H_ */
