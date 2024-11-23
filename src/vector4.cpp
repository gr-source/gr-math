#include "vector4.hpp"
#include "vector3.hpp"

#include "gmath.hpp"

Vector4& Vector4::operator /=(vvalue rhs) {
    x /= rhs;
    y /= rhs;
    z /= rhs;
    w /= rhs;
    return  *this;
}

bool Vector4::operator >(const Vector4 &rhs) const {
    return (x > rhs.x) && (y > rhs.y) && (z > rhs.z) && (w > rhs.w);
}

bool Vector4::operator !=(const Vector4 &lhs) const {
    return (x != lhs.x) && (y != lhs.y) && (z != lhs.z) && (w != lhs.w);
}

Vector4::operator Vector3() const {
    return {x, y, z};
}

bool Vector4::operator==(const Vector4 &rhs) const {
    return Math::magnitude(*this - rhs) > 0.0f;
}

const float &Vector4::operator[](int index) const {
    return data[index];
}

float &Vector4::operator[](int index) {
    return data[index];
}

const Vector4 Vector4::zero = {0.0f, 0.0f, 0.0f, 0.0f};

// operator -
Vector4 operator -(const Vector4 &lhs, const Vector4 &rhs) noexcept {
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
}

// operator +
Vector4 operator+(const Vector4 &lhs, const Vector4 &rhs) noexcept {
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
}

// operator *
Vector4 operator *(const Vector4 &lhs, const Vector4 &rhs) noexcept {
    return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w};
}

Vector4 operator *(const Vector4 &lhs, vvalue rhs) noexcept {
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs};
}

Vector4 operator *(vvalue lhs, const Vector4 &rhs) noexcept {
    return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w};
}

// operator /
Vector4 operator /(const Vector4 &lhs, const Vector4 &rhs) noexcept {
    return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w};
}

Vector4 operator /(vvalue lhs, const Vector4 &rhs) noexcept {
    return {lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w};
}

Vector4 operator /(const Vector4 &lhs, vvalue rhs) noexcept {
    return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs};
}

// stream
std::istream &operator >>(std::istream &is, Vector4 &rhs) {
    is >> rhs.x >> rhs.y >> rhs.z >> rhs.w;
    return is;
}

std::ostream &operator <<(std::ostream &os, const Vector4 &rhs) {
    os << rhs.x << " " << rhs.y << " " << rhs.z << " " << rhs.w;
    return os;
}





