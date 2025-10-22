#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

int main()
{
    const int num_pro = std::thread::hardware_concurrency();

    std::cout << std::this_thread::get_id() << endl;

    vector<std::thread> my_threads;
    my_threads.resize(num_pro);

    for (auto &e : my_threads)
    {
        e = std::thread([]()
                        { cout << std::this_thread::get_id() <<endl;
        while(true)
        {
        } });
        static int maThreadCount;
        cout << maThreadCount << endl;
        ++maThreadCount;
    }
    for (auto &e : my_threads)
    {
        e.join();
    }
    return 0;
}