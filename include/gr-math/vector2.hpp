#pragma once

#include "types.hpp"

struct Vector2 {
    union {
        struct {
            vvalue x;
            vvalue y;
        };
        vvalue data[2];
    };

    Vector2& operator +=(const Vector2& lhs);

    Vector2& operator *=(vvalue lhs);

    Vector2& operator /=(vvalue lhs);

    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;

    static Vector2 zero;

    static Vector2 one;

    static Vector2 left;

    static Vector2 right;

    static Vector2 up;

    static Vector2 down;

    friend std::istream &operator >>(std::istream &is, Vector2 &other);

    friend std::ostream &operator <<(std::ostream &os, const Vector2 &other);
};

// operator -
Vector2 operator -(const Vector2 &lhs, const Vector2 &rhs) noexcept;

// operator +
Vector2 operator +(const Vector2 &lhs, const Vector2 &rhs) noexcept;

// operator *
Vector2 operator *(const Vector2 &lhs, const Vector2 &rhs) noexcept;

Vector2 operator *(const Vector2& lhs, vvalue rhs) noexcept;

Vector2 operator *(vvalue lhs, const Vector2& rhs) noexcept;

// operator /
Vector2 operator /(const Vector2& lhs, const Vector2& rhs) noexcept;

Vector2 operator /(const Vector2& lhs, vvalue rhs) noexcept;

Vector2 operator /(vvalue lhs, const Vector2& rhs) noexcept;

// stream
std::istream &operator >>(std::istream &is, Vector2 &other);

std::ostream &operator <<(std::ostream &os, const Vector2 &other);

