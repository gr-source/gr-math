#pragma once

#include "vector.hpp"

template <typename T>
struct type_traits<mat3<T>>
{
    static constexpr mat3<T> identity =
    {
        {
            { T(1),  T(0),  T(0) },
            { T(0),  T(1),  T(0) },
            { T(0),  T(0),  T(1) }
        }
    };

    static constexpr mat3<T> zero =
    {
        {
            { T(0),  T(0),  T(0) },
            { T(0),  T(0),  T(0) },
            { T(0),  T(0),  T(0) }
        }
    };
};

/*
#include "mat3x3_operator.inl"

#include "vector3.hpp"

// Column-Major
template <>
struct mat<f32, 3, 3>
{
    union
    {
        struct
        {
            vector<f32, 3> col0;
            vector<f32, 3> col1;
            vector<f32, 3> col2;
        };
        vector<f32, 3> data[3];
    };

    static mat<f32, 3, 3> identityMatrix;

    static mat<f32, 3, 3> zeroMatrix;

    // [Column][Row]
    inline constexpr const vector<f32, 3> &operator[](int i) const noexcept
    {
        return data[i];
    }

    // [Column][Row]
    inline constexpr vector<f32, 3> &operator[](int i) noexcept
    {
        return data[i];
    }
};

inline mat<f32, 3, 3> mat<f32, 3, 3>::identityMatrix = {
    vector<f32, 3>{ T(1),  T(0),  T(0)},
    vector<f32, 3>{ T(0),  T(1),  T(0)},
    vector<f32, 3>{ T(0),  T(0),  T(1)}
};

inline mat<f32, 3, 3> mat<f32, 3, 3>::zeroMatrix = {
    vector<f32, 3>{ T(0),  T(0),  T(0)},
    vector<f32, 3>{ T(0),  T(0),  T(0)},
    vector<f32, 3>{ T(0),  T(0),  T(0)}
};
*/


