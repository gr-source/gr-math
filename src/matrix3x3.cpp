#include "../include/matrix3x3.h"
#include "../include/gmath.h"

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

Matrix3x3::Matrix3x3(const Quaternion& q) {
    //i = x    j = y   k = z   r = w

    /* linha 0 */
    m00 = 1.0f - 2.0f * ((q.y * q.y) + (q.z * q.z));
    m10 = 2.0f * ((q.x * q.y) - (q.z * q.w));
    m20 = 2.0f * ((q.x * q.z) + (q.y * q.w));

    /* linha 1 */
    m01 = 2.0f * ((q.x * q.y) + (q.z * q.w));
    m11 = 1.0f - 2.0f * ((q.x * q.x) + (q.z * q.z));
    m21 = 2.0f * ((q.y * q.z) - (q.x * q.w));
    
    /* linha 2 */
    m02 = 2.0f * ((q.x * q.z) - (q.y * q.w));
    m12 = 2.0f * ((q.y * q.z) + (q.x * q.w));
    m22 = 1.0f - 2.0f * ((q.x * q.x) + (q.y * q.y));
}

const Matrix3x3 Matrix3x3::translate(const Matrix3x3& m, const Vector2& v) {
    Matrix3x3 result = m;
    result.m20 += v.x;
    result.m21 += v.y;
    return result;
}

const Matrix3x3 Matrix3x3::scale(const Matrix3x3& m, const Vector2& v) {
    Matrix3x3 result = m;
    result.m00 *= Math::dot(m.getRow(0), Vector3(v, 1.0f));
    result.m11 *= Math::dot(m.getRow(1), Vector3(v, 1.0f));
    return result;
}

const Matrix3x3 Matrix3x3::rotate(const Matrix3x3& m, const Quaternion& q) {
    Matrix3x3 result = Matrix3x3::identityMatrix;
    result.m00 = 1.0f - (2.0f * ((q.y * q.y) + (q.z * q.z)));
    result.m10 = 2.0f * ((q.x * q.y) + (q.w * q.z));

    result.m01 = 2.0f * ((q.x * q.y) - (q.w * q.z));
    result.m11 = 1.0f - (2.0f * ((q.x * q.x) + (q.z * q.z)));

    return m * result;
}

Matrix3x3 Matrix3x3::inverse() const {
    Vector3 row0 = getColumn(0);
    Vector3 row1 = getColumn(1);
    Vector3 row2 = getColumn(2);

    Vector3 tmp0 = Math::cross(row1, row2);
    Vector3 tmp1 = Math::cross(row2, row0);
    Vector3 tmp2 = Math::cross(row0, row1);

    vvalue detinv = 1.0f / Math::dot(row2, tmp2);

    return Matrix3x3(
        tmp0.x * detinv, tmp1.x * detinv, tmp2.x * detinv,
        tmp0.y * detinv, tmp1.y * detinv, tmp2.y * detinv,
        tmp0.z * detinv, tmp1.z * detinv, tmp2.z * detinv
    );
}

Matrix3x3 Matrix3x3::transpose() const {
    return Matrix3x3(getRow(0), getRow(1), getRow(2));
}

void Matrix3x3::print() const {
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            std::cout << get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

vvalue Matrix3x3::get(int row, int col) const {
    return data[row * 3 + col];
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

void Matrix3x3::setColumn(const Vector3& col0, const Vector3& col1, const Vector3& col2) {
    m00 = col0.x;
    m10 = col0.y;
    m20 = col0.z;

    m01 = col1.x;
    m11 = col1.y;
    m21 = col1.z;

    m02 = col2.x;
    m12 = col2.y;
    m22 = col2.z;
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

void Matrix3x3::setRow(const Vector3& row0, const Vector3& row1, const Vector3& row2) {
    m00 = row0.x;
    m01 = row0.y;
    m02 = row0.z;

    m10 = row1.x;
    m11 = row1.y;
    m12 = row1.z;

    m20 = row2.x;
    m21 = row2.y;
    m22 = row2.z;
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

Matrix3x3 Matrix3x3::operator*(vvalue lhs) const {
    return Matrix3x3(
        getColumn(0) * lhs,
        getColumn(1) * lhs,
        getColumn(2) * lhs
    );
}

Matrix3x3& Matrix3x3::operator*=(vvalue lhs) {
    m00 *= lhs;
    m01 *= lhs;
    m02 *= lhs;

    m10 *= lhs;
    m11 *= lhs;
    m12 *= lhs;

    m20 *= lhs;
    m21 *= lhs;
    m22 *= lhs;

    return *this;
}

Matrix3x3& Matrix3x3::operator -=(const Matrix3x3& rhs) {
    m00 -= rhs.m00;
    m01 -= rhs.m01;
    m02 -= rhs.m02;

    m10 -= rhs.m10;
    m11 -= rhs.m11;
    m12 -= rhs.m12;

    m20 -= rhs.m20;
    m21 -= rhs.m21;
    m22 -= rhs.m22;
    return *this;
}

Matrix3x3 Matrix3x3::operator -(const Matrix3x3& rhs) const {
    return Matrix3x3(
        getColumn(0) - rhs.getColumn(0),
        getColumn(1) - rhs.getColumn(1),
        getColumn(2) - rhs.getColumn(2)
    );
}

Matrix3x3& Matrix3x3::operator +=(const Matrix3x3& rhs) {
    m00 += rhs.m00;
    m01 += rhs.m01;
    m02 += rhs.m02;

    m10 += rhs.m10;
    m11 += rhs.m11;
    m12 += rhs.m12;

    m20 += rhs.m20;
    m21 += rhs.m21;
    m22 += rhs.m22;
    return *this;
}

vvalue& Matrix3x3::operator()(int row, int col) {
    return data[row * 3 + col];
}

const vvalue& Matrix3x3::operator()(int row, int col) const {
    return data[row * 3 + col];
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

