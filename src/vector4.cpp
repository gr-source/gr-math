#include "vector4.h"
#include "vector3.h"

Vector4::Vector4(const Vector3& rhs, vvalue w) : x(rhs.x), y(rhs.y), z(rhs.z), w(w) {}

Vector4::Vector4(vvalue x, vvalue y, vvalue z, vvalue w) : x(x), y(y), z(z), w(w) {}

Vector4& Vector4::operator /=(vvalue rhs) {
    x /= rhs;
    y /= rhs;
    z /= rhs;
    w /= rhs;
    return  *this;
}

Vector4& Vector4::operator =(const Vector4& rhs) {
    if (this == &rhs) {
        return *this;
    }
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = rhs.w;
    return *this;
}

const bool Vector4::operator >(const Vector4 &rhs) const {
    return (x > rhs.x) && (y > rhs.y) && (z > rhs.z) && (w > rhs.w);
}

const bool Vector4::operator !=(const Vector4 &lhs) const {
    return (x != lhs.x) && (y != lhs.y) && (z != lhs.z) && (w != lhs.w);
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

// stream
std::istream &operator >>(std::istream &is, Vector4 &rhs) {
    is >> rhs.x >> rhs.y >> rhs.z >> rhs.w;
    return is;
}

std::ostream &operator <<(std::ostream &os, const Vector4 &rhs) {
    os << rhs.x << " " << rhs.y << " " << rhs.z << " " << rhs.w;
    return os;
}



