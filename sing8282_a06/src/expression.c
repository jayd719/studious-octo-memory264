/*
 -------------------------------------
 File:    expression.c
 Project: sing8282_a06
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-26
 -------------------------------------
 */

#include"expression.h"
#include <math.h>

QUEUE infix_to_postfix(char *infixstr) {

	QUEUE exp = { 0 };
	STACK stack = { 0 };

	NODE *poppedNode = NULL;

	char *p = infixstr;

	while (*p) {
		NODE *newNode = new_node(*p, get_type(*p));

		// if element is operand
		if (newNode->type == 0) {

			char num[10];
			num[0] = newNode->data;

			int i = 1;
			while (get_type(*(p + 1)) == 0) {
				num[i] = *p;
				i++;
				p++;
			}

			int number = newNode->data - 48;
			double j = 0;
			if (i > 1) {
				while (i > 0) {
					number = (num[i] - 48) * (int) pow(10.0, j);
					i--;
					j++;
				}

			}
			newNode->data = number;
			enqueue(&exp, newNode);

			// if element is operator
		} else if (newNode->type == 1) {

			// if stack is empty
			if (stack.top == NULL) {
				push(&stack, newNode);

				// if stack is not empty
			} else {
				// compare the pros of top element in stack and current

				if (get_priority(stack.top->type)
						> get_priority(newNode->type)) {
					// if operator is stack has higher precendence, add it to queue
					enqueue(&exp, pop(&stack));
				}

				// push the operator to stack
				push(&stack, newNode);

			}

			// if element is opening bracket
		} else if (newNode->type == 2) {
			push(&stack, newNode);

			// closing bracket
		} else if (newNode->type == 3) {

			poppedNode = pop(&stack);

			while (poppedNode->type != 2) {
				// skip brackets
				if (poppedNode->type != 2 && poppedNode->type != 3) {
					enqueue(&exp, poppedNode);
				}
				poppedNode = pop(&stack);
			}
		}
		p++;
	}
	enqueue(&exp, pop(&stack));

	return exp;

}

int evaluate_postfix(QUEUE queue) {
	int sum = 0;

	STACK callStack = { 0 };

	while (queue.front != NULL) {
		// if operand push it to stack
		if (queue.front->type == 0) {
			push(&callStack, dequeue(&queue));
		} else {

			NODE *operator = dequeue(&queue);

			NODE *op1 = pop(&callStack);
			NODE *op2 = pop(&callStack);

			switch (operator->data) {

			case '+':
				push(&callStack, new_node((op2->data + op1->data), 0));
				break;

			case '-':
				push(&callStack, new_node((op2->data - op1->data), 0));
				break;

			case '*':
				push(&callStack, new_node((op2->data * op1->data), 0));
				break;

			case '/':
				push(&callStack, new_node((op2->data / op1->data), 0));
				break;
			}
		}
	}
	sum = callStack.top->data;

	return sum;
}

/*
 * Evaluate and return the value of infix expression passed by string infixstr,
 * using infix_to_postfix() and evaluate_postfix() functions.
 * @param infixstr - string of infix expression.
 * @return - value of the infix expression.
 */
int evaluate_infix(char *infixstr) {
	return evaluate_postfix(infix_to_postfix(infixstr));

}
