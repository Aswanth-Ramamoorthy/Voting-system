/**
 * @file get_file_column_size.c
 *
 * @brief Implementation of getting a CSV file column size.
 *
 *
 * @author Aswanth Ramamoorthy
 *
 **/

#include<stdio.h>
#include<string.h>
#include "../include/get_file_column_size.h"
#include"../include/get_field.h"
// To get the column size of the file
int get_file_column_size(char* tmp){

	char* tempHeaderRow = get_field(tmp, 1);
	char* token = strtok(tempHeaderRow, ",");
	int totalCols = 0;
	while (token != NULL){

		token = strtok(NULL, ",");
		totalCols++;
	}
	return totalCols;
}
