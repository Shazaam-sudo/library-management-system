#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger
{
private:
    static void log(const std::string& level, const std::string& message);
public:
    static void info(const std::string& message);
    static void warning(const std::string& message);
    static void error(const std::string& message);
};

#endif