#include "logger.h"
using namespace yazi::utility;

const char *Logger::s_level = {
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL"};

Logger *Logger::m_install = nullptr;

Logger::Logger()
{
}
Logger::~Logger()
{
}

Logger *Logger::instance()
{
    if (m_install == nullptr)
    {
        m_install = new Logger();
    }
    return m_install;
}
void Logger::open(const std::string &filename)
{
    std::string m_failename = filename;
    m_fout.open(filename,ios::app);
    if (m_fout.fail())
    {
        throw std::logic_error("open file failed" + filename);
    }
}
void Logger::close()
{
    m_fail.close();
}