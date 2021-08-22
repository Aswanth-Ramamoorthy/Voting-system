# Voting System

Voting system is a software that allows users to vote with high authenticity, reliability and ease of voting on the go.

* [Authors](#authors)
* [Installation](#installation)
* [Usage](#usage)
* [File Structure](#file-structure)
* [How to Compile and Test](#how-to-compile-and-test)
* [For Developers](#for-developers)
* [License](#license)


# Authors


- Aswanth Ramamoorthy  -  aswanthramamoorthy@cmail.carleton.ca  -  Carleton University


# Installation

Installation steps are mentioned in [INSTALL.md](https://github.com/Aswanth-Ramamoorthy/Voting-system/blob/dev/INSTALL.md)

# Usage

To run, you must first install it. Then you can follow instructions mentioned in
[User_Manual.md](https://github.com/Aswanth-Ramamoorthy/Voting-system/blob/dev/doc/User_Manual.md).

# File Structure

The correct file structure

```
├── assets				-> Flowchart
├── bin					-> Binary directory
├── data				-> csv files
│   ├── candidate_details.csv
│   ├── auth.csv
│   ├── second_auth1.csv
│   ├── userdetails.csv
│   └── vote_count.csv
│ 
├── doc
│   ├── html				-> Doxygen document
│   ├── Developer_Manual.md		-> Developer document
│   └── User_Manual.md			-> User document
│ 
├── include				-> Header files
│   ├── admin_login.h
│   ├── attempt_count.h
│   ├── candidate_details.h
│   ├── cast_vote.h
│   ├── display_count.h
│   ├── function.h
│   ├── get_field.h
│   ├── get_file_column_size.h
│   ├── int_to_string.h
│   ├── replace_char.h
│   ├── secondary_authentication.h
│   ├── user_details.h
│   └── user_login.h
│   
├── src					-> voting system
│   ├── admin_login.c
│   ├── attempt_count.c
│   ├── candidate_details.c
│   ├── cast_vote.c
│   ├── display_count.c
│   ├── get_field.c
│   ├── get_file_column_size.c
│   ├── int_to_string.c
│   ├── main.c
│   ├── replace_char.c
│   ├── secondary_authentication.c
│   ├── user_details.c
│   └── user_login.c
│ 
│  
├── test
│   ├── data				-> csv files for testing
│   │   ├── temp.csv
│   │   ├── test_auth.csv
│   │   ├── candidate_details.csv
│   │   ├── test_second_auth.csv
│   │   ├── test_user_details.csv
│   │   └── test_vote_count.csv	
│   │		
│   ├── include
│   │   └── test_all_cases.h		-> header file for testing 
│   │	
│   ├── results
│   │   └── results.csv			-> header file for testing 
│   │		    
│   └── src				-> Main function for testing 
│       └── test.c 
│  
├── Electronic_polling_system_config	-> Doxygen file
├── INSTALL.md				-> Installation Guide
├── LICENSE				-> License file
├── Makefile				-> Makefile
├── Project Documentation		-> Complete Project Document 
└── README.md				-> Readme file
 		
```

# How to Compile and Test

The instructions below have been verified to work on Windows using Cygwin and gcc,

* `make` (default) Will build the application and test application.
* `Epoll -a` Will run only the application.
* `Epoll -t` Will run only the test application.
* `Epoll -h` Will display the help documentation.
* `make clean` Will remove all build artifacts.

# For Developers

The developer manual is available [here](https://github.com/Aswanth-Ramamoorthy/Voting-system/blob/dev/doc/Developer_Manual.md).

# License

This project is licensed under the GPL 2.0 License - see the [LICENSE.md](https://github.com/Aswanth-Ramamoorthy/Voting-system/blob/dev/LICENSE) file for details.


