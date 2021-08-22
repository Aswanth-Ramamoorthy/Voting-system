/**
 * @file attempt_count.c
 *
 * @brief Implementation of attempt_count function to prevent the user from casting duplicate votes
 *
 *
 * @author Aswanth Ramamoorthy
 *
 **/

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"../include/attempt_count.h"

/**
 * @brief This function to prevent the user who already casted vote.
 *
 *
 * @details This function records every attempt made by an user to vote.
 * After one successful vote(attempt>=1) the user is restricted further voting .
 *
 *
 *
 * @param[in] It takes the username as the input parameter.
 *
 * @return This function has no return value.(This function is used to make necessary changes to the files)
 *
 **/

int attempt_count(char* username)
{

	// File pointer to hold reference of input file 

	FILE* fPtr;
	FILE* fTemp;
	char buffer[1000];
	int line, count;


	//  Open all required files 

	fPtr = fopen("data/userdetails.csv", "r+");
	fTemp = fopen("data/replace.csv", "w+");

	// fopen() return NULL if unable to open file in given mode.
	if (fPtr == NULL || fTemp == NULL) {

		// Unable to open file hence exit 
		printf("\nUnable to open file.\n");
		printf("Please check whether file exists and you have read/write privilege.\n");
		exit(EXIT_SUCCESS);
	}
	//Read line from source file and write to destination
	// file after replacing given line.

	count = 0;
	line = 1;
	while ((fgets(buffer, 1000, fPtr)) != NULL) {

		count++;
		char buf[1000];
		strncpy(buf, buffer, 1000);
		char* name = strtok(buf, ",");
		//If current line is line to replace 
		if (strcmp(name, username) == 0) {

			int i = 0;
			for (int j = 0; j < 1000; j++) {

				if (buffer[j] == ',')
					i++;
				if (i > 5) 
					break;
				fputc(buffer[j], fTemp);
			}
			fputc(',', fTemp);
			fputc('y', fTemp);
			fputc('\n', fTemp);

		}
		else {
			fputs(buffer, fTemp);
		}
	}


	// Close all files to release resource 
	fclose(fPtr);
	fclose(fTemp);


	// Delete original source file 
	remove("data/userdetails.csv");

	// Rename temporary file as original file 
	rename("data/replace.csv", "data/userdetails.csv");

    return 0;


}
