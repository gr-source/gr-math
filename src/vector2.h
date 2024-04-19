#pragma once

#include "types.h"

struct Vector2 {
    union {
        struct {
            vvalue x;
            vvalue y;
        };
        vvalue data[2];
    };

    Vector2(vvalue x = 0.0f, vvalue y = 0.0f) : x(x), y(y) {}

    Vector2(const Vector2& other) : x(other.x), y(other.y) {}

    Vector2 operator /(const Vector2& other) const;

    Vector2 operator /(vvalue other) const;

    Vector2 operator -(const Vector2& other) const;

    Vector2 operator -(vvalue other) const;

    Vector2 operator+(const Vector2& lhs);
    Vector2& operator +=(vvalue rhs);

    Vector2 operator *(const Vector2& other) const;

    Vector2 operator *(vvalue other) const;

    Vector2& operator =(const Vector2& other);

    static const Vector2 zero;

    static const Vector2 one;

    bool operator !=(const Vector2& other) const;

    friend std::istream& operator >>(std::istream& is, Vector2& other) {
        is >> other.x >> other.y;
        return is;
    }

    friend std::ostream& operator <<(std::ostream& os, const Vector2& other) {
        os << other.x << " " << other.y;
        return os;
    }
};



