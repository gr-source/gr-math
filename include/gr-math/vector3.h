#pragma once

#include "types.h"

struct Vector3 {
    union {
        struct {
            vvalue x;
            vvalue y;
            vvalue z;
        };
        vvalue data[3];
    };

    Vector3(vvalue x = 0.0f, vvalue y = 0.0f, vvalue z = 0.0f);

    Vector3(const Vector2& rhs, vvalue z = 1.0f);
    Vector3(const Vector4& rhs);

    vvalue operator[](int index) const;

    vvalue& operator[](int index);

    Vector3 operator -(const Vector3& other) const;

    Vector3 operator -() const;

    Vector3 operator +(const Vector3& other) const;

    Vector3 operator /(const Vector3& other) const;
    Vector3& operator /=(const Vector3& rhs);
    Vector3& operator /=(vvalue rhs);

    Vector3& operator +=(const Vector3& other);

    Vector3& operator -=(const Vector3& other);

    Vector3 operator *(const Vector3& other) const;
    Vector3& operator *=(const Vector3& other);
    Vector3& operator *=(vvalue other);

    bool operator==(const Vector3& other) const;

    bool operator!=(const Vector3& other) const;

    Vector3& operator=(const Vector3& other);

    bool operator>(const Vector3& other) const;
    bool operator<(const Vector3& other) const;

    friend std::istream& operator >>(std::istream& is, Vector3& other) {
        is >> other.x >> other.y >> other.z;
        return is;
    }
    
    friend std::ostream& operator <<(std::ostream& os, const Vector3& other) {
        os << other.x << " " << other.y << " " << other.z;
        return os;
    }
    
    static const Vector3 zero;

    static const Vector3 one;

    static const Vector3 forward;

    static const Vector3 right;

    static const Vector3 up;
};

const Vector3 operator *(vvalue rhs, const Vector3& lhs);

const Vector3 operator *(const Vector3& rhs, vvalue lhs);

const Vector3 operator /(vvalue rhs, const Vector3& lhs);

const Vector3 operator /(const Vector3& rhs, vvalue lhs);


