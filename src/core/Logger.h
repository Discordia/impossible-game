#pragma once

#include <string>

enum LogLevel
{
    LOG_ERROR,
    LOG_WARN,
    LOG_INFO,
    LOG_DEBUG
};

class Logger
{
public:
    explicit Logger(const std::string& tag);

    static Logger create(const std::string& tag);
    void logf(LogLevel level, std::string message, ...) const;

private:
    const std::string tag;
};