/****************************************
PROGRAM NAME - main
PROGRAMMER - Kuriozity
LANGUAGE - C++
SYSTEM - Windows 11
CREATION DATE - 29/09/2023
NOTE - None :)
*****************************************/

#include <iostream>
#include <stdlib.h>
#include <vector>

struct Obstacle {
/*
    Group data from Obstacle -detected in inputX.txt file-
    
    Args:
        x (int): X coordinate of obstacle
        y (int): Y coordinate of obstacle
        index (int): index number of obstacle in input file
*/
    int index;
    int x;
    int y;
};

int main(){
    //Retreives radar visibility range in inputX.txt
    //Retreives number of obstacle in inputX.txt
    int visibility;
    int numObstacles;
    std::cin >> visibility;
    std::cin >> numObstacles;

    //Create obstacle objectS
    //Every line of coordinates in the file will be processed as obstacle
    std::vector<Obstacle> obstacles;

    //Fill obstacle info and push it the vector listing all obstacles
    //BUT only consider obstacle in visibility range
    for (int i = 0; i < numObstacles; ++i) {
        int x, y;
        std::cin >> x >> y;
        if (x * x + y * y <= visibility * visibility) {
            Obstacle obstacle;
            obstacle.index = i;
            obstacle.x = x;
            obstacle.y = y;
            obstacles.push_back(obstacle);
        }
    }

    return 0;
}