/*
 -------------------------------------
 File:    sum_three_integers.c
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

int sum_three_integers(void) {
	while (1) {

		printf("Enter three comma-separated integers:");
		// accept input from user;
		int i = 0;
		char str[50] = { };
		char ch = getchar();
		while (ch != '\n') {
			str[i] = ch;
			i++;
			ch = getchar();
		}
		str[i] = '\0';
		// check length of input
		char *p = str;
		int count = 0;
		while (*p) {
			count++;
			p++;
		}

		p = str;

		if (count >= 5 && isdigit(*p) && isdigit(*(p + 2))
				&& isdigit(*(p + 4))) {

			return (*p + *(p + 2) + *(p + 4) - 144);

			break;
		}
		printf("The integers were not properly entered.\n");
	}

}
