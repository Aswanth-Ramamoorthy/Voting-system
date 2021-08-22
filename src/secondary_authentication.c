/**
 * @file secondary_authentication.c
 *
 * @brief Implementation of two step authentication for casting vote.
 *
 *
 * @author Aswanth Ramamoorthy
 *
 **/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../include/secondary_authentication.h"
#include"../include/user_details.h"

/**
* @brief This function acts as a two-factor authentication for the user to cast vote.
*
*
* @details This function displays the available ID proofs the user possesses and when
*
* the user selects the ID proof and passes the ID number as the input.
*
* It compares the given input with the existing data in the file.
*
* Once they match the user gets authenticated.
*
* @param[in] The function takes "name" as the input parameter which is the logged in username
*
* @param[out] The function calls the user_details function and displays the user information.
*
* @return Returns 0 on unsuccessful authentication and 1 for successful authentication
**/


int secondary_authentication(char* name){

	char ID_type[20];
	char ID_number[20];
	char name_on_ID[30];
	printf("\n===========================================================================");
	printf("\nSecondary Authentication");
	printf("\n\n\nBelow are the list of Available ID's that are accepted to cast your vote");
	printf("\n\t 1.Voter card.\n\t 2.Passport.\n\t 3.Provincial card");
	printf("\n\nIf you have any one of this ID's Press Enter to proceed...!!\n");

	fgetc(stdin);
	printf("\n===========================================================================\n");

	printf("\n\n");

	printf("Please enter your ID type\n\t(Hint:ID-Votercard \n\t\tID-Passport\n\t\tID-ProvincialCard) :");
	scanf("%s", &ID_type);

	printf("\nEnter your name (Exactly printed on your ID):");
	scanf("%s", &name_on_ID);

	printf("\nEnter the ID-number(Exactly Printed on your ID):");
	scanf("%s", &ID_number);
	int b = atoi(ID_number);
	FILE* fp = fopen("data/second_auth1.csv", "r");//file that has details of user's secondary authentication
	char string[1024];
	int row_count = 0;
	int field_count = 0, flag = 0;
	if (!fp){

		printf("Can't open file\n");
		return 0; //returns when file not found

	}while (fgets(string, 1024, fp) && flag == 0){

		field_count = 0;
		row_count++;
		if (row_count == 1){

			continue;
		}
		char* field = strtok(string, ",");
		if (strcmp(field, name_on_ID) == 0 && strcmp(name_on_ID, name) == 0){    //compares data entered by user with data in file

			field = strtok(NULL, ",");
			if (strcmp(field, ID_type) == 0){   //compares user id type with that in file

			 	field = strtok(NULL, ",");
				int a = atoi(field);
				if (a == b){

					while (field){

						flag++;
						field_count++;
						break;
					}
				}
			}
		}
		if (strcmp(name, name_on_ID) != 0){

			flag = 0;
		}
	}
	if (flag == 0){
		char ch;
		printf("\nStatus:Invalid User ID's");
		fgetc(stdin);
		printf("\n");
		printf("\n\n\t\t\t\t  (PRESS [y] and enter TO RE-LOGIN): ");
		scanf("%c",&ch);
		if (ch == 'y'|| ch == 'Y'){
			secondary_authentication(name);//option to retry
		}
	}else{

		printf("\nStatus:Successful Login");
		printf("\n\nSelected ID is Valid");
	        fgetc(stdin);
		printf("\nPress Enter to display your details...!!");
		fgetc(stdin);
		user_details(name);// TO call the user details function to display user details

	}
	fclose(fp);
	return 0;
}

