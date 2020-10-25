#pragma once

#include <iostream>
#include <chrono>
#include <thread>

class FrameTimer {
public:
    FrameTimer() {
        startFrameTime = std::chrono::high_resolution_clock::now();
        endFrameTime = std::chrono::high_resolution_clock::now();
    }
    
    float_t frame() {
        endFrameTime = std::chrono::high_resolution_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(endFrameTime - startFrameTime).count();
        startFrameTime = endFrameTime;
        return elapsedTime / 1000000.0f;
    }

private:
    std::chrono::high_resolution_clock::time_point startFrameTime;
    std::chrono::high_resolution_clock::time_point endFrameTime;
};