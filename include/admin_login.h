/**
 * @file admin_login.h
 *
 * @brief Implementation of admin login function for access to the system
 * 
 *
 * @author Aswanth Ramamoorthy
 * 
 **/
#ifndef _ADMIN_LOGIN_H_
#define _ADMIN_LOGIN_H_

/** 
 * @brief This function is to authenticate admin into the system
 *
 *
 * @details This function compares the input(i.e Admin-ID and PAssword) given 
 * by the Admin.when the comparison gets successful the output will display as 
 * Welcome.Login success!
 *
 * @param[in] It takes the Admin-ID, Password and File name as the input parameter. 
 *
 * @return Return 0 on successful login and 1 if login failed.
 *
 **/
extern int admin_login();
#endif 

