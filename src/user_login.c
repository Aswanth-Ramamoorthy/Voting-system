/**
 * @file user_login.c
 *
 * @brief Implementation of user login login function with password encryption
 *
 *
 * @author Aswanth Ramamoorthy
 *
 **/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include"../include/user_login.h"
#include"../include/secondary_authentication.h"
/**
* @brief This function acts as a Authentication for the user to cast vote
*
* @param[in] The function does not take any input parameter but takes user_name and password
*
* as input from the user in input terminal
*
* and compares it with the data in the file.
*
* @param[out] This function calls secondary_authentication on successful user login
*
* @return Returns 0 on successful authentication and returns 1 on unsuccessful authentication
*
**/

int user_login(){

	char username[30];
	char password[30];
	FILE* fp = fopen("data/auth.csv", "r");//file containing user authentication details
	printf("\n--*--*--*--*--*--*--*--*--*");
	printf("\n\tUSER LOGIN\n");
	printf("--*--*--*--*--*--*--*--*--*\n");
	printf("Enter your username:\n");
	scanf("%s", &username); //fetching input from user
	fgetc(stdin);
	printf("Enter your password:\n");
	scanf("%s", &password);
	char string[1024];
	int row_count = 0;
	int field_count = 0, flag = 0;

	if (!fp) {

		printf("Can't open file\n");
		return 0; //returns when file does not exist
	}
	while (fgets(string, 1024, fp) && flag == 0){

		field_count = 0;
		row_count++;
		if (row_count == 1){

			continue;
		}
		char* field = strtok(string, ",");
		if (strcmp(field, username) == 0){  //compares entered username to that of auth.csv file

			field = strtok(NULL, ",");
			if (strcmp(field, password) == 0){  //compares entered password to that of auth.csv file

				while (field) {

					
					flag++;
					field_count++;
					break;
				}
			}
		}
	}
	if (flag == 0){
		char ch;
		printf("\nStatus:Invalid login");
		fgetc(stdin);
		printf("\n");
		printf("\n\n\t\t\t\t  (PRESS [y] and enter TO RE-LOGIN): ");
		scanf("%c",&ch);
		if (ch == 'y'|| ch == 'Y'){

			user_login(); //making the function available for user to retry
		}

	}else{

		printf("\nStatus:Successful Login");
		printf("\n\n");
		fgetc(stdin);
		printf("\n\nPress Enter to continue for Secondary Authentication");
		fgetc(stdin);
		secondary_authentication(username); //this function enables secured login for user
	}
	fclose(fp);
	return 0;

}

