#include "vector.hpp"

template <typename T>
inline constexpr vector<T, 3> operator -(const vector<T, 3> &other) noexcept
{
    return {-other.x, -other.y, -other.z};
}

template <typename T>
inline constexpr vector<T, 3> &operator +=(vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    return lhs;
}

template <typename T>
inline constexpr vector<T, 3> &operator +=(vector<T, 3> &lhs, T rhs) noexcept
{
    lhs.x += rhs;
    lhs.y += rhs;
    lhs.z += rhs;
    return lhs;
}

template <typename T>
inline constexpr vector<T, 3> &operator -=(vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    return lhs;
}

template <typename T>
inline constexpr vector<T, 3> &operator -=(vector<T, 3> &lhs, T rhs) noexcept
{
    lhs.x -= rhs;
    lhs.y -= rhs;
    lhs.z -= rhs;
    return lhs;
}

template <typename T>
inline constexpr vector<T, 3> &operator *=(vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    return lhs;
}

template <typename T>
inline constexpr vector<T, 3> &operator *=(vector<T, 3> &lhs, T rhs) noexcept
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    return lhs;
}

template <typename T>
inline constexpr vector<T, 3> &operator /=(vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;
    return lhs;
}

template <typename T>
inline constexpr vector<T, 3> &operator /=(vector<T, 3> &lhs, T rhs) noexcept
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    return lhs;
}

template <typename T>
inline constexpr vector<T, 3> operator +(const vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

template <typename T>
inline constexpr vector<T, 3> operator -(const vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

template <typename T>
inline constexpr vector<T, 3> operator *(const vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
}

template <typename T>
inline constexpr vector<T, 3> operator *(const vector<T, 3> &lhs, const T &rhs) noexcept
{
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

template <typename T>
inline constexpr vector<T, 3> operator *(const T &lhs, const vector<T, 3> &rhs) noexcept
{
    return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z};
}

template <typename T>
inline constexpr vector<T, 3> operator /(const vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
}

template <typename T>
inline constexpr vector<T, 3> operator /(const vector<T, 3> &lhs, const T &rhs) noexcept
{
    return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
}



