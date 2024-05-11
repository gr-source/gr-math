#include "gr-math/vector2.h"

Vector2 Vector2::operator /(const Vector2& other) const {
    return {x / other.x, y / other.y};
}

Vector2 Vector2::operator /(vvalue other) const {
    return {x / other, y / other};
}

Vector2 Vector2::operator -(const Vector2& other) const {
    return {x - other.x, y - other.y};
}

Vector2 Vector2::operator -(vvalue other) const {
    return {
        x - other,
        y - other
    };
}

Vector2 Vector2::operator+(const Vector2& lhs) {
    return {x + lhs.x, y + lhs.y};
}

Vector2& Vector2::operator +=(vvalue rhs) {
    x += rhs;
    y += rhs;

    return *this;
}

Vector2 Vector2::operator *(const Vector2& other) const {
    return {x * other.x, y * other.y};
}

Vector2 Vector2::operator *(vvalue other) const {
    return {x * other, y * other};
}

Vector2& Vector2::operator =(const Vector2& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

bool Vector2::operator !=(const Vector2& other) const {
    return ((x != other.x) || (y != other.y));
}

const Vector2 Vector2::zero = {0.0f, 0.0f};

const Vector2 Vector2::one = {1.0f, 1.0f};

