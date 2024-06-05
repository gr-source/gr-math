#include "matrix4x4.h"
#include "gmath.h"

#define CHECK_SCALE(value) (value > 0.001f ? value : 1.0f)

Matrix4x4::Matrix4x4(vvalue m00, vvalue m01, vvalue m02, vvalue m03, vvalue m10, vvalue m11, vvalue m12, vvalue m13, vvalue m20, vvalue m21, vvalue m22, vvalue m23, vvalue m30, vvalue m31, vvalue m32, vvalue m33) :
        m00(m00), m01(m01), m02(m02), m03(m03),
        m10(m10), m11(m11), m12(m12), m13(m13),
        m20(m20), m21(m21), m22(m22), m23(m23),
        m30(m30), m31(m31), m32(m32), m33(m33) {}

Matrix4x4::Matrix4x4(const Vector4& row0, const Vector4& row1, const Vector4& row2, const Vector4& row3) : 
    m00(row0.x), m01(row0.y), m02(row0.z), m03(row0.w),
    m10(row1.x), m11(row1.y), m12(row1.z), m13(row1.w),
    m20(row2.x), m21(row2.y), m22(row2.z), m23(row2.w),
    m30(row3.x), m31(row3.y), m32(row3.z), m33(row3.w) {}

Matrix4x4::Matrix4x4(const Matrix3x3& rhs) :
    m00(rhs.m00), m01(rhs.m01), m02(rhs.m02), m03(0.0f),
    m10(rhs.m10), m11(rhs.m11), m12(rhs.m12), m13(0.0f),
    m20(rhs.m20), m21(rhs.m21), m22(rhs.m22), m23(0.0f),
    m30(0.0f),    m31(0.0f),    m32(0.0f),    m33(1.0f) {}

/* ========================================= */

void Matrix4x4::decompose(Vector3& scale, Quaternion& rotation, Vector3& position) const {
    position = Vector3(getRow(3));

    scale = Vector3(
        CHECK_SCALE(Math::magnitude(getRow(0))),
        CHECK_SCALE(Math::magnitude(getRow(1))),
        CHECK_SCALE(Math::magnitude(getRow(2)))
    );

    Matrix3x3 matrix(
        Vector3(getRow(0)) / scale.x,
        Vector3(getRow(1)) / scale.y,
        Vector3(getRow(2)) / scale.z
    );

    rotation = Math::normalize(Math::Mat4ToQuat(matrix));
}

Matrix4x4 Matrix4x4::transpose() const {
    return Matrix4x4(
        getRow(0),
        getRow(1),
        getRow(2),
        getRow(3)
    );
}

Vector4 Matrix4x4::getColumn(int index) const {
    switch (index) {
        case 0:
            return {m00, m10, m20, m30};
        case 1:
            return {m01, m11, m21, m31};
        case 2:
            return {m02, m12, m22, m32};
        case 3:
            return {m03, m13, m23, m33};
        default:
            return {0.0f, 0.0f, 0.0f, 0.0f};
    }
}

Vector4 Matrix4x4::getRow(int index) const {
    switch (index) {
        case 0:
            return {m00, m01, m02, m03};
        case 1:
            return {m10, m11, m12, m13};
        case 2:
            return {m20, m21, m22, m23};
        case 3:
            return {m30, m31, m32, m33};
        default:
            return {0.0f, 0.0f, 0.0f, 0.0f};
    }
}

/* ========================================= */

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& other) noexcept {
    if (this != &other) {
        m00 = other.m00; m10 = other.m10; m20 = other.m20; m30 = other.m30;
        m01 = other.m01; m11 = other.m11; m21 = other.m21; m31 = other.m31;
        m02 = other.m02; m12 = other.m12; m22 = other.m22; m32 = other.m32;
        m03 = other.m03; m13 = other.m13; m23 = other.m23; m33 = other.m33;
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

const vvalue& Matrix4x4::operator[](int index) const {
    return data[index];
}

vvalue& Matrix4x4::operator[](int index) {
    return data[index];
}

bool Matrix4x4::operator==(const Matrix4x4& other) const noexcept {
    return (
        (m00 == other.m00 && m10 == other.m10 && m20 == other.m20 && m30 == other.m30) &&
        (m01 == other.m01 && m11 == other.m11 && m21 == other.m21 && m31 == other.m31) &&
        (m02 == other.m02 && m12 == other.m12 && m22 == other.m22 && m32 == other.m32) &&
        (m03 == other.m03 && m13 == other.m13 && m23 == other.m23 && m33 == other.m33)
    );
}

const Matrix4x4 Matrix4x4::zeroMatrix = Matrix4x4{
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f
};

const Matrix4x4 Matrix4x4::identityMatrix = Matrix4x4{
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

const Matrix4x4 operator*(const Matrix4x4 &lhs, const Matrix4x4 &rhs) noexcept {
    return Matrix4x4( // s * r * t  -  v * p
        lhs.getRow(0) * rhs, // (lhs.m00 * rhs.m00) + (lhs.m01 * rhs.m10) + (lhs.m02 * rhs.m20) + (lhs.m03 * rhs.m30)
        lhs.getRow(1) * rhs,
        lhs.getRow(2) * rhs,
        lhs.getRow(3) * rhs
    );
}

const Vector4 operator*(const Matrix4x4 &lhs, const Vector4 &rhs) noexcept {
    return {
        Math::dot(lhs.getColumn(0), rhs), // (lhs.m00 * rhs.x) + (lhs.m10 * rhs.y) + (lhs.m20 * rhs.z) + (lhs.m30 * rhs.w)
        Math::dot(lhs.getColumn(1), rhs),
        Math::dot(lhs.getColumn(2), rhs),
        Math::dot(lhs.getColumn(3), rhs)
    };
}

const Vector4 operator*(const Vector4 &lhs, const Matrix4x4 &rhs) noexcept {
    return {
        Math::dot(lhs, rhs.getColumn(0)), // (lhs.x * rhs.m00) + (lhs.y * rhs.m10) + (lhs.z * rhs.m20) + (lhs.w * rhs.m30)
        Math::dot(lhs, rhs.getColumn(1)),
        Math::dot(lhs, rhs.getColumn(2)),
        Math::dot(lhs, rhs.getColumn(3))
    };
}
