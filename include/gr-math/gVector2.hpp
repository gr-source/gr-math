#pragma once

#include <istream>

template <typename T>
struct gVector2 {
    union {
        struct {
            T x;
            T y;
        };
        T data[2];
    };
    
    gVector2(T x, T y);

    gVector2<T> &operator +=(const gVector2<T>& lhs);
    gVector2<T> &operator +=(T lhs);

    gVector2<T> &operator -=(const gVector2<T>& lhs);
    gVector2<T> &operator -=(T lhs);

    gVector2<T> &operator *=(const gVector2<T>& lhs);
    gVector2<T> &operator *=(T lhs);

    gVector2<T> &operator /=(const gVector2<T>& lhs);
    gVector2<T> &operator /=(T lhs);

    gVector2<T> &operator =(const gVector2<T>& lhs);

    const bool operator ==(const gVector2<T> &rhs) const;

    /*
    inline friend std::istream &operator >>(std::istream& is, gVector2<T>& other) {
        is >> other.x >> other.y;
    }

    inline friend std::ostream &operator <<(std::ostream& os, const gVector2<T>& other) {
        os << other.x << " " << other.y;
        return os;
    }
    */
};

template <typename T>
inline gVector2<T>::gVector2(T x, T y) : x(x), y(y) {}

template <typename T>
inline gVector2<T> &gVector2<T>::operator+=(const gVector2<T> &lhs) {
    if (this == &lhs) {
        return *this;
    }
    *this = *this + lhs;
    return *this;
}

template <typename T>
inline gVector2<T> &gVector2<T>::operator+=(T lhs) {
    x += lhs;
    y += lhs;
}

template <typename T>
inline gVector2<T> &gVector2<T>::operator-=(const gVector2<T> &lhs) {
    if (this == &lhs) {
        return *this;
    }
    *this = *this - lhs;
    return *this;
}

template <typename T>
inline gVector2<T> &gVector2<T>::operator-=(T lhs) {
    x -= lhs;
    y -= lhs;
}

template <typename T>
inline gVector2<T> &gVector2<T>::operator*=(const gVector2<T> &lhs) {
    if (this == &lhs) {
        return *this;
    }
    *this = *this * lhs;
    return *this;
}

template <typename T>
inline gVector2<T> &gVector2<T>::operator*=(T lhs) {
    x *= lhs;
    y *= lhs;
}

template <typename T>
inline gVector2<T> &gVector2<T>::operator/=(const gVector2<T> &lhs) {
    if (this == &lhs) {
        return *this;
    }
    *this = *this / lhs;
    return *this;
}

template <typename T>
inline gVector2<T> &gVector2<T>::operator/=(T lhs) {
    x /= lhs;
    y /= lhs;
}

template <typename T>
inline gVector2<T> &gVector2<T>::operator=(const gVector2<T> &lhs) {
    if (this == &lhs) {
        return *this;
    }
    x = lhs.x;
    y = lhs.y;

    return *this;
}

// operator +
template <typename T>
inline gVector2<T> operator +(const gVector2<T>& lhs, const gVector2<T>& rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

template <typename T>
inline gVector2<T> operator +(const gVector2<T>& lhs, float rhs) {
    return {lhs.x + rhs, lhs.y + rhs};
}

template <typename T>
inline gVector2<T> operator +(float lhs, const gVector2<T>& rhs) {
    return {lhs + rhs.x, lhs + rhs.y};
}

// operator -
template <typename T>
inline gVector2<T> operator -(const gVector2<T>& lhs, const gVector2<T>& rhs) {
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

template <typename T>
inline gVector2<T> operator -(const gVector2<T>& lhs, float rhs) {
    return {lhs.x - rhs, lhs.y - rhs};
}

template <typename T>
inline gVector2<T> operator -(float lhs, const gVector2<T>& rhs) {
    return {lhs - rhs.x, lhs - rhs.y};
}

// operator *
template <typename T>
inline gVector2<T> operator *(const gVector2<T>& lhs, const gVector2<T>& rhs) {
    return {lhs.x * rhs.x, lhs.y * rhs.y};
}

template <typename T>
inline gVector2<T> operator *(const gVector2<T>& lhs, float rhs) {
    return {lhs.x * rhs, lhs.y * rhs};
}

template <typename T>
inline gVector2<T> operator *(float lhs, const gVector2<T>& rhs) {
    return {lhs * rhs.x, lhs * rhs.y};
}

// operator /
template <typename T>
inline gVector2<T> operator /(const gVector2<T>& lhs, const gVector2<T>& rhs) {
    return {lhs.x / rhs.x, lhs.y / rhs.y};
}

template <typename T>
inline gVector2<T> operator /(const gVector2<T>& lhs, float rhs) {
    return {lhs.x / rhs, lhs.y / rhs};
}

template <typename T>
inline gVector2<T> operator /(float lhs, const gVector2<T>& rhs) {
    return {lhs / rhs.x, lhs / rhs.y};
}

template <typename T>
inline const bool gVector2<T>::operator==(const gVector2<T> &rhs) const {
    return (x == rhs.x) && (y == rhs.y);
}
