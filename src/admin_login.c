/**
 * @file admin_login.h
 *
 * @brief Implementation of admin login function for access to the system
 *
 *
 * @author Aswanth Ramamoorthy
 *
 **/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../include/admin_login.h"
#include"../include/display_count.h"

/**
 * @brief This function is to authenticate admin into the system
 *
 *
 * @details This function compares the input(i.e Admin-ID and Password) given
 * by the Admin.when the comparison gets successful the output will display as
 * Welcome.Login success!
 *
 * @param[in] It takes the Admin-ID, Password and File name as the input parameter.
 *
 * @return Return 0 on successful login and 1 if login failed.
 *
 **/
int admin_login(){

	char adminID[15];
	char adminpass[12];
	printf("Enter your Admin-ID:\n");
	scanf("%s", &adminID);//inputs admin ID from user
	fgetc(stdin);
	printf("Enter your password:\n");
	scanf("%s",&adminpass);
	fgetc(stdin);
	if (strcmp(adminID, "Admin") == 0) {

		if (strcmp(adminpass, "white!23") == 0) {

			printf("\nWelcome.Login Success!");
			display_count();//calls the display_count function 

		}
		else {
			char ch;
			printf("\nwrong password");
			fgetc(stdin);
			printf("\n\n\t\t\t\t  (PRESS [y] and enter TO RE-LOGIN): ");
			scanf("%c",&ch);
			if (ch == 'y'|| ch == 'Y'){ 
				admin_login();//call the admin_login function again to get the inputs
			}

		}
	}return 0;
}


