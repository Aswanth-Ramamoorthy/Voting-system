/**
 *
 * @file test.h
 *
 * @brief Simply contains headers of the test function.
 *
 * @author Priyanga Soundararajan - priyangasoundararaja@cmail.carleton.ca
 * @author Aswanth Ramamoorthy - aswanthramamoorthy@cmail.carleton.ca
 * @author Vignesh Balaji - vigneshbalaji@cmail.carleton.ca
 * @author Soma Ravindran - somaravindran@cmail.carleton.ca
 **/
 

#ifndef _TEST_ALL_CASES_H_
#define _TEST_ALL_CASES_H_

extern int test_all_cases();

extern int test_admin_login();

extern int test_user_login();

extern int test_user_details(char* name);

extern int test_cast_vote(char* province);

extern int test_candidate_details(char* province);

extern int test_secondary_authentication(char* name);

extern int test_display_count();



#endif