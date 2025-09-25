#include "vector.hpp"

template <typename T>
constexpr vector<T, 2> operator -(const vector<T, 2> &other) noexcept
{
    return {-other.x, -other.y};
}

template <typename T>
constexpr vector<T, 2> &operator +=(vector<T, 2> &lhs, const vector<T, 2> &rhs) noexcept
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

template <typename T>
constexpr vector<T, 2> &operator +=(vector<T, 2> &lhs, T rhs) noexcept
{
    lhs.x += rhs;
    lhs.y += rhs;
    return lhs;
}

template <typename T>
constexpr vector<T, 2> &operator -=(vector<T, 2> &lhs, const vector<T, 2> &rhs) noexcept
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

template <typename T>
constexpr vector<T, 2> &operator -=(vector<T, 2> &lhs, T rhs) noexcept
{
    lhs.x -= rhs;
    lhs.y -= rhs;
    return lhs;
}

template <typename T>
constexpr vector<T, 2> &operator *=(vector<T, 2> &lhs, const vector<T, 2> &rhs) noexcept
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    return lhs;
}

template <typename T>
constexpr vector<T, 2> &operator *=(vector<T, 2> &lhs, T rhs) noexcept
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    return lhs;
}

template <typename T>
constexpr vector<T, 2> &operator /=(vector<T, 2> &lhs, const vector<T, 2> &rhs) noexcept
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    return lhs;
}

template <typename T>
constexpr vector<T, 2> &operator /=(vector<T, 2> &lhs, T rhs) noexcept
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}

template <typename T>
constexpr vector<T, 2> operator +(const vector<T, 2> &lhs, const vector<T, 2> &rhs) noexcept
{
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

template <typename T>
constexpr vector<T, 2> operator -(const vector<T, 2> &lhs, const vector<T, 2> &rhs) noexcept
{
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

template <typename T>
constexpr vector<T, 2> operator *(const vector<T, 2> &lhs, const vector<T, 2> &rhs) noexcept
{
    return {lhs.x * rhs.x, lhs.y * rhs.y};
}

template <typename T>
constexpr vector<T, 2> operator *(const vector<T, 2> &lhs, T rhs) noexcept
{
    return {lhs.x * rhs, lhs.y * rhs};
}

template <typename T>
constexpr vector<T, 2> operator *(T lhs, const vector<T, 2> &rhs) noexcept
{
    return {lhs * rhs.x, lhs * rhs.y};
}

template <typename T>
constexpr vector<T, 2> operator /(const vector<T, 2> &lhs, const vector<T, 2> &rhs) noexcept
{
    return {lhs.x / rhs.x, lhs.y / rhs.y};
}

template <typename T>
constexpr vector<T, 2> operator /(const vector<T, 2> &lhs, T rhs) noexcept
{
    return {lhs.x / rhs, lhs.y / rhs};
}

