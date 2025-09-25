#include "vector.hpp"

template <typename T>
constexpr quat<T> operator +(const quat<T> &lhs,const quat<T> &rhs) noexcept
{
    return {lhs.w + rhs.w, lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

template <typename T>
constexpr quat<T> &operator *=(quat<T> &lhs, const quat<T> &rhs) noexcept
{
    lhs = lhs * rhs;
    return lhs;
}

template <typename T>
constexpr quat<T> operator *(const quat<T> &lhs, const quat<T> &rhs) noexcept
{
    return {
        (lhs.w * rhs.w) - (lhs.x * rhs.x) - (lhs.y * rhs.y) - (lhs.z * rhs.z),
        (lhs.w * rhs.x) + (lhs.x * rhs.w) + (lhs.y * rhs.z) - (lhs.z * rhs.y),
        (lhs.w * rhs.y) - (lhs.x * rhs.z) + (lhs.y * rhs.w) + (lhs.z * rhs.x),
        (lhs.w * rhs.z) + (lhs.x * rhs.y) - (lhs.y * rhs.x) + (lhs.z * rhs.w)
    };
}

template <typename T>
constexpr quat<T> operator *(const quat<T> &lhs, T rhs) noexcept
{
    return {lhs.w * rhs, lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

template <typename T>
constexpr quat<T> operator /(const quat<T> &lhs, T rhs) noexcept
{
    return quat<T>{lhs.w / rhs, lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
}


template <typename T>
constexpr quat<T> operator -(const quat<T> &q)
{
    return {-q.w, -q.x, -q.y, -q.z};
}

