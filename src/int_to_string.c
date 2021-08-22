/**
 * @file int_to_string.c
 *
 * @brief Implementation of int_to_string function to convert int to string
 *
 *
 *
 * @author Aswanth Ramamoorthy
 *
 *
 **/

#include<stdio.h>
#include<string.h>
#include"../include/int_to_string.h"
// Convert int to string
char* int_to_string(int num, char* str){

	if (str == NULL){

		return NULL;
	}
	sprintf(str, "%d", num);
	return str;
}
