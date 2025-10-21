#pragma once

#include "mat3x3_operator.inl"

template <>
struct mat<float, 3, 3>
{
    union
    {
        struct
        {
            vector<float, 3> row0;
            vector<float, 3> row1;
            vector<float, 3> row2;
        };
        vector<float, 3> data[3];
    };

    static mat<float, 3, 3> identityMatrix;

    static mat<float, 3, 3> zeroMatrix;

    constexpr const vector<float, 3> &operator[](int i) const noexcept
    {
        return data[i];
    }

    constexpr vector<float, 3> &operator[](int i) noexcept
    {
        return data[i];
    }
};

inline mat<float, 3, 3> mat<float, 3, 3>::identityMatrix = {
    vector<float, 3>{1.0f, 0.0f, 0.0f},
    vector<float, 3>{0.0f, 1.0f, 0.0f},
    vector<float, 3>{0.0f, 0.0f, 1.0f}
};

inline mat<float, 3, 3> mat<float, 3, 3>::zeroMatrix = {
    vector<float, 3>{0.0f, 0.0f, 0.0f},
    vector<float, 3>{0.0f, 0.0f, 0.0f},
    vector<float, 3>{0.0f, 0.0f, 0.0f}
};

/*
#include "vector3.hpp"
#include "types.hpp"

/* === Matrix3x3===
* ordem de multiplicação:
* m = t * r * s

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
*/


