#include "matrix3x3.h"
#include "gmath.h"

Matrix3x3::Matrix3x3(vvalue m00, vvalue m01, vvalue m02, vvalue m10, vvalue m11, vvalue m12, vvalue m20, vvalue m21, vvalue m22) :
    m00(m00), m01(m01), m02(m02),
    m10(m10), m11(m11), m12(m12),
    m20(m20), m21(m21), m22(m22) {}

Matrix3x3::Matrix3x3(const Vector3& row0, const Vector3& row1, const Vector3& row2)  :
    m00(row0.x), m01(row0.y), m02(row0.z),
    m10(row1.x), m11(row1.y), m12(row1.z),
    m20(row2.x), m21(row2.y), m22(row2.z) {}

Matrix3x3::Matrix3x3(const Matrix4x4& rhs) :
    m00(rhs.m00), m01(rhs.m01), m02(rhs.m02),
    m10(rhs.m10), m11(rhs.m11), m12(rhs.m12),
    m20(rhs.m20), m21(rhs.m21), m22(rhs.m22) {}

Matrix3x3 Matrix3x3::transpose() const {
    return Matrix3x3(getRow(0), getRow(1), getRow(2));
}

Vector3 Matrix3x3::getColumn(int index) const {
    switch (index) {
        case 0:
            return Vector3(m00, m10, m20);
        case 1:
            return Vector3(m01, m11, m21);
        case 2:
            return Vector3(m02, m12, m22);
        default:
            return Vector3(0.0f, 0.0f, 0.0f);
    }
}

Vector3 Matrix3x3::getRow(int index) const {
    switch (index) {
        case 0:
            return Vector4(m00, m01, m02);
        case 1:
            return Vector4(m10, m11, m12);
        case 2:
            return Vector4(m20, m21, m22);
        default:
            return Vector4(0.0f, 0.0f, 0.0f, 0.0f);
    }
}

const Matrix3x3 Matrix3x3::identityMatrix = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

const Matrix3x3 Matrix3x3::zeroMatrix = {
    0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f
};

const Matrix3x3 operator*(const Matrix3x3 &lhs, const Matrix3x3 &rhs) noexcept {
    return Matrix3x3( // s * r * t
        lhs.getRow(0) * rhs, // (lhs.m00 * rhs.m00) + (lhs.m01 * rhs.m10) + (lhs.m02 * rhs.m20) + (lhs.m03 * rhs.m30)
        lhs.getRow(1) * rhs,
        lhs.getRow(2) * rhs
    );
}

const Vector3 operator*(const Matrix3x3 &lhs, const Vector3 &rhs) noexcept {
    return {
        Math::dot(lhs.getColumn(0), rhs), // (lhs.m00 * rhs.x) + (lhs.m10 * rhs.y) + (lhs.m20 * rhs.z) + (lhs.m30 * rhs.w)
        Math::dot(lhs.getColumn(1), rhs),
        Math::dot(lhs.getColumn(2), rhs)
    };
}

const Vector3 operator*(const Vector3 &lhs, const Matrix3x3 &rhs) noexcept {
    return {
        Math::dot(lhs, rhs.getColumn(0)), // (lhs.x * rhs.m00) + (lhs.y * rhs.m01) + (lhs.z * rhs.m02) + (lhs.w * rhs.m03)
        Math::dot(lhs, rhs.getColumn(1)),
        Math::dot(lhs, rhs.getColumn(2))
    };
}


