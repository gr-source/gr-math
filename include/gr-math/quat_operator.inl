#include "vector.hpp"

template <typename T>
inline constexpr quat<T> operator +(const quat<T> &lhs,const quat<T> &rhs) noexcept
{
    return {lhs.w + rhs.w, lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

template <typename T>
inline constexpr quat<T> &operator *=(quat<T> &lhs, const quat<T> &rhs) noexcept
{
    lhs = lhs * rhs;
    return lhs;
}

template <typename T>
inline constexpr quat<T> operator *(const quat<T> &lhs, const quat<T> &rhs) noexcept
{
    return {
        (lhs.w * rhs.w) - (lhs.x * rhs.x) - (lhs.y * rhs.y) - (lhs.z * rhs.z),
        (lhs.w * rhs.x) + (lhs.x * rhs.w) + (lhs.y * rhs.z) - (lhs.z * rhs.y),
        (lhs.w * rhs.y) - (lhs.x * rhs.z) + (lhs.y * rhs.w) + (lhs.z * rhs.x),
        (lhs.w * rhs.z) + (lhs.x * rhs.y) - (lhs.y * rhs.x) + (lhs.z * rhs.w)
    };
}

template <typename T>
inline constexpr quat<T> operator *(const quat<T> &lhs, T rhs) noexcept
{
    return {lhs.w * rhs, lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

template <typename T>
inline constexpr vector<T, 3> operator *(const quat<T> &lhs, const vector<T, 3> &rhs) noexcept
{
    T w = lhs.w;
    T x = lhs.x;
    T y = lhs.y;
    T z = lhs.z;

    T vx = rhs.x;
    T vy = rhs.y;
    T vz = rhs.z;

    T qx2 = x + x;
    T qy2 = y + y;
    T qz2 = z + z;

    T qxqx2 = x * qx2;
    T qxqy2 = x * qy2;
    T qxqz2 = x * qz2;

    T qyqy2 = y * qy2;
    T qyqz2 = y * qz2;
    T qzqz2 = z * qz2;

    T qwqx2 = w * qx2;
    T qwqy2 = w * qy2;
    T qwqz2 = w * qz2;

    return {
        (1 - qyqy2 - qzqz2) * vx + (qxqy2 - qwqz2) * vy + (qxqz2 + qwqy2) * vz,
        (qxqy2 + qwqz2) * vx + (1 - qxqx2 - qzqz2) * vy + (qyqz2 - qwqx2) * vz,
        (qxqz2 - qwqy2) * vx + (qyqz2 + qwqx2) * vy + (1 - qxqx2 - qyqy2) * vz
    };
}

template <typename T>
inline constexpr quat<T> operator /(const quat<T> &lhs, T rhs) noexcept
{
    return quat<T>{lhs.w / rhs, lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
}


template <typename T>
inline constexpr quat<T> operator -(const quat<T> &q)
{
    return {-q.w, -q.x, -q.y, -q.z};
}

