#include "vector.hpp"

template <typename T>
inline constexpr vector4<T> operator -(const vector4<T> &other) noexcept
{
    return {-other.x, -other.y, -other.z, -other.w};
}

template <typename T>
inline constexpr vector4<T> &operator +=(vector4<T> &lhs, const vector4<T> &rhs) noexcept
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;
    return lhs;
}

template <typename T>
inline constexpr vector4<T> &operator +=(vector4<T> &lhs, T rhs) noexcept
{
    lhs.x += rhs;
    lhs.y += rhs;
    lhs.z += rhs;
    lhs.w += rhs;
    return lhs;
}

template <typename T>
inline constexpr vector4<T> &operator -=(vector4<T> &lhs, const vector4<T> &rhs) noexcept
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    lhs.w -= rhs.w;
    return lhs;
}

template <typename T>
inline constexpr vector4<T> &operator -=(vector4<T> &lhs, T rhs) noexcept
{
    lhs.x -= rhs;
    lhs.y -= rhs;
    lhs.z -= rhs;
    lhs.w -= rhs;
    return lhs;
}

template <typename T>
inline constexpr vector4<T> &operator *=(vector4<T> &lhs, const vector4<T> &rhs) noexcept
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    lhs.w *= rhs.w;
    return lhs;
}

template <typename T>
inline constexpr vector4<T> &operator *=(vector4<T> &lhs, T rhs) noexcept
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    lhs.w *= rhs;
    return lhs;
}

template <typename T>
inline constexpr vector4<T> &operator /=(vector4<T> &lhs, const vector4<T> &rhs) noexcept
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;
    lhs.w /= rhs.w;
    return lhs;
}

template <typename T>
inline constexpr vector4<T> &operator /=(vector4<T> &lhs, T rhs) noexcept
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    lhs.w /= rhs;
    return lhs;
}

template <typename T>
inline constexpr vector4<T> operator +(const vector4<T> &lhs, const vector4<T> &rhs) noexcept
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
}

template <typename T>
inline constexpr vector4<T> operator -(const vector4<T> &lhs, const vector4<T> &rhs) noexcept
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
}

template <typename T>
inline constexpr vector4<T> operator *(const vector4<T> &lhs, const vector4<T> &rhs) noexcept
{
    return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w};
}

template <typename T>
inline constexpr vector4<T> operator *(const vector4<T> &lhs, const T &rhs) noexcept
{
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs};
}

template <typename T>
inline constexpr vector4<T> operator *(const T &lhs, const vector4<T> &rhs) noexcept
{
    return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w};
}

template <typename T>
inline constexpr vector4<T> operator /(const vector4<T> &lhs, const vector4<T> &rhs) noexcept
{
    return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w};
}

template <typename T>
inline constexpr vector4<T> operator /(const vector4<T> &lhs, const T &rhs) noexcept
{
    return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs};
}



