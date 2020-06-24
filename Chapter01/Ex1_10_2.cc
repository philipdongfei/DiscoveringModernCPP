#include <iostream>

int main()
{
    /*
     * int* - pointer to int
     * int const * - pointer to const int
     * int * const - const pointer to int
     * int const * const - const pointer to const int
     * const int * == int const *
     * const int * const == int const * const
     *
     * carzy
     * int ** - pointer to pointer to int
     * int ** const - a const pointer to a pointer to an int
     * int * const * - a pointer to a const pointer to an int
     * int const ** - a pointer to a pointer to a const int
     * int * const * const - a const pointer to a const pointer to an int.
     */

    char c = 'a';
    char *pChar = &c;
    int nArray[10];
    int* pArray;
    int** ppArray;
    int const* pConstInt;

    int* const  pIntConst;


}
