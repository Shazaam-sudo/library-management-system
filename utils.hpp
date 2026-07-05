#ifndef UTILS_H
#define UTILS_H

#include <string>

int getValidInteger(const std::string& message, int minValue, int maxValue);
std::string getValidString(const std::string& message);
void leftTrim(std::string& strVal);
void rightTrim(std::string& strVal);

#endif