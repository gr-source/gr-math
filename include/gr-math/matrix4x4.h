#pragma once

#include "types.h"

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

    Matrix4x4(
        const Vector4& col0,
        const Vector4& col1,
        const Vector4& col2,
        const Vector4& col3
    );

    Matrix4x4(const Matrix3x3& rhs);
    
    /* ========================================= */

    void decompose(Vector3& scale, Quaternion& rotation, Vector3& position) const;

    Matrix4x4 transpose() const;

    Matrix4x4 inverse() const;

    vvalue get(int row, int col) const;

    Vector4 getColumn(int index) const;

    Vector4 getRow(int index) const;

    void print() const;

    /* ========================================= */
    
    Matrix4x4& operator=(const Matrix4x4& other) noexcept;

    Matrix4x4 operator*(const Matrix4x4& rhs) const noexcept;
    Matrix4x4& operator*=(const Matrix4x4& rhs) noexcept;

    Vector4 operator *(const Vector4& rhs) const noexcept;

    bool operator==(const Matrix4x4& other) const noexcept;

    const vvalue& operator[](int index) const;
    vvalue& operator[](int index);

    vvalue& operator()(int row, int col);
    const vvalue& operator()(int row, int col) const;

    static const Matrix4x4 zeroMatrix;
    static const Matrix4x4 identityMatrix;
};
