#pragma once

#include "vector4.hpp"

#include "mat4x4_operator.inl"

// [Column][Row]

template <>
struct mat<f32, 4, 4>
{
    union
    {
        struct
        {
            vector<f32, 4> col0;
            vector<f32, 4> col1;
            vector<f32, 4> col2;
            vector<f32, 4> col3;
        };
        vector<f32, 4> data[4];
    };

    /* ========================================= */

    void decompose(Vector3& scale, Quaternion& rotation, Vector3& position) const;

    Matrix4x4 transpose() const;

    Vector4 getColumn(int index) const;

    Vector4 getRow(int index) const;

    inline constexpr const Vector4& operator[](int index) const
    {
        return data[index];
    }
    
    inline constexpr Vector4& operator[](int index)
    {
        return data[index];
    }

    static Matrix4x4 zeroMatrix;
    
    static Matrix4x4 identityMatrix;
};


