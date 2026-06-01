#pragma once

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
    vector<f32, 3>{1.0f, 0.0f, 0.0f},
    vector<f32, 3>{0.0f, 1.0f, 0.0f},
    vector<f32, 3>{0.0f, 0.0f, 1.0f}
};

inline mat<f32, 3, 3> mat<f32, 3, 3>::zeroMatrix = {
    vector<f32, 3>{0.0f, 0.0f, 0.0f},
    vector<f32, 3>{0.0f, 0.0f, 0.0f},
    vector<f32, 3>{0.0f, 0.0f, 0.0f}
};



