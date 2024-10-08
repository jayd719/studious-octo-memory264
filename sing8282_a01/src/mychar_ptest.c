///**
// * -------------------------------------
// * @file  mychar_ptest.c
// * Public test driver
// * -------------------------------------
// * @author Hongbing Fan, 123456789, hfan@wlu.ca
// *
// * @version 2024-01-11
// *
// * -------------------------------------
// */
//
//#include <stdio.h>
//#include "mychar.h"
//
//void test_mychar(void) {
//	printf("------------------\n");
//	printf("Test: mychar\n\n");
//
//	static const char tests[] = { '2', '8', 'A', 'a', 'z', '+', '-', '$' };
//	int count = sizeof tests / sizeof *tests;
//
//	int i;
//	for (i = 0; i < count; i++) {
//		char c = tests[i];
//		int t = mytype(c);
//		printf("Char\tASCII\tMyType\n");
//		printf("%4c\t%5d\t%6d\n", c, c, t);
//
//		if (t == 0) {
//			printf("  char_to_int: %d\n", char_to_int(c));
//		} else if (t == 1) {
//			printf("  operator\n");
//		} else if (t == 2) {
//			printf("  caseflip: %c\n", case_flip(c));
//		} else {
//			printf("  Not typed\n");
//		}
//	}
//	printf("\n");
//}
//
//void test(char c) {
//	int t = mytype(c);
//	printf("Char\tASCII\tMyType\n");
//	printf("%c\t%d\t%d\n", c, c, t);
//
//	if (t == 0) {
//		printf("Square:%d\n", char_to_int(c) * char_to_int(c));
//	} else if (t == 1) {
//		printf("operator\n");
//	} else if (t == 2) {
//		printf("Caseflip:%c\n", case_flip(c));
//	} else {
//		printf("Not typed\n");
//	}
//}
//
//int main(int argc, char *args[]) {
//	char c;
//	if (argc <= 1) {
//		test_mychar();
//	} else {
//
//		do {
//			printf("Enter a character (! to quit)\n");
//			scanf("%c", &c);
//			if (c != '\n') {
//				while (getc(stdin) != '\n')
//					;  // this is to flush input buffer
//			}
//			test(c);
//
//			if (c == '!')
//				break;
//
//		} while (1);
//
//	}
//	printf("\n");
//
//	return 0;
//}
