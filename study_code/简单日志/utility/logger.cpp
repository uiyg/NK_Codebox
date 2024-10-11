#include "logger.h"

#include <time.h>
#include <string.h>
#include <iostream>
#include <stdexcept>
#include <stdarg.h>
#include <direct.h> //获取路径

using namespace yazi::utility;

const char *Logger::s_level[LEVEL_COUNT] = {
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL"};

Logger *Logger::m_instance = nullptr;

Logger::Logger() : m_level(DEBUG), m_max(0), m_len(0)
{
}
Logger::~Logger()
{
    close();
}

Logger *Logger::instance()
{
    if (m_instance == nullptr)
    {
        m_instance = new Logger();
    }
    return m_instance;
}
void Logger::open(const std::string &filename)
{
    m_filename = filename;
    m_fout.open(filename, std::ios::app);
    if (m_fout.fail())
    {
        throw std::logic_error("open file failed" + filename);
    }
    // 获取原文件长度
    m_fout.seekp(0, std::ios::end);
    m_len = m_fout.tellp();
}
void Logger::close()
{
    m_fout.close();
}

// 日志格式
void Logger::log(enum Level level, const char *file, int line, const char *format, ...)
{
    // 判断日志级别,如果小于当前级别则不输出
    if (m_level > level)
    {
        return;
    }
    if (m_fout.fail())
    {
        throw std::logic_error("open file failed" + m_filename);
    }

    // 获取时间戳
    time_t tick = time(nullptr);
    struct tm *ptm = localtime(&tick);
    char timestamp[32];
    memset(timestamp, 0, 32);
    strftime(timestamp, 32, "%Y-%m-%d %H:%M:%S", ptm);

    int len = 0;
    // 格式封面  时间 级别 文件 行号
    const char *ftm = "%s %s %s:%d\n";
    int size = snprintf(nullptr, 0, ftm, timestamp, s_level[level], file, line);
    // 输出格式化后的日志
    if (size > 0)
    { // 确定缓冲区大小
        char *buffer = new char[size + 1];
        snprintf(buffer, size + 1, ftm, timestamp, s_level[level], file, line);
        std::cout << buffer;
        m_fout << buffer;
        m_len += size; // 更新日志长度
        delete[] buffer;
    }

    va_list arg_ptr;                            // 定义一个va_list类型的变量arg_ptr，用于存储可变参数列表
    va_start(arg_ptr, format);                  // 初始化arg_ptr，使其指向可变参数列表的第一个参数
    size = vsnprintf(NULL, 0, format, arg_ptr); // 计算格式化字符串的长度，但不输出
    va_end(arg_ptr);                            // 清理arg_ptr
    if (size > 0)                               // 如果格式化字符串的长度大于0
    {
        char *content = new char[size + 1];            // 分配一个大小为size+1的字符数组，用于存储格式化字符串
        va_start(arg_ptr, format);                     // 重新初始化arg_ptr，使其指向可变参数列表的第一个参数
        vsnprintf(content, size + 1, format, arg_ptr); // 将格式化字符串输出到content中
        va_end(arg_ptr);                               // 清理arg_ptr
        content[size] = 0;
        std::cout << content << std::endl; // 输出格式化字符串
        m_fout << content;                 // 将格式化字符串写入文件
        delete[] content;                  // 释放content的内存
        m_len += size;                     // 更新日志长度
    }

    m_fout << '\n';
    // 将内容写入日志文件
    m_fout.flush();
    // std::cout << timestamp << std::endl;
    // std::cout << file << std::endl;
    // std::cout << "第 " << line << " 行调用" << std::endl;
    // std::cout << format << std::endl;

    if (m_len >= m_max && m_max > 0)
    {
        rotate();
    }
}

void Logger::level(int level)
{
    m_level = level;
}

void Logger::max(int bytes)
{
    m_max = bytes;
}

void Logger::rotate()
{
    close(); // 关闭当前日志文件

    // 获取当前时间戳
    time_t tick = time(NULL);
    struct tm *ptm = localtime(&tick);
    char timestamp[32];
    memset(timestamp, 0, sizeof(timestamp));
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", ptm);
    // 构造新的文件名
    std::string new_filename = m_filename + "_" + timestamp + ".log";

    // 重命名当前日志文件
    // 上次错误在open函数中m_filename打错字了，导致无法正确打开文件
    if (rename(m_filename.c_str(), new_filename.c_str()) != 0)
    {
        throw std::logic_error("rename log file failed: " + std::string(strerror(errno)));
    }

    // 重新打开新的日志文件
    open(m_filename);
}
