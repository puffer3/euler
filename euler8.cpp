//
// Created by Henry Glover on 5/14/23.
//
//
//The four adjacent digits in the 1000-digit number
//that have the greatest product are 9 × 9 × 8 × 9 = 5832.
//
//73167176531330624919225119674426574742355349194934
//96983520312774506326239578318016984801869478851843
//85861560789112949495459501737958331952853208805511
//12540698747158523863050715693290963295227443043557
//66896648950445244523161731856403098711121722383113
//62229893423380308135336276614282806444486645238749
//30358907296290491560440772390713810515859307960866
//70172427121883998797908792274921901699720888093776
//65727333001053367881220235421809751254540594752243
//52584907711670556013604839586446706324415722155397
//53697817977846174064955149290862569321978468622482
//83972241375657056057490261407972968652414535100474
//82166370484403199890008895243450658541227588666881
//16427171479924442928230863465674813919123162824586
//17866458359124566529476545682848912883142607690042
//24219022671055626321111109370544217506941658960408
//07198403850962455444362981230987879927244284909188
//84580156166097919133875499200524063689912560717606
//05886116467109405077541002256983155200055935729725
//71636269561882670428252483600823257530420752963450
//
//Find the thirteen adjacent digits in the 1000-digit
// number that have the greatest product. What is the value of this product?


/* convert number to string
 * iterate thru and calculate the product of adjacent digits
 * check it its higher than the last selection of digits and keep this highest score
 *
*/

#include <string>
#include <iostream>
#include <stdio.h>



int main () {

    std::string number =
            "731671765313306249192251196744265747423553491949349698352031277450632623957831801698480186947885184385861560789112949495459501737958331952853208805511"
            "125406987471585238630507156932909632952274430435576689664895044524452316173185640309871112172238311362229893423380308135336276614282806444486645238749"
            "303589072962904915604407723907138105158593079608667017242712188399879790879227492190169972088809377665727333001053367881220235421809751254540594752243"
            "525849077116705560136048395864467063244157221553975369781797784617406495514929086256932197846862248283972241375657056057490261407972968652414535100474"
            "821663704844031998900088952434506585412275886668811642717147992444292823086346567481391912316282458617866458359124566529476545682848912883142607690042"
            "242190226710556263211111093705442175069416589604080719840385096245544436298123098787992724428490918884580156166097919133875499200524063689912560717606"
            "0588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";


    int adjacentDigits = 13;
    long long maxProduct = 0;

    /*
     * size_t is an unsigned integer data type that is commonly used for representing
     * sizes and indices in memory. It is often used to express the sizes of arrays,
     * containers, and memory buffers. It's an implementation-defined type, meaning
     * its actual size can vary depending on the platform and compiler, but it is guaranteed
     * to be large enough to hold the size of the largest object that the platform can handle.
     */


    // Iterate through the number to find the maximum product of adjacent digits

    for (size_t i = 0; i <= number.size() - adjacentDigits; ++i) {
        // Initialize the product for this sequence of adjacent digits
        long long product = 1;

        //The *= operator is a compound assignment operator in
        // C++ that combines the multiplication operation with the assignment operation.


        //The ASCII values of characters '0', '1', ..., '9' are consecutive. For example,
        // the ASCII value of '0' is 48, '1' is 49, '2' is 50, and so on. By subtracting
        // the ASCII value of '0' from the ASCII value of a digit character, you
        // effectively get the integer value of that digit.


        // Calculate the product of the current sequence of adjacent digits
        for (size_t j = i; j < i + adjacentDigits; ++j) {
            // Convert character digit to integer by subtracting ASCII value of '0'
            product *= (number[j] - '0'); // Accumulate the product
        }

        //check new product against max product
        if (product > maxProduct) {
            maxProduct = product;
        }
    }

    //print maxiumum product

    std::cout << "Maximum product of 13 adjacent digitis is : " << maxProduct << std::endl;

    return 0;

}