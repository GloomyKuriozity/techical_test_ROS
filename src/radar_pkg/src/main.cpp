/****************************************
PROGRAM NAME - main
PROGRAMMER - Kuriozity
LANGUAGE - C++
SYSTEM - Windows 11
CREATION DATE - 29/09/2023
NOTE - None :)
*****************************************/

#include <iostream>
#include <fstream>
#include "functions.h"

bool fileExists(const std::string& fileName) {
    std::ifstream file(fileName);
    return file.good();
}

// To run this code you need to write main /path/to/inputX.txt
// Pass inputX in argument to know if it exist or not
int main(int argc, char* argv[]){

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file_name>" << std::endl;
        return 1;
    }

    std::string inputFileName = argv[1];
    int visibility;
    int numObstacles;

    if (!fileExists(inputFileName)) {
        std::cerr << "Error: Input file '" << inputFileName << "' does not exist." << std::endl;
        return 1;
    }

    std::ifstream inputFile(inputFileName);

    inputFile >> visibility;
    inputFile >> numObstacles;

    processObstacle(visibility, numObstacles);

    return 0;
}