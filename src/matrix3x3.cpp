#include "matrix3x3.h"
#include "gmath.h"

Matrix3x3::Matrix3x3(vvalue m00, vvalue m01, vvalue m02, vvalue m10, vvalue m11, vvalue m12, vvalue m20, vvalue m21, vvalue m22) :
    m00(m00), m01(m01), m02(m02),
    m10(m10), m11(m11), m12(m12),
    m20(m20), m21(m21), m22(m22) {}

Matrix3x3::Matrix3x3(const Vector3& col0, const Vector3& col1, const Vector3& col2)  :
    m00(col0.x), m01(col1.x), m02(col2.x),
    m10(col0.y), m11(col1.y), m12(col2.y),
    m20(col0.z), m21(col1.z), m22(col2.z) {}

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

Matrix3x3 Matrix3x3::operator *(const Matrix3x3& rhs) const {
    Vector3 rhsx = rhs.getColumn(0);
    Vector3 rhsy = rhs.getColumn(1);
    Vector3 rhsz = rhs.getColumn(2);

    return Matrix3x3(
        (*this) * rhsx,
        (*this) * rhsy,
        (*this) * rhsz
    );
}

Vector3 Matrix3x3::operator *(const Vector3& rhs) const {
    return Vector3(
        Math::dot(getColumn(0), rhs),
        Math::dot(getColumn(1), rhs),
        Math::dot(getColumn(2), rhs)
	);
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

