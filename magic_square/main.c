/********************************************************\
File Name: main.c
Author: Liri (5/4/2020)
Purpose: This file print true if the given array is
		 magic square, and false otherwise
\********************************************************/

#include <stdio.h>
#include <stdbool.h>

#define SIZE (3)
#define INITIAL_INDEX (0)
#define INITIAL_NUMBER (0)
#define PRINT_TRUE ("true\n")
#define PRINT_FALSE ("false\n")

bool check_if_array_is_magic_square(int two_dimension_array[SIZE][SIZE]) {
	/********************************************************\
	* Function name - check_if_array_is_magic_square
	*
	* Function Purpose - check if given array is magic square
	*
	* Parameters - IN int two_dimension_array[SIZE][SIZE] - the given 2D array
	*			   OUT int - false - if the array is not magic square
	*						 true - otherwise
	* Return Value - false - if the array is not magic square
	*				 true - otherwise
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - this function check if the sum of each
	*			  row equal to the sum of each column
	*
	* Author - Liri
	\********************************************************/
	int row_index = INITIAL_INDEX;
	int column_index = INITIAL_INDEX;
	int sum_of_first_row = INITIAL_NUMBER;
	int sum_of_next_row = INITIAL_NUMBER;
	int sum_of_next_column = INITIAL_NUMBER;

	/*save the sum of the first row*/
	for (column_index = INITIAL_INDEX; column_index < SIZE; ++column_index)
	{
		sum_of_first_row += two_dimension_array[INITIAL_INDEX][column_index];
	}

	/*check if the first row is equal to the other rows and columns*/
	for (row_index = INITIAL_INDEX; row_index < SIZE; ++row_index)
	{
		sum_of_next_row = INITIAL_NUMBER;
		sum_of_next_column = INITIAL_NUMBER;
		for (column_index = INITIAL_INDEX; column_index < SIZE; ++column_index)
		{
			sum_of_next_row += two_dimension_array[row_index][column_index];
			sum_of_next_column += two_dimension_array[column_index][row_index];
		}
		if (sum_of_next_row != sum_of_first_row || sum_of_next_column != sum_of_first_row)
		{
			return false;
		}
	}
	return true;
}

void main() {
	/********************************************************\
	* Function name - main
	*
	* Function Purpose - check if the array is magic square
	*					 if it is - print true
	*					 otherwise - print false
	*
	* Parameters - no Input/Output parameters
	*
	* Return Value - there isn't return value
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - this function call to function that check if
	*			  given array is magic square.
	*			  if it is - print true
	*			  otherwise - print false
	*
	* Author - Liri
	\********************************************************/
	int two_dimension_array[SIZE][SIZE] = { { 1, 2, 3 },
											{ 4, 1, 1 },
											{ 1, 3, 2 } };
	bool array_is_magic_square = false;

	array_is_magic_square = check_if_array_is_magic_square(two_dimension_array);

	if (array_is_magic_square == true)
	{
		printf(PRINT_TRUE);
	}
	else
	{
		printf(PRINT_FALSE);
	}
}