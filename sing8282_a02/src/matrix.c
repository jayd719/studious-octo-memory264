/*
 -------------------------------------
 File:    matrix.c
 Project: sing8282_a02
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-01-22
 -------------------------------------
 */

#include"matrix.h"

float norm(float *v, int n) {
	float sum = 0;

	for (int i = 0; i < n; i++) {
		sum += *(v + i) * *(v + i);
	}
	return sqrtf(sum);
}

/*
 * Compute and return the dot product of vectors v1[n] and v2[n], namely the sum of product of corresponding elements of v1 and v2.
 *
 * @param v1 - the address of the first vector array.
 * @param v2 - the address of the second vector array.
 * @param n - the length of vector v1 and v2.
 * @return -  the value of dot product of v1 and v2.
 */
float dot_product(float *v1, float *v2, int n) {

	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += *(v1 + i) * *(v2 + i);
	}
	return sum;
}

/*
 * Compute the multiplication of matrix and vector.
 * @param m - the address of the first matrix array.
 * @param v - the address of the vector array.
 * @param vout - the address of the output vector array.
 * @param n - the length of vector v.
 */
void matrix_multiply_vector(float *m, float *v, float *vout, int n) {

	for (int i = 0; i < n; i++) {
		*(vout + i) = 0;
		for (int j = 0; j < n; j++) {
			*(vout + i) += (*(m + i * n + j)) * (*(v + j));
		}

	}

}

/*
 * Compute the multiplication of two n by matrices.
 * @param m1 - the address of the first matrix array.
 * @param m2 - the address of the second matrix array.
 * @param m3 - the address of the output matrix array.
 * @param n - the row and colum size of m1 and m2.
 */
void matrix_multiply_matrix(float *m1, float *m2, float *m3, int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				*(m3 + i * n + j) += *(m1 + i * n + k) * *(m2 + k * n + j);
			}
		}

	}

}
