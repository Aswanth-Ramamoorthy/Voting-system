# Introduction

Electronic Polling machine is a software to enable the users to vote with highly authentic and reliable polling system with the ease of voting on the go, so that one does not fail to cast their vote, by using this application.

# Requirement

Software enables user to cast the vote by giving their credentials as input and each function is called from the other.

# Assumption

- It is assumed that functionality to add, update and delete the list of voters and candidate records (nominees) are provided by an existing system and is not part of this problem.
- The list of voters as well as the candidates of the province are maintained in the database.
- Every citizen eligible to vote is provided with a secure identification number by the government.
- The user credentials are maintained in a highly secure server and is accessible only by an authorized official (Admin).
- The winner of the total elections is decided based on the total votes recieved in each province and to be classified as confedential.


# Program Flow

The program flow for the application is as follows:


- The main.c file calls the functions in user_login and admin_login based on user input to run the alogorithm.
- The user_login function calls:
  - The function in user_login.c to get the valid login credentials from the voter i.e(username and password) and compare it as given in auth.csv file.
  - The function in secondary_authentication.c to get identity proof details of the voter from a government approved proof such as Voter_card, Passport and Provincial_card.
  - The function in user_details.c to display the detailed information about the voter such as First_name, Last_name, Age, Phone_number, Postal_code and Province.
  - The function in candidate_details.c to display the list of all the candidates available based on province of the voter.
  - The function in get_field.c to read the field of any csv file.
  - The function in int_to_string.c to convert integer to string.
  - The function in get_file_column_size.c to read the column values of the csv files.
  - The function in cast_vote.c to enable the users to cast the vote from list of candidates displayed according to their respective province.
  - The function in attempt_count.c to keep track of voting history of the voter for preventing duplicate entries.

- The admin_login function calls:
  - The function in admin_login.c to get the valid login credentials from admin i.e(username and password).
  - The function in display_count.c gets input from admin and displays the votes secured by candidates in each province.
 

# Documentation

Complete documentation of the source code can be found [here](https://github.com/Epolling/Electronic_Polling_system/tree/dev/doc/html/index.html).
