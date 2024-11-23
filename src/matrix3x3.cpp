#include "matrix3x3.hpp"
#include "gmath.hpp"

Matrix3x3::Matrix3x3(const Vector3& row0, const Vector3& row1, const Vector3& row2) {
    data[0] = {row0.x, row1.x, row2.x};
    data[1] = {row0.y, row1.y, row2.y};
    data[2] = {row0.z, row1.z, row2.z};
}

Matrix3x3::Matrix3x3(const Matrix4x4& rhs) {
    data[0] = {rhs[0][0], rhs[0][1], rhs[0][2]};
    data[1] = {rhs[1][0], rhs[1][1], rhs[1][2]};
    data[2] = {rhs[2][0], rhs[2][1], rhs[2][2]};
}

// Matrix3x3::Matrix3x3(const Matrix4x4& rhs) :
//     m00(rhs[0][0]), m01(rhs[0][1]), m02(rhs[0][2]),
//     m10(rhs[1][0]), m11(rhs[1][1]), m12(rhs[1][2]),
//     m20(rhs[2][0]), m21(rhs[2][1]), m22(rhs[2][2]) {}

const Matrix3x3 Matrix3x3::transpose() const {
    return Matrix3x3(getRow(0), getRow(1), getRow(2));
}

const Vector3 Matrix3x3::getColumn(int index) const {
    switch (index) {
        case 0:
            return {data[0][0], data[1][0], data[2][0]};
        case 1:
            return {data[0][1], data[1][1], data[2][1]};
        case 2:
            return {data[0][2], data[1][2], data[2][2]};
        default:
            return {0.0f, 0.0f, 0.0f};
    }
}

const Vector3 Matrix3x3::getRow(int index) const {
    switch (index) {
        case 0:
            return {data[0][0], data[0][1], data[0][2]};
        case 1:
            return {data[1][0], data[1][1], data[1][2]};
        case 2:
            return {data[2][0], data[2][1], data[2][2]};
        default:
            return {0.0f, 0.0f, 0.0f};
    }
}

const Vector3 &Matrix3x3::operator[](int index) const {
    return data[index];
}

Vector3 &Matrix3x3::operator[](int index) {
    return data[index];
}

const Matrix3x3 Matrix3x3::identityMatrix = {
    {1.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 1.0f}
};

const Matrix3x3 Matrix3x3::zeroMatrix = {
    {0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f}
};

const Matrix3x3 operator*(const Matrix3x3 &lhs, const Matrix3x3 &rhs) noexcept {
    return Matrix3x3( // t * r * s
        lhs.getColumn(0) * rhs, // (lhs.m00 * rhs.m00) + (lhs.m01 * rhs.m10) + (lhs.m02 * rhs.m20) + (lhs.m03 * rhs.m30)
        lhs.getColumn(1) * rhs,
        lhs.getColumn(2) * rhs
    );
}

const Vector3 operator*(const Matrix3x3 &lhs, const Vector3 &rhs) noexcept {
    return {
        Math::dot(lhs.getColumn(0), rhs), // (lhs.m00 * rhs.x) + (lhs.m01 * rhs.y) + (lhs.m02 * rhs.z)
        Math::dot(lhs.getColumn(1), rhs),
        Math::dot(lhs.getColumn(2), rhs)
    };
}

const Vector3 operator*(const Vector3 &lhs, const Matrix3x3 &rhs) noexcept {
    return {
        Math::dot(lhs, rhs.getRow(0)), // (lhs.x * rhs.m00) + (lhs.y * rhs.m10) + (lhs.z * rhs.m20) + (lhs.w * rhs.m30)
        Math::dot(lhs, rhs.getRow(1)),
        Math::dot(lhs, rhs.getRow(2))
    };
}


