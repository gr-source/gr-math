#pragma once

#include "vector4.hpp"

/*
 s.x        t.x
    s.y     t.y
        s.z t.z
*/
struct Matrix4x4
{
    union
    {
        struct
        {
            Vector4 row0;
            Vector4 row1;
            Vector4 row2;
            Vector4 row3;
        };
        Vector4 data[4];
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

    const float *getData() const;
    
    float *getData();

    static Matrix4x4 zeroMatrix;
    
    static Matrix4x4 identityMatrix;
};

// operator *
Matrix4x4 operator *(const Matrix4x4& lhs, const Matrix4x4& rhs) noexcept;

Vector4 operator *(const Matrix4x4& lhs, const Vector4& rhs) noexcept;

Vector4 operator *(const Vector4& lhs, const Matrix4x4& rhs) noexcept;

