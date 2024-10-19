#include "matrix3x3.h"
#include "gmath.h"

Matrix3x3::Matrix3x3(vvalue m00, vvalue m01, vvalue m02, vvalue m10, vvalue m11, vvalue m12, vvalue m20, vvalue m21, vvalue m22) :
    m00(m00), m01(m01), m02(m02),
    m10(m10), m11(m11), m12(m12),
    m20(m20), m21(m21), m22(m22) {}

Matrix3x3::Matrix3x3(const Vector3& column0, const Vector3& column1, const Vector3& column2)  :
    m00(column0.x), m01(column1.x), m02(column2.x),
    m10(column0.y), m11(column1.y), m12(column2.y),
    m20(column0.z), m21(column1.z), m22(column2.z) {}

Matrix3x3::Matrix3x3(const Matrix4x4& rhs) :
    m00(rhs[0][0]), m01(rhs[0][1]), m02(rhs[0][2]),
    m10(rhs[1][0]), m11(rhs[1][1]), m12(rhs[1][2]),
    m20(rhs[2][0]), m21(rhs[2][1]), m22(rhs[2][2]) {}

const Matrix3x3 Matrix3x3::transpose() const {
    return Matrix3x3(getRow(0), getRow(1), getRow(2));
}

const Vector3 Matrix3x3::getColumn(int index) const {
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

const Vector3 Matrix3x3::getRow(int index) const {
    switch (index) {
        case 0:
            return {m00, m01, m02};
        case 1:
            return {m10, m11, m12};
        case 2:
            return {m20, m21, m22};
        default:
            return {0.0f, 0.0f, 0.0f};
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


