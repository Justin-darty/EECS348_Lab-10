/*
 * Program: Lab 10 - Calculator
 * Author: Justin Daugherty
 * Description: This file contains the implementation of functions to parse a string into a double value.
 *              The `parse_number` function is used to convert a valid string into a double for further calculations.
 * Date: April 16, 2025
 */

#include "calculator.hpp"
#include <sstream>

double parse_number(const std::string &expression) {
    std::stringstream ss(expression);
    double value = 0.0;
    ss >> value;
    return value;
}
