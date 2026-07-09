#include "vector.hpp"

template <typename T>
inline constexpr vector3<T> operator -(const vector3<T> &other) noexcept
{
    return {-other.x, -other.y, -other.z};
}

template <typename T>
inline constexpr vector3<T> &operator +=(vector3<T> &lhs, const vector3<T> &rhs) noexcept
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    return lhs;
}

template <typename T>
inline constexpr vector3<T> &operator +=(vector3<T> &lhs, T rhs) noexcept
{
    lhs.x += rhs;
    lhs.y += rhs;
    lhs.z += rhs;
    return lhs;
}

template <typename T>
inline constexpr vector3<T> &operator -=(vector3<T> &lhs, const vector3<T> &rhs) noexcept
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    return lhs;
}

template <typename T>
inline constexpr vector3<T> &operator -=(vector3<T> &lhs, T rhs) noexcept
{
    lhs.x -= rhs;
    lhs.y -= rhs;
    lhs.z -= rhs;
    return lhs;
}

template <typename T>
inline constexpr vector3<T> &operator *=(vector3<T> &lhs, const vector3<T> &rhs) noexcept
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    return lhs;
}

template <typename T>
inline constexpr vector3<T> &operator *=(vector3<T> &lhs, T rhs) noexcept
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    return lhs;
}

template <typename T>
inline constexpr vector3<T> &operator /=(vector3<T> &lhs, const vector3<T> &rhs) noexcept
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;
    return lhs;
}

template <typename T>
inline constexpr vector3<T> &operator /=(vector3<T> &lhs, T rhs) noexcept
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    return lhs;
}

template <typename T>
inline constexpr vector3<T> operator +(const vector3<T> &lhs, const vector3<T> &rhs) noexcept
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

template <typename T>
inline constexpr vector3<T> operator +(const vector3<T> &lhs, T rhs) noexcept
{
    return {lhs.x + rhs, lhs.y + rhs, lhs.z + rhs};
}

template <typename T>
inline constexpr vector3<T> operator -(const vector3<T> &lhs, const vector3<T> &rhs) noexcept
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

template <typename T>
inline constexpr vector3<T> operator -(const vector3<T> &lhs, T rhs) noexcept
{
    return {lhs.x - rhs, lhs.y - rhs, lhs.z - rhs};
}

template <typename T>
inline constexpr vector3<T> operator *(const vector3<T> &lhs, const vector3<T> &rhs) noexcept
{
    return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
}

template <typename T>
inline constexpr vector3<T> operator *(const vector3<T> &lhs, const T &rhs) noexcept
{
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

template <typename T>
inline constexpr vector3<T> operator *(const T &lhs, const vector3<T> &rhs) noexcept
{
    return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z};
}

template <typename T>
inline constexpr vector3<T> operator /(const vector3<T> &lhs, const vector3<T> &rhs) noexcept
{
    return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
}

template <typename T>
inline constexpr vector3<T> operator /(const vector3<T> &lhs, const T &rhs) noexcept
{
    return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
}



