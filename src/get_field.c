/**
 * @file get_field.c
 *
 * @brief Implementation of get_field function to get particular field in csv file
 *
 *
 *
 * @author Aswanth Ramamoorthy
 *
 *
 **/

#include<stdio.h>
#include<string.h>
#include"../include/get_field.h"
// read the csv file(Particular filed)
char* get_field(char* line, int num){

	for (char* tok = strtok(line, ";");
		tok && *tok;
		tok = strtok(NULL, ";\n"))
	{
		if (!--num)
			return tok;
	}
	return NULL;
}
