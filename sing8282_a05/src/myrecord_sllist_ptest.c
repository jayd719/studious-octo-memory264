///*
// --------------------------------------------------
// File:    myrecord_llist_ptest.c
// About:   public test driver
// Author:  HBF
// Version: 2024-01-25
// --------------------------------------------------
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include "myrecord_sllist.h"
//
//RECORD tests[] = { { "A1", 10 }, { "A2", 20 }, { "A3", 30 }, { "A4", 40 }, {
//		"A5", 50 }, { "A8", 60 }, { "A7", 70 }, { "A6", 80 }, { "A9", 90 }, {
//		"A10", 100 } };
//char *delete_items[] = { "A2", "A4", "A6", "A1" };
//char *search_items[] = { "A1", "A3", "A5", "B" };
//
//void sll_data_display(SLL *sllp);
//void test_ssl_insert() {
//	printf("------------------\n");
//	printf("Test: ssl_insert\n\n");
//	int n = sizeof(tests) / sizeof(RECORD);
//	SLL sllist = { 0 };
//	printf("given linked list:");
//	sll_data_display(&sllist);
//	printf("\n");
//	for (int i = n - 2; i >= n / 2; i--) {
//		printf("sll_insert(%s %0.1f): ", tests[i].name, tests[i].score);
//		sll_insert(&sllist, tests[i].name, tests[i].score);
//		sll_data_display(&sllist);
//		printf("\n");
//	}
//	printf("\n");
//}
//
//void test_ssl_delete() {
//	printf("------------------\n");
//	printf("Test: ssl_delete\n\n");
//	int n = sizeof(tests) / sizeof(RECORD);
//	SLL sllist = { 0 };
//	for (int i = 0; i < n - 1; i++) {
//		sll_insert(&sllist, tests[i].name, tests[i].score);
//	}
//	n = sizeof delete_items / sizeof *delete_items;
//	printf("given linked list:");
//	sll_data_display(&sllist);
//	printf("\n");
//	for (int i = 0; i < n; i++) {
//		printf("sll_delete(%s): ", delete_items[i]);
//		sll_delete(&sllist, delete_items[i]);
//		sll_data_display(&sllist);
//		printf("\n");
//	}
//	printf("\n");
//	printf("Before Delete %d \n", sllist.length);
//
//	sll_clean(&sllist);
//	printf("After Delete %d \n", sllist.length);
//	sll_data_display(&sllist);
//}
//
//void test_ssl_search() {
//	printf("------------------\n");
//	printf("Test: ssl_search\n\n");
//	int n = sizeof(tests) / sizeof(RECORD);
//	SLL sllist = { 0 };
//	for (int i = 0; i < n; i++) {
//		sll_insert(&sllist, tests[i].name, tests[i].score);
//	}
//	printf("given linked list:");
//	sll_data_display(&sllist);
//	printf("\n");
//	n = sizeof search_items / sizeof *search_items;
//	NODE *np = NULL;
//	for (int i = 0; i < n; i++) {
//		np = sll_search(&sllist, search_items[i]);
//		if (np != NULL)
//			printf("sll_search(%s): %s %.1f\n", search_items[i], np->data.name,
//					np->data.score);
//		else
//			printf("sll_search(%s): not found\n", search_items[i]);
//	}
//	printf("\n");
//}
//
//void test_import_data();
//
//int main(int argc, char *args[]) {
//	if (argc <= 1) {
//		test_ssl_insert();
//		test_ssl_search();
//		test_ssl_delete();
//
//	} else {
//		test_import_data();
//	}
//	return 0;
//}
//
//typedef struct {
//	int count;
//	float mean;
//	float stddev;
//	float median;
//} STATS;
//
//char infilename[40] = "marks.txt";
//char *stats_format = "%-10s%-6.1f\n";
//int import_data(FILE *fp, SLL *sllp);
//STATS process_data(SLL *sllp);
//void sll_display(SLL *sllp);
//
//void test_import_data() {
//	printf("------------------\n");
//	printf("Test: import_data\n\n");
//	printf("Import data from file\n");
//	SLL sllist = { 0 };
//	FILE *fp = fopen(infilename, "r");
//	import_data(fp, &sllist);
//	fclose(fp);
//	sll_display(&sllist);
//	printf("\nTest: process_data\n\n");
//	STATS stats = process_data(&sllist);
//	printf(stats_format, "count", (float) stats.count);
//	printf(stats_format, "mean", stats.mean);
//	printf(stats_format, "stddev", stats.stddev);
//	printf(stats_format, "median", stats.median);
//	printf("\n");
//}
//
//void select_sort_inc(float *a[], int left, int right) {
//	int i, j, k;
//	float *temp;
//	for (i = left; i <= right; ++i) {
//		k = i;
//		for (j = i + 1; j <= right; ++j) {
//			if (*a[j] < *a[k]) {
//				k = j;
//			}
//		}
//		if (i != k) {
//			temp = a[k];
//			a[k] = a[i];
//			a[i] = temp;
//		}
//	}
//}
//
//float median(SLL *sllp) {
//	if (sllp->start == NULL)
//		return 0;
//	NODE *np = sllp->start;
//	int i = 0, n = sllp->length;
//	float *a[n];
//	while (np) {
//		a[i] = &(np->data.score);
//		np = np->next;
//		i++;
//	}
//	select_sort_inc(a, 0, n - 1);
//	return (n % 2 == 1) ? *a[n / 2] : (*a[n / 2 - 1] + *a[n / 2]) / 2;
//}
//
//STATS process_data(SLL *sllp) {
//	int count = 0;
//	float mean = 0;
//	float stddev = 0;
//	NODE *np = sllp->start;
//	while (np != NULL) {
//		count++;
//		mean += np->data.score;
//		stddev += np->data.score * np->data.score;
//		np = np->next;
//	}
//	mean /= count;
//	stddev = sqrt(stddev / count - mean * mean);
//
//	STATS stats = { };
//	stats.count = count;
//	stats.mean = mean;
//	stats.stddev = stddev;
//	stats.median = median(sllp);
//	return stats;
//}
//
//int import_data(FILE *fp, SLL *sllp) {
//	char line[40], name[40];
//	float score = 0;
//	while (fgets(line, sizeof(line), fp) != NULL) {
//		if (sscanf(line, "%[^,],%f", name, &score) >= 2)
//			sll_insert(sllp, name, score);
//	}
//	return sllp->length;
//}
//
//void sll_display(SLL *sllp) {
//	NODE *np = sllp->start;
//	printf("length:%d\n", sllp->length);
//	while (np != NULL) {
//		printf("%s,%.1f\n", np->data.name, np->data.score);
//		np = np->next;
//	}
//}
//
//void sll_data_display(SLL *sllp) {
//	NODE *np = sllp->start;
//	printf("length %d ", sllp->length);
//	while (np != NULL) {
//		printf("%s %.1f ", np->data.name, np->data.score);
//		np = np->next;
//	}
//}
