#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

std::mutex mtx;
using namespace std;

atomic<int> shared_memory(0);

int main()
{
    auto count_func = [&]() {
        for ( int i = 0; i < 1000; ++i)
        {
            this_thread::sleep_for(std::chrono::microseconds(1));
            
            
            //mtx.lock();
            std::scoped_lock lock(mtx);
            
            cout << this_thread::get_id() << endl;
            
            shared_memory++;
            //mtx.unlock();
        }
    };

    thread t1 = thread(count_func);
    thread t2 = thread(count_func);
    thread t3 = thread(count_func);
    thread t4 = thread(count_func);
    thread t5 = thread(count_func);
    thread t6 = thread(count_func);
    thread t7 = thread(count_func);
    thread t8 = thread(count_func);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    cout << "After" << endl;
    cout << shared_memory << endl;

    return 0;
}