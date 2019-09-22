#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

const int kValueRange = 5000000;
const int kArraySize = 100000;

void print_vector(const std::vector<int>& v) {
    for (auto& i : v)
        std::cout << i << ' ';
    std::cout << '\n';
}

void selection_sort(std::vector<int>& v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        int least = i;
        int j = i + 1;
        for (; j < n; j++)
            if (v[j] < v[least])
                least = j;
        std::swap(v[i], v[least]);
    }
}

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

    // print_vector(v);
    
    auto start = std::chrono::system_clock::now();
    selection_sort(v);
    auto end = std::chrono::system_clock::now();

    // print_vector(v);

    auto elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "us\n";
}