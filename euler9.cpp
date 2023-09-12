//
// Created by Henry Glover on 8/23/23.
//
/*
 * pathagorean triplet is a set of three natural numbers
 * a<b<c for which
 * a^2 + b^2 = c^2
 *
 * for example 3^2 + 4^2 = 9 + 16 = 25 = 5^2
 *
 * there exists exactly one pythagorean triplet for which
 * a+b+c = 1000 find the product
 *
 * I think I did this inefficiently, come back to try and speed up.
 */



#include <iostream>
#include <cmath>


bool pathTrip (int numa, int numb, int numC);

int main () {


    for (int a = 3; a < 1000; a++) {
        for (int b = 4; b < 1000; b++) {
            for (int c = 5; c < 1000; c++) {
                if (pathTrip(a, b, c) && (a + b + c == 1000)) {
                    std::cout << "The pathagorian Triplet thats sum is 1000 is : " << a << " , " << b << " & " << c << std::endl;
                    std::cout << a * b * c << std::endl;
                    return 0;
                }

            }
        }
    }
}

bool pathTrip (int numa, int numb, int numC) {

    if (std::pow(numa, 2) + std::pow(numb, 2) == std::pow(numC, 2)) {
        return true;
    }
    else {
        return false;
    }

}


