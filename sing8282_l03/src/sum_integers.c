/*
 -------------------------------------
 File:    sum_integers.c
 Project: sing8282_l03
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-01-28
 -------------------------------------
 */

#include "functions.h"
#include <ctype.h>

int sum_integers(void) {
	printf("Enter integers, one per line:\n");

	int sum = 0;

	while (1) {
		int i = 0;
		char str[100] = { };
		char ch = getchar();

		while (ch != '\n') {
			str[i] = ch;
			i++;
			ch = getchar();
		}

		char rChar = str[0];
		if (isdigit(rChar)) {
			sum += (rChar - 48);
		} else {
			break;
		}
	}
	return sum;

}
