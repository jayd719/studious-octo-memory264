/*
 ============================================================================
 Name        : finalPractice.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void inputUserString(char *str) {
	int i = 0;
	printf("Enter Input String:\t");
	char ch = getchar();
	while (ch != '\n') {
		str[i] = ch;
		i++;
		ch = getchar();
	}
	str[i] = '\0';
}

void displayChar(char *string) {
	char *p = string;
	while (*p != '\0') {
		printf("%c", *p);
		p++;
	}
	printf("\n");
}

int stringLenght(char *str) {
	int length = 0;
	char *p = str;

	while (*p) {
		length++;
		p++;
	}
	return length;
}
void copy_string(char *from, char *to) {
	while (*from) {
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

void convertToUpperCase(char *str) {
	while (*str) {
		if (*str >= 'a' && *str <= 'z') {
			*str = *str - 32;
		}
		str++;
	}
}

void reverseString(char *str) {
	if (str == NULL)
		return;

	char *p = str;
	char *temp = 0;
	while (*p) {
		p++;
	}
	p--;

	while (str < p) {
		temp = str;
		*str = *p;
		p = temp;

		p--;
		str++;
	}
}

typedef struct date {
	int MM;
	int YY;
	int DD;
} DATE;

typedef struct record {
	int data;
	int name[30];
	DATE date;
} RECORD;

typedef union value {
	int data1;
	float data2;
} VALUE;

typedef enum boolean {
	True = 1, False = 0
} BOOLEAN;

void printFileData(char *fileName) {

	FILE *fp = fopen(fileName, "r");
	if (fp == NULL) {
		perror("could not open file");
		return;
	}

	char buf[100];

	while (!feof(fp)) {
		if (fgets(buf, sizeof(buf), fp)) {
			printf("%s", buf);
		}

	}
	fclose(fp);
}

int main() {
//	char str[120];
//	inputUserString(str);
//	displayChar(str);

	char str[] = "This @is now working123";
	printf("Lenght of[%s] is %d\n\n", str, stringLenght(str));

	char to[] = "\0";
	printf("String Before Copy: %s\n", to);
	copy_string(str, to);
	printf("String After Copy:: %s\n\n", to);

	convertToUpperCase(to);
	printf("String After Conversion: %s\n\n", to);

	reverseString(to);
	printf("Reversed String: %s\n\n", to);

	printf("--Printing File Data--\n");
	char fileName[] = "file.txt";
	printFileData(fileName);
	printf("\n------------------------------------\n\n\n");
	return 0;
}
