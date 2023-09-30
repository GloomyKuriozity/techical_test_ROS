#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <fstream>

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

void processObstacle(int visibility, int numObstacles,std::istream& input);
bool fileExists(const std::string& fileName);

#endif // FUNCTIONS_H