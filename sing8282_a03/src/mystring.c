/*
 -------------------------------------
 File:    mystring.c
 Project: sing8282_a03
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-01
 -------------------------------------
 */

#include"mystring.h"

/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.
 *
 * @param s - char pointer to a str
 * @return - return the number of words.
 */
int str_words(char *s) {
	int words = 0;
	char wordStarted = 0;

	while (*s) {
		if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')) {
			wordStarted = 1;
		} else if ((wordStarted == 1)
				&& (*s == ' ' || *s == ',' || *s == '.')) {
			wordStarted = 0;
			words++;
		}
		s++;
	}

	if ((*(s - 1) >= 'A' && *(s - 1) <= 'Z')
			|| (*(s - 1) >= 'a' && *(s - 1) <= 'z')) {
		words++;
	}
	return words;
}

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a str
 * @return - return the number of actual flips.
 */
int str_lower(char *s) {
	int flip = 0;
	while (*s) {
		if (*s >= 'A' && *s <= 'Z') {
			*s = *s + 32;
			flip += 1;
		}
		s++;
	}
	return flip;
}

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a str
 */
void str_trim(char *s) {
	char *p = s;
	char spaceRequired = 0;

	while (*p) {
		if (*p != ' ') {
			*s = *p;
			spaceRequired = 1;
			s++;
		} else if (*p == ' ' && spaceRequired == 1) {
			*s = ' ';
			spaceRequired = 0;
			s++;
		}
		p++;
	}
	if (*(s - 1) != ' ') {
		*s = '\0';
	} else {
		*(s - 1) = '\0';
	}

}
