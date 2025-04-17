/*
 * Program: Lab 10 - Calculator
 * Author: Justin Daugherty
 * Description: This program reads numbers from a user-specified file, checks if they are valid double values,
 *              adds them to a constant (-123.456), and outputs the result. Invalid numbers are flagged.
 *              The program performs basic string processing and regex matching to validate and process the data.
 * Date: April 16, 2025
 */

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>
#include <cctype>
#include "calculator.hpp"

// Trim leading/trailing whitespace and control characters
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    return (first == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

// Validate if the input string is a valid double
bool isValidDouble(const std::string& input) {
    std::regex doublePattern(R"(^[+-]?(\d+(\.\d*)?|\.\d+)$)");  // Updated pattern
    return std::regex_match(input, doublePattern);
}

int main() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file '" << filename << "'\n";
        return 1;
    }

    std::string line;
    const double constant = -123.456;

    while (std::getline(file, line)) {
        line = trim(line);
        std::cout << "Processing: '" << line << "'\n";  // Debugging line

        if (isValidDouble(line)) {
            double parsed = parse_number(line);
            double result = parsed + constant;
            std::cout << line << " + (" << constant << ") = " << result << "\n";
        } else {
            std::cout << "Invalid double: " << line << "\n";
        }
    }

    file.close();
    return 0;
}
