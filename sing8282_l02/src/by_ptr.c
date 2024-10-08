/*
 -------------------------------------
 File:    by_prt.c
 Project: sing8282_l02
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-01-21
 -------------------------------------
 */

#include "by_ptr.h"

void fill_values_by_ptr(int *values, int size) {

	for (int i = 0; i < size; i++) {
		*(values + i) = i + 1;
	}
}

void fill_squares_by_ptr(int *values, long int *squares, int size) {

	for (int i = 0; i < size; i++) {
		*(squares + i) = *(values + i) * *(values + i);
	}

}

void print_by_ptr(int *values, long int *squares, int size) {

	printf("Value Square\n");
	printf("----- ----------\n");
	for (int i = 0; i < size; i++) {
		printf("%5d %10ld\n", *(values + i), *(squares + i));
	}

}
