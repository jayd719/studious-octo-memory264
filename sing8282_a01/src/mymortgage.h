/*
 -------------------------------------
 File:    mymortgage.h
 Project: sing8282_a01
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-01-19
 -------------------------------------
 */
#ifndef MYMORTGAGE_H_
#define MYMORTGAGE_H_

#include <stdio.h>
#include "math.h"

/**
 * Compute the monthly payment of given mortgage princile, annual interest rate (%), and mortgage years.
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - monthly payment, float type.
 */
float monthly_payment(float principal_amount, float annual_interest_rate,
		int years);

/**
 * Determine the total payment of loan given mortgage princile, annual interest rate (%), and mortgage years.
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - the total payment of the loan, float type.
 */
float total_payment(float principal_amount, float annual_interest_rate,
		int years);

/**
 * Determine the total interested payed for the loan given mortgage princile, annual interest rate (%), and mortgage years.
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - the total interest payed by the end of paying off the loan, float type.
 */
float total_interest(float principal_amount, float annual_interest_rate,
		int years);

#endif /* MYMORTGAGE_H_ */
