/**
 * @file secondary_authentication.h
 *
 * @brief Implementation of two step authentication for casting vote.
 * 
 *
 * @author Aswanth Ramamoorthy
 * 
 **/
#ifndef _SECONDARY_AUTHENTICATION_H_
#define _SECONDARY_AUTHENTICATION_H_
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
extern int secondary_authentication(char* name);
#endif 
