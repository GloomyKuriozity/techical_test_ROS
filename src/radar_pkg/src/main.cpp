/****************************************
PROGRAM NAME - main
PROGRAMMER - Kuriozity
LANGUAGE - C++
SYSTEM - Windows 11
CREATION DATE - 29/09/2023
NOTE - None :)
*****************************************/

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <algorithm>
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

    //Fill obstacle info and push it in the vector listing all obstacles
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


    // Sort obstacles based on angle.
    // sortByAngle impose the order by increasing angle
    std::sort(obstacles.begin(), obstacles.end(), sortByAngle);

    return 0;
}