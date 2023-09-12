//
// Created by Henry Glover on 8/23/23.
//
/* the sum of the primes below 10 is 2 + 3 + 5 + 7 = 17
 *
 * find the sum of all the primes below two million
 *
*/
//
// Created by Henry Glover on 8/27/23.
//

#include <iostream>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }


    // why does this code work so much better than my code :  a: a math thing i dont know

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    long long totalPrime = 0;

    for (int i = 2; i < 2000000; i++) {
        if (isPrime(i)) {
            totalPrime += i;
        }
    }

    std::cout << "Total sum of prime numbers under 2000000 = " << totalPrime << std::endl;

    return 0;
}
