/**
 * @file candidate_details.h
 *
 * @brief Implementation of candidate_details function to display the candidates contesting in
 * a particular province
 * 
 *
 * @author Aswanth Ramamoorthy
 * 
 * 
 **/
#ifndef _CANDIDATE_DETAILS_H_
#define _CANDIDATE_DETAILS_H_
/** 
 * @brief The function displays a list of candidates present in the file. 
 *
 * @param[in] The function takes “province” as input parameter. 
 *
 * @param[out] The function displays candidate details in the logged in user's province
 *
 * @return Return 0 when entered province is valid else return 1
 *
 **/
extern int candidate_details(char* province,char* username);
#endif 
