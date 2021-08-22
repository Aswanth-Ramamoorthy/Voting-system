/**
 * @file attempt_count.h
 *
 * @brief Implementation of attempt_count function to prevent the user from casting duplicate votes
 * 
 *
 * @author Aswanth Ramamoorthy
 * 
 **/
#ifndef _ATTEMPT_COUNT_H_
#define _ATTEMPT_COUNT_H_

/** 
 * @brief This function to prevent the user who already casted vote.
 *
 *
 * @details This function records every attempt made by an user to vote. 
 * After one successful vote(attempt>=1) the user is restricted further voting .
 * 
 * 
 *
 * @param[in] It takes the username as the input parameter. 
 *
 * @return This function has no return value.(This function is used to make necessary changes to the files)
 *
 **/
 extern int attempt_count(char* username);
#endif 