/**
 * @file replace_char.c
 *
 * @brief Implementation of replacing a character with other.
 *
 *
 * @author Aswanth Ramamoorthy
 *
 **/

#include<stdio.h>
#include<string.h>
#include"../include/replace_char.h"
char* replace_char(char* str, char find, char replace){

	char* current_pos = strchr(str, find);
	while (current_pos){

		*current_pos = replace;
		current_pos = strchr(current_pos, find);
	}
	return str;
}
