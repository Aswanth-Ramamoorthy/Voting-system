/**
 * @file candidate_details.h
 *
 * @brief Implementation of candidate_details function to display the candidates contesting in
 * a particular province
 *
 *
 * @author Aswanth Ramamoorthy
 *
 *
 **/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../include/get_field.h"
#include"../include/candidate_details.h"
#include"../include/cast_vote.h"

/**
 * @brief The function displays a list of candidates present in the file.
 *
 * @param[in] The function takes “province” as input parameter.
 *
 * @param[out] The function displays candidate details in the logged in user's province
 *
 * @return Return 0 when entered province is valid else return 1
 *
 **/

int candidate_details(char* province, char* username){

	char buf[1024];
	printf("\n==========================================");
	printf("\nCANDIDATES INFORMATION");
	printf("\n------------------------------------------");
	FILE* fp = fopen("data/candidate_details.csv", "r");
	if (!fp) {

		printf("Can't open file\n"); //returns when file does not exist
		return 0;
	}

	int row = 0;
	province = strtok(province, "\r\n");

	while (fgets(buf, 1024, fp)){

		if (row == 0){

			row++;
			continue;
		}

		char* tmp = strdup(buf);
		printf("\n");
		char* tempRow = get_field(tmp, 1);

		char* token = strtok(tempRow, ",");
		const char* fieldProvince = token;

		if (strcmp(fieldProvince, province) == 0){   //compares province of logged in user with that of candidate_details.csv file

			int col = 1;
			while (token != NULL){

				if (col == 1){

					printf("Below are your candidates for your Province:");
					printf("%s", token);
					printf("\n--------------------------");
					col++;
					continue;
				}
				else if (col > 2) {

					printf("\nCandidate");
					printf("%d", col - 2);
					printf(": ");
					printf("%s", token);
					printf("\n");
				}

				token = strtok(NULL, ",");
				col++;
			}
		}

		free(tmp);
		row++;
	}
	fclose(fp);
	printf("Press enter to cast your vote\n");
	fgetc(stdin);
	cast_vote(province,username);
	return 0;
	
}
