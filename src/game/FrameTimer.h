#pragma once

#include <chrono>
#include <thread>

static const double FRAME_TIME_MS = 16.67;

class FrameTimer {
public:
    FrameTimer() {
        currentTime = std::chrono::system_clock::now();
        lastTime = std::chrono::system_clock::now();
    }
    
    void frame() {
        currentTime = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> frameTime = currentTime - lastTime;
        lastTime = currentTime;

        if (frameTime.count() < FRAME_TIME_MS) {
            std::chrono::duration<double, std::milli> delta_ms(FRAME_TIME_MS - frameTime.count());
            auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
            std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
        }
    }

private:
    std::chrono::system_clock::time_point currentTime;
    std::chrono::system_clock::time_point lastTime;
};