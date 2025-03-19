#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <random>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>
#include <exception>

using namespace std;

mutex mtx;


void dotProductNaive(const vector<int>& v0, const vector<int>& v1,
const unsigned i_start, const unsigned i_end, unsigned long long & sum)
{
    for (unsigned i = i_start; i < i_end; ++i)
    {
        sum += v0[i] * v1[i];
    }
    
}

void dotProduct(const vector<int>& v0, const vector<int>& v1,
const unsigned i_start, const unsigned i_end, atomic<unsigned long long> & sum)
{
    unsigned long long partial_sum = 0;
    for (unsigned i = i_start; i < i_end; ++i)
    {
        partial_sum += v0[i] * v1[i];
    }
    sum += partial_sum;
}



int main()
{
    const long long n_data = 100'000'000;
    const unsigned n_threads = 4;

    std::vector<int> v0, v1;
    v0.reserve(n_data);
    v1.reserve(n_data);

    random_device rd_seed;
    mt19937 gen(rd_seed());
    uniform_int_distribution<int> uniformDist(1, 10);

    for (long long i = 0; i < n_data; ++i)
    {
        v0.push_back(uniformDist(gen));
        v1.push_back(uniformDist(gen));
    }

    cout << "std::inner_product" <<endl;
    {
        const auto start = chrono::high_resolution_clock::now();
        const auto sum = inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);
        const chrono::duration<double> duration = chrono::high_resolution_clock::now() - start;
        cout << "sum: " << sum << " duration: " << duration.count() << "s" << endl;
    }

    cout << "Naive" <<endl;
    {
        const auto start = chrono::high_resolution_clock::now();
        unsigned long long sum = 0;
        vector<thread> threads;
        threads.resize(n_threads);
        
        const unsigned n_data_per_thread = n_data / n_threads;
        for (unsigned i = 0; i < n_threads; ++i)
        {
            threads[i] = thread(dotProductNaive, ref(v0), ref(v1), 
            i * n_data_per_thread, (i + 1) * n_data_per_thread, ref(sum));
        }

        for (auto& t : threads)
        {
            t.join();
        }
        
        const chrono::duration<double> duration 
        = chrono::high_resolution_clock::now() - start;
        std::cout << "sum: " << sum << " duration: " << duration.count() << "s" << endl;

    }
    return 0;
}