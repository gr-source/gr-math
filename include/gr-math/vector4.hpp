#pragma once

#include "types.hpp"

/*
* (X) O componente x do Vector.
* (Y) O componente y do Vector.
* (Z) O componente z do Vector.
* (W) O componente w do Vector.
*/
struct Vector4
{
    union
    {
        struct
        {
            vvalue x;
            vvalue y;
            vvalue z;
            vvalue w;
        };
        vvalue data[4];
    };

    Vector4& operator /=(vvalue rhs);
    
    bool operator >(const Vector4& rhs) const;

    bool operator !=(const Vector4& lhs) const;

    operator Vector3() const;

    bool operator ==(const Vector4 &rhs) const;

    inline constexpr const float &operator [](int index) const
    {
        return data[index];
    }

    inline constexpr float &operator [](int index)
    {
        return data[index];
    }

    static Vector4 zero;

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



