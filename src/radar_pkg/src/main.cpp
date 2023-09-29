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

int main(){
    //Retreives radar visibility range in inputX.txt
    //Retreives number of obstacle in inputX.txt
    int visibility;
    int numObstacles;
    std::cin >> visibility;
    std::cin >> numObstacles;

    processObstacle(visibility, numObstacles);

    return 0;
}