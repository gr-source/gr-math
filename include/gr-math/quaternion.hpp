#pragma once

#include "quat_operator.inl"

/*
* (W) O componente w do quatérnion, que é a parte do número real do quatérnion.
* (X) O componente x do quatérnion, que é o coeficiente do vetor de unidade i no quatérnion.
* (Y) O componente y do quatérnion, que é o coeficiente do vetor de unidade j no quatérnion.
* (Z) O componente z do quatérnion, que é o coeficiente do vetor de unidade k no quatérnion.
*/

template <typename T>
struct quat
{
    union
    {
        struct
        {
            T w;
            T x;
            T y;
            T z;
        };
        T data[4];
    };

    static quat<T> identity;
    /*
    Quaternion(float value = 0.0f);
    
    Quaternion(float w, float x, float y, float z);

    Quaternion& operator *=(const Quaternion& rhs);

    Quaternion& operator /=(float rhs);

    Quaternion operator +(const Quaternion& lhs) const;

    Quaternion operator -(const Quaternion& lhs) const;

    Quaternion operator -() const;

    Quaternion& operator =(const Quaternion& other);

    Quaternion& operator +=(const Quaternion& lhs);

    const bool operator !=(const Quaternion& lhs);

    static const Quaternion identity;

    friend std::istream& operator >>(std::istream& is, Quaternion& rhs) {
        is >> rhs.w >> rhs.x >> rhs.y >> rhs.z;
        return is;
    }

    friend std::ostream& operator <<(std::ostream& os, const Quaternion& rhs) {
        os << rhs.w << " " << rhs.x << " " << rhs.y << " " << rhs.z;
        return os;
    }
    */
};

template <typename T>
quat<T> quat<T>::identity = {T(1), T(0), T(0), T(0)};

/*
// operator *
Quaternion operator *(const Quaternion &lhs, const Quaternion &rhs) noexcept;

Quaternion operator *(const Quaternion &lhs, float rhs) noexcept;

Vector3 operator *(const Quaternion &lhs, const Vector3 &rhs) noexcept;

Quaternion operator /(const Quaternion &lhs, float rhs) noexcept;
*/




