#pragma once

#include "types.h"

/* === Matrix3x3===
* ordem de multiplicação:
* m = t * r * s
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

    Matrix3x3(const Vector3& column0, const Vector3& column1, const Vector3& column2);

    Matrix3x3(const Matrix4x4& rhs);
 
    const Matrix3x3 transpose() const;

    const Vector3 getColumn(int index) const;

    const Vector3 getRow(int index) const;

    static const Matrix3x3 identityMatrix;
    static const Matrix3x3 zeroMatrix;
};

const Matrix3x3 operator*(const Matrix3x3& lhs, const Matrix3x3& rhs) noexcept;

const Vector3 operator*(const Matrix3x3& lhs, const Vector3& rhs) noexcept;

const Vector3 operator*(const Vector3& lhs, const Matrix3x3& rhs) noexcept;

