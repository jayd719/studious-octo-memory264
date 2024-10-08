/**
 * -------------------------------------
 * @file  factorial_ptest.c
 * Public test driver
 * -------------------------------------
 * @author Hongbing Fan, 123456789, hfan@wlu.ca
 *
 * @version 2024-01-11
 *
 * -------------------------------------
 */

#include <stdlib.h>
#include <stdio.h>
#include "factorial.h"

void test_factorial(int n) {
	printf("------------------\n");
	printf("Test: factorial\n\n");

	for (int x = 1; x < n; x++) {
		int f = factorial(x);

		if (f != 0)
			printf("%d!: %d\n", x, f);
		else
			printf("%d!: overflow\n", x);
	}
	printf("\n");
}

void test(int n) {
	int f = factorial(n);
	if (f != 0)
		printf("%d!:%d\n", n, f);
	else
		printf("%d!:overflow\n", n);
}

int main(int argc, char *args[]) {
	setvbuf(stdout, NULL, _IONBF, 0);

	if (argc <= 1) {
		test_factorial(15);
	} else {
		int n = 0;
		int x = sscanf(args[1], "%d", &n);
		if (x >= 1) {
			test(n);
		} else {
			printf("%s:invalid input\n", args[1]);
		}
	}
	return 0;
}
