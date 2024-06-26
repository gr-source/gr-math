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

    Vector2(vvalue x = 0.0f, vvalue y = 0.0f);

    Vector2(const Vector2& other);

    Vector2(const Vector3& other);

    Vector2& operator =(const Vector2& other);

    Vector2& operator+=(const Vector2& lhs);

    const bool operator==(const Vector2& other) const;
    const bool operator!=(const Vector2& other) const;

    static const Vector2 zero;

    static const Vector2 one;

    friend std::istream& operator >>(std::istream& is, Vector2& other) {
        is >> other.x >> other.y;
        return is;
    }

    friend std::ostream& operator <<(std::ostream& os, const Vector2& other) {
        os << other.x << " " << other.y;
        return os;
    }
};

const Vector2 operator-(const Vector2& lhs, const Vector2& rhs);

const Vector2 operator+(const Vector2& lhs, const Vector2& rhs);

const Vector2 operator*(const Vector2& lhs, const Vector2& rhs);

const Vector2 operator*(const Vector2& lhs, vvalue rhs);

const Vector2 operator*(vvalue lhs, const Vector2& rhs);

const Vector2 operator/(const Vector2& lhs, const Vector2& rhs);

const Vector2 operator/(const Vector2& lhs, vvalue rhs);

const Vector2 operator/(vvalue lhs, const Vector2& rhs);
