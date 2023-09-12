//
// Created by Henry Glover on 8/19/23.
//
/*
 * 2520 is the smallest number that
 * can be divided by each of the numbers
 * 1 - 10 without any remainder
 *
 * what is the smallest positive number
 * that is evenly divisible by all of the
 * numbers 1 - 20
 *
 *
 * Go back and solve this code with the
 * least common multiple method.  my loop limit is
 * a silly solution but still it worked
 */

#include <iostream>


bool evenDivisible (int num) ;

int main ()  {

    for (int i = 20; i < 10000000000; i++) {
        if (evenDivisible(i)) {
            std::cout << "The smallest number divisible by 1-20 is : " << i << std::endl;
            return true;
        }


    }
  return 0;
}


bool evenDivisible (int num) {

    for (int i = 1; i < 21; i++) {
       if (num % i != 0) {
           return false;
       }
    }

    return true;

}