/*
 -------------------------------------
 File:    mystring.h
 Project: sing8282_a03
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-01
 -------------------------------------
 */
#ifndef MYSTRING_H_
#define MYSTRING_H_

/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.
 *
 * @param s - char pointer to a str
 * @return - return the number of words.
 */
int str_words(char *s);

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a str
 * @return - return the number of actual flips.
 */
int str_lower(char *s);

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a str
 */
void str_trim(char *s);

#endif /* MYSTRING_H_ */
