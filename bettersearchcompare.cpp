//
// Created by Lenovo on 16/08/2023.
//
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include "stopwatch.h"

int binary_search(const std::vector<int>& v, int seek){
    int first = 0,
        last = static_cast<int>(v.size()) - 1,
        mid;
    while (first <= last){
        mid = first + (last - first + 1)/2;
        if (v[mid] == seek)
            return mid;
        else if (v[mid] > seek)
            last = mid - 1;
        else
            first = mid + 1;
    }
    return -1;
}

int linear_search(const std::vector<int>& v, int seek){
    size_t n = static_cast<int>(v.size());
    for (size_t i = 0; i < n && v[i] <= seek; i++)
        if (v[i] == seek)
            return static_cast<int>(i);
    return -1;
}

int main(){
    const size_t SIZE = 30000;
    std::vector<int> list(SIZE);

    Stopwatch timer;

    for (size_t i = 0; i < SIZE; i++)
        list[i] = static_cast<int>(i);

    timer.start();
    for (size_t i = 0; i < SIZE; i++)
        linear_search(list,static_cast<int>(i));

    timer.stop();
    std::cout << "Linear elapsed: " << timer.elapsed() << " seconds\n";

    timer.reset();

    timer.start();
    for (size_t i = 0; i < SIZE; i++)
        binary_search(list, static_cast<int>(i));

    timer.stop();
    std::cout << "Binary elapsed: " << timer.elapsed() << " seconds\n";
}
