#pragma once

#include "types.h"

/*
* (W) O componente w do quatérnion, que é a parte do número real do quatérnion.
* (X) O componente x do quatérnion, que é o coeficiente do vetor de unidade i no quatérnion.
* (Y) O componente y do quatérnion, que é o coeficiente do vetor de unidade j no quatérnion.
* (Z) O componente z do quatérnion, que é o coeficiente do vetor de unidade k no quatérnion.
*/
struct Quaternion {
    union { //JPL (w,x,y,z) - Hamilton (x, y, z, w)
        struct {
            vvalue w;
            vvalue x;
            vvalue y;
            vvalue z;
        };
        vvalue data[4];
    };

    Quaternion(vvalue value = 0.0f);
    
    Quaternion(vvalue w, vvalue x, vvalue y, vvalue z);

    Quaternion(const Matrix3x3& rhs);

    Quaternion(vvalue angle, const Vector3& axis);

    Vector3 operator*(const Vector3& rhs) const;

    Quaternion operator *(const Quaternion& lhs) const;

    Quaternion& operator *=(const Quaternion& rhs);

    Quaternion operator +(const Quaternion& lhs) const;

    Quaternion operator -(const Quaternion& lhs) const;

    Quaternion operator -() const;

    Quaternion operator =(const Quaternion& other);

    Quaternion& operator +=(const Quaternion& lhs);

    Vector3 eulerAngles() const;

    static const Quaternion identity;

    static const Quaternion LookRotation(const Vector3& forward, const Vector3& upward);

    static const Quaternion Euler(vvalue angle, const Vector3& axis);

    static const Quaternion Euler(const Vector3& axis);

    static const Quaternion Slerp(const Quaternion& lhs, const Quaternion& rhs, vvalue f);

    friend std::istream& operator >>(std::istream& is, Quaternion& rhs) {
        is >> rhs.w >> rhs.x >> rhs.y >> rhs.z;
        return is;
    }

    friend std::ostream& operator <<(std::ostream& os, const Quaternion& rhs) {
        os << rhs.w << " " << rhs.x << " " << rhs.y << " " << rhs.z;
        return os;
    }
};






