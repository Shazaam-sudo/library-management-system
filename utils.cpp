#include "utils.hpp"
#include <iostream>
#include <limits>
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;

int getValidInteger(const std::string& message, int minValue, int maxValue)
{
    while(true)
    {
        std::cout<<message;

        int intVal = 0;
        std::cin>>intVal;

        if(std::cin.fail())
        {
            std::cout<<std::endl;
            std::cout<<"Invalid Input. Please enter a number between "<<minValue<<" and "<<maxValue<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (intVal < minValue || intVal > maxValue)
        {
            std::cout<<"Invalid Input. Please enter a number between "<<minValue<<" and "<<maxValue<<std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return intVal;
        }
    }
}

std::string getValidString(const std::string& message)
{
    while(true)
    {
        std::cout<<message;

        std::string strVal = "";
        std::getline(std::cin, strVal);

        if(strVal.empty())
        {
            std::cout<<"Input cannot be empty. Please try again."<<std::endl;
        }
        else
        {
            leftTrim(strVal);

            if(strVal.empty())
            {
                std::cout<<"Input cannot be empty. Please try again."<<std::endl;
                continue;
            }

            rightTrim(strVal);

            return strVal;
        }
    }
}

void rightTrim(std::string& strVal)
{
    int i = strVal.size() - 1;

    while(i >= 0 && strVal[i] == ' ')
    {
        i--;
    }

    strVal = strVal.substr(0, i + 1);
}

void leftTrim(std::string& strVal)
{
    std::size_t i = 0;

    while(i < strVal.size() && strVal[i] == ' ')
    {
        i++;
    }

    strVal = strVal.substr(i);
}