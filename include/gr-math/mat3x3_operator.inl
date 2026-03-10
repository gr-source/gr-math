#include "vector3.hpp"


template <typename T>
inline constexpr mat<T, 3, 3> operator *(const mat<T, 3, 3> &lhs, const mat<T, 3, 3> &rhs) noexcept
{
    mat<T, 3, 3> result{};
    vector<T, 3> rowA0 = lhs.row0;
    vector<T, 3> rowA1 = lhs.row1;
    vector<T, 3> rowA2 = lhs.row2;

    vector<T, 3> rowB0 = rhs.row0;
    vector<T, 3> rowB1 = rhs.row1;
    vector<T, 3> rowB2 = rhs.row2;

    result[0] = rowA0 * rowB0[0] + rowA1 * rowB0[1] + rowA2 * rowB0[2];
    result[1] = rowA0 * rowB1[0] + rowA1 * rowB1[1] + rowA2 * rowB1[2];
    result[2] = rowA0 * rowB2[0] + rowA1 * rowB2[1] + rowA2 * rowB2[2];


    // result.row0 = (lhs.row0[0] * rhs.row0) + (lhs.row0[1] * rhs.row1) + (lhs.row0[2] * rhs.row2);
    // result.row1 = (lhs.row1[0] * rhs.row0) + (lhs.row1[1] * rhs.row1) + (lhs.row1[2] * rhs.row2);
    // result.row2 = (lhs.row2[0] * rhs.row0) + (lhs.row2[1] * rhs.row1) + (lhs.row2[2] * rhs.row2);

    return result;
}
