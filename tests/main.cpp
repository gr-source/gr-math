#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>
#include <chrono>

#include "../include/gr-math/gmath.hpp"

class FunctionTimer
{
public:
    FunctionTimer() : startTime(std::chrono::high_resolution_clock::now()), deltaTime(0.0f)
    {
    }

    void start()
    {
        startTime = std::chrono::high_resolution_clock::now();
    }

    void end()
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration<float>(currentTime - startTime).count();
    }

    float getDeltaTime() const
    {
        return deltaTime;
    }

    float getFps() const
    {
        return (deltaTime > 0.0f) ? (1.0f / deltaTime) : 0.0f;
    }

private:
    std::chrono::high_resolution_clock::time_point startTime;

    float deltaTime;
};

int main()
{
    Quaternion q = {1.0f, 0.0f, 0.0f, 0.0f};

    printf("Quat: w(%f), x(%f), y(%f), z(%f)\n", q.w, q.x, q.y, q.z);
}



