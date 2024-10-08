/*
 -------------------------------------
 File:    fibonacci.c
 Project: sing8282_a02
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-01-22
 -------------------------------------
 */

#include "fibonacci.h"

int iterative_fibonacci(int n) {

	int i = 1;
	int nth_fib = 0;

	int first_number = 0;
	int second_number = 1;

	if (n == 0) {
		nth_fib = first_number;
	} else if (n == 1) {
		nth_fib = second_number;
	} else {
		while (i < n) {
			nth_fib = first_number + second_number;
			first_number = second_number;
			second_number = nth_fib;
			i++;
		}
	}
	return nth_fib;
}

int recursive_fibonacci(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return recursive_fibonacci(n - 2) + recursive_fibonacci(n - 1);

}

int dpbu_fibonacci(int *f, int n) {

	*f = 0;
	*(f + 1) = 1;
	for (int i = 2; i <= n; i++) {
		*(f + i) = *(f + (i - 2)) + *(f + (i - 1));
	}

	return *(f + n);
}

int dptd_fibonacci(int *f, int n) {

	if (n <= 1) {
		*(f + n) = n;

	} else if (*(f + n) > 0) {
		return *(f + n);

	} else {
		*(f + n) = dptd_fibonacci(f, n - 2) + dptd_fibonacci(f, n - 1);
	}
	return *(f + n);
}
