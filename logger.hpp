#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger
{
public:
    enum class LogLevel
    {
        Info,
        Warning,
        Error
    };

private:
    static void log(LogLevel level, const std::string& message);

public:
    static void info(const std::string& message);
    static void warning(const std::string& message);
    static void error(const std::string& message);
};

#endif