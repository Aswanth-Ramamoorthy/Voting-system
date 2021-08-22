/**
 * @file main.c
 *
 * @brief Implementation of main function
 *
 *
 *
 * @author Aswanth Ramamoorthy
 *
 *
 **/
#include "../include/function.h"
#include "../test/include/test_all_cases.h"
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char* argv[]) {

	int opt;
	while ((opt = getopt(argc, argv, "hati")) != -1) {

		switch (opt) {
		case 'i':
			printf("-t Runs automated unit testing a nd exits\n");
			printf("-a Runs main program and exits\n");
			printf("-h Instruction to run the program\n");
			return 0;
			break;

		case 't':
			// Run automated unit testing 
			printf("Running automated unit testing\n");
			test_all_cases();
			printf("Automated testing has completed\n");
			return 0;
			break;

		case 'h':
			printf("\nPlease Enter to follow the Below instructions to execute the software successfully\n");
			printf("\n\n");
			printf("\n************Please Follow The Below Steps To Execute The Program Successfully***********\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\nStep 1: Choose the mode to enter: Enter 1 for Admin or Enter 2 for User\n");
			printf("\n");
			printf("\nUser Mode\n");
			printf("\n");
			printf("\nStep 2: Enter Usename and Password when prompted\n");
			printf("\nStep 3: You will be prompted for secondary authentication details\n");
			printf("\nStep 4: Enter all the details needed (ID type, Name on ID & ID-Number) when prompted\n");
			printf("\nStep 5: Enter to view your details\n");
			printf("\nStep 6: Enter to view all the candidates in your province\n");
			printf("\nStep 7: Enter the Candidate number (Example: Candidate1, Candidate2, Candidate3) to vote\n");
			printf("\nStep 8: Your vote is casted\n");
			printf("\n");
			printf("\n");
			printf("\nAdmin Mode\n");
			printf("\n");
			printf("\nStep 2: Enter Admin ID and Password when prompted\n");
			printf("\nStep 3: You are logged in as admin and have access to view poll results\n");
			printf("\nStep 4: Enter src/data/vote_count.csv for normal execution and test/data/test_vote_count.csv for test mode\n");
			printf("\nStep 5: You can view the results now\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\nBelow Are Some Of The Valid Input Parameters For Test Cases Or Program Execution:\n");
			printf("\n");
			printf("\nInput Parameters Are Dependent On The Input Files\n");
			printf("\n");
			printf("\nAll Parameters Are Case Sensitive\n");
			printf("\n");
			printf("\n");
			printf("\nAdmin Login Inputs\n");
			printf("\n");
			printf("\nAdmin-ID: Admin\n");
			printf("\nPassword: white!23\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\nUser Details Inputs\n");
			printf("\n");
			printf("\nUsername:Aswanth\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\nCast Vote Inputs\n");
			printf("\n");
			printf("\nCandidate Id: Candidate1\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\nDisplay Results Inputs\n");
			printf("\n");
			printf("\nFilename: test/data/test_vote_count.csv\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\nCandidate Details Inputs\n");
			printf("\n");
			printf("\nProvince: Ontario\n");
			printf("\n");
			printf("\n");
			printf("\nSecondary Authentication Inputs\n");
			printf("\n");
			printf("\nID type: ID-Votercard\n");
			printf("\nName: Aswanth\n");
			printf("\nID-Number: 1111\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\nUser Login Inputs\n");
			printf("\n");
			printf("\nUsername: Priyanga\n");
			printf("\nPassword: Black3\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			return 0;
			break;

		case 'a':
			// Run Electronic Polling system program 

			printf("Electronic Polling System\n");

			int n;

			printf("\n\t\t\t\t==========================================");
			printf("\n\t\t\t\tWELCOME TO THE PRESIDENTIAL ELECTIONS 2020");
			printf("\n\t\t\t\t==========================================");
			printf("\n\nInstructions:\n\n");
			printf("1.You can vote only once.\n2.Login using your User-ID and Password.\n3.Proceed to vote if your information displayed is correct.\n4.Please be fair and impartial in voting");
			printf("\n\n\t\t\t\tIf you agree Press Enter to proceed...!!");
			if (fgetc(stdin))

				XY:
			printf("\n\n\n\t\t\t\t1. Admin Login\t\t2. User Login");//option to choose level of access
			printf("\n\n\n\t\t\t\t\tENTER YOUR CHOICE: ");
			scanf("%d", &n);//fetching input from user
			
			switch (n){
			
			case 1:
				admin_login();//secure admin login to view results
				break;
			
			case 2:
				user_login();//access to the polling system
				break;
			
			default: printf("\n\n\t\t\t\tNO MATCH FOUND");
				printf("\n\n\t\t\tPress Enter to re-Enter the choice");
				if (fgetc(stdin))
					goto XY; //option to retry
			}
			
		}
	}return 0;
}
