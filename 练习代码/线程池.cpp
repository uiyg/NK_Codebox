#include <iostream>
#include <mingw.mutex.h>
#include <mingw.condition_variable.h>
#include <mingw.thread.h>
#include <queue>
#include <functional>

class Threadpool
{
public:
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
int main()
{
    Threadpool pool(4);
    for (int i = 0; i < 8; i++)
    {
        pool.enqueue([i]
                     { printf("Task %d:is running! thradID:%d\n", i, std::this_thread::get_id());
            std::this_thread::sleep_for(std::chrono::seconds(1));
            printf("Task %d:is end! thradID:%d\n", i, std::this_thread::get_id()); });
    }
    return 0;
}