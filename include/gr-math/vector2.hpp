#pragma once

#include "vector.hpp"

#include "vec2_operator.inl"

template <>
struct vector<float, 2>
{
    union
    {
        struct
        {
            float x;
            float y;
        };
        float data[2];
    };

    static vector<float, 2> zero;

    static vector<float, 2> one;

    static vector<float, 2> left;

    static vector<float, 2> right;

    static vector<float, 2> up;

    static vector<float, 2> down;
    
    constexpr const float &operator[](int i) const noexcept
    {
        return data[i];
    }

    constexpr float &operator[](int i) noexcept
    {
        return data[i];
    }
};

inline vector<float, 2> vector<float, 2>::zero = {0.0f, 0.0f};

inline vector<float, 2> vector<float, 2>::one = {1.0f, 1.0f};

inline vector<float, 2> vector<float, 2>::left = {-1.0f, 0.0f};

inline vector<float, 2> vector<float, 2>::right = {1.0f, 0.0f};

inline vector<float, 2> vector<float, 2>::up = {0.0f, 1.0f};

inline vector<float, 2> vector<float, 2>::down = {0.0f, -1.0f};



