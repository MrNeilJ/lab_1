/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.7.2017
 *
 * Description: This is the file for the function readMatrix.
 * This function takes in a Pointer to a 2D array and the
 * size of each section [x] [x].  It will then allow the user
 * to input a numerical value into each portion of the array
 * until it is completely full.
**************************************************************/
#include <iostream>
#include <limits>
#include "readMatrix.hpp"

void readMatrix (double ** ptr, int size) {
// Prompt the user for input values to fill up the size of their matrix
    std::cout << "\nPlease Enter the numbers you'd like to use in the matrix: " << std::endl;
	double temp;

    // Loop through each array value and add the value in.
    for (int i = 0, count = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout <<  "Value " << count + 1 << ": ";

			if(std::cin >> temp)
			{
				ptr[i][j] = temp;
				count++;
			}
			else
			{
				// Clear the error for the cin stream
				std::cin.clear();

				// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				std::cout << "This was not a valid input, please try again. Integers only!" << std::endl;

				// Go back a step and try the input again.
				j--;

			}

		}

    }
    std::cout << "\nThank you for your input!" << std::endl;

}

