/**
 * @file display_count.c
 *
 * @brief Implementation of display_count function to display the final count of the
 * votes casted.
 *
 *
 * @author Aswanth Ramamoorthy
 *
 *
 **/

#include<stdio.h>
#include<string.h>
#include"../include/display_count.h"

/**
 * The function displays a final cont of the votes present in the file.
 * @param[in] the function takes “filename” as input parameter.
 *
 * @param[out] the function displays the "vote_count.csv" file as the output.
 *
 *
 * @return Return 0 when file opens and return 1 when filename is invalid.
 *
 **/

int display_count(){

	char filename[100];

	printf("\nEnter the filename in the following format to open \n");
	printf("\nExample: data/filename\n");
	scanf("%s", filename);//reads file name from input by admin 

	// Open file
	FILE* fp = fopen(filename, "r");//file to display
	if (fp == NULL){
                char ch;
		printf("Cannot open file \n");
		printf("\n\n\t(PRESS [Y] TO RE-ENTER file name)");
        scanf("%c",&ch);
		if (ch == 'y' || ch == 'Y') {
			display_count();//option to retry 

		}
	}

	// Read contents from file
	printf("\n\nTHE NUMBER VOTES CASTED FOR INDIVIDUAL CANDIDATES IN PARTICULAR PROVINCE\n");
	char c = fgetc(fp);
	while (c != EOF){
		printf("%c", c);
		c = fgetc(fp); // To read contents from file
	}
	fclose(fp);
	return 0;
}
