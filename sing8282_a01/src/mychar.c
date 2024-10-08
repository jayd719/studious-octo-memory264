/*
 -------------------------------------
 File:    mychar.c
 Project: sing8282_a01
 Assignment 1 Source File 1
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-01-14
 -------------------------------------
 */
#include "mychar.h"

/**
 * Determine the type of a char character.
 *
 * @param c - char type value
 * @return - 0 if c is a digit, 1 if c is an arithmetic operator, 2 if c is an English letter; otherwise -1.
 */
int mytype(char c) {
	// define list of operators
//	const char OPERATORS[] = { '+', '-', '*', '/', '%' };

	int return_value = -1;

	if (isdigit(c)) {
		// check if input is digit
		return_value = 0;
	} else if (isalpha(c)) {
		return_value = 2;
	} else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
		return_value = 1;
	}

	return return_value;

}

/**
 * Flip the case of an English character.
 *
 * @param c - char type value of ASCII code of English letter.
 * @return  -  c's upper/lower case letter if c is a lower/upper case English letter.
 */
char case_flip(char c) {
	if (c >= 'a' && c <= 'z') {
		c -= 32;

	} else {
		c += 32;
	}
	return c;
}

/**
 * Convert digit character to the corresponding integer value.
 *
 * @param c - char type value of ASCII code of digit charactor.
 * @return - its corresponding integer value if c is a digit character.
 */
int char_to_int(char c) {
	return (int) c - 48;

}

