/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.7.2017
 *
 * Description: This application prompts the user for input
 * to see how big of a matrix they would like to create (2 or 3).
 * It then runs a function called readMatrix which pulls from
 * the terminal input from the user until it cannot hold any
 * more.  From there it prints out the Matrix array and the
 * determinant value of the array.
**************************************************************/

#include "readMatrix.hpp"
#include "determinant.hpp"
#include <iostream>
#include <limits>

int main() {
    // Welcome the user to the application
    std::cout << "Welcome to the Matrix! Matrix Maker that is..." << std::endl;
    std::cout << "\nTell me...how big do you want your matrix? (2 for 2x2 & 3 for 3x3): ";

    // Define Variables used for size and pointer to a variable.
    int matrixSize;
    double** matrixPtr = NULL;
	int count = 0;

    // Take input from the customer and ensure that the value inputted is a 2 or a 3
    do {
        std::cin >> matrixSize;
        // Check to see what the user inputted is a valid response

		if (matrixSize == 2 || matrixSize == 3)
        {
            matrixPtr = new double*[matrixSize];
            for (int i = 0; i < matrixSize; i++)
            {
                matrixPtr[i] = new double[matrixSize];
            }
        }
		else if (count >= 4)
		{
			std::cout << "Seems like you don't understand.  Re-run the program when you're ready. Now quitting."
					  << std::endl;
			return 0;
		}
        // If it isn't, then tell the user and loop again.
        else
        {
			// Clear the error for the cin stream
			std::cin.clear();

			// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "It appears you did not choose a 2 or a 3, try again!" << std::endl;
			count++;
        }
		std::cin.clear();
    } while (matrixSize != 2 && matrixSize != 3);

	// Call the readMatrix function to get further input from the user
    readMatrix(matrixPtr, matrixSize);

    std::cout << "Below is your printed Matrix: " << std::endl;

    // Loop through first portion of the Matrix Array
    for (int i = 0; i < matrixSize; i++)
    {
        // Loop through the second portion of the Matrix Array
        for (int j = 0; j < matrixSize; j++) {

            // print the value and a space
            std::cout << matrixPtr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Define a variable and run the determinant function
    double determinantValue = determinant(matrixPtr, matrixSize);

    std::cout << "\nDeterminant: " << determinantValue << std::endl;

    // Delete dynamic memory
    for (int i = 0; i < matrixSize; i++)
    {
        delete [] matrixPtr[i];
    }

    delete [] matrixPtr;

    // Set ptr to NULL to make sure it isn't accessed by accident and crash the system
    matrixPtr = NULL;

    // End the program
    return 0;
}