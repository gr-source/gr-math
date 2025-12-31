#pragma once

#include "types.hpp"

#include "vec4_operator.inl"

template <>
struct vector<f32, 4>
{
    union
    {
        struct
        {
            f32 x;
            f32 y;
            f32 z;
            f32 w;
        };
        f32 data[4];
    };

    static vector zero;

    constexpr const f32 &operator[](int i) const noexcept
    {
        return data[i];
    }

    constexpr f32 &operator[](int i) noexcept
    {
        return data[i];
    }
};

inline vector<f32, 4> vector<f32, 4>::zero = {0.0f, 0.0f, 0.0f, 0.0f};




