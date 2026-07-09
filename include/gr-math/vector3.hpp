#pragma once

#include "vec3_operator.inl"

template <typename T>
struct type_traits<vector3<T>>
{
    static constexpr vector3<T> zero =
        { T(0),  T(0),  T(0) };

    static constexpr vector3<T> one =
        { T(1),  T(1),  T(1) };

    static constexpr vector3<T> right =
        { T(1),  T(0),  T(0) };

    static constexpr vector3<T> left =
        {- T(1),  T(0),  T(0) };

    static constexpr vector3<T> up =
        { T(0),  T(1),  T(0) };

    static constexpr vector3<T> down =
        { T(0), - T(1),  T(0) };

    static constexpr vector3<T> forward =
        { T(0),  T(0),  T(1) };

    static constexpr vector3<T> backward =
        { T(0),  T(0), - T(1) };
};

/*
#include "types.hpp"

#include "vec3_operator.inl"

template <>
struct alignas(16) vector<f32, 3>
{
    union
    {
        struct
        {
            f32 x;
            f32 y;
            f32 z;
            f32 _pad;
        };
        f32 data[4];
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

static constexpr vector3<T> zero = { T(0),  T(0),  T(0),  T(0)};

static constexpr vector3<T> one = { T(1),  T(1),  T(1),  T(0)};

static constexpr vector3<T> right = { T(1),  T(0),  T(0),  T(0)};

static constexpr vector3<T> left  = {- T(1),  T(0),  T(0),  T(0)};

static constexpr vector3<T> up = { T(0),  T(1),  T(0),  T(0)};

static constexpr vector3<T> down = { T(0), - T(1),  T(0),  T(0)};

static constexpr vector3<T> forward = { T(0),  T(0),  T(1),  T(0)};

static constexpr vector3<T> backward = { T(0),  T(0), - T(1),  T(0)};
*/


