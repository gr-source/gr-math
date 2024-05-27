#include "vector2.h"

Vector2& Vector2::operator =(const Vector2& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vector2 &Vector2::operator+=(const Vector2 &lhs) {
    *this = *this + lhs;
    return *this;
}

bool Vector2::operator !=(const Vector2& other) const {
    return ((x != other.x) || (y != other.y));
}

const Vector2 Vector2::zero = {0.0f, 0.0f};

const Vector2 Vector2::one = {1.0f, 1.0f};

const Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs) {
    return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

const Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs) {
    return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

const Vector2 operator*(const Vector2 &lhs, const Vector2 &rhs) {
    return Vector2(lhs.x * rhs.x, lhs.y * rhs.y);
}

const Vector2 operator*(const Vector2 &lhs, vvalue rhs) {
    return Vector2(lhs.x * rhs, lhs.y * rhs);
}

const Vector2 operator*(vvalue lhs, const Vector2 &rhs) {
    return Vector2(lhs * rhs.x, lhs * rhs.y);
}

const Vector2 operator/(const Vector2 &lhs, const Vector2 &rhs) {
    return Vector2(lhs.x / rhs.x, lhs.y / rhs.y);
}

const Vector2 operator/(const Vector2 &lhs, vvalue rhs) {
    return Vector2(lhs.x / rhs, lhs.y / rhs);
}

const Vector2 operator/(vvalue lhs, const Vector2 &rhs) {
    return Vector2(lhs / rhs.x, lhs / rhs.y);
}
