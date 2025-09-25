#include "vector.hpp"

template <typename T>
constexpr vector<T, 4> operator -(const vector<T, 4> &other) noexcept
{
    return {-other.x, -other.y, -other.z, -other.w};
}

template <typename T>
constexpr vector<T, 4> &operator +=(vector<T, 4> &lhs, const vector<T, 4> &rhs) noexcept
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;
    return lhs;
}

template <typename T>
constexpr vector<T, 4> &operator +=(vector<T, 4> &lhs, T rhs) noexcept
{
    lhs.x += rhs;
    lhs.y += rhs;
    lhs.z += rhs;
    lhs.w += rhs;
    return lhs;
}

template <typename T>
constexpr vector<T, 4> &operator -=(vector<T, 4> &lhs, const vector<T, 4> &rhs) noexcept
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    lhs.w -= rhs.w;
    return lhs;
}

template <typename T>
constexpr vector<T, 4> &operator -=(vector<T, 4> &lhs, T rhs) noexcept
{
    lhs.x -= rhs;
    lhs.y -= rhs;
    lhs.z -= rhs;
    lhs.w -= rhs;
    return lhs;
}

template <typename T>
constexpr vector<T, 4> &operator *=(vector<T, 4> &lhs, const vector<T, 4> &rhs) noexcept
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    lhs.w *= rhs.w;
    return lhs;
}

template <typename T>
constexpr vector<T, 4> &operator *=(vector<T, 4> &lhs, T rhs) noexcept
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    lhs.w *= rhs;
    return lhs;
}

template <typename T>
constexpr vector<T, 4> &operator /=(vector<T, 4> &lhs, const vector<T, 4> &rhs) noexcept
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;
    lhs.w /= rhs.w;
    return lhs;
}

template <typename T>
constexpr vector<T, 4> &operator /=(vector<T, 4> &lhs, T rhs) noexcept
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    lhs.w /= rhs;
    return lhs;
}

template <typename T>
constexpr vector<T, 4> operator +(const vector<T, 4> &lhs, const vector<T, 4> &rhs) noexcept
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
}

template <typename T>
constexpr vector<T, 4> operator -(const vector<T, 4> &lhs, const vector<T, 4> &rhs) noexcept
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
}

template <typename T>
constexpr vector<T, 4> operator *(const vector<T, 4> &lhs, const vector<T, 4> &rhs) noexcept
{
    return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w};
}

template <typename T>
constexpr vector<T, 4> operator *(const vector<T, 4> &lhs, const T &rhs) noexcept
{
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs};
}

template <typename T>
constexpr vector<T, 4> operator *(const T &lhs, const vector<T, 4> &rhs) noexcept
{
    return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w};
}

template <typename T>
constexpr vector<T, 4> operator /(const vector<T, 4> &lhs, const vector<T, 4> &rhs) noexcept
{
    return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w};
}

template <typename T>
constexpr vector<T, 4> operator /(const vector<T, 4> &lhs, const T &rhs) noexcept
{
    return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs};
}



