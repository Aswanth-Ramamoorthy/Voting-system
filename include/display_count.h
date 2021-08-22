/**
 * @file display_count.h
 *
 * @brief Implementation of display_count function to display the final count of the
 * votes casted.
 * 
 *
 * @author Aswanth Ramamoorthy
 * 
 * 
 **/
#ifndef _DISPLAY_COUNT_H_
#define _DISPLAY_COUNT_H_
/**
 * The function displays a final cont of the votes present in the file. 
 * @param[in] the function takes “filename” as input parameter.
 *
 * @param[out] the function displays the "vote_count.csv" file as the output.
 *  
 *
 * @return Return 0 when file opens and return 1 when filename is invalid.
 *
 **/
extern int display_count();
#endif 


