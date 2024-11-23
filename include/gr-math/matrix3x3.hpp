#pragma once

#include "vector3.hpp"

/* === Matrix3x3===
* ordem de multiplicação:
* m = t * r * s
*/
struct Matrix3x3 {
    union {
        struct {
            Vector3 row0;
            Vector3 row1;
            Vector3 row2;
        };
        Vector3 data[3];
    };

    Matrix3x3(const Vector3& row0, const Vector3& row1, const Vector3& row2);

    Matrix3x3(const Matrix4x4& rhs);
 
    const Matrix3x3 transpose() const;

    const Vector3 getColumn(int index) const;

    const Vector3 getRow(int index) const;

    const Vector3 &operator [](int index) const;

    Vector3 &operator [](int index);

    static const Matrix3x3 identityMatrix;
    static const Matrix3x3 zeroMatrix;
};

const Matrix3x3 operator*(const Matrix3x3& lhs, const Matrix3x3& rhs) noexcept;

const Vector3 operator*(const Matrix3x3& lhs, const Vector3& rhs) noexcept;

const Vector3 operator*(const Vector3& lhs, const Matrix3x3& rhs) noexcept;

