/*
 -------------------------------------
 File:    mymortgage.c
 Project: sing8282_a01
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-01-19
 -------------------------------------
 */

#include "mymortgage.h"

/**
 * Compute the monthly payment of given mortgage princile, annual interest rate (%), and mortgage years.
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - monthly payment, float type.
 */
float monthly_payment(float principal_amount, float annual_interest_rate,
		int years) {

	annual_interest_rate = annual_interest_rate / 100;
	float monthy_interest_rate = annual_interest_rate / 12;
	float number_of_periods = 12 * years;

	float a = principal_amount * (monthy_interest_rate);

	float b = pow((1 + monthy_interest_rate), number_of_periods);

	float c = 1 - (1 / b);

	float monthly_payment = a / c;

	return monthly_payment;
}

/**
 * Determine the total payment of loan given mortgage princile, annual interest rate (%), and mortgage years.
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - the total payment of the loan, float type.
 */
float total_payment(float principal_amount, float annual_interest_rate,
		int years) {

	float mon = monthly_payment(principal_amount, annual_interest_rate, years);

	return mon * years * 12;
}

/**
 * Determine the total interested payed for the loan given mortgage princile, annual interest rate (%), and mortgage years.
 *
 * @param principal_amount - float type.
 * @param annual_interest_rate - value of parcentage rate, e.g. 5 means 5%, float type.
 * @param years - number of mortgage year, int type.
 * @return - the total interest payed by the end of paying off the loan, float type.
 */
float total_interest(float principal_amount, float annual_interest_rate,
		int years) {

	float total = total_payment(principal_amount, annual_interest_rate, years);
	return total - principal_amount;
}
