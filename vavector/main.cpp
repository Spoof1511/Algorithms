#include <cstring>
#include <iostream>
#include <random>
#include <algorithm>
#include "VAVector1.hpp"

int random_generate(int min, int max)
{
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    return uni(rng);
}

int main()
{
    Vector<int> vec_one(5);

    int min = 30;
    int max = 100;
    int output = random_generate(min, max);

    while(output != 100)
    {
        vec_one.push_back(output);
        output = random_generate(min, max);
    }

    std::cout << vec_one << std::endl;

    std::cout << "Accumulate: " << std::accumulate(vec_one.begin(), vec_one.end(), 0) << std::endl;

    std::sort(vec_one.begin(), vec_one.end(), [](int const& a, int const& b) { return a > b; });

    std::cout << "Sorted: " << vec_one << std::endl;

    Vector<int> vec_copy(vec_one);

    std::cout << "Copy of vector: " << vec_copy << std::endl;

    return 0;
}