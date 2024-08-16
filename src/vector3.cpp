#include "vector3.h"
#include "gmath.h"

Vector3::Vector3(vvalue x, vvalue y, vvalue z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector2& rhs, vvalue z) : x(rhs.x), y(rhs.y), z(z) {}

Vector3::Vector3(const Vector4& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {}

vvalue Vector3::operator[](int index) const {
    return data[index];
}

vvalue& Vector3::operator[](int index) {
    return data[index];
}

Vector3 Vector3::operator -() const {
    return {-x, -y, -z};
}

Vector3& Vector3::operator /=(const Vector3& rhs) {
    if (this == &rhs) {
        return *this;
    }
    *this = *this / rhs;
    return *this;
}

Vector3& Vector3::operator /=(vvalue rhs) {
    x /= rhs;
    y /= rhs;
    z /= rhs;
    return *this;
}

Vector3& Vector3::operator +=(const Vector3& other) {
    if (this == &other) {
        return *this;
    }
    *this = *this + other;
    return *this;
}

Vector3 &Vector3::operator +=(vvalue other) {
    x += other;
    y += other;
    z += other;
    return *this;
}

Vector3& Vector3::operator -=(const Vector3& other) {
    if (this == &other) {
        return *this;
    }
    *this = *this - other;
    return *this;
}

Vector3 &Vector3::operator -=(vvalue other) {
    x -= other;
    y -= other;
    z -= other;
    return *this;
}

Vector3& Vector3::operator *=(const Vector3& other) {
    if (this == &other) {
        return *this;
    }
    *this = *this * other;
    return *this;
}

Vector3& Vector3::operator *=(vvalue other) {
    x *= other;
    y *= other;
    z *= other;
    return *this;
}

Vector3& Vector3::operator =(const Vector3& other) {
    if (this == &other) {
        return *this;
    }
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

const bool Vector3::operator ==(const Vector3& other) const {
    return ((x == other.x) && (y == other.y) && (z == other.z));
}

const bool Vector3::operator !=(const Vector3& other) const {
    return ((x != other.x) || (y != other.y) || (z != other.z));
}

const bool Vector3::operator >(const Vector3& other) const {
    return (x > other.x) && (y > other.y) && (z > other.z);
}

const bool Vector3::operator <(const Vector3& other) const {
    return (x < other.x) && (y < other.y) && (z < other.z);
}

const Vector3 Vector3::zero = {0.0f, 0.0f, 0.0f};

const Vector3 Vector3::one = {1.0f, 1.0f, 1.0f};

const Vector3 Vector3::forward = {0.0f, 0.0f, 1.0f};

const Vector3 Vector3::right = {1.0f, 0.0f, 0.0f};

const Vector3 Vector3::up = {0.0f, 1.0f, 0.0f};

// operator -
Vector3 operator -(vvalue lhs, const Vector3 &rhs) noexcept {
    return {lhs - rhs.x, lhs - rhs.y, lhs - rhs.z};
}

Vector3 operator -(const Vector3 &lhs, vvalue rhs) noexcept {
    return {lhs.x - rhs, lhs.y - rhs, lhs.z - rhs};
}

Vector3 operator -(const Vector3 &lhs, const Vector3 &rhs) noexcept {
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

// operator +
Vector3 operator +(vvalue lhs, const Vector3 &rhs) noexcept {
    return {lhs + rhs.x, lhs + rhs.y, lhs + rhs.z};
}

Vector3 operator +(const Vector3 &lhs, vvalue rhs) noexcept {
    return {lhs.x + rhs, lhs.y + rhs, lhs.z + rhs};
}

Vector3 operator +(const Vector3 &lhs, const Vector3 &rhs) noexcept {
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

// operator *
Vector3 operator *(vvalue lhs, const Vector3 &rhs) noexcept {
    return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z};
}

Vector3 operator *(const Vector3 &lhs, vvalue rhs) noexcept {
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

Vector3 operator*(const Vector3 &lhs, const Vector3 &rhs) noexcept {
    return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
}

// operator /
Vector3 operator /(vvalue lhs, const Vector3 &rhs) noexcept {
    return {lhs / rhs.x, lhs / rhs.y, lhs / rhs.z};
}

Vector3 operator /(const Vector3 &lhs, vvalue rhs) noexcept {
    return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
}

Vector3 operator/(const Vector3 &lhs, const Vector3 &rhs) noexcept {
    return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
}

// stream
std::istream &operator >>(std::istream &is, Vector3 &other) {
    is >> other.x >> other.y >> other.z;
    return is;
}

std::ostream &operator <<(std::ostream &os, const Vector3 &other) {
    os << other.x << " " << other.y << " " << other.z;
    return os;
}
