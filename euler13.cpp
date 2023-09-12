

//in this problem I learned how to read specific string values into an array one by one by subtracting '0'.


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;



int main () {
    int e13Grid[100][50] = {};  // initialize empty 2d array

    int sumArray[51] = {};

//how to open a file
    ifstream inputFile("euler13numbers.txt");

//error handling for file opening
    if (!inputFile) {
        cerr << "Error opening array file." << endl;
        return 1; //exit with error code 1
    }

//read data from file into the array
    for (int i = 0; i <= 99; i++) {
        string line;
        if (inputFile >> line) {
//            std::cout << line << std::endl;  //troubleshooting
            for (int j = 0; j <= 49; j++) {
                e13Grid[i][j] = line[j] - '0';  //subtract '0' from string value to convert it to an integer
            }
        } else {
            cerr << "Error reading array from data";
            inputFile.close();
            return 2;
        }
    }



//close file
    inputFile.close();



    int carryOver ;
    int lowestDigit ;

    for (int j = 50; j != 0; j--) {
        int colValue = 0 + carryOver;
        carryOver = 0;  // reinitialize carryover
        for (int i = 0; i <= 99; i++) {

            colValue += e13Grid[i][j-1] ;


        }

//        std::cout << "column " << j << " : " << colValue << endl; // output column value
        lowestDigit = colValue % 10;  //get array value by modulo by 10
        carryOver = (colValue - lowestDigit) / 10;  // subtract lowest digit and divide by 10 to add to next column
//        std::cout << "Lowest digit: " << lowestDigit << std::endl;
//        cout << "remainder : " << carryOver << endl;

        sumArray[j+1] = lowestDigit;
    }

    //deal with 2 digit remainder
    sumArray[1] = carryOver % 10; //ones digit
    sumArray[0] = (carryOver / 10)  % 10;  //tens digit

    //print solution
    for (int i = 0; i < 10; i++) {
        cout << sumArray[i];
    }

}
