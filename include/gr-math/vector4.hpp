#pragma once

#include "vector.hpp"

#include "vec4_operator.inl"

template <>
struct vector<float, 4>
{
    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        float data[4];
    };

    static vector zero;

    constexpr const float &operator[](int i) const noexcept
    {
        return data[i];
    }

    constexpr float &operator[](int i) noexcept
    {
        return data[i];
    }
};

inline vector<float, 4> vector<float, 4>::zero = {0.0f, 0.0f, 0.0f, 0.0f};




