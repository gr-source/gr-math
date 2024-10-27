#include "matrix4x4.h"
#include "gmath.h"

Matrix4x4::Matrix4x4(const Vector4& row0, const Vector4& row1, const Vector4& row2, const Vector4& row3) {
    data[0] = {row0.x, row1.x, row2.x, row3.x};
    data[1] = {row0.y, row1.y, row2.y, row3.y};
    data[2] = {row0.z, row1.z, row2.z, row3.z};
    data[3] = {row0.w, row1.w, row2.w, row3.w};
}

Matrix4x4::Matrix4x4(const Matrix3x3& rhs) {
    data[0] = {rhs[0][0], rhs[0][1], rhs[0][2], 0.0f};
    data[1] = {rhs[1][0], rhs[1][1], rhs[1][2], 0.0f};
    data[2] = {rhs[2][0], rhs[2][1], rhs[2][2], 0.0f};
    data[3] = {0.0f,      0.0f,      0.0f,      1.0f};
}

/* ========================================= */

void Matrix4x4::decompose(Vector3& scale, Quaternion& rotation, Vector3& position) const {
    position = Vector3(getRow(3));

    scale = {
        Math::magnitude(getRow(0)),
        Math::magnitude(getRow(1)),
        Math::magnitude(getRow(2))
    };

    Matrix3x3 matrix(
        Vector3(getRow(0)) / scale.x,
        Vector3(getRow(1)) / scale.y,
        Vector3(getRow(2)) / scale.z
    );

    rotation = Math::normalize(Math::Mat4ToQuat(matrix));
}

const Matrix4x4 Matrix4x4::transpose() const {
    return Matrix4x4(getColumn(0), getColumn(1), getColumn(2), getColumn(3));
}

const Vector4 Matrix4x4::getColumn(int index) const {
    switch (index) {
        case 0:
            return {data[0][0], data[1][0], data[2][0], data[3][0]};
        case 1:
            return {data[0][1], data[1][1], data[2][1], data[3][1]};
        case 2:
            return {data[0][2], data[1][2], data[2][2], data[3][2]};
        case 3:
            return {data[0][3], data[1][3], data[2][3], data[3][3]};
        default:
            return {0.0f, 0.0f, 0.0f, 0.0f};
    }
}

const Vector4 Matrix4x4::getRow(int index) const {
    return data[index];
    // switch (index) {
    //     case 0:
    //         return {m00, m01, m02, m03};
    //     case 1:
    //         return {m10, m11, m12, m13};
    //     case 2:
    //         return {m20, m21, m22, m23};
    //     case 3:
    //         return {m30, m31, m32, m33};
    //     default:
    //         return {0.0f, 0.0f, 0.0f, 0.0f};
    // }
}

/* ========================================= */

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& other) noexcept {
    if (this != &other) {
        data[0] = other.data[0];
        data[1] = other.data[1];
        data[2] = other.data[2];
        data[3] = other.data[3];
        // m00 = other.m00; m10 = other.m10; m20 = other.m20; m30 = other.m30;
        // m01 = other.m01; m11 = other.m11; m21 = other.m21; m31 = other.m31;
        // m02 = other.m02; m12 = other.m12; m22 = other.m22; m32 = other.m32;
        // m03 = other.m03; m13 = other.m13; m23 = other.m23; m33 = other.m33;
    }
    return *this;
}

Matrix4x4 &Matrix4x4::operator*=(const Matrix4x4 &rhs) noexcept {
    *this = *this * rhs;
    return *this;
}

const Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &rhs) const noexcept {
    return Matrix4x4(
        getColumn(0) - rhs.getColumn(0),
        getColumn(1) - rhs.getColumn(1),
        getColumn(2) - rhs.getColumn(2),
        getColumn(3) - rhs.getColumn(3)
    );
}

const Matrix4x4 Matrix4x4::operator/(const Matrix4x4 &rhs) const noexcept {
    return Matrix4x4(
        getColumn(0) / rhs.getColumn(0),
        getColumn(1) / rhs.getColumn(1),
        getColumn(2) / rhs.getColumn(2),
        getColumn(3) / rhs.getColumn(3)
    );
}

const bool Matrix4x4::operator>(const Matrix4x4 &rhs) const noexcept {
    return getColumn(0) > rhs.getColumn(0) && getColumn(1) > rhs.getColumn(1) && getColumn(2) > rhs.getColumn(2) && getColumn(3) > rhs.getColumn(3);
}

const bool Matrix4x4::operator!=(const Matrix4x4 &lhs) const noexcept {
    return (getColumn(0) != lhs.getColumn(0)) && (getColumn(1) != lhs.getColumn(1)) && (getColumn(1) != lhs.getColumn(1)) && (getColumn(2) != lhs.getColumn(2));
}

const Vector4& Matrix4x4::operator[](int index) const {
    return data[index];
}

Vector4& Matrix4x4::operator[](int index) {
    return data[index];
}

const float *Matrix4x4::getData() const {
    return reinterpret_cast<const float *>(data);
}

float *Matrix4x4::getData() {
    return reinterpret_cast<float *>(data);
}

const bool Matrix4x4::operator==(const Matrix4x4& other) const noexcept {
    return (
        data[0] == other.data[0] &&
        data[1] == other.data[1] &&
        data[2] == other.data[2] &&
        data[3] == other.data[3]
        // (m00 == other.m00 && m10 == other.m10 && m20 == other.m20 && m30 == other.m30) &&
        // (m01 == other.m01 && m11 == other.m11 && m21 == other.m21 && m31 == other.m31) &&
        // (m02 == other.m02 && m12 == other.m12 && m22 == other.m22 && m32 == other.m32) &&
        // (m03 == other.m03 && m13 == other.m13 && m23 == other.m23 && m33 == other.m33)
    );
}

const Matrix4x4 Matrix4x4::zeroMatrix = Matrix4x4{
    {0.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 0.0f}
};

const Matrix4x4 Matrix4x4::identityMatrix = Matrix4x4{
    {1.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 0.0f, 1.0f}
};

Matrix4x4 operator+(const Matrix4x4 &lhs, const Matrix4x4 &rhs) noexcept {
    return Matrix4x4(
        lhs.getColumn(0) + rhs.getColumn(0),
        lhs.getColumn(1) + rhs.getColumn(1),
        lhs.getColumn(2) + rhs.getColumn(2),
        lhs.getColumn(3) + rhs.getColumn(3)
    );
}

Matrix4x4 operator *(const Matrix4x4 &lhs, const Matrix4x4 &rhs) noexcept {
    return Matrix4x4( // t * r * s  -  v * p
        lhs.getColumn(0) * rhs, // (lhs.m00 * rhs.m00) + (lhs.m10 * rhs.m01) + (lhs.m20 * rhs.m02) + (lhs.m30 * rhs.m03)
        lhs.getColumn(1) * rhs,
        lhs.getColumn(2) * rhs,
        lhs.getColumn(3) * rhs
    );
}

Vector4 operator *(const Matrix4x4 &lhs, const Vector4 &rhs) noexcept {
    return {
        Math::dot(lhs.getColumn(0), rhs), // (lhs.m00 * rhs.x) + (lhs.m10 * rhs.y) + (lhs.m20 * rhs.z) + (lhs.m30 * rhs.w)
        Math::dot(lhs.getColumn(1), rhs),
        Math::dot(lhs.getColumn(2), rhs),
        Math::dot(lhs.getColumn(3), rhs)
    };
}

Vector4 operator *(const Vector4 &lhs, const Matrix4x4 &rhs) noexcept {
    return {
        Math::dot(lhs, rhs.getRow(0)), // (lhs.x * rhs.m00) + (lhs.y * rhs.m01) + (lhs.z * rhs.m02) + (lhs.w * rhs.m03)
        Math::dot(lhs, rhs.getRow(1)),
        Math::dot(lhs, rhs.getRow(2)),
        Math::dot(lhs, rhs.getRow(3))
    };
}

Matrix4x4 operator *(const Matrix4x4 &lhs, vvalue rhs) noexcept {
    return Matrix4x4::identityMatrix;
    // (
    //     lhs.getColumn(0) * rhs,
    //     lhs.getColumn(1) * rhs,
    //     lhs.getColumn(2) * rhs,
    //     lhs.getColumn(3) * rhs
    // );
}





