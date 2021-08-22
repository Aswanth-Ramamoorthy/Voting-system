# Introduction

Electronic Polling machine is a software that allows users to vote with high authenticity, reliability and ease of voting on the go.

# Installation

Please refer to [INSTALL.md](https://github.com/Epolling/Electronic_Polling_system/blob/dev/INSTALL.md) file for installation instructions.

# Usage

- The following parameters are to be given after the launching executable file Epoll.
- The user needs to input whether he wants to login as 1.admin or as 2.voter 

- In case of Voter :
  - The Voter should enter name and password(provided by government) in-order to login and cast their vote.
  - All voters attempting to vote after authentication need to select any one government issued identity proof from the three documents Voter_card (or) Passport (or) Provincial_card. Example : ID-Votercard (or) ID-Passport (or) ID-Provincialcard.
  - After selecting one document voter needs to enter their name as in the document selected and also the ID number of the document for reliability and second level of authentication.
  - System displays the user details like first name, last name, age, Phone number,postal code and the province name.
  - The candidate details of the respective user's province is displayed for the user to cast the vote upon user's request
  - Users needs to choose their candidate whom they wish to poll their vote by giving respective candidate id. Example: (Candidate2)
  - Vote is polled for a respective candidate by which a count of vote increases for a person and displays message that user has voted successfully and exits the program.

- In case of Admin : 
  - The Admin should enter name and password.
  - The Admin has access to vote_count.csv file for viewing the votes secured by candidates in each province.

  
Please note that the binary is located within `bin` folder

The program runs using the command below:

```
./bin/Epoll -a 
```

# Testing

Unit testing is done for each functions defined in the software. The test cases can be run using the command below:

```
./bin/Epoll -t
```

# Help

User can run the below command to know the details about input parameters.

```
./bin/Epoll -h
```

# Output Generation

Below output file will be generated. 

Output file - vote_count.csv file that gives the votes secured by candidates in each province.

```
make clean && make
```

Then run the `Epoll` binary again
