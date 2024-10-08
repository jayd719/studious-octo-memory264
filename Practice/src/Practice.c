/*
 ============================================================================
 Name        : Practice.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	int data;
	struct node *next;
} NODE;

NODE inccc(NODE *p) {
	(*p).data = (*p).data + 1;
	return *p;
}

int main() {
//	int a;
//	int *p;
//
//	a = 10;
//	p = &a;
//
////	*(p + 1) = 20;
//
//	printf("Print Address of both variable\n");
//	printf("%d\n", &a);
//	printf("%d\n\n", p);
//
//	printf("Print value in the variables\n");
//	printf("%d\n", a);
//	printf("%d\n", *p);
//
//	*p = 12;
//	printf("a after *p\n");
//	printf("%d\n", a);
//
//	int b = *(p + 1);
//	printf("%d\n", b);
//
//	printf("ARRAYS\n\n\n");
//	int A[5];
//	A[0] = 1;
//	A[1] = 2;
//	A[2] = 3;
//	A[3] = 4;
//
//	printf("%d\n", A);
//	int *j = A;
//
//	printf("%d\n", j);
//
//	printf("%d", *j);
//
//	printf("\n\n\nMultiDimensional Array\n\n");
//
//	int B[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
//
//	int (*k)[3];
//	k = B;
//
//	printf("Address of B %d\n", &B);
//	printf("Address of K %d\n", k);
//
//	for (int m = 0; m < 3; m++) {
//		for (int n = 0; n < 3; n++) {
//			printf("%d ", *(*(k + m) + n));
//		}
//		printf("\n");
//	}
//
//	printf("\n\n\n");
//	float C[3][3] = { { 1.1, 2.2, 3.3 }, { 4.4, 5.5, 6.6 }, { 7.7, 8.8, 9.9 } };
//
//	float *v = C;
//
//	for (int l = 0; l < 3; l++) {
//		for (int o = 0; o < 3; o++) {
//			printf("%f ", *((v + l) + o));
//		}
//		printf("\n");
//	}
//
//	char str[10] = "hello";
//	printf("%s\n", str);
//
//	char *l = "Hello";
//	printf("%s\n", l);      // output: Hello
//	printf("%s\n", (l + 1)); // output: l
//	// this statement is not allowed.
//
//	char names[20][40] = { "Jorge", "Dan", "Brian" };
//	printf("%s\n", names[0]);    // output: Jorge
//	printf("%s\n", names[1]);    // output: Dan
//	printf("%s\n", names[2]);    // output: Brian
//	printf("%c", *(names[2] + 1));  // output: n

//	char str[100];
//	int i = 0;
//	char ch = getchar();
//	while (ch != '\n') {
//		str[i] = ch;
//		i++;
//		ch = getchar();
//	}
//	str[i] = '\0';
//
//	printf("%s", str);
//
//	char *p = str;
//	printf("\nnew PRinting using pointer\n");
//	while (*p) {
//		putchar(*(p));
//		p++;
//	}

//	char str[30] = "This is ";
//	char str2[20] = "now 1010 working";
//
//	char *p = str;
//	char *k = str2;
//	int counter = 0;
//
//	while (*p) {
//		p++;
//		counter++;
//	}
//
//	while (*k) {
//		*p = *k;
//		p++;
//		k++;
//	}
//	printf("%s", str);
//
////	convert to uppercase
//
//	printf("\nconvert String to uppercase\n");
//	p = str;
//	while (*p) {
//		if (*p >= 'a' && *p <= 'z') {
//			*p -= 32;
//		}
//		p++;
//	}
//
//	printf("%s", str);
//
//	printf("\nReverse a String \n");
//
//	char *s = str;
//	char *t = p;
//	p--;
//	while (s < p) {
//		*t = *s;
//		*s = *p;
//		*p = *t;
//
//		s++;
//		p--;
//	}
//	printf("%s", str);

//	struct record {
//		int id;
//		float score;
//		char m;
//	};
//
//	printf("Size of Structure %d\n", sizeof(struct record));
//
//	typedef struct {
//		char first_name[20];
//		char mid_name[20];
//		char last_name[20];
//	} NAME;
//
//	typedef struct {
//		int dd;
//		int mm;
//		int yy;
//	} DATE;
//
//	typedef struct {
//		int id;
//		NAME name;
//		DATE dob;
//	} STUDENT;
//
//	STUDENT s1 = { 1212, { "JON", "ROB", "DON" }, { 20, 12, 1991 } };
//
//	printf("%s\n", s1.name.first_name);
//	printf("%d\n", &s1.dob.dd);
//	printf("\n\n");
//
//	STUDENT *ptr = &s1;
//
//	printf("%d\n", &(*ptr).dob.dd);
//	printf("%d\n", &ptr->dob.dd);
//	printf("%d\n", &s1.dob.dd);
//	printf("%d\n", (*ptr).dob.dd);

	NODE n1, n2, *ptr = &n1;
	n1.data = 1;
	n1.next = &n2;
	n2.data = 2;
	n2.next = NULL;

	inccc(ptr);
	printf("%d\n", ptr->data);        // output: 1
	printf("%d\n", ptr->next->data);
	printf("%d\n", (*ptr).data);        // output: 1
	printf("%d\n", (*ptr).next->data);  // output: 2

	printf("%d", sizeof(char));
#define DICTIONARY_SIZE 1000  // Adjust the size according to your needs
#define MAX_WORD_LENGTH 50

	char dictionary[DICTIONARY_SIZE * (MAX_WORD_LENGTH + 1)] = { 0 }; // Single-dimensional array

	// Add "this" to the array
	strncpy(dictionary, "this", MAX_WORD_LENGTH);

	// Add "that" to the array
	strncpy(dictionary + (MAX_WORD_LENGTH + 1), "that", MAX_WORD_LENGTH);

	// Print the contents of the array
	printf("1: %s\n", dictionary);
	printf("2: %s\n", dictionary + (MAX_WORD_LENGTH + 1));

	return 0;
}

