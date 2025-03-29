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

Matrix4x4 multi(const Matrix4x4 &A, const Matrix4x4 & B)
{
    Matrix4x4 result = Matrix4x4::zeroMatrix;

    return result;
}

int main() {
    FunctionTimer func;

    Matrix4x4 A = {
        Vector4{1.0f,  2.0f,   3.0f,   4.0f},
        Vector4{5.0f,  6.0f,   7.0f,   8.0f},
        Vector4{9.0f,  10.0f,  11.0f,  12.0f},
        Vector4{13.0f, 14.0f,  15.0f,  16.0f}
    };// Math::CreateTRS(Vector3{0.0, 200.0f, 100.0f}, Math::euler(Vector3{100.0f, 200.0f, 16.0f}), Vector3{1.0f, 1.0f, 1.0f});

    Matrix4x4 B = {
        Vector4{16.0f, 15.0f,  14.0f,  13.0f},
        Vector4{12.0f, 11.0f,  10.0f,  9.0f},
        Vector4{8.0f,  7.0f,   6.0f,   5.0f},
        Vector4{4.0f,  3.0f,   2.0f,   1.0f}
    }; // Math::CreateTRS(Vector3{17.0, 20.0f, 9.0f}, Math::euler(Vector3{10.0f, 82.0f, 906.0f}), Vector3{1.0f, 1.0f, 1.0f});
    
    Vector4 result = Vector4::zero; // Matrix4x4::zeroMatrix;
    Vector4 f = Vector4{1.0f, 1.0f, 1.0f, 1.0f};

    func.start();
    for (int i=0;i<100000;i++)
    {
        result = f * A;
        /*result = multi(A, B);*/
    }
        /*auto c = a * b;*/
    func.end();

    std::cout << "Result" << std::endl;
    std::cerr << std::setprecision(6) << std::fixed << "Time: " << func.getDeltaTime() << std::endl;
    std::cerr << std::setprecision(6) << std::fixed << "Fps:  " << func.getFps() << std::endl;

    for (int x=0;x<4;x++)
    {
        /*for (int y=0;y<4;y++)*/
        {
            std::cout << result[x] << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}



