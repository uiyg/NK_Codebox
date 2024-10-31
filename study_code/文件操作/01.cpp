#include <fstream>
#include <iostream>
int main()
{

    std::ofstream out("test.txt");
    out << "hello world" << std::endl;
    out << "这是一行测试数据" << std::endl;
    out << "这是第二行测试数据" << std::endl;
    // out << "这是第三行测试数据" << std::endl;


    std::ifstream in;
    in.open("test.txt",std::ios::in);
    if (!in.is_open())
    {
        std::cout << "文件打开失败" << std::endl;
        return -1;
    }
    
    char c;
    while (in.get(c)){
        std::cout << c;
    }
    in.close();
    return 0;
}