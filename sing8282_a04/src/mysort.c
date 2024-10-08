/*
 -------------------------------------
 File:    mysort.c
 Project: sing8282_a04
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-06
 -------------------------------------
 */

#include"mysort.h"
#define FLOATFORMAT "%.0f"

void select_sort_inc(float *a[], int left, int right) {

	for (int i = left; i < right; i++) {
		int minIndex = i;
		for (int j = i; j < right; j++) {
			if (a[j] < a[minIndex]) {
				minIndex = i;
			}
		}

		float *temp = a[i];
		*a[i] = *a[minIndex];
		*a[minIndex] = *temp;
	}

}
//void select_sort_inc(float *a[], int left, int right) {
//
//	for (int i = left; i < right; i++) {
//		float *min = a[i];
//
//		for (int j = i; j <= right; j++) {
//			if (*(a[j]) < *(min)) {
//				min = a[j];
//			}
//		}
//		float tmp = *min;
//		*min = *a[i];
//		*a[i] = tmp;
//
//	}
//
//}

void quick_sort_inc(float *a[], int left, int right) {

	if (right <= left)
		return;
	int j = left - 1;
	int i = left;
	while (i < right) {
		if ((*(a[i]) < *(a[right]))) {
			j++;
			float temp = *a[j];
			*a[j] = *a[i];
			*a[i] = temp;
		}
		i++;
	}
	j++;
	float temp = *a[j];
	*a[j] = *a[i];
	*a[i] = temp;

	quick_sort_inc(a, left, j - 1);
	quick_sort_inc(a, j + 1, right);

}
