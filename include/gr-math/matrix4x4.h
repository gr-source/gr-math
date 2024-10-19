#pragma once

#include "vector4.h"

/*
 s.x        t.x
    s.y     t.y
        s.z t.z
*/
struct Matrix4x4 {
    Vector4 data[4];

    Matrix4x4(const Vector4& row0, const Vector4& row1, const Vector4& row2, const Vector4& row3);

    Matrix4x4(const Matrix3x3& rhs);
    
    /* ========================================= */

    void decompose(Vector3& scale, Quaternion& rotation, Vector3& position) const;

    const Matrix4x4 transpose() const;

    const Vector4 getColumn(int index) const;

    const Vector4 getRow(int index) const;

    /* ========================================= */
    
    Matrix4x4& operator=(const Matrix4x4& other) noexcept;

    Matrix4x4& operator*=(const Matrix4x4& rhs) noexcept;

    const Matrix4x4 operator-(const Matrix4x4& rhs) const noexcept;
    const Matrix4x4 operator/(const Matrix4x4& rhs) const noexcept;
    
    const bool operator>(const Matrix4x4& rhs) const noexcept;

    const bool operator!=(const Matrix4x4& lhs) const noexcept;

    const bool operator==(const Matrix4x4& other) const noexcept;

    const Vector4& operator[](int index) const;
    Vector4& operator[](int index);

    const float *getData() const;
    float *getData();

    static const Matrix4x4 zeroMatrix;
    static const Matrix4x4 identityMatrix;
};

// operator +
Matrix4x4 operator +(const Matrix4x4& lhs, const Matrix4x4& rhs) noexcept;

// operator *
Matrix4x4 operator *(const Matrix4x4& lhs, const Matrix4x4& rhs) noexcept;

Vector4 operator *(const Matrix4x4& lhs, const Vector4& rhs) noexcept;

Vector4 operator *(const Vector4& lhs, const Matrix4x4& rhs) noexcept;

Matrix4x4 operator *(const Matrix4x4& lhs, vvalue rhs) noexcept;



