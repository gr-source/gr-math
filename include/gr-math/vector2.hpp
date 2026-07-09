#pragma once

#include "vec2_operator.inl"

template <typename T>
struct type_traits<vector2<T>>
{
    static constexpr vector2<T> zero =
        { T(0), T(0) };

    static constexpr vector2<T> one =
        { T(1), T(1) };

    static constexpr vector2<T> left =
        { T(-1), T(0) };

    static constexpr vector2<T> right =
        { T(1), T(0) };

    static constexpr vector2<T> up =
        { T(0), T(1) };

    static constexpr vector2<T> down =
        { T(0), T(-1) };
};

/*
#include "types.hpp"

#include "vec2_operator.inl"

struct Vector2
{
    f32 x;
    f32 y;

    constexpr vector(f32 _x, f32 _y) : x(_x) {}

    inline static const vector<f32, 2> zero = {0.0f, 0.0f, 0.0f};

    static vector<f32, 2> one;


    
    inline constexpr const f32 &operator[](int i) const noexcept
    {
        return data[i];
    }

    inline constexpr f32 &operator[](int i) noexcept
    {
        return data[i];
    }
};

static constexpr vector2<T> zero = {0.0f, 0.0f};

static constexpr vector2<T> one = {1.0f, 1.0f};


*/


