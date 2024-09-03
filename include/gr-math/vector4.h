#pragma once

#include "types.h"

/*
* (X) O componente x do Vector.
* (Y) O componente y do Vector.
* (Z) O componente z do Vector.
* (W) O componente w do Vector.
*/
struct Vector4 {
    union {
        struct {
            vvalue x;
            vvalue y;
            vvalue z;
            vvalue w;
        };
        vvalue data[4];
    };

    Vector4(const Vector3 &rhs, vvalue w);
    Vector4(vvalue x = 0.0f, vvalue y = 0.0f, vvalue z = 0.0f, vvalue w = 1.0f);

    Vector4& operator /=(vvalue rhs);
    
    Vector4& operator =(const Vector4& rhs);

    const bool operator >(const Vector4& rhs) const;

    const bool operator !=(const Vector4& lhs) const;

    operator Vector3() const;

    static const Vector4 zero;

    friend std::istream &operator >>(std::istream &is, Vector4 &rhs);

    friend std::ostream &operator <<(std::ostream &os, const Vector4 &rhs);
};

// operator -
Vector4 operator -(const Vector4 &lhs, const Vector4 &rhs) noexcept;

// operator +
Vector4 operator +(const Vector4 &lhs, const Vector4 &rhs) noexcept;

// operator *
Vector4 operator *(const Vector4 &lhs, const Vector4 &rhs) noexcept;

Vector4 operator *(const Vector4 &lhs, vvalue rhs) noexcept;

Vector4 operator *(vvalue lhs, const Vector4 &rhs) noexcept;

// operator /
Vector4 operator /(const Vector4 &lhs, const Vector4 &rhs) noexcept;

Vector4 operator /(vvalue lhs, const Vector4 &rhs) noexcept;

Vector4 operator /(const Vector4 &lhs, vvalue rhs) noexcept;

// stream
std::istream &operator >>(std::istream &is, Vector4 &rhs);

std::ostream &operator <<(std::ostream &os, const Vector4 &rhs);
