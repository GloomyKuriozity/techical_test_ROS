#define _USE_MATH_DEFINES
#include "functions.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>

bool sortByAngle(const Obstacle& a, const Obstacle& b) {
    /*
        Particular order of triage not by linear increasing number but circular increasing angle
    
        Args:
            a (Obstacle&): obstacle 1 information
            b (Obstacle&): obstacle 2 information
        
        Returns:
            angleA (double): obstacle 1 angle
            angleB (double): obstacle 2 angle
    */
    double angleA = std::atan2(a.y, a.x);
    double angleB = std::atan2(b.y, b.x);
    
    //Normalize angles for comparison consistency
    angleA = (angleA < 0) ? (angleA + 2 * M_PI) : angleA;
    angleB = (angleB < 0) ? (angleB + 2 * M_PI) : angleB;

    return angleA < angleB;
}

void processObstacle(int visibility, int numObstacles,std::istream& input){
    /*
        Display obstacle in order of detection

        Args:
            visibility (int): radar range of visibility
            numObstacles (int): number of obstacle in environment
            input (istream): file input with given data
    */
   
    std::vector<Obstacle> obstacles;

    //Fill obstacle info and push it in the vector listing all obstacles
    //BUT only consider obstacle in visibility range
    for (int i = 0; i < numObstacles; ++i) {
        int x, y;

        //Check if coordinates are correctly retreived
        if (!(input >> x >> y)) {
            std::cerr << "Error: Unable to read obstacle data from input." << std::endl;
            return;
        }

        if (x * x + y * y <= visibility * visibility) {
            Obstacle obstacle;
            obstacle.index = i;
            obstacle.x = x;
            obstacle.y = y;
            obstacles.push_back(obstacle);
        }
    }

    // Sort obstacles based on angle.
    // sortByAngle impose the order by increasing angle
    std::sort(obstacles.begin(), obstacles.end(), sortByAngle);

    // Print result : obstacles indices in order of detection
    for (const auto& obstacle : obstacles) {
        std::cout << obstacle.index << " ";
    }
    std::cout << std::endl;
}