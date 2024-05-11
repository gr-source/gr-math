#pragma once

#include "types.h"

/* === Matrix3x3===
* ordem de multiplicação:
* m = s * r * t
*/
struct Matrix3x3 {
    union {
        struct {
            vvalue m00, m01, m02;
            vvalue m10, m11, m12;
            vvalue m20, m21, m22;
        };
        vvalue data[9];
    };

    Matrix3x3(
        vvalue m00 = 1.0f, vvalue m01 = 0.0f, vvalue m02 = 0.0f,
        vvalue m10 = 0.0f, vvalue m11 = 1.0f, vvalue m12 = 0.0f,
        vvalue m20 = 0.0f, vvalue m21 = 0.0f, vvalue m22 = 1.0f);

    Matrix3x3(const Vector3& col0, const Vector3& col1, const Vector3& col2);

    Matrix3x3(const Matrix4x4& rhs);
    
    Matrix3x3(const Quaternion& q);

    static const Matrix3x3 translate(const Matrix3x3& m, const Vector2& v);

    static const Matrix3x3 scale(const Matrix3x3& m, const Vector2& v);

    static const Matrix3x3 rotate(const Matrix3x3& m, const Quaternion& q);

    Matrix3x3 inverse() const;
    Matrix3x3 transpose() const;

    void print() const;

    vvalue get(int row, int col) const;

    Vector3 getColumn(int index) const;
    void setColumn(const Vector3& col0, const Vector3& col1, const Vector3& col2);

    Vector3 getRow(int index) const;
    void setRow(const Vector3& row0, const Vector3& row1, const Vector3& row2);

    Matrix3x3 operator *(const Matrix3x3& rhs) const;
    Vector3 operator *(const Vector3& rhs) const;
    Matrix3x3 operator*(vvalue lhs) const;
    Matrix3x3& operator*=(vvalue lhs);

    Matrix3x3& operator -=(const Matrix3x3& rhs);
    Matrix3x3 operator -(const Matrix3x3& rhs) const;

    Matrix3x3& operator +=(const Matrix3x3& rhs);

    vvalue& operator()(int row, int col);
    const vvalue& operator()(int row, int col) const;

    static const Matrix3x3 identityMatrix;
    static const Matrix3x3 zeroMatrix;
};

