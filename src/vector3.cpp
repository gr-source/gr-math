#include "vector3.hpp"
#include "gmath.hpp"

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

bool Vector3::operator ==(const Vector3& rhs) const {
    return Math::magnitude(*this - rhs) < 1.0e-6;
}

bool Vector3::operator !=(const Vector3& rhs) const {
    return Math::magnitude(*this - rhs) >= 1.0e-6;
}

bool Vector3::operator >(const Vector3 &rhs) const {
    return Math::magnitude(*this) > Math::magnitude(rhs);
}

bool Vector3::operator >=(const Vector3 &rhs) const {
    return Math::magnitude(*this) >= Math::magnitude(rhs);
}


bool Vector3::operator <(const Vector3 &rhs) const {
    return Math::magnitude(*this) < Math::magnitude(rhs);
}

bool Vector3::operator <=(const Vector3 &rhs) const {
    return Math::magnitude(*this) <= Math::magnitude(rhs);
}

Vector3::operator Vector4() const {
    return {x, y, z, 1.0f};
}

Vector3 Vector3::zero = {0.0f, 0.0f, 0.0f};

Vector3 Vector3::one = {1.0f, 1.0f, 1.0f};

Vector3 Vector3::right = {1.0f, 0.0f, 0.0f};

Vector3 Vector3::left = {-1.0f, 0.0f, 0.0f};

Vector3 Vector3::up = {0.0f, 1.0f, 0.0f};

Vector3 Vector3::down = {0.0f, -1.0f, 0.0f};

Vector3 Vector3::forward = {0.0f, 0.0f, 1.0f};

Vector3 Vector3::backward = {0.0f, 0.0f, -1.0f};


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
