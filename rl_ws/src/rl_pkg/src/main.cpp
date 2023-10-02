/****************************************
PROGRAM NAME - main
PROGRAMMER - Kuriozity
LANGUAGE - C++
SYSTEM - Windows 11
CREATION DATE - 30/09/2023
NOTE - None :)
*****************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <sstream>
#include "functions.h"

/*
The complexity of the algorithm is determine
by the number of operation guaranted we can expect
during its processing. In this case, if we consider
the number of points n and iterations k:
> Initialization: O(n)
> Loop : O(k)
> Loop insides: O(1)
> Error: O(1)
> Model: O(1)
> Finalization: O(1)
========> Complexity = O(nk)

This algorithm is commonly called RANSAC (Random Sample Consensus)
and its basically taking samples at random, creating a row of inclusion of
sample and settle for the most inclusive and error-less model.

For n=2 and a probability of 0.23 to pick an inlier point
P(not_select_n_inlier) = (1 - P(select_inlier))^n = (0.77)^n
P(select_n_inlier_every_k_iteration) = 0.99 <= 1 - P(not_select_n_inlier)^k 
0.99 <= 1 - 0.77^(nk)
k = ln(0.01)/(n*ln(0.77))
*/

//This node will be used through the command main2 < C:\ws\techical_test_ROS\rl_ws\src\rl_pkg\include\input.txt
int main() {
    //Create a vector that will stack up all the points
    //Create coordinates recipients that will be stack up for every points
    std::vector<std::pair<double, double>> data;
    double x, y;

    //Read data from standard input.txt and put it in data vector
    while (std::cin >> x >> y) {
        data.emplace_back(x, y);
    }

    int n = 2;       //Number of points required to create an initial model
    int k = 85;      //Number of iterations
    double t = 0.03; //Threshold value for error
    int d = 20;      //Minimum number of points required for a valid model

    //The formula for simple linear regression is Y = mX + b, says Google
    //I doubt data will often be linear between eachother, but let's find m and b anyway
    std::pair<double, double> result = bestmodelRegression(data,n,k,t,d);

    //Cut the result into displayable variables
    double slope = result.first;
    double intercept = result.second;

    //Display the equation of the line
    std::cout << "Best Model Equation: y = " << std::fixed << std::setprecision(2) << slope << "x + " << intercept << std::endl;


    return 0;
}
