/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.7.2017
 *
 * Description: This is the function file for the function
 * called determinant.  In this function it takes in two pieces
 * of information, a Pointer to a 2D Array, and the size of
 * each portion of the array ([x][x]).  From here it calculates
 * the determinant.  Determinant value was replicated from the
 * site "Mathisfun.com".  It then returns the value of the
 * determinant.
**************************************************************/

#include "determinant.hpp"

double determinant (double** ptr, int size)
{
// Isolate which formula will be required
    if (size == 2)
    {
        return ((ptr[0][0] * ptr[1][1]) - (ptr[0][1] * ptr[1][0]));
    }
    else
    {
        return ((ptr[0][0] * ptr[1][1] * ptr[2][2]) +
                (ptr[0][1] * ptr[1][2] * ptr[2][0])  +
                (ptr[0][2] * ptr[1][0] * ptr[2][1])) -
               ((ptr[0][1] * ptr[1][0] * ptr[2][2])  +
                (ptr[0][0] * ptr[1][2] * ptr[2][1])  +
                (ptr[0][2] * ptr[1][1] * ptr[2][0]));
    }
}