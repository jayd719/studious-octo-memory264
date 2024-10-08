/*
 -------------------------------------
 File:    factorial.h
 Project: sing8282_a01
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-01-14
 -------------------------------------
 */

#include <stdio.h>
#include <limits.h>

#ifndef FACTORIAL_H_
#define FACTORIAL_H_

/**
 * Compute the factorial n! and does overflow detection.
 *
 * @param n - a positive integer value
 * @return -  the factorial n! if it is not overflow; otherwise 0.
 */
int factorial(int n);

#endif /* FACTORIAL_H_ */
