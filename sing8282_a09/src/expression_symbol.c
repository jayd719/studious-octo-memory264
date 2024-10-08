/*
 -------------------------------------
 File:    expression_symbol.c
 Project: sing8282_a09
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-03-21
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_queue_stack.h"
#include "expression_symbol.h"

/* Convert symbolic infix expression string to postfix expression in QUEUE type
 * @param ht - pointer to a HASHTABLE
 * @param infixstr - pointer to string of infix expression
 * @return - postfix exprssion in QUEUE type
 */
QUEUE infix_to_postfix_symbol(HASHTABLE *ht, char *infixstr) {
	QUEUE queue = { 0 };
	STACK stack = { 0 };
	char *p = infixstr;
	int sign = 1;
	int num = 0;
	char symbol[11] = { 0 };

	while (*p) {
		if (*p == '-' && (p == infixstr || *(p - 1) == '(')) {
			sign = -1;
		} else if (*p >= '0' && *p <= '9') {
			num = *p - '0';
			while ((*(p + 1) >= '0' && *(p + 1) <= '9')) {
				num = num * 10 + *(p + 1) - '0';
				p++;
			}
			enqueue(&queue, new_node(sign * num, 0));
			sign = 1;
		} else if (*p == '(') {
			push(&stack, new_node('(', 2));
		} else if (*p == ')') {
			while (stack.top) {
				if (stack.top->type == 2) {
					free(pop(&stack));
					break;
				}
				enqueue(&queue, pop(&stack));
			}
		} else if (*p == '/' || *p == '*' || *p == '%' || *p == '+'
				|| *p == '-') {
			while (stack.top && stack.top->type == 1
					&& get_priority(stack.top->data) >= get_priority(*p))
				enqueue(&queue, pop(&stack));
			push(&stack, new_node(*p, 1));
		} else if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
			char *sp = symbol;
			*sp = *p;
			while ((*(p + 1) >= 'a' && *(p + 1) <= 'z')
					|| (*(p + 1) >= 'A' && *(p + 1) <= 'Z')
					|| (*(p + 1) >= '0' && *(p + 1) <= '9')) {
				p++;
				sp++;
				*sp = *p;
			}
			*(sp + 1) = '\0';

			HASHNODE *node = hashtable_search(ht, sp);
			enqueue(&queue, new_node(node->value, 0));

		}
		p++;
	}

	while (stack.top) {
		enqueue(&queue, pop(&stack));
	}

	return queue;
}

/* Evaluate symbolic infix expression string.
 * @param ht - pointer to a HASHTABLE
 * @param infixstr - pointer to string of infix expression
 * @return  - the value of the infix expression.
 */
int evaluate_infix_symbol(HASHTABLE *ht, char *infixstr) {
	return evaluate_postfix(infix_to_postfix_symbol(ht, infixstr));
}

/* Evaluate postfix expression.
 * @param queue - postfix queue
 * @return  - the value of the postfix exprssion.
 */
int evaluate_postfix(QUEUE queue) {
	STACK s = { 0 };
	int sum = 0;
	while (queue.front != NULL) {
		if (queue.front->type == 0) {
			push(&s, dequeue(&queue));
		} else {
			NODE *operator = dequeue(&queue);

			NODE *op1 = pop(&s);
			NODE *op2 = pop(&s);

			switch (operator->data) {

			case '+':
				push(&s, new_node((op2->data + op1->data), 0));
				break;

			case '-':
				push(&s, new_node((op2->data - op1->data), 0));
				break;

			case '*':
				push(&s, new_node((op2->data * op1->data), 0));
				break;

			case '/':
				push(&s, new_node((op2->data / op1->data), 0));
				break;
			}
		}

	}
	sum = s.top->data;
	clean_stack(&s);
	return sum;
}

/* Evaluate statement like b = (a+3)*2;
 * @param ht - pointer to a HASHTABLE to resolve the value of symbols on the right side.
 * @return  - symbol on the left side and its value in HASHDATA type.
 */
HASHDATA evaluate_statement(HASHTABLE *ht, char *statement) {
	HASHDATA hd = { 0 };
	char line[80] = { 0 };
	strcpy(line, statement);
	char *p = line, *dp = line;
	while (*p) {
		if (*p != ' ') {
			*dp = *p;
			dp++;
		}
		p++;
	}
	char name[20] = { 0 };
	char *eqp = strstr(line, "=");
	if (eqp) {
		//*eqp='\0'; strcpy(name, line);
		for (p = line, dp = name; p != eqp; p++)
			*dp = *p;
		if ((name[0] >= 'a' && name[0] <= 'z')
				|| (name[0] >= 'A' && name[0] <= 'Z')) {
			int value = evaluate_infix_symbol(ht, eqp + 1);
			hashtable_insert(ht, name, value);
			strcpy(hd.key, name);
			hd.value = value;
		}
	} else {
		strcpy(name, line);
		if ((name[0] >= 'a' && name[0] <= 'z')
				|| (name[0] >= 'A' && name[0] <= 'Z')) {
			HASHNODE *hnp = hashtable_search(ht, name);
			if (hnp) {
				strcpy(hd.key, name);
				hd.value = hnp->value;
			}
		}
	}
	return hd;

}
