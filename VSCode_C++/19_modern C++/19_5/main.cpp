#include <iostream>
#include <future>
#include <thread>

using namespace std;


int main()
{
    // {
    //     int result;

    //     std::thread t ([&] {result = 1 + 2; });
    //     t.join();
    //     cout << result << endl;
    // }

    {
        auto fut = std::async([] { return 1+2;});
        cout << fut.get() << endl;
    }
}