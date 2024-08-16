#pragma once

#include "types.h"

/*
 s.x        t.x
    s.y     t.y
        s.z t.z
*/
struct Matrix4x4 {
    union {
        struct {
            vvalue m00, m01, m02, m03;
            vvalue m10, m11, m12, m13;
            vvalue m20, m21, m22, m23;
            vvalue m30, m31, m32, m33;
        };
        vvalue data[16];
    };

    Matrix4x4(
        vvalue m00 = 1.0f, vvalue m01 = 0.0f, vvalue m02 = 0.0f, vvalue m03 = 0.0f,
        vvalue m10 = 0.0f, vvalue m11 = 1.0f, vvalue m12 = 0.0f, vvalue m13 = 0.0f,
        vvalue m20 = 0.0f, vvalue m21 = 0.0f, vvalue m22 = 1.0f, vvalue m23 = 0.0f,
        vvalue m30 = 0.0f, vvalue m31 = 0.0f, vvalue m32 = 0.0f, vvalue m33 = 1.0f
    );

    Matrix4x4(const Vector4& column0, const Vector4& column1, const Vector4& column2, const Vector4& column3);

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

    const vvalue& operator[](int index) const;
    vvalue& operator[](int index);

    static const Matrix4x4 zeroMatrix;
    static const Matrix4x4 identityMatrix;
};

// operator +
Matrix4x4 operator +(const Matrix4x4& lhs, const Matrix4x4& rhs) noexcept;

// operator *
const Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs) noexcept;

const Matrix4x4 operator*(const Matrix4x4& lhs, vvalue rhs) noexcept;

const Vector4 operator*(const Matrix4x4& lhs, const Vector4& rhs) noexcept;

const Vector4 operator*(const Vector4& lhs, const Matrix4x4& rhs) noexcept;
