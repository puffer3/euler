//
// Created by Henry Glover on 8/15/23.
/*
If we list all the natural numbers below $10$ that are multiples of $3$ or $5$, we get $3, 5, 6$ and $9$.
The sum of these multiples is $23$.
Find the sum of all the multiples of $3$ or $5$ below $1000$.
*/

//#include "euler1.h"
#include <iostream>
//#include <cmath>

// Function declaration
void euler1();

int main() {
    euler1();
    return 0;
}

// Function Definition

void euler1() {
    int numsum = 0;

    for (int i = 0; i < 1000; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
                numsum = numsum + i ;
                std::cout << i << std::endl ;
        }
    }

    std::cout << "Sum of Multiples of 3 or 5 below 1000 is : " << numsum << std::endl ;

}


