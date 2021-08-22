/**
 * @file cast_vote.h
 *
 * @brief Implementation of cast_vote function to cast vote for the preferred candidate.
 * 
 *
 * @author Aswanth Ramamoorthy
 * 
 **/
#ifndef _CAST_VOTE_H_
#define _CAST_VOTE_H_

/**
 *
 * @brief The function to cast vote for the preferred candidate. 
 * @param[in] the function takes “province” as input parameter and gets "candidate_id" as input from the user input terminal
 *
 * @param[out] The function calls "attemp_count" function and displays a message to the user
 *
 * @return Return 0 when vote is casted and return 1 if "candidate_id" id invalid to cast vote.
 *
 **/
extern int cast_vote(char* province, char* username);
#endif 