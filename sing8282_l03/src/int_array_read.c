/*
 -------------------------------------
 File:    int_array_read.c
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

void int_array_read(int *array, int size) {
	int j = 0;

	printf("Enter 4 values for an array of int.\n");
	while (j < size) {
		printf("Value for index %d:", j);

		int i = 0;
		char str[50] = { };
		char ch = getchar();
		while (ch != '\n') {
			str[i] = ch;
			i++;
			ch = getchar();
		}
		str[i] = '\0';

		char *rChar = str;

		int sign = 0;
		if (*rChar == '-') {
			rChar++;
			sign = 1;
		}

		if (isdigit(*(rChar))) {
			*(array + j) = (int) (*(rChar) - 48);
			if (sign) {
				*(array + j) = -(int) (*(rChar) - 48);
			}

			j++;
		} else {
			printf("Not a valid integer\n");
		}

	}

}
