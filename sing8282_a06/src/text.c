/*
 -------------------------------------
 File:    text.c
 Project: sing8282_a06
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-04-12
 -------------------------------------
 */
#include"expression.h"
#include <math.h>

//Write a program to add and subtract 10hrs 20mins 50sec and 5hrs 30min 40sec.

typedef struct time {
	int hrs;
	int mins;
	int seconds;
} TIME;

void checkValidTime(TIME *time) {
	if (time->hrs < 0 && time->hrs > 24) {
		perror("InValid Hours");
		return;
	}

	if (time->mins > 60 && time->mins < 0) {
		perror("InValid Invalid Minutes");
		return;
	}

}
