#pragma once

#include <iostream>
#include <chrono>
#include <thread>

static const float_t FRAME_TIME = 1.0f / 60.0f;

class FrameTimer {
public:
    FrameTimer() {
        startFrameTime = std::chrono::high_resolution_clock::now();
        endFrameTime = std::chrono::high_resolution_clock::now();
    }
    
    float_t frame() {
        /*endFrameTime = std::chrono::high_resolution_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(endFrameTime - startFrameTime).count();
        std::cout << "Elapsed time: " << elapsed_time << std::endl;
        startFrameTime = endFrameTime; */
        return FRAME_TIME;
    }

private:
    std::chrono::high_resolution_clock::time_point startFrameTime;
    std::chrono::high_resolution_clock::time_point endFrameTime;
};