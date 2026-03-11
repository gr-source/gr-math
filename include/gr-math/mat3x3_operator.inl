#include "vector.hpp"

template <typename T>
inline constexpr mat<T, 3, 3> operator *(const mat<T, 3, 3> &lhs, const mat<T, 3, 3> &rhs) noexcept
{
    mat<T, 3, 3> result;
    result.col0 = (lhs.col0 * rhs.col0[0]) + (lhs.col1 * rhs.col0[1]) + (lhs.col2 * rhs.col0[2]);
    result.col1 = (lhs.col0 * rhs.col1[0]) + (lhs.col1 * rhs.col1[1]) + (lhs.col2 * rhs.col1[2]);
    result.col2 = (lhs.col0 * rhs.col2[0]) + (lhs.col1 * rhs.col2[1]) + (lhs.col2 * rhs.col2[2]);
    return result;
}


template <typename T>
inline constexpr vector<T, 3> operator *(const mat<T, 3, 3> &lhs, const vector<T, 3> &rhs) noexcept
{
    return (lhs.col0 * rhs.x) + (lhs.col1 * rhs.y) + (lhs.col2 * rhs.z);
}



