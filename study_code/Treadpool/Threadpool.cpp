// 本程序演示了线程池的使用。
// 它创建一个指定数量的线程池，并将任务添加到池中执行。
// 任务在池中的线程中执行。
// 本程序使用C++11标准库中的多线程和同步功能。
#include <iostream>
#include <mingw.mutex.h>
#include <mingw.condition_variable.h>
#include <mingw.thread.h>
#include <queue>
#include <functional>

// Threadpool类代表一个线程池。
class Threadpool
{
public:
    // 构造函数创建一个指定数量的线程池。
    Threadpool(int numThread) : stop(false)
    {
        for (int i = 0; i < numThread; i++)
        {
            threads.emplace_back([this]
                                 {
                while(true){
                    std::unique_lock<std::mutex> lock(mutex);
                    condition.wait(lock, [this]
                                   { return stop || !tasks.empty(); });
                    if (!stop)
                        return;
                    std::function<void()> task(std::move(tasks.front()));
                    tasks.pop();
                    lock.unlock();
                    task();
                } });
        }
    }
    // 析构函数停止池中的所有线程。
    ~Threadpool()
    {
        {
            std::unique_lock<std::mutex> lock;
            stop = true;
        }
        condition.notify_all();
        {
            for (std::thread &thread : threads)
            {
                thread.join();
            }
        }
    }
    // enqueue函数将任务添加到池的队列中。
    template <typename F, typename... Args>
    void enqueue(F &&f, Args &&...args)
    {
        std::function<void()> task(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        {
            std::unique_lock<std::mutex> lock(mutex);
            tasks.emplace(std::move(task));
        }
        condition.notify_one();
    }

private:
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;
    std::mutex mutex;
    std::condition_variable condition;
    bool stop;
};
// main函数创建一个4个线程的池，并添加8个任务。
int main()
{
    Threadpool pool(4);
    for (int i = 0; i < 8; i++)
    {
        pool.enqueue([i]
                     { printf("任务%d正在运行！线程ID：%d\n", i, std::this_thread::get_id());
            std::this_thread::sleep_for(std::chrono::seconds(1));
            printf("任务%d已完成！线程ID：%d\n", i, std::this_thread::get_id()); });
    }
    return 0;
}