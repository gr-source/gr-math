#include "vector2.h"

#include "gmath.h"

Vector2::Vector2(vvalue x, vvalue y) : x(x), y(y) {}

Vector2::Vector2(const Vector2 &other) : x(other.x), y(other.y) {}

Vector2 &Vector2::operator =(const Vector2 &other) {
    if (this == &other) {
        return *this;
    }
    x = other.x;
    y = other.y;
    return *this;
}

Vector2 &Vector2::operator +=(const Vector2 &lhs) {
    *this = *this + lhs;
    return *this;
}

Vector2 &Vector2::operator *=(vvalue lhs) {
    x *= lhs;
    y *= lhs;
    return *this;
}

Vector2 & Vector2::operator /=(vvalue lhs) {
    x /= lhs;
    y /= lhs;
    return *this;
}

bool Vector2::operator ==(const Vector2 &rhs) const {
    return Math::magnitude(*this - rhs) < 1e-6f;
}

bool Vector2::operator !=(const Vector2 &other) const {
    return ((x != other.x) || (y != other.y));
}

const Vector2 Vector2::zero = {0.0f, 0.0f};

const Vector2 Vector2::one = {1.0f, 1.0f};

// operator -
Vector2 operator -(const Vector2 &lhs, const Vector2 &rhs) noexcept {
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

// operator +
Vector2 operator +(const Vector2 &lhs, const Vector2 &rhs) noexcept {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

// operator *
Vector2 operator *(const Vector2 &lhs, const Vector2 &rhs) noexcept {
    return {lhs.x * rhs.x, lhs.y * rhs.y};
}

Vector2 operator *(const Vector2 &lhs, vvalue rhs) noexcept {
    return {lhs.x * rhs, lhs.y * rhs};
}

Vector2 operator *(vvalue lhs, const Vector2 &rhs) noexcept {
    return {lhs * rhs.x, lhs * rhs.y};
}

// operator /
Vector2 operator /(const Vector2 &lhs, const Vector2 &rhs) noexcept {
    return {lhs.x / rhs.x, lhs.y / rhs.y};
}

Vector2 operator /(const Vector2 &lhs, vvalue rhs) noexcept {
    return {lhs.x / rhs, lhs.y / rhs};
}

Vector2 operator /(vvalue lhs, const Vector2 &rhs) noexcept {
    return {lhs / rhs.x, lhs / rhs.y};
}

// stream
std::istream &operator >>(std::istream &is, Vector2 &other) {
    is >> other.x >> other.y;
    return is;
}

std::ostream &operator <<(std::ostream &os, const Vector2 &other) {
    os << other.x << " " << other.y;
    return os;
}

