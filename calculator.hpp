#ifndef __CALCULATOR_HPP
#define __CALCULATOR_HPP

#include <string>

// Parses a valid double-formatted string and returns the double value.
// Assumes the string has already been validated.
double parse_number(const std::string &expression);

#endif // __CALCULATOR_HPP
