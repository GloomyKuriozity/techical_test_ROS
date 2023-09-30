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

int main() {
    //Create a vector that will stack up all the points
    //Create coordinates recipients that will be stack up for every points
    std::vector<std::pair<double, double>> data;
    double x, y;

    //Read data from standard input.txt and put it in data vector
    while (std::cin >> x >> y) {
        data.emplace_back(x, y);
    }
    //The formula for simple linear regression is Y = mX + b, says Google
    //I doubt data will often be linear between eachother, but let's find m and b anyway
    std::pair<double, double> result = linearRegression(data);

    return 0;
}
