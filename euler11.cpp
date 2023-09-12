//What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the grid?




#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
const int grid_dim = 20;

int checkMax (int arr[grid_dim][grid_dim]) ;

int main () {

    int eulerGrid [grid_dim][grid_dim];  // initialize 2d array

    //how to open a file
    ifstream inputFile("array.txt");

    //error handling for file opening
    if (!inputFile) {
        cerr << "Error opening array file." << endl;
        return 1; //exit with error code 1
    }

    //read data from file into the array
    for (int i = 0; i < grid_dim; i++) {
        for (int j = 0; j < grid_dim; j++) {
            string value; //read value as a string
            if (inputFile >> value) {
                eulerGrid [i] [j] = stoi(value); //stoi = String To Integer
            }
            else {
                cerr << "error reading data in array file" <<endl;
                inputFile.close();
                return 2;  // exit with error code 2
            }
        }
    }

    //close file
    inputFile.close();

    checkMax(eulerGrid);

    return 0; // exit without error


}

int checkMax (int gCheck[grid_dim][grid_dim] ) {

    //even tho it doesnt matter what order you multiply numbers in,
    // I am going to do all the directions to make sure I can access
    // 2d array data predictably

    int maximumValue = 0;


//print array to make sure its passed correctly
/*
    for (int i = 0; i < grid_dim; ++i) {
        for (int j = 0; j < grid_dim; ++j) {
            std::cout << gCheck[i][j] << ' ';
        }
        std::cout << std::endl; // Move to the next line for the next row
    }
*/


    //check forward adjacent values

    int forBuffer = 0;
    int forMax = 0;

    for (int i = 0; i < grid_dim; ++i) {
        for (int j = 0; j < grid_dim - 3; ++j) {
            forBuffer = ( gCheck[i][j] * gCheck[i][j+1] * gCheck[i][j+2] * gCheck[i][j+3] );

            if (forBuffer > forMax) {
                forMax = forBuffer;
                // for troubleshooting cout << gCheck[i][j] << " * " << gCheck[i][j+1] << " * " <<  gCheck[i][j+2] << " * " <<  gCheck[i][j+3] << " = " << forBuffer << endl;

            }
        }
    }

    cout << "Largest Forward Value : " <<forMax << endl;
    cout << endl;

    //check backward adjacent values

    int backBuffer = 0;
    int backMax = 0;

    for (int i = 0; i < (grid_dim); ++i) {
        for (int j = 0; j < grid_dim - 3 ; j++) {
            backBuffer = ( gCheck[i][j + 3] * gCheck[i][j+ 2] * gCheck[i][j + 1] * gCheck[i][j] );
            if (backBuffer > backMax) {
                backMax = backBuffer;
                // for troubleshooting cout <<  gCheck[i][j+3] << " * " <<  gCheck[i][j+2] << " * " << gCheck[i][j+1] << " * " <<  gCheck[i][j] << " * "  << " = " << backBuffer << endl;

            }
        }

    }

    cout << "Largest Backward Value : " <<backMax << endl;
    cout << endl;

    //check upward values

    int upBuffer = 0;
    int upMax = 0;

    for (int i = 3; i < grid_dim; ++i) {
        for (int j = 0; j < grid_dim; ++j) {
            upBuffer = ( gCheck[i][j] * gCheck[i-1][j] * gCheck[i-2][j] * gCheck[i-3][j] );
            if (upBuffer > upMax) {
                upMax = upBuffer;
                // for troubleshooting cout <<  gCheck[i][j] << " * " << gCheck[i-1][j]  << " * " <<  gCheck[i-2][j]  << " * " <<  gCheck[i-3][j] << " = " << upMax << endl;

            }
        }

    }

    cout << "Largest upward Value : " <<upMax << endl;
    cout << endl;

    //check downward values

    int downBuffer = 0;
    int downMax = 0;

    for (int i = 0; i < grid_dim - 3; ++i) {
        for (int j = 0; j < grid_dim; ++j) {
            downBuffer = ( gCheck[i][j] * gCheck[i+1][j] * gCheck[i+2][j] * gCheck[i+3][j] );
            if (downBuffer > downMax) {
                downMax = downBuffer;
                // for troubleshooting cout << gCheck[i][j] << " * " << gCheck[i+1][j] << " * " << gCheck[i+2][j] << " * " << gCheck[i+3][j]  << " = " << downMax  << endl;

            }
        }

    }

    cout << "Largest downward Value : " <<downMax << endl;
    cout << endl;

// calculate forward diagonal values
    int diagforBuffer = 0;
    int diagforMax = 0;

    for (int i = 0; i < grid_dim - 3; ++i) {
        for (int j = 0; j < grid_dim -3; ++j) {
            diagforBuffer = ( gCheck[i][j] * gCheck[i+1][j+1] * gCheck[i+2][j+2] * gCheck[i+3][j+3] );
            if (diagforBuffer > diagforMax) {
                diagforMax = diagforBuffer;
                 // for troubleshooting cout << gCheck[i][j] << " * " << gCheck[i+1][j+1] << " * " << gCheck[i+2][j+2] << " * " << gCheck[i+3][j+3]  << " = " << diagforMax  << endl;

            }
        }

    }

    cout << "Largest Forward Diagonal  Value : " <<diagforMax << endl;
    cout << endl;

    //calculate backwards diagonal value


    int diagbackBuffer = 0;
    int diagbackMax = 0;


    for (int i = 0; i < grid_dim - 3; ++i) {
        for (int j = 3; j < grid_dim ; ++j) {
            diagbackBuffer = ( gCheck[i][j] * gCheck[i+1][j-1] * gCheck[i+2][j-2] * gCheck[i+3][j-3] );
            if (diagbackBuffer > diagbackMax) {
                diagbackMax = diagbackBuffer;
                // for troubleshooting cout << gCheck[i][j] << " * " << gCheck[i+1][j-1] << " * " << gCheck[i+2][j-2] << " * " << gCheck[i+3][j-3]  << " = " << diagbackMax  << endl;

            }
        }

    }

    cout << "Largest backward Diagonal  Value : " <<diagbackMax << endl;
    cout << endl;

    maximumValue = max ( max (upMax, forMax), max(diagforMax, diagbackMax));

    cout << "Largest Of All Values : " << maximumValue << endl;



}
