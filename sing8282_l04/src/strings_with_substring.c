/*
 -------------------------------------
 File:    strings_with_substring.c
 Project: sing8282_l04
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-05
 -------------------------------------
 */

#include "functions.h"

void strings_with_substring(strings_array *data, char *substr) {

	int i = 0;
	while (i < data->lines) {
		char *p = data->strings[i];
		if (strstr(p, substr)) {
			printf("%s\n", data->strings[i]);
		}

		i++;
	}

}
