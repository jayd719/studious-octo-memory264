/*
 -------------------------------------
 File:    myword.c
 Project: sing8282_a03
 file description
 -------------------------------------
 Author:  Jashandeep Singh
 ID:      169018282
 Email:   sing8282@mylaurier.ca
 Version  2024-02-01
 -------------------------------------
 */

#include"myword.h"
#include <string.h>

#define MAX_LEN 10
#define MAX_WORDS 1000

/*
 * Load word data from file, and insert words a directory represented by char array.
 *
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored.
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.
 */
int create_dictionary(FILE *fp, char *dictionnary) {
	int words = 0;
	char c;

	char word[20];
	int j = 0;

	while (!feof(fp)) {
		c = fgetc(fp);
		if (c == ',' || c == '\0' || c == '\n' || c == ' ' || c == '.'
				|| feof(fp)) {
			word[j] = '\0';
			j = 0;
			strncpy(dictionnary + (MAX_LEN*words), word, MAX_LEN);
			words++;
		} else {
			word[j] = c;
			j += 1;
		}
	}
	return words;

}

/*
 * Determine if a given word is contained in the given dictionary.
 *
 * @param *dictionary -  char pointer to a char array of given dictionary.
 * @param *word  -  pointer to a given word.
 *
 * @return - TRUE if the word is in the dictionary, FALSE otherwise.
 */
BOOLEAN contain_word(char *dictionary, char *word) {
	enum boolean contains;
	contains = false;
	char *k;

	int i = 0;
	while (i < 122 && contains == false) {
		char *c = word;
		k = (dictionary + (MAX_LEN * i));
		enum boolean equals = true;
		while (*c && *k && equals == true) {
			if (*c != *k) {
				equals = false;
			}
			c++;
			k++;
		}

		if (!*c && !*k && equals == true) {
			contains = true;
		}

		i++;
	}
	return contains;

}

/*
 * Process text data from a file for word statistic information of line count, word count, keyword count, and frequency of keyword.
 *
 * @param *fp -  FILE pointer of input text data file. .
 * @param *words  -  WORD array for keywords and their frequencies.
 * @param *dictionary  -  stop-word/common-word dictionary.
 *
 * @return - WORDSTATS value of processed word stats information.
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {

	WORDSTATS stats = { 0, 0, 0 };

	char wo[20];
	int j = 0;
	char buf[128];
	while (!feof(fp)) {
		if (fgets(buf, sizeof(buf), fp)) {
			stats.word_count += str_words(buf);
			stats.line_count += 1;

			str_lower(buf);

			char *k;
			k = buf;
			char wordStarted = 'n';
			while (*k) {
				if ((*k == ',' || *k == ' ' || *k == '.' || *k == '\n')
						&& wordStarted == 'y') {

					wo[j] = '\0';
					j = 0;
//					printf("%s\n", wo);
					if (!contain_word(dictionary, wo)) {
						WORD word;
						word.count = 1;
						strcpy(word.word, wo);

						words[stats.keyword_count] = word;
						stats.keyword_count += 1;

						printf("%s\n", wo);

					}

					wordStarted = 'n';

				} else if ((*k >= 'A' && *k <= 'Z')
						|| (*k >= 'a' && *k <= 'z')) {

					wo[j] = *k;
					j++;
					wordStarted = 'y';
				}

				k++;
			}
		}

	}

	return stats;

}
