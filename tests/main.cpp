#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>
#include <chrono>

#include "../include/gr-math/gmath.hpp"

class FunctionTimer
{
public:
    FunctionTimer(const std::string& name) :
        m_name(name),
        m_start(std::chrono::steady_clock::now())
    {}

    ~FunctionTimer()
    {
        auto end =
                std::chrono::steady_clock::now();

            auto duration =
                std::chrono::duration<double, std::milli>(
                    end - m_start);

            std::cout
                << m_name
                << ": "
                << std::fixed
                << std::setprecision(3)
                << duration.count()
                << " ms\n";
    }


private:
    std::chrono::steady_clock::time_point m_start;

    std::string m_name;
};

int main()
{
    {
        FunctionTimer test("Multi");

        Vector3 value = type_traits<Vector3>::one;
        for (size_t i=0;i<1000000;i++)
        {
            value *= Vector3{float(i), float(i + 11), float(i + 2)};
        }

        std::cout
            << "Value: "
            << std::fixed
            << std::setprecision(3)
            << value.x
            << " "
            << value.y
            << " "
            << value.z
            << std::endl;
    }
}



