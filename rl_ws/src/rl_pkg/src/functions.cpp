#include "functions.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <sstream>

std::pair<double, double> linearRegression(const std::vector<std::pair<double, double>>& data) {
    /*
        Will proceed to find the m and b of the linear equation Y = m*x+b using the data in input file

        Args:
            data (vector 2D): contain all the points coordinates

        Returns:
            slope_intercept (2 double): m and b resulting 
    
    */

    //To find the slope, we will the least-square method which will result in m = (nΣ(xy) - ΣxΣy) / (nΣ(x^2) - (Σx)^2)
    //The intercept being just Y when x=0, it will be straightforward after finding the slope
    std::pair<double, double> slope_intercept;
    double sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0;
    int n = data.size();

    //We take x and y from the data file and add them up into the right sums
    for (const auto& point : data) {
        double x = point.first;
        double y = point.second;
        sumX += x;
        sumY += y;
        sumXY += x * y;
        sumX2 += x * x;
    }
    //Centering the values; use traditionnally for linear regression
    //But more importantly for simplications; instead of working with all data, we work with one data for all
    double meanX = sumX / n;
    double meanY = sumY / n;

    //m = (nΣ(xy) - ΣxΣy) / (nΣ(x^2) - (Σx)^2)
    double slope = (sumXY - n * meanX * meanY) / (sumX2 - n * meanX * meanX);

    //b = y - mx
    slope_intercept = {slope, meanY - slope * meanX};

    return slope_intercept;
}

double errorModel(const std::pair<double, double>& model, const std::pair<double, double>& point) {
    /*
        Compute the error of a point to the model between the expected result Y and the Y already given 

        Args:
            model (double): first computed model from the first set of points
            point (double): point to be tested
            
        Returns:
            " " (double): error between resulted Y and given Y
    */
    double predictedY = model.first * point.first + model.second;
    return std::abs(predictedY - point.second);
}

std::pair<double, double> bestmodelRegression(const std::vector<std::pair<double, double>>& data, int n, int k, double t, int d) {
    /*
        Compute the error of a point to the model

        Args:
            data (double): data retreived from input file
            n (int): number of points required to create an initial model
            k (int): number of iterations
            t (int): error threshold for the points
            d (int): minimum number of points required for a valid model
            
        Returns:
            bestModel (double): m and b forming the best linear model
    */

    //We initialize the model as empty and the best error found is maximal (infinite)
    std::pair<double, double> bestModel = {0.0, 0.0};
    double bestError = std::numeric_limits<double>::infinity();

    //Start random number generator based on system clock
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    //Take n (2) random points from the data set in input file
    for (int iterations = 0; iterations < k; ++iterations) {
        std::vector<std::pair<double, double>> chosen_ones;
        for (int i = 0; i < n; ++i) {
            int index = std::rand() % data.size();
            chosen_ones.push_back(data[index]);
        }

        //Linear regression with the points chosen before
        std::pair<double, double> model = linearRegression(chosen_ones);

        //Go through every other points that are not the chosen ones
        for (const std::pair<double, double>& point : data) {
            if (std::find(chosen_ones.begin(), chosen_ones.end(), point) != chosen_ones.end()) {
                continue; // Skip points already in chosen_ones
            }

            //We will calculate the error between the expected result Y computed with the model before and the Y given for the point in the input file
            double error = errorModel(model, point);

            //If the error is below the threshold t, the point is added to the chosen_ones
            if (error < t) {
                chosen_ones.push_back(point);
            }
        }

        //Check if the number of chosen_ones is greater than or equal to d. If not, there are not enough points to be considered the best scenario
        if (chosen_ones.size() >= d) {
            //We recompute the model with more data with a minimal error between them
            model = linearRegression(chosen_ones);

            //We calculate the sum of errors for all chosen_ones with the updated model
            double sumError = 0.0;
            for (const std::pair<double, double>& point : chosen_ones) {
                sumError += errorModel(model, point);
            }

            //If the sum of errors is less than the current bestError, update bestModel and bestError
            if (sumError < bestError) {
                bestModel = model;
                bestError = sumError;
            }
        }
    }

    return bestModel;
}