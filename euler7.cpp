//
// Created by Henry Glover on 8/21/23.
//
/*
 * By Listing the first six prime numbers
 * 2,3,5,7,11,13
 *
 * we can see that the 6th prime is 13
 *
 * what is the 10001 prime number?
 *
 */

#include <iostream>

bool isPrime (int num) ;

int main () {

    int num = 2 ;
    int count = 0 ;

    while (count != 10001) {
        if (isPrime(num)) {
            count++;
        }
        num++;
    }

    std::cout << " The 10001st prime number is : " <<  num -1  << std::endl;
}

bool isPrime (int num) {

    if (num <= 1) {
        return false;
    }

    for (int i = 2; i <= std::sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

