/**
 * @file user_details.h
 *
 * @brief Implementation of displaying the user details.
 * 
 *
 * @author Aswanth Ramamoorthy
 * 
 **/
#ifndef _USER_DETAILS_H_
#define _USER_DETAILS_H_

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
extern int user_details(char* name);
#endif 