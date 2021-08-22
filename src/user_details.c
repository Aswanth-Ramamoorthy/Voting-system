/**
 * @file user_details.c
 *
 * @brief Implementation of displaying the user details.
 *
 *
 * @author Aswanth Ramamoorthy
 *
 **/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../include/user_details.h"
#include"../include/candidate_details.h"

/**
* @brief This function is to display the user details from the file.
*
*
* @details This function displays the available user information such as First name ,Last name,
* Age,Phone Number ,postal code and Province.
*
* It compares the given input(i.e Username) with the existing data in the file.
*
*
* @param[in] The function takes the User name as the input parameter.
*
* @param[out] The function calls the candidate_details function and displays the candidates in the user's province.
*
* @return Returns 0 if the username matches with the one in file, Returns 1 if name is not valid in file
**/

int user_details(char* name) {

	char buf[1024];
	int row = 0, col = 0;
	printf("\n==========================================================================");
	printf("\n\n");
	printf("\n========================");
	printf("\nUSER INFORMATION");
	printf("\n========================");
	FILE* fp = fopen("data/userdetails.csv", "r");//Open file containing details of all users or voters
	if (!fp) {

		printf("Can't open file\n");
		return 0;//returns when file does not exist

	}while (fgets(buf, 1024, fp)) {

		col = 0;
		row++;

		if (row == 1) {

			continue;
		}
		char* field = strtok(buf, ",");
		printf("\n");
		char* string = field;
		string = strtok(NULL, ",");
		if (strcmp(field, name) == 0) {  //compares username fetched from previous function with that of user_details file

			while (field) {

				if (col == 0) {

					printf("First Name:\t"); //prints First Name value fetched from file
				}
				if (col == 1) {

					printf("Last Name:\t");  //prints Last Name fetched from file
					printf("%s\n", string);
					col++;
				}
				if (col == 2) {

					printf("Age:\t");  //prints Age fetched from file

				}
				if (col == 3) {

					printf("Phone:\t");  //prints Phone number fetched from file
				}
				if (col == 4) {

					printf("Postal code:\t"); //prints postal code fetched from file
				}
				if (col == 5) {

					printf("Province:\t"); //prints province fetched from file
					printf("%s\n", field);
					char* voted = strtok(NULL, ",");
					if (voted[0] == 'n')
					{
						printf("\n\nPress Enter to view the candidates in your Province...!!");
						fgetc(stdin);
						fclose(fp);
						candidate_details(field, name);
						break;
					}else {
						printf("\n\nYou already casted the vote to-");
					}


				}
				if (col < 5 && col != 1) {

					printf("%s\n", field);
					field = strtok(NULL, ",");
					col++;
				}
			}
			printf("\n");
		}
	}
        fclose(fp);
	return 0;
}
