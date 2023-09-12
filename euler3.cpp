//
// Created by Henry Glover on 8/18/23.
/*
 * the prime factors of 13196 are 5, 7, 13 and 29
 *
 * what is the largest prime factor of the number 600851475143
 */
//

//declare function
#include <iostream>

void euler3 (int &largestFactor) ;



int main ()

    {

    int largestPrimeFactor = 0;
    euler3(largestPrimeFactor);
    std::cout << " The Largest Prime Factor of 600851475143 is " << largestPrimeFactor << std::endl;
    return 0;

    }

// function definition :

void euler3 (int &largestFactor)

{
    long long number = 600851475143LL;

    for (long long i = 2; i<= number; i++)
    {
        while (number % i == 0)
        {
            largestFactor = i;
            number /= i;
        }

    }
}