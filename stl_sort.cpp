#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

const int kValueRange = 5000000;
const int kArraySize = 100000;
int main()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, kValueRange);
 
    std::vector<int> v(kArraySize);
    for (auto& i : v) {
        //Use dis to transform the random unsigned int generated by gen into an int in [1, 1,000]
        i = dis(gen);
    }

    auto start = std::chrono::system_clock::now();
    
    std:sort(begin(v), end(v));

    auto end = std::chrono::system_clock::now();

    auto elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "us\n";
}