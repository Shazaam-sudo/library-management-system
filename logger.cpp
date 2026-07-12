#include "logger.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

namespace
{
    constexpr const char* RED    = "\033[31m";
    constexpr const char* GREEN  = "\033[32m";
    constexpr const char* YELLOW = "\033[33m";
    constexpr const char* RESET  = "\033[0m";

    std::string getCurrentTime()
    {
        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);

        if(localTime == nullptr)
        {
            return "Unknown Time";
        }

        std::ostringstream oss;

        oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");

        return oss.str();
    }

    const char* getLogString(Logger::LogLevel level)
    {
        if(level == Logger::LogLevel::Info)
            return "INFO";

        else if(level == Logger::LogLevel::Warning)
            return "WARNING";    
        
        return "ERROR";
    }

    const char* getColor(Logger::LogLevel level)
    {
        if(level == Logger::LogLevel::Info)
            return GREEN;
        
        else if(level == Logger::LogLevel::Warning)
            return YELLOW;

        return RED;
    }
}

void Logger::log(Logger::LogLevel level, const std::string& message)
{
    const std::string currentDateTime = getCurrentTime();
    const char* loglevel = getLogString(level);
    const char* color = getColor(level);

    std::ofstream file("logs.txt", std::ios::app);

    if(!file)
    {
        std::cout<<currentDateTime<<" "
             <<RED
             << "[ERROR] "
             <<RESET
             <<"Filed to open logs file"
             <<std::endl;
    }
    else
    {
        file<<currentDateTime<<" "
            << "[" << loglevel << "] "
            <<message
            <<'\n';
    }

    std::cout<<currentDateTime<<" "
             <<color
             << "[" << loglevel << "] "
             <<RESET
             <<message
             <<std::endl;
}

void Logger::info(const std::string& message)
{
    log(Logger::LogLevel::Info, message);
}

void Logger::warning(const std::string& message)
{
    log(Logger::LogLevel::Warning, message);
}

void Logger::error(const std::string& message)
{
    log(Logger::LogLevel::Error, message);
}