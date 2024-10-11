#include <iostream>
#include "logger.h"
using namespace yazi::utility;
int main()
{
    // std::cout << "hello world" << std::endl;
    yazi::utility::Logger::instance()->open("./text.log");
    // 过滤级别
    // yazi::utility::Logger::instance()->level(yazi::utility::Logger::DEBUG);
    yazi::utility::Logger::instance()->max(1024);
    // yazi::utility::Logger::instance()->log(
    //     yazi::utility::Logger::DEBUG, __FILE__, __LINE__, "hello world");

    // yazi::utility::Logger::instance()->log(
    //     yazi::utility::Logger::DEBUG, __FILE__, __LINE__, "name is: %s,age is: %d", "jack", 18);

    // 用不了yazi::utility::debug("hello world");不知道为什么
    debug("hello world");
    debug("jack", 18);
    info("info message");
    warn("warn message");
    error("error message");
    debug("hello world");
    debug("jack", 18);
    info("info message");
    warn("warn message");
    error("error message");
    return 0;
}