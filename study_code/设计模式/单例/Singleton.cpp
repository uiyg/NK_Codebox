#include <iostream>
using namespace std;

// 单例模式的任务队列
class Singleton
{
public:
    // 删除拷贝构造函数和赋值运算符重载函数，防止拷贝
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    
    // 提供一个静态的公有方法，用于获取唯一的实例
    static Singleton *getInstance()
    {
        return instance;
    }

    void print()
    {
        cout << "这是单例模式的一个任务队列成员函数" << endl;
    }

private:
    Singleton() = default;
    static Singleton *instance;
};
Singleton *Singleton::instance = new Singleton();

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    s1->print();
    s2->print();
    return 0;
}