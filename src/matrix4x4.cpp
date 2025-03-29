#include "matrix4x4.hpp"
#include "gmath.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

/* ========================================= */

void Matrix4x4::decompose(Vector3& scale, Quaternion& rotation, Vector3& position) const {
    auto row0 = (*this)[0];
    auto row1 = (*this)[1];
    auto row2 = (*this)[2];
    auto row3 = (*this)[3];

    position = Vector3(getRow(3));

    scale = Vector3{
        Math::magnitude(row0),
        Math::magnitude(row1),
        Math::magnitude(row2)
    };

    row0 /= scale.x;
    row1 /= scale.y;
    row2 /= scale.z;


    Matrix4x4 m = {
        Vector4{row0.x,   row1.x,   row2.x,   0.0f},
        Vector4{row0.y,   row1.y,   row2.y,   0.0f},
        Vector4{row0.z,   row1.z,   row2.z,   0.0f},
        Vector4{0.0f,           0.0f,           0.0f,           0.0f},
    };
    /*m[0] = (*this)[0] / scale.x;*/
    /*m[1] = (*this)[0] / scale.y;*/
    /*m[2] = (*this)[0] / scale.z;*/

    rotation = Math::normalize(Math::Mat4ToQuat(m));
}

Matrix4x4 Matrix4x4::transpose() const {
    return Matrix4x4::identityMatrix;
    /*return Matrix4x4(getColumn(0), getColumn(1), getColumn(2), getColumn(3));*/
}

Vector4 Matrix4x4::getColumn(int index) const {
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

Vector4 Matrix4x4::getRow(int index) const {
    return data[index];
}

/* ========================================= */
/*
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
*/
/*
Matrix4x4 &Matrix4x4::operator*=(const Matrix4x4 &rhs) noexcept {
    *this = *this * rhs;
    return *this;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &rhs) const noexcept {
    return Matrix4x4(
        getColumn(0) - rhs.getColumn(0),
        getColumn(1) - rhs.getColumn(1),
        getColumn(2) - rhs.getColumn(2),
        getColumn(3) - rhs.getColumn(3)
    );
}

Matrix4x4 Matrix4x4::operator/(const Matrix4x4 &rhs) const noexcept {
    return Matrix4x4(
        getColumn(0) / rhs.getColumn(0),
        getColumn(1) / rhs.getColumn(1),
        getColumn(2) / rhs.getColumn(2),
        getColumn(3) / rhs.getColumn(3)
    );
}

bool Matrix4x4::operator>(const Matrix4x4 &rhs) const noexcept {
    return getColumn(0) > rhs.getColumn(0) && getColumn(1) > rhs.getColumn(1) && getColumn(2) > rhs.getColumn(2) && getColumn(3) > rhs.getColumn(3);
}

bool Matrix4x4::operator!=(const Matrix4x4 &lhs) const noexcept {
    return (getColumn(0) != lhs.getColumn(0)) && (getColumn(1) != lhs.getColumn(1)) && (getColumn(1) != lhs.getColumn(1)) && (getColumn(2) != lhs.getColumn(2));
}
*/

/*const Vector4& Matrix4x4::operator[](int index) const {*/
/*    return data[index];*/
/*}*/
/**/
/*Vector4& Matrix4x4::operator[](int index) {*/
/*    return data[index];*/
/*}*/

const float *Matrix4x4::getData() const {
    return reinterpret_cast<const float *>(data);
}

float *Matrix4x4::getData() {
    return reinterpret_cast<float *>(data);
}

/*
bool Matrix4x4::operator==(const Matrix4x4& other) const noexcept {
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
*/
Matrix4x4 Matrix4x4::zeroMatrix = Matrix4x4{
    Vector4{0.0f, 0.0f, 0.0f, 0.0f},
    Vector4{0.0f, 0.0f, 0.0f, 0.0f},
    Vector4{0.0f, 0.0f, 0.0f, 0.0f},
    Vector4{0.0f, 0.0f, 0.0f, 0.0f}
};

Matrix4x4 Matrix4x4::identityMatrix = Matrix4x4{
    Vector4{1.0f, 0.0f, 0.0f, 0.0f},
    Vector4{0.0f, 1.0f, 0.0f, 0.0f},
    Vector4{0.0f, 0.0f, 1.0f, 0.0f},
    Vector4{0.0f, 0.0f, 0.0f, 1.0f}
};

/*
Matrix4x4 operator+(const Matrix4x4 &lhs, const Matrix4x4 &rhs) noexcept {
    return Matrix4x4(
        lhs.getColumn(0) + rhs.getColumn(0),
        lhs.getColumn(1) + rhs.getColumn(1),
        lhs.getColumn(2) + rhs.getColumn(2),
        lhs.getColumn(3) + rhs.getColumn(3)
    );
}
*/

Matrix4x4 operator *(const Matrix4x4 &lhs, const Matrix4x4 &rhs) noexcept {
    // Teste de otimização, descobrir que armazenando algumas variaveis o calculo da multiplicação de matrizes diminui.
    Matrix4x4 result = Matrix4x4::zeroMatrix;

	Vector4 rowA0 = lhs[0];
    Vector4 rowA1 = lhs[1];
	Vector4 rowA2 = lhs[2];
    Vector4 rowA3 = lhs[3];

	Vector4 rowB0 = rhs[0];
	Vector4 rowB1 = rhs[1];
	Vector4 rowB2 = rhs[2];
	Vector4 rowB3 = rhs[3];

	result[0] = rowA0 * rowB0[0] + rowA1 * rowB0[1] + rowA2 * rowB0[2] + rowA3 * rowB0[3];
	result[1] = rowA0 * rowB1[0] + rowA1 * rowB1[1] + rowA2 * rowB1[2] + rowA3 * rowB1[3];
	result[2] = rowA0 * rowB2[0] + rowA1 * rowB2[1] + rowA2 * rowB2[2] + rowA3 * rowB2[3];
	result[3] = rowA0 * rowB3[0] + rowA1 * rowB3[1] + rowA2 * rowB3[2] + rowA3 * rowB3[3];

    return result;
}

Vector4 operator *(const Matrix4x4 &lhs, const Vector4 &rhs) noexcept {
    Vector4 result = Vector4::zero;

	Vector4 rowA0 = lhs[0];
    Vector4 rowA1 = lhs[1];
	Vector4 rowA2 = lhs[2];
    Vector4 rowA3 = lhs[3];

	result[0] = rowA0[0] * rhs.x + rowA1[0] * rhs.y + rowA2[0] * rhs.z + rowA3[0] * rhs.w;
	result[1] = rowA0[1] * rhs.x + rowA1[1] * rhs.y + rowA2[1] * rhs.z + rowA3[1] * rhs.w;
	result[2] = rowA0[2] * rhs.x + rowA1[2] * rhs.y + rowA2[2] * rhs.z + rowA3[2] * rhs.w;
	result[3] = rowA0[3] * rhs.x + rowA1[3] * rhs.y + rowA2[3] * rhs.z + rowA3[3] * rhs.w;

    return result;
}

Vector4 operator *(const Vector4 &lhs, const Matrix4x4 &rhs) noexcept {
    Vector4 result = Vector4::zero;

	Vector4 rowB0 = rhs[0];
	Vector4 rowB1 = rhs[1];
	Vector4 rowB2 = rhs[2];
	Vector4 rowB3 = rhs[3];

	result[0] = lhs.x * rowB0[0] + lhs.y * rowB0[1] + lhs.z * rowB0[2] + lhs.w * rowB0[3];
	result[1] = lhs.x * rowB1[0] + lhs.y * rowB1[1] + lhs.z * rowB1[2] + lhs.w * rowB1[3];
	result[2] = lhs.x * rowB2[0] + lhs.y * rowB2[1] + lhs.z * rowB2[2] + lhs.w * rowB2[3];
	result[3] = lhs.x * rowB3[0] + lhs.y * rowB3[1] + lhs.z * rowB3[2] + lhs.w * rowB3[3];

    return result;
}

/*
Matrix4x4 operator *(const Matrix4x4 &lhs, vvalue rhs) noexcept {
    return Matrix4x4::identityMatrix;
}
*/





