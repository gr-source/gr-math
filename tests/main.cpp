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
    Vector3 next = Vector3::zero;
    next += Vector3{1.1f, 1.3f, 1.6f};

    next = -next;

    std::cout << next.x << ", " << next.y << ", " << next.z << std::endl;
}



