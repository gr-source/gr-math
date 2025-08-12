#pragma once

#include "vector.hpp"
#include "vec3_operator.inl"

template <>
struct vector<float, 3>
{
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        float data[3];
    };

    static vector zero;

    static vector one;

    static vector right;

    static vector left;

    static vector up;

    static vector down;

    static vector forward;

    static vector backward;

    constexpr const float &operator[](int i) const noexcept
    {
        return data[i];
    }

    constexpr float &operator[](int i) noexcept
    {
        return data[i];
    }
};

inline vector<float, 3> vector<float, 3>::zero = {0.0f, 0.0f, 0.0f};

inline vector<float, 3> vector<float, 3>::one = {1.0f, 1.0f, 1.0f};

inline vector<float, 3> vector<float, 3>::right = {1.0f, 0.0f, 0.0f};

inline vector<float, 3> vector<float, 3>::left  = {-1.0f, 0.0f, 0.0f};

inline vector<float, 3> vector<float, 3>::up = {0.0f, 1.0f, 0.0f};

inline vector<float, 3> vector<float, 3>::down = {0.0f, -1.0f, 0.0f};

inline vector<float, 3> vector<float, 3>::forward = {0.0f, 0.0f, 1.0f};

inline vector<float, 3> vector<float, 3>::backward = {0.0f, 0.0f, -1.0f};



