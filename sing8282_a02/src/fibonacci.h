/*
 -------------------------------------
 File:    fibonacci.h
 Project: sing8282_a02
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-01-22
 -------------------------------------
 */

#include <stdio.h>

#ifndef FIBONACCI_H_
#define FIBONACCI_H_

/**
 * Computes the nth Fibonacci number using iterative algorithm
 *
 * @param n - a positive integer value
 * @return -  nth Fibonacci number
 */
int iterative_fibonacci(int n);

/**
 * Computes the nth Fibonacci number using recursive algorithm
 *
 * @param n - a positive integer value
 * @return -  nth Fibonacci number
 */
int recursive_fibonacci(int n);

/**
 * Computes the nth Fibonacci number using dynamic programming bottom-up method
 *
 * @param n - a positive integer value
 * @return -  nth Fibonacci number
 */
int dpbu_fibonacci(int *f, int n);

/**
 * Computes the nth Fibonacci number using dynamic programming top-down method
 *
 * @param n - a positive integer value
 * @return -  nth Fibonacci number
 */
int dptd_fibonacci(int *f, int n);
#endif /* FIBONACCI_H_ */
