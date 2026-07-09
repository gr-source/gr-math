#include "vector.hpp"

template <typename T>
inline constexpr vector2<T> operator -(const vector2<T> &other) noexcept
{
    return {-other.x, -other.y};
}

template <typename T>
inline constexpr vector2<T> &operator +=(vector2<T> &lhs, const vector2<T> &rhs) noexcept
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

template <typename T>
inline constexpr vector2<T> &operator +=(vector2<T> &lhs, T rhs) noexcept
{
    lhs.x += rhs;
    lhs.y += rhs;
    return lhs;
}

template <typename T>
inline constexpr vector2<T> &operator -=(vector2<T> &lhs, const vector2<T> &rhs) noexcept
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

template <typename T>
inline constexpr vector2<T> &operator -=(vector2<T> &lhs, T rhs) noexcept
{
    lhs.x -= rhs;
    lhs.y -= rhs;
    return lhs;
}

template <typename T>
inline constexpr vector2<T> &operator *=(vector2<T> &lhs, const vector2<T> &rhs) noexcept
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    return lhs;
}

template <typename T>
inline constexpr vector2<T> &operator *=(vector2<T> &lhs, T rhs) noexcept
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    return lhs;
}

template <typename T>
inline constexpr vector2<T> &operator /=(vector2<T> &lhs, const vector2<T> &rhs) noexcept
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    return lhs;
}

template <typename T>
inline constexpr vector2<T> &operator /=(vector2<T> &lhs, T rhs) noexcept
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}

template <typename T>
inline constexpr vector2<T> operator +(const vector2<T> &lhs, const vector2<T> &rhs) noexcept
{
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

template <typename T>
inline constexpr vector2<T> operator -(const vector2<T> &lhs, const vector2<T> &rhs) noexcept
{
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

template <typename T>
inline constexpr vector2<T> operator *(const vector2<T> &lhs, const vector2<T> &rhs) noexcept
{
    return {lhs.x * rhs.x, lhs.y * rhs.y};
}

template <typename T>
inline constexpr vector2<T> operator *(const vector2<T> &lhs, T rhs) noexcept
{
    return {lhs.x * rhs, lhs.y * rhs};
}

template <typename T>
inline constexpr vector2<T> operator *(T lhs, const vector2<T> &rhs) noexcept
{
    return {lhs * rhs.x, lhs * rhs.y};
}

template <typename T>
inline constexpr vector2<T> operator /(const vector2<T> &lhs, const vector2<T> &rhs) noexcept
{
    return {lhs.x / rhs.x, lhs.y / rhs.y};
}

template <typename T>
inline constexpr vector2<T> operator /(const vector2<T> &lhs, T rhs) noexcept
{
    return {lhs.x / rhs, lhs.y / rhs};
}

