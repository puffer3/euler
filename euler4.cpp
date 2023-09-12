//
// Created by Henry Glover on 8/18/23.
/*
 * a palindromic number reads the same both ways
 * the largest palindrome made from the product of two
 * two digit numbers is 9009 = 91 x 99
 *
 * find the largest palindrome made from the product of
 * two three digit numbers
 *
 */
//

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool isPal (int num); // return a number if function is true

int main ()
{
    int largestPal = 0 ;
    {
        for (int i = 100; i <= 999; i++) {
            for (int j = 999; j >= 100; j--)
            {
                int product = i * j;
                if (isPal(product) && product > largestPal) {
                    largestPal = product ;
                }
            }
        }
    }

    std::cout << "largest palindrome " << largestPal << std::endl;
    return 0;
}

bool isPal (int num) {

    //check and see if number is a palendrome

    char numStr[6] ;
    sprintf(numStr, "%d", num); // turn num into string  %d is for formatting an integer

    int left = 0;
    int right = strlen(numStr) - 1; //string length minus 1

    //compare while moving in

    while (left < right) {
        if (numStr[left] != numStr[right]) {
            return false;
        }
        left++;
        right--;

    }
    return true;

}


