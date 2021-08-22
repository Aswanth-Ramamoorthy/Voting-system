
#include "../test/include/test_all_cases.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define itoa(x)

int test_user_login(){

    char username[15];
    char password[12];
    FILE* fp = fopen("test/data/test_auth.csv", "r");//file containing user authentication details
    printf("\n--*--*--*--*--*--*--*--*--*");
    printf("\n\tUSER LOGIN\n");
    printf("--*--*--*--*--*--*--*--*--*\n");
    printf("Enter your username:\n");//fetching input from user
    scanf("%s", &username);
    fgetc(stdin);
    printf("Enter your password:\n");
    scanf("%s", &password);
    char string[1024];
    int row_count = 0;
    int field_count = 0, flag = 0;
    if (!fp){

        printf("Can't open file\n");
        return -1; //returns when file does not exist
    }
    while (fgets(string, 1024, fp) && flag == 0){

        field_count = 0;
        row_count++;
        if (row_count == 1){

            continue;
        }
        char* field = strtok(string, ",");

        if (strcmp(field, username) == 0){

            field = strtok(NULL, ",");

            if (strcmp(field, password) == 0){

                while (field){

                    flag++;
                    field_count++;
                    break;

                }
            }
        }
    }
    if (flag == 0)
    {
	char ch;
        printf("\nStatus:Invalid login");
        return 0;
	fgetc(stdin);
	printf("\n");
	printf("\n\n\t\t\t\t  (PRESS [y] and enter TO RE-LOGIN): ");
	scanf("%c",&ch);
	if (ch == 'y'|| ch == 'Y'){
        test_user_login();
	}

    }else{

        printf("\nStatus:Successful Login");
        printf("\n\n");
        printf("\n\n");
        return 1;
        printf("\nPress enter to proceed for secondary authentication");
        fgetc(stdin);
        test_secondary_authentication(username);
        
    }
    fclose(fp);


}

int test_user_details(char* name){

    char buf[1024];
    int row = 0, col = 0;
    printf("\n==========================================================================");
    printf("\n\n");
    printf("\n========================");
    printf("\nUSER INFORMATION");
    printf("\n========================");
    FILE* fp = fopen("test/data/test_user_details.csv", "r");
    if (!fp){

        printf("Can't open file\n");
        return -1;
    }while (fgets(buf, 1024, fp))

    {
        col = 0;
        row++;

        if (row == 1){

            continue;
        }
        char* field = strtok(buf, ",");
        printf("\n");
        char* string = field;
        string = strtok(NULL, ",");
        if (strcmp(field, name) == 0){

            while (field){

                if (col == 0){

                    printf("First Name:\t");
                
                }
                if (col == 1){

                    printf("Last Name:\t");
                    printf("%s\n", string);
                    col++;
                }
                if (col == 2){

                    printf("Age:\t");

                }
                if (col == 3){

                    printf("Phone:\t");
                }
                if (col == 4){

                    printf("Postal code:\t");
                }
                if (col == 5){

                    printf("Province:\t");
                    printf("%s\n", field);
                    printf("\n\nPress Enter to view the candidates in your Province...!!");
                    fgetc(stdin);
                    test_candidate_details(field);
                    return 0;
                    break;
                }
                if (col < 5 && col != 1){

                    printf("%s\n", field);
                    field = strtok(NULL, ",");
                    col++;
                }
            }
            printf("\n");
        }
       
    }
    fclose(fp);
    return 1;
 
}

char* test_intToString(int num, char* str){

    if (str == NULL){

        return NULL;
    }
    sprintf(str, "%d", num);
    return str;
}

char* test_getfield(char* line, int num){

    for (char* tok = strtok(line, ";");
        tok && *tok;
        tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int test_getFileColSize(char* tmp){

    char* tempHeaderRow = test_getfield(tmp, 1);
    char* token = strtok(tempHeaderRow, ",");
    int totalCols = 0;
    while (token != NULL){

        token = strtok(NULL, ",");
        totalCols++;
    }
    return totalCols;
}


char* tets_replace_char(char* str, char find, char replace){

    char* current_pos = strchr(str, find);
    while (current_pos){

        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }
    return str;
}

int test_cast_vote(char* province){

    FILE* fp;

    char buf[1024];
    char candidate_id[30];
    printf("\n==========================================");
    printf("\n::::::Cast Your Vote::::::");
    printf("\n------------------------------------------");
    printf("\n----Type in the Candidate Id (e.g Candidate1) and press Enter to cast your vote----------");
    printf("\n\n");
    printf("Enter your preferred Candidate Id here:");
    scanf("%s", &candidate_id);
    if ((strcmp(candidate_id, "Candidate1") == 0) || (strcmp(candidate_id, "Candidate2") == 0) || (strcmp(candidate_id, "Candidate3") == 0) || (strcmp(candidate_id, "Candidate4") == 0) || (strcmp(candidate_id, "Candidate5") == 0)){

        fp = fopen("test/data/test_vote_count.csv", "r+");

        if (!fp){

            printf("Can't open file\n");
            return -1;
        }

        FILE* tempVoteFile = fopen("test/data/temp.csv", "w+");
        int row = 0;
        while (fgets(buf, 1024, fp)){

            char* tmp = strdup(buf);
            char* tmp2 = strdup(buf);
            int fileColSize = test_getFileColSize(tmp2);
            static int selectedCandidateColIndexInFile;
            if (row == 0){

                char* tempHeaderRow = test_getfield(tmp, 1);
                fprintf(tempVoteFile, tempHeaderRow);
                char* token = strtok(tempHeaderRow, ",");
                int headerCol = 0;
                while (token != NULL){

                    if (strcmp(token, candidate_id) == 0){

                        selectedCandidateColIndexInFile = headerCol;
                        break;
                    }
                    token = strtok(NULL, ",");
                    headerCol++;
                }
                row++;
                continue;
            }
            printf("\n");
            char* tempRow = test_getfield(tmp, 1);
            char* token = strtok(tempRow, ",");
            const char* fieldProvince = token;
            if (strcmp(fieldProvince, province) == 0){

                int col = 1;
                while (token != NULL) {
                    if (selectedCandidateColIndexInFile == (col - 1)){

                        int tempToken = atoi(token);
                        tempToken++;
                        char str[20];
                        if (test_intToString(tempToken, str) != NULL){

                            fprintf(tempVoteFile, strcat(str, ","));
                        }

                    }
                    else {
                        if (col == fileColSize){

                            fprintf(tempVoteFile, "%s%s", token, "");
                        }
                        else {
                            fprintf(tempVoteFile, "%s%s", token, ",");
                        }
                    }

                    token = strtok(NULL, ",");
                    col++;
                }
            }
            else{
                int col = 1;
                while (token != NULL){

                    if (col == fileColSize){

                        fprintf(tempVoteFile, "%s%s", token, "");
                    }else{

                        fprintf(tempVoteFile, "%s%s", token, ",");
                    }
                    token = strtok(NULL, ",");
                    col++;
                }
            }
            free(tmp);
            row++;
        }
        fclose(fp);
        printf("\n");
        printf("Vote casted for your candidate: ");
        printf("%s", candidate_id);
        printf(" successfully.");
        printf("\n\nThank you!!!");
        printf("\n\n");
        printf("Press any key to exit");
        fgetc(stdin);
        fclose(tempVoteFile);
        remove("test/data/test_vote_count.csv");
        rename("test/data/temp.csv", "test/data/test_vote_count.csv");
        return 0;
    }else{

        printf("Please enter a valid candidate number as given in the e.g");
        printf("\n\n");
        return 1;
        test_cast_vote(province);
    }
    return -2;
}

int test_candidate_details(char* province){

    char buf[1024];
    printf("\n==========================================");
    printf("\nCANDIDATES INFORMATION");
    printf("\n------------------------------------------");
    FILE* fp = fopen("test/data/test_candidate_details.csv", "r");
    if (!fp){

        printf("Can't open file\n");
        return -1;
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
        char* tempRow = test_getfield(tmp, 1);

        char* token = strtok(tempRow, ",");
        const char* fieldProvince = token;

        if (strcmp(fieldProvince, province) == 0){

            int col = 1;
            while (token != NULL){

                if (col == 1){

                    printf("Below are your candidates for your Province:");
                    printf("%s", token);
                    printf("\n--------------------------");
                    col++;
                    continue;

                }else if (col > 2){

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
    printf("\nPress Enter to vote...!!");
    return 0;
    printf("\n\n\n");
    test_cast_vote(province);

}

int test_admin_login() {

    char adminID[15];
    char adminpass[12];
    printf("Enter your Admin-ID:\n");
    scanf("%s", &adminID);
    printf("Enter your password:\n");
    scanf("%s",&adminpass);
    fgetc(stdin);
    if (strcmp(adminID, "Admin") == 0) {

        if (strcmp(adminpass, "white!23") == 0) {

            printf("\nWelcome.Login Success!");
            return 0;
            test_display_count();


        }
        else {
	    char ch;
            printf("\nwrong password");
	    return 1;
	    fgetc(stdin);
	    printf("\n\n\t\t\t\t  (PRESS [y] and enter TO RE-LOGIN): ");
	    scanf("%c",&ch);
	    if (ch == 'y'|| ch == 'Y'){
                test_admin_login();
            }

        }
    }return -2;
}


int test_secondary_authentication(char* name){

    char ID_type[40];
    char ID_number[40];
    char name_on_ID[40];
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
    FILE* fp = fopen("test/data/test_second_auth.csv", "r");
    char string[1024];
    int row_count = 0;
    int field_count = 0, flag = 0;
    if (!fp){

        printf("Can't open file\n");
        return 0;
    }
    while (fgets(string, 1024, fp) && flag == 0){

        field_count = 0;
        row_count++;
        if (row_count == 1){

            continue;
        }
        char* field = strtok(string, ",");
        if (strcmp(field, name_on_ID) == 0 && strcmp(name_on_ID, name) == 0){

            field = strtok(NULL, ",");
            if (strcmp(field, ID_type) == 0){


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
        return 0;
	printf("\n");
	printf("\n\n\t\t\t\t  (PRESS [y] and enter TO RE-LOGIN): ");
	scanf("%c",&ch);
	if (ch == 'y'|| ch == 'Y'){
            test_secondary_authentication(name);
        }

    }else{

        printf("\nStatus:Successful Login");
          
        printf("\n\nSelected ID is Valid");
        printf("\nPress Enter to display your details...!!");
        fgetc(stdin);
        test_user_details(name);
        return 1;

    }
    fclose(fp);
    return -2;
}


int test_display_count(){

    char filename[100];

    printf("\nEnter the filename in the following format to open \n");
    printf("\nExample: test/data/filename\n");
    scanf("%s", &filename);

    // Open file
    FILE* fp = fopen(filename, "r");
    if (!fp){
                char ch;
		printf("Cannot open file \n");
		return 0;
		printf("\n\n\t(PRESS [Y] TO RE-ENTER file name)");
                scanf("%c",&ch);
		if (ch == 'y' || ch == 'Y')  {
            test_display_count();
            
        }
    }
    // Read contents from file
    char c = fgetc(fp);
    while (c != EOF){

        printf("%c", c);
        c = fgetc(fp);
    }

    fclose(fp);
    return 1;
}

int test_all_cases() {

    printf("\n\t\t\t\t============================================");
    printf("\n\t\t\t\tTest Functions for Electronic Polling System");
    printf("\n\t\t\t\t============================================");
    printf("\n\n\t\t\t\tIf you agree Press Enter to proceed...!!");
    fgetc(stdin);
    int value, choice;
    FILE* test_output = fopen("test/data/test_output.csv", "w");
    printf("\n1. Enter 1 to test admin login function.\n");
    printf("\n2. Enter 2 to test user details function.\n");
    printf("\n3. Enter 3 to test cast vote function.\n");
    printf("\n4. Enter 4 to test display results function.\n");
    printf("\n5. Enter 5 to test candidate details function.\n");
    printf("\n6. Enter 6 to test secondary authentication function. \n");
    printf("\n7. Enter 7 to test user login function.\n");
    scanf("%d", &choice);
    switch (choice) {

    case 1:
        printf("\nTesting admin login function\n");

        value = test_admin_login(); //Passing correct username and wrong password
        if (value == 0) {

            char c[400];
            sprintf(c, "1)Criteria Passed with correct username and password, Expected Output: 0, Output: %d .\n", value);
            printf(c);
            fprintf(test_output, c);
        }
        else {

            char c[400];
            sprintf(c, "1)Criteria Failed with incorrect username and password, Expected Output: 1, Output: %d .\n", value);
            printf(c);
            fprintf(test_output, c);
        }

        fclose(test_output);
        break;

    case 2:
        printf("\n\nTesting user details function.\n");

        //Input parameter does not affect filename as it is passed internally
        //No other criteria is checked here as this function is called from user_details function where all conditions are already checked
        //To check the working of the functionality me manually provided the username

        char uname[30];
        printf("Enter the username by captializing each word:");
        scanf("%s", &uname);
        printf("\n");
        value = test_user_details(uname);
        printf("\n");
        if (value == 0) // When user credentials are valid
        {
            char c[400];
            sprintf(c, "2)Criteria Passed with provided username, Expected Output: 0, Output: %d .\n", value);
            printf(c);
            fprintf(test_output, c);
        }
        else {
            //When user credentials are invalid
            char c[400];
            sprintf(c, "2)Criteria Failed with provided usernmae, Expected Output: 1, Output: %d .\n", value);
            printf(c);
            fprintf(test_output, c);
        }
        break;
        fclose(test_output);

    case 3:
        printf("\n\nTesting cast_vote function.\n");

        // Test case  - Vote count should be incremented for each candidate from votes by users under each province 
        //Input parameter does not affect filename as it is passed internally.

        value = test_cast_vote("Ontario");
        printf("\n");
        if (value == 0) // When Candidate_Id is valid
        {
            char c[400];
            sprintf(c, "2)Criteria Passed with valid Candidate_ID, Valid Candidate_Id, Expected Output: 0, Output: %d .\n", value);
            printf(c);
            fprintf(test_output, c);
        }
        else {
            // When Candidate_Id is not valid
            char c[400];
            sprintf(c, "2)Criteria Failed with valid Candidate_ID, valid Candidate_Id: Candidate1, Expected Output: 1, Output: %d .\n", value);
            printf(c);
            fprintf(test_output, c);
        }
        break;
        fclose(test_output);

    case 4:
        printf("\n\nTesting display results function.\n");

        // Test case  - Display results of poll if the file exists

        value = test_display_count();

        //Input parameter does not affect filename as it is passed internally

        printf("\n");

        if (value == 1)//When file name is Valid
        {
            char c[400];
            sprintf(c, "1)Criteria Passed with valid Filename: test_vote_count.csv, Expected Output: 1, Output: %d .\n", value);
            printf(c);
            fprintf(test_output, c);
        }
        else {
            char c[400];
            sprintf(c, "1)Criteria Failed with invalid Filename: vote_count.csv, Expected Output: 0, Output: %d .\n", value);
            printf(c);
            fprintf(test_output, c);
        }

        break;
        fclose(test_output);

    case 5:

        printf("\n\nTesting candidate details function.\n");
        char province[60];
        printf("Enter Province\n");
        scanf("%s", &province);

        // Test case  - Display candidate details if the file exists
        //This function gets the inputs(i.e province) from the previous function test_user_details it only returns the correct candidatate details
        //For testing the functionality manually pass the input(i.e 'Ontario','Alberta','Quebec')

        value = test_candidate_details(province);

        printf("\n");
        if (value == 0) {

            char c[400];
            sprintf(c, "1)Criteria Passed with valid provided province ; Expected Output : 0, Output : % d .\n", value);
            printf(c);
            fprintf(test_output, c);

        }
        break;
        fclose(test_output);

    case 6:

        printf("\n\nTesting secondary authentication function");
        char name[30];
        printf("Enter the name\n");
        scanf("%s", &name);

        //Input parameter does not affect filename as it is passed internally
        //This function gets the inputs(i.e Username) from the previous function test_user_login. 
        //For testing the functionality manually pass the input(i.e 'Aswanth','Vignesh')
        value = test_secondary_authentication(name);
        printf("\n");

        if (value == 1) // When user secondary details are valid
        {
            char c[400];
            sprintf(c, "2)Criteria Passed -matching ID-Type,ID-number and name_on_ID,Expected Output: 1, Output: %d .\n", value);
            printf(c);
            fprintf(test_output, c);
        }
        else {

            char c[400];
            sprintf(c, "2)Criteria Failed - unmatched ID-Type,ID-number and name_on_ID, Expected Output: 0, Output: %d .\n", value);
            printf(c);
            fprintf(test_output, c);
        }break;
        fclose(test_output);

    case 7:
        printf("\n\nTesting user_login function");
        // Test case  - Check whether the user is authenticated if file is found
        value = test_user_login();
        if (value == 1) // When Username and Password are correct
        {
            char c[400];
            sprintf(c, "2)Criteria Passed with correct Username ,Password, Expected Output: 1, Output: %d .\n", value);
            printf(c);
            fprintf(test_output, c);

        }
        else {

            char c[400];
            sprintf(c, "2)Criteria Failed with incorrect Username, Password, Expected Output: 0, Output: %d .\n", value);
            printf(c);
            fprintf(test_output, c);
        }

        break;
        fclose(test_output);
    }
    return 0;   
}
