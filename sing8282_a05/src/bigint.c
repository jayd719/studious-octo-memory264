/*
 -------------------------------------
 File:    bigint.c
 Project: sing8282_a05
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-14
 -------------------------------------
 */
#include"bigint.h"
/*
 * Define BIGINT as DLL
 */
//typedef DLL BIGINT;
/*
 * Creates and returns BIGINT object by converting the digit string.
 */
BIGINT bigint(char *digitstr) {
	BIGINT bigint = { 0 };
	while (*digitstr) {
		NODE *node = new_node(*digitstr - '0');
		dll_insert_end(&bigint, node);
		digitstr++;
	}
	return bigint;
}

/*
 * Add two BIGINT operants and returns the sum in BIGINT type.
 * @param oprand1  - first operand of BIGINT type.
 * @param oprand2  - second operand of BIGINT type.
 * @return - the sum of oprand1 and oprand2 in BIGINT type.
 */
BIGINT bigint_add(BIGINT oprand1, BIGINT oprand2) {
	BIGINT result = { 0 };
	int carry = 0;
	int sum = 0;

	int val1;
	int val2;

	NODE *curr_op1 = oprand1.end;
	NODE *curr_op2 = oprand2.end;

	while (!(curr_op1 == NULL && curr_op2 == NULL)) {

		if (curr_op1 == NULL) {
			val1 = 0;
		} else {
			val1 = curr_op1->data;
			curr_op1 = curr_op1->prev;
		}

		if (curr_op2 == NULL) {
			val2 = 0;
		} else {
			val2 = curr_op2->data;
			curr_op2 = curr_op2->prev;
		}

		sum = val1 + val2 + carry;

		if (sum > 9) {
			carry = 1;
			sum = sum - 10;
		} else {
			carry = 0;
		}

		dll_insert_start(&result, new_node(sum));

	}

	if (carry > 0) {
		dll_insert_start(&result, new_node(carry));
	}

	return result;

}

/*
 * Compute and return Fibonacci(n)
 * @param n - input positive integer
 * @return  - Fibonacci(n) in BIGINT type
 */
BIGINT bigint_fibonacci(int n) {

	BIGINT nth;

	BIGINT one = bigint("0");
	BIGINT two = bigint("1");
	if (n == 0)
		return one;
	if (n == 1)
		return two;

	int i = 1;
	while (i < n) {
		nth = bigint_add(one, two);
		one = two;
		two = nth;
		i++;
	}

	return nth;
}
