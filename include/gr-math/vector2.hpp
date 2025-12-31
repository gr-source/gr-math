#pragma once

#include "types.hpp"

#include "vec2_operator.inl"

template <>
struct vector<f32, 2>
{
    union
    {
        struct
        {
            f32 x;
            f32 y;
        };
        f32 data[2];
    };

    static vector<f32, 2> zero;

    static vector<f32, 2> one;

    static vector<f32, 2> left;

    static vector<f32, 2> right;

    static vector<f32, 2> up;

    static vector<f32, 2> down;
    
    constexpr const f32 &operator[](int i) const noexcept
    {
        return data[i];
    }

    constexpr f32 &operator[](int i) noexcept
    {
        return data[i];
    }
};

inline vector<f32, 2> vector<f32, 2>::zero = {0.0f, 0.0f};

inline vector<f32, 2> vector<f32, 2>::one = {1.0f, 1.0f};

inline vector<f32, 2> vector<f32, 2>::left = {-1.0f, 0.0f};

inline vector<f32, 2> vector<f32, 2>::right = {1.0f, 0.0f};

inline vector<f32, 2> vector<f32, 2>::up = {0.0f, 1.0f};

inline vector<f32, 2> vector<f32, 2>::down = {0.0f, -1.0f};



