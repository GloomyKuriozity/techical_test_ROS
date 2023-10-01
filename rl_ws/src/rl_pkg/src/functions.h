#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <sstream>

std::pair<double, double> linearRegression(const std::vector<std::pair<double, double>>& data);
double errorModel(const std::pair<double, double>& model, const std::pair<double, double>& point);
std::pair<double, double> bestmodelRegression(const std::vector<std::pair<double, double>>& data, int n, int k, double t, int d);

#endif // FUNCTIONS_H