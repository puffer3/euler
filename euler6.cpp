//
// Created by Henry Glover on 8/19/23.
//
/*
 *
 * The sum of the squares of the first ten nat num is:
 *
 * 1^2 + 2^2 + 10^2 = 385
 *
 * the square of the sum of the first ten nat num is:
 *
 * (1+2+...+10)^2 = 55^2 = 3025
 *
 * the difference is 3025 - 385 = 2640
 *
 * do the same for the first 100 numbers
 *
 */

#include <iostream>

int squareOfSum (int num) ;

int sumOfSquare (int num) ;

int main () {

    int length = 100;

    int diffNum = sumOfSquare(length) - squareOfSum(length);

    std::cout << "difference of the square of the sum minus the sum of the squares is : " << diffNum << std::endl;

}

int squareOfSum (int num) {

    int sqrSumTotal = 0;

    for (int i = 0; i <= num; i++) {

         sqrSumTotal = sqrSumTotal + (i * i);

    }

    std::cout << "Square of Sum : " << sqrSumTotal << std::endl;

    return sqrSumTotal;


}

int sumOfSquare (int num) {

    int sumSqrTotal = 0;

    for (int i = 0; i <= num; i++) {

         sumSqrTotal = sumSqrTotal + i;

    }

    sumSqrTotal = sumSqrTotal * sumSqrTotal;

    std::cout << "Sum of Square : " << sumSqrTotal << std::endl;
    return sumSqrTotal;
}