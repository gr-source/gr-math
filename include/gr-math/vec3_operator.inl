#include "vector.hpp"

template <typename T>
constexpr vector<T, 3> &operator +=(vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    return lhs;
}

template <typename T>
constexpr vector<T, 3> &operator +=(vector<T, 3> &lhs, T rhs) noexcept
{
    lhs.x += rhs;
    lhs.y += rhs;
    lhs.z += rhs;
    return lhs;
}

template <typename T>
constexpr vector<T, 3> &operator -=(vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    return lhs;
}

template <typename T>
constexpr vector<T, 3> &operator -=(vector<T, 3> &lhs, T rhs) noexcept
{
    lhs.x -= rhs;
    lhs.y -= rhs;
    lhs.z -= rhs;
    return lhs;
}

template <typename T>
constexpr vector<T, 3> &operator *=(vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    return lhs;
}

template <typename T>
constexpr vector<T, 3> &operator *=(vector<T, 3> &lhs, T rhs) noexcept
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    return lhs;
}

template <typename T>
constexpr vector<T, 3> &operator /=(vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;
    return lhs;
}

template <typename T>
constexpr vector<T, 3> &operator /=(vector<T, 3> &lhs, T rhs) noexcept
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    return lhs;
}

template <typename T>
constexpr vector<T, 3> operator +(const vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

template <typename T>
constexpr vector<T, 3> operator -(const vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

template <typename T>
constexpr vector<T, 3> operator *(const vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    return {lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
}

template <typename L, typename R>
constexpr vector<L, 3> operator *(const vector<L, 3> &lhs, const R &rhs) noexcept
{
    return {lhs.x * L(rhs), lhs.y * L(rhs), lhs.z * L(rhs)};
}

template <typename L, typename R>
constexpr vector<R, 3> operator *(const L &lhs, const vector<R, 3> &rhs) noexcept
{
    return {R(lhs) * rhs.x, R(lhs) * rhs.y, R(lhs) * rhs.z};
}

template <typename T>
constexpr vector<T, 3> operator /(const vector<T, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
}

template <typename L, typename R>
constexpr vector<L, 3> operator /(const vector<L, 3> &lhs, const R &rhs) noexcept
{
    return {lhs.x / L(rhs), lhs.y / L(rhs), lhs.z / L(rhs)};
}



