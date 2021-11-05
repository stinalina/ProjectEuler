#pragma once
#include <iostream>
#include <chrono>

class Timer
{
public:
    void Run()
    {
        m_StartTimepoint = std::chrono::high_resolution_clock::now();
    }

    void Stop()
    {
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        long long start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_StartTimepoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::milliseconds>(endTimepoint).time_since_epoch().count();

        std::cout << "Solution tooks " << end - start << "ms\n";
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};