/*
 -------------------------------------
 File:    strings_length.c
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

void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long,
		int length) {

	int i = 0;
	while (i < data->lines) {
		char *s = data->strings[i];

		int data_lenght = 0;
		while (*s) {
			data_lenght++;
			s++;
		}

		if (data_lenght < length) {
			fprintf(fp_short, "%s\n", data->strings[i]);

		} else {
			fprintf(fp_long, "%s\n", data->strings[i]);

		}

		i++;
	}

}
