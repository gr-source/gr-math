#pragma once

#include "types.hpp"

struct Vector3 {
    union {
        struct {
            vvalue x;
            vvalue y;
            vvalue z;
        };
        vvalue data[3];
    };

    // Vector3(vvalue x = 0.0f, vvalue y = 0.0f, vvalue z = 0.0f);

    vvalue operator[](int index) const;

    vvalue& operator[](int index);

    Vector3 operator -() const;

    Vector3& operator /=(const Vector3 &other);
    Vector3& operator /=(vvalue other);

    Vector3& operator +=(const Vector3 &other);
    Vector3& operator +=(vvalue other);

    Vector3& operator -=(const Vector3 &other);
    Vector3& operator -=(vvalue other);

    Vector3& operator *=(const Vector3 &other);
    Vector3& operator *=(vvalue other);

    // Vector3& operator =(const Vector3 &other);

    bool operator ==(const Vector3 &other) const;

    bool operator !=(const Vector3 &other) const;

    bool operator >(const Vector3 &rhs) const;
    bool operator >=(const Vector3 &rhs) const;

    bool operator <(const Vector3 &rhs) const;
    bool operator <=(const Vector3 &rhs) const;

    operator Vector4() const;

    static Vector3 zero;

    static Vector3 one;

    static Vector3 right;

    static Vector3 left;

    static Vector3 up;

    static Vector3 down;

    static Vector3 forward;

    static Vector3 backward;

    friend std::istream &operator >>(std::istream &is, Vector3 &other);

    friend std::ostream &operator <<(std::ostream &os, const Vector3 &other);
};

// operator -
Vector3 operator -(vvalue lhs, const Vector3 &rhs) noexcept;

Vector3 operator -(const Vector3 &lhs, vvalue rhs) noexcept;

Vector3 operator -(const Vector3 &lhs, const Vector3 &rhs) noexcept;

// operator +
Vector3 operator +(vvalue lhs, const Vector3 &rhs) noexcept;

Vector3 operator +(const Vector3 &lhs, vvalue rhs) noexcept;

Vector3 operator +(const Vector3 &lhs, const Vector3 &rhs) noexcept;

// operator *
Vector3 operator *(vvalue lhs, const Vector3 &rhs) noexcept;

Vector3 operator *(const Vector3 &lhs, vvalue rhs) noexcept;

Vector3 operator *(const Vector3 &lhs, const Vector3 &rhs) noexcept;

// operator /
Vector3 operator /(vvalue lhs, const Vector3 &rhs) noexcept;

Vector3 operator /(const Vector3 &lhs, vvalue rhs) noexcept;

Vector3 operator /(const Vector3 &lhs, const Vector3 &rhs) noexcept;

// stream 
std::istream &operator >>(std::istream &is, Vector3 &other);

std::ostream &operator <<(std::ostream &os, const Vector3 &other);
