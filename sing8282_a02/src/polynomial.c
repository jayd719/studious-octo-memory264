/*
 -------------------------------------
 File:    polynomial.c
 Project: sing8282_a02
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-01-22
 -------------------------------------
 */
#include "polynomial.h"

#define EPSILON 1e-6

float horner(float *p, int n, float x) {
	float temp_array[n];

	temp_array[0] = *(p);

	for (int i = 1; i < n; i++) {
		temp_array[i] = *(p + i) + (temp_array[i - 1] * x);
	}

	return temp_array[n - 1];
//
}

float bisection(float *p, int n, float a, float b) {

	float c = 0;

	return c;
}
