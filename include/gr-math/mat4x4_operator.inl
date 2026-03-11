#include "vector.hpp"


template <typename T>
inline constexpr mat<T, 4, 4> operator *(const mat<T, 4, 4> &lhs, const mat<T, 4, 4> &rhs) noexcept
{
    mat<T, 4, 4> result{};

    result.col0 = (lhs.col0 * rhs.col0[0]) + (lhs.col1 * rhs.col0[1]) + (lhs.col2 * rhs.col0[2]) + (lhs.col3 * rhs.col0[3]);
    result.col1 = (lhs.col0 * rhs.col1[0]) + (lhs.col1 * rhs.col1[1]) + (lhs.col2 * rhs.col1[2]) + (lhs.col3 * rhs.col1[3]);
    result.col2 = (lhs.col0 * rhs.col2[0]) + (lhs.col1 * rhs.col2[1]) + (lhs.col2 * rhs.col2[2]) + (lhs.col3 * rhs.col2[3]);
    result.col3 = (lhs.col0 * rhs.col3[0]) + (lhs.col1 * rhs.col3[1]) + (lhs.col2 * rhs.col3[2]) + (lhs.col3 * rhs.col3[3]);

    return result;
}

template <typename T>
inline constexpr vector<T, 4> operator *(const mat<T, 4, 4> &lhs, const vector<T, 4> &rhs) noexcept
{
    return (lhs.col0 * rhs.x) + (lhs.col1 * rhs.y) + (lhs.col2 * rhs.z) + (lhs.col3 * rhs.w);
}



