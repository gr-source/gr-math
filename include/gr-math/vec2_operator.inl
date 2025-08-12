#include "vector.hpp"

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

template <typename L, typename R>
constexpr vector<L, 2> operator *(const vector<L, 2> &lhs, R rhs) noexcept
{
    return {lhs.x * L(rhs), lhs.y * L(rhs)};
}

template <typename L, typename R>
constexpr vector<R, 2> operator *(L lhs, const vector<R, 2> &rhs) noexcept
{
    return {R(lhs) * rhs.x, R(lhs) * rhs.y};
}

template <typename T>
constexpr vector<T, 2> operator /(const vector<T, 2> &lhs, const vector<T, 2> &rhs) noexcept
{
    return {lhs.x / rhs.x, lhs.y / rhs.y};
}

template <typename L, typename R>
constexpr vector<L, 2> operator /(const vector<L, 2> &lhs, R rhs) noexcept
{
    return {lhs.x / L(rhs), lhs.y / L(rhs)};
}

