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

    Vector4(const Vector3& rhs, vvalue w = 1.0f);

    Vector4(vvalue x = 0.0f, vvalue y = 0.0f, vvalue z = 0.0f, vvalue w = 1.0f);

    const Vector4 operator*(const Vector4& rhs) const;
    const Vector4 operator-(const Vector4& rhs) const;
    const Vector4 operator/(const Vector4& rhs) const;

    Vector4& operator=(const Vector4& rhs);
    Vector4& operator /=(vvalue rhs);

    const bool operator>(const Vector4& rhs) const;

    const bool operator!=(const Vector4& lhs) const;

    friend std::istream& operator >>(std::istream& is, Vector4& rhs) {
        is >> rhs.x >> rhs.y >> rhs.z >> rhs.w;
        return is;
    }

    friend std::ostream& operator <<(std::ostream& os, const Vector4& rhs) {
        os << rhs.x << " " << rhs.y << " " << rhs.z << " " << rhs.w;
        return os;
    }

    static const Vector4 zero;
};

