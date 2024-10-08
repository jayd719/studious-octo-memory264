/*
 -------------------------------------
 File:    myrecord.c
 Project: sing8282_a04
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-06
 -------------------------------------
 */
#include"myrecord.h"
/*
 * Convert a percentage grade to letter grade defined by percentage ranges
 * A+=[90, 100], A=[85, 90), A-=[80, 85), B+=[77, 80), B=[73, 77) B=[70, 73),
 * C+=[67, 70), C=[63, 77), C-=[60, 63), D+=[57,60),D=[53,57),D=[50,53), F=[0,50).
 *
 * @param score -  percetage grade.
 *
 * @return - letter grade wrapped in GRADE structure type.
 */
GRADE grade(float score) {
	GRADE grade;

	if (score >= 90.0) {
		strcpy(grade.letter_grade, "A+");
	} else if (score >= 85.0) {
		strcpy(grade.letter_grade, "A");

	} else if (score >= 80.0) {
		strcpy(grade.letter_grade, "A-");

	} else if (score >= 77.0) {
		strcpy(grade.letter_grade, "B+");

	} else if (score >= 73.0) {
		strcpy(grade.letter_grade, "B");

	} else if (score >= 70.0) {
		strcpy(grade.letter_grade, "B-");

	} else if (score >= 67.0) {
		strcpy(grade.letter_grade, "C+");

	} else if (score >= 63.0) {
		strcpy(grade.letter_grade, "C");

	} else if (score >= 60.0) {
		strcpy(grade.letter_grade, "C-");

	} else if (score >= 57.0) {
		strcpy(grade.letter_grade, "D+");

	} else if (score >= 53.0) {
		strcpy(grade.letter_grade, "D");

	} else if (score >= 50.0) {
		strcpy(grade.letter_grade, "D-");

	}

	else {
		strcpy(grade.letter_grade, "F");
	}
	return grade;
}

/*
 *  Import record data from file and retrieves and stores all record entries
 *  in the RECORD array passed by records, and returns the number of record count.
 *
 *  @param *fp -  FILE pointer to intput file.
 *  @param dataset - array of RECODR type to store record data.
 *  @return   - number record count
 */
int import_data(FILE *fp, RECORD *dataset) {
	int records = 0;
	char myString[100];

	// Read the content
	while (fgets(myString, 100, fp)) {

		RECORD record;
		int i = 0;
		while (i < strlen(myString) && myString[i] != ',') {
			record.name[i] = myString[i];
			i++;
		}
		record.name[i] = '\0';

		char float_string[10];

		int j = 0;
		i++;
		while (i < strlen(myString)) {
			float_string[j] = myString[i];
			j++;
			i++;
		}
		float_string[j] = '\0';

		record.score = strtod(float_string, NULL);

		dataset[records] = record;

		records++;
	}

	return records;
}

/*
 *  Take the RECORD data array as input, compute the average score, standard deviation,
 *  median of the score values of the record data, and returns the results in STATS type.
 *
 *  @param dataset -  input record data array.
 *  @param count -  the number of data record in dataset array.
 *  @return  -  stats value in STATS type.
 */
STATS process_data(RECORD *dataset, int count) {
	STATS stats;
	stats.count = count;

	float sum = 0;
	for (int i = 0; i < count; i++) {
		sum += dataset->score;
		dataset++;
	}
	stats.mean = sum / stats.count;

	return stats;
}

/*
 *  This function takes output file named outfilename,
 *  RECORD array by records,and output stats information,
 *   and processed record data to files in required format.
 *
 *  @param *fp -  FILE pointer to output file.
 *  @param count -  the number of data record in dataset array.
 *  @return - returns 1 if successful; 0 if count < 1
 */
int report_data(FILE *fp, RECORD *dataset, int count) {

	if (count < 1)
		return 0;

	for (int i = 0; i < count; ++i) {
		fprintf(fp, "%s,%.2f,%s\n", dataset->name, dataset->score,
				grade(dataset->score).letter_grade);
		dataset++;
	}
	return 1;
}
