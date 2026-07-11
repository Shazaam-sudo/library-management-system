#include "logger.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

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
}

void Logger::log(const std::string& level, const std::string& message)
{
    const std::string currentDateTime = getCurrentTime();
    const char* color = RESET;
    if(level == "INFO")
    {
        color = GREEN;

    }
    else if(level == "WARNING")
    {
        color = YELLOW;
    }
    else
    {
        color = RED;
    }

    std::cout<<currentDateTime<<" "
             <<color
             << "[" << level << "] "
             <<RESET
             <<message<<std::endl;
}

void Logger::info(const std::string& message)
{
    log("INFO", message);
}

void Logger::warning(const std::string& message)
{
    log("WARNING", message);
}

void Logger::error(const std::string& message)
{
    log("ERROR", message);
}