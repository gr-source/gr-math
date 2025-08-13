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

template <typename L, typename R>
constexpr vector<L, 4> operator *(const vector<L, 4> &lhs, const R &rhs) noexcept
{
    return {lhs.x * L(rhs), lhs.y * L(rhs), lhs.z * L(rhs), lhs.w * L(rhs)};
}

template <typename L, typename R>
constexpr vector<R, 4> operator *(const L &lhs, const vector<R, 4> &rhs) noexcept
{
    return {R(lhs) * rhs.x, R(lhs) * rhs.y, R(lhs) * rhs.z, R(lhs) * rhs.w};
}

template <typename T>
constexpr vector<T, 4> operator /(const vector<T, 4> &lhs, const vector<T, 4> &rhs) noexcept
{
    return {lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w};
}

template <typename L, typename R>
constexpr vector<L, 4> operator /(const vector<L, 4> &lhs, const R &rhs) noexcept
{
    return {lhs.x / L(rhs), lhs.y / L(rhs), lhs.z / L(rhs), lhs.w / L(rhs)};
}



