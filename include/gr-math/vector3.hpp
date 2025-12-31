#pragma once

#include "types.hpp"

#include "vec3_operator.inl"

template <>
struct vector<f32, 3>
{
    union
    {
        struct
        {
            f32 x;
            f32 y;
            f32 z;
        };
        f32 data[3];
    };

    static vector zero;

    static vector one;

    static vector right;

    static vector left;

    static vector up;

    static vector down;

    static vector forward;

    static vector backward;

    constexpr const f32 &operator[](int i) const noexcept
    {
        return data[i];
    }

    constexpr f32 &operator[](int i) noexcept
    {
        return data[i];
    }
};

inline vector<f32, 3> vector<f32, 3>::zero = {0.0f, 0.0f, 0.0f};

inline vector<f32, 3> vector<f32, 3>::one = {1.0f, 1.0f, 1.0f};

inline vector<f32, 3> vector<f32, 3>::right = {1.0f, 0.0f, 0.0f};

inline vector<f32, 3> vector<f32, 3>::left  = {-1.0f, 0.0f, 0.0f};

inline vector<f32, 3> vector<f32, 3>::up = {0.0f, 1.0f, 0.0f};

inline vector<f32, 3> vector<f32, 3>::down = {0.0f, -1.0f, 0.0f};

inline vector<f32, 3> vector<f32, 3>::forward = {0.0f, 0.0f, 1.0f};

inline vector<f32, 3> vector<f32, 3>::backward = {0.0f, 0.0f, -1.0f};



