#include "logger.h"

#include <time.h>
#include <string.h>
#include <iostream>
#include <stdexcept>
#include <stdarg.h>
#include <direct.h> //��ȡ·��

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
    // ��ȡԭ�ļ�����
    m_fout.seekp(0, std::ios::end);
    m_len = m_fout.tellp();
}
void Logger::close()
{
    m_fout.close();
}

// ��־��ʽ
void Logger::log(enum Level level, const char *file, int line, const char *format, ...)
{
    // �ж���־����,���С�ڵ�ǰ���������
    if (m_level > level)
    {
        return;
    }
    if (m_fout.fail())
    {
        throw std::logic_error("open file failed" + m_filename);
    }

    // ��ȡʱ���
    time_t tick = time(nullptr);
    struct tm *ptm = localtime(&tick);
    char timestamp[32];
    memset(timestamp, 0, 32);
    strftime(timestamp, 32, "%Y-%m-%d %H:%M:%S", ptm);

    int len = 0;
    // ��ʽ����  ʱ�� ���� �ļ� �к�
    const char *ftm = "%s %s %s:%d\n";
    int size = snprintf(nullptr, 0, ftm, timestamp, s_level[level], file, line);
    // �����ʽ�������־
    if (size > 0)
    { // ȷ����������С
        char *buffer = new char[size + 1];
        snprintf(buffer, size + 1, ftm, timestamp, s_level[level], file, line);
        std::cout << buffer;
        m_fout << buffer;
        m_len += size; // ������־����
        delete[] buffer;
    }

    va_list arg_ptr;                            // ����һ��va_list���͵ı���arg_ptr�����ڴ洢�ɱ�����б�
    va_start(arg_ptr, format);                  // ��ʼ��arg_ptr��ʹ��ָ��ɱ�����б�ĵ�һ������
    size = vsnprintf(NULL, 0, format, arg_ptr); // �����ʽ���ַ����ĳ��ȣ��������
    va_end(arg_ptr);                            // ����arg_ptr
    if (size > 0)                               // �����ʽ���ַ����ĳ��ȴ���0
    {
        char *content = new char[size + 1];            // ����һ����СΪsize+1���ַ����飬���ڴ洢��ʽ���ַ���
        va_start(arg_ptr, format);                     // ���³�ʼ��arg_ptr��ʹ��ָ��ɱ�����б�ĵ�һ������
        vsnprintf(content, size + 1, format, arg_ptr); // ����ʽ���ַ��������content��
        va_end(arg_ptr);                               // ����arg_ptr
        content[size] = 0;
        std::cout << content << std::endl; // �����ʽ���ַ���
        m_fout << content;                 // ����ʽ���ַ���д���ļ�
        delete[] content;                  // �ͷ�content���ڴ�
        m_len += size;                     // ������־����
    }

    m_fout << '\n';
    // ������д����־�ļ�
    m_fout.flush();
    // std::cout << timestamp << std::endl;
    // std::cout << file << std::endl;
    // std::cout << "�� " << line << " �е���" << std::endl;
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
    close(); // �رյ�ǰ��־�ļ�

    // ��ȡ��ǰʱ���
    time_t tick = time(NULL);
    struct tm *ptm = localtime(&tick);
    char timestamp[32];
    memset(timestamp, 0, sizeof(timestamp));
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", ptm);
    // �����µ��ļ���
    std::string new_filename = m_filename + "_" + timestamp + ".log";

    // ��������ǰ��־�ļ�
    // �ϴδ�����open������m_filename������ˣ������޷���ȷ���ļ�
    if (rename(m_filename.c_str(), new_filename.c_str()) != 0)
    {
        throw std::logic_error("rename log file failed: " + std::string(strerror(errno)));
    }

    // ���´��µ���־�ļ�
    open(m_filename);
}
