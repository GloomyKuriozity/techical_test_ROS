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

// To run this code you need to write main /path/to/inputX.txt
// Pass inputX in argument to know if it exist or not
int main(int argc, char* argv[]){
    //Check if path correct
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file_path>" << std::endl;
        return 1;
    }

    //Retreive path
    std::string filePath = argv[1];

    //Check if file exist or/and can be accessed
    if (!fileExists(filePath)) {
        std::cerr << "Error: Input file '" << filePath << "' does not exist or is not accessible." << std::endl;
        return 1;
    }

    //Check if file can be opened
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file '" << filePath << "'." << std::endl;
        return 1; 
    }

    int visibility;
    int numObstacles;

    //Check if visibility has been correctly retreived from inputX
    if (!(inputFile >> visibility)) {
        std::cerr << "Error: Unable to read visibility from the input file." << std::endl;
        return 1;
    }
    
    //Check if number of obstacles has been correctly retreived from inputX
    if (!(inputFile >> numObstacles)) {
        std::cerr << "Error: Unable to read the number of obstacles from the input file." << std::endl;
        return 1;
    }

    processObstacle(visibility, numObstacles,inputFile);

    return 0;
}