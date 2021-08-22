/**
 * @file user_login.h
 *
 * @brief Implementation of user login login function with password encryption
 * 
 *
 * @author Aswanth Ramamoorthy
 * 
 **/
#ifndef _USER_LOGIN_H_
#define _USER_LOGIN_H_
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
extern int user_login();
#endif 
