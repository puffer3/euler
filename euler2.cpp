//
// Created by Henry Glover on 8/16/23.
//
//
// fibonacci sequence - add two previous terms
//1,2,3,5,8,13,21,34,55,89
// By considering the terms in the Fibonacci sequence whose values do
// not exceed four million, find the sum of the even-valued terms.
#include <iostream>

// function declaration

void euler2 (int &fibSumEven) ;

int main ()

    {
    int fibSumEven = 0;
    euler2(fibSumEven);
    std::cout << "Sum of Even Fibonacci values below 4 million is : " << fibSumEven << std::endl;
    return 0;

    }

// function definition

void euler2 (int &fibSumEven)

{

    int fibA = 1;
    int fibB = 2;
    int fibC = 0;

    while (fibB < 4000000)

    {
        fibC = fibA + fibB;
        fibA = fibB;
        fibB = fibC;

        if (fibC % 2 == 0)

        {
            fibSumEven += fibC;
            std::cout << "Added to sum even value : "  << fibC << std::endl;
        }
    }

}






/*   this was how I first solved it ::

    for (int i = 0; fibB < 4000000 && fibA < 4000000; ++i) {
        fibC = fibA + fibB;
        fibA = fibB;
        fibB = fibC;
        if (fibC % 2 == 0) {
            fibSumEven = fibSumEven + fibC;
            std::cout << "added to sum even vale : " << fibC << std::endl;
        }
    }

    std::cout << " Sum of Even Fibonachi values below 4 Million is : " << fibSumEven << std::endl;

    }

*/