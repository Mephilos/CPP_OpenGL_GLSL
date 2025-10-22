#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;
mutex mtx;// mutual exclusion
int main()
{   
    auto work_func = [](const string& name)
    {
        for(int i = 0; i < 5 ; i++)
        {
            std::this_thread::sleep_for(std::chrono::microseconds(100));

            cout << name << " " << std::this_thread::get_id() << "Working " << i << endl;
        }
    };
    
    std::thread t1 = std::thread(work_func , "Twilight");
    std::thread t2 = std::thread(work_func , "FlutterShy");

    t1.join();
    t2.join();
}
