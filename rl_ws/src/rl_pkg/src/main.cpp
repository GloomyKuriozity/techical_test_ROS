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

int main() {
    //Create a vector that will stack up all the points
    //Create coordinates recipients that will be stack up for every points
    std::vector<std::pair<double, double>> data;
    double x, y;

    //Read data from standard input.txt and put it in data vector
    while (std::cin >> x >> y) {
        data.emplace_back(x, y);
    }

    return 0;
}
