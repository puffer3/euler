//
// Created by Henry Glover on 9/4/23.
//
// What is the value of the first triangle
// number to have over five hundred divisors?
// unfinished

#include <iostream>
#include <cstring>

int triangle_number (int tri);

int main () {

    int current_t = 1;
    int ival = 2;

    while (true) {
        current_t += ival;
        int factors = triangle_number(current_t);

        if (factors >= 500 )
        {
            std::cout << "our triangle number is : " << current_t << std::endl;
            break;
        }

        ival += 1;
    }

    return 0;

}


int triangle_number (int tri) {

    int factors = 0;

    // factor for perfect squares and add one to count

    // all other factors are n or value / n until n * n = tri  so add 2 to count

    for (int n = 1; n * n <= tri; n++)
    {
        if (n * n == tri) {
            factors += 1;   //factor for perfect squares
        }
        else if ( tri % n == 0 )
        {
            factors += 2;  //add a factor for the n number and the divisor into tri for example 400 / 2 = 200, both 200 and 2 are divisors

            //            std::cout << "added factor : " << n << " for number : " << tri<< std::endl; // for troubleshooting
        }
    }

    return factors;

}






