/**
 * -------------------------------------
 * @file  mymortgage_ptest.c
 * Public test driver
 * -------------------------------------
 * @author Hongbing Fan, 123456789, hfan@wlu.ca
 *
 * @version 2024-01-11
 *
 * -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "mymortgage.h"

#define EPSILON 1e-6 //#define EPSILON 0.000001

typedef struct {
	float principal;
	float rate;
	int years;
} mortgage_struct;

void test_mymortgage(void) {
	printf("------------------\n");
	printf("Test: mymortgage\n\n");

	static const mortgage_struct tests[] = { { 1000.0, 5.0, 10 }, { 250000, 9.5,
			20 }, { 100.0, 1.0, 1 } };
	int count = sizeof tests / sizeof *tests;

	for (int i = 0; i < count; i++) {
		float principal = tests[i].principal;
		float rate = tests[i].rate;
		int years = tests[i].years;

		printf("principal:       %12.2f\n", principal);
		printf("interest rate:   %12.2f%%\n", rate);
		printf("years:           %12d\n", years);
		printf("monthly payment: %12.2f\n",
				monthly_payment(principal, rate, years));
		printf("total payment:   %12.2f\n",
				total_payment(principal, rate, years));
		printf("total interest:  %12.2f\n\n",
				total_interest(principal, rate, years));
	}
}

void test(float a, float b, int c) {
	printf("principle:%.2f\nannual interest rate:%.2f%%\nyears:%d\n", a, b, c);
	printf("monthly payment:%.2f\n", monthly_payment(a, b, c));
	printf("total payment:%.2f\n", total_payment(a, b, c));
	printf("total interest:%.2f\n", total_interest(a, b, c));
}

int main(int argc, char *argv[]) {

	if (argc <= 1) {
		test_mymortgage();
	} else {
		float a, b;
		int c;
		printf(
				"argument format:principle,rate(%%),years, e.g., 1000.0,5.0,1\n");
		int n = sscanf(argv[1], "%f,%f,%d", &a, &b, &c);
		if (n == 3 && a > EPSILON && b > EPSILON && c > 0) {
			printf("principle:%.2f\nannual interest rate:%.2f\nyears:%d\n", a,
					b, c);
			test(a, b, c);
		} else {
			printf("invalid command argument\n");
			printf(
					"argument format:principle,rate(%%),years, e.g., 1000.0,5.0,1\n");
		}
	}
	printf("\n");
	return 0;
}
