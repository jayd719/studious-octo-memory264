/*
 -------------------------------------
 File:    factorial.c
 Project: sing8282_a01
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-01-14
 -------------------------------------
 */

#include "factorial.h"
/**
 * Compute the factorial n! and does overflow detection.
 *
 * @param n - a positive integer value
 * @return -  the factorial n! if it is not overflow; otherwise 0.
 */
int factorial(int n) {
	int i = 1;
	int factorial = 1;
	int MAX = INT_MAX;
	while (i <= n) {
		factorial = factorial * i;
		if (factorial > MAX - factorial) {
			factorial = 0;
			break;
		}
		++i;
	}

	return factorial;
}
