#include "vector.hpp"

template <typename T>
constexpr mat4<T> operator *(const mat4<T> &lhs, const mat4<T> &rhs) noexcept
{
    mat4<T> result{};

    result[0] = (lhs[0] * rhs[0][0]) + (lhs[1] * rhs[0][1]) + (lhs[2] * rhs[0][2]) + (lhs[3] * rhs[0][3]);
    result[1] = (lhs[0] * rhs[1][0]) + (lhs[1] * rhs[1][1]) + (lhs[2] * rhs[1][2]) + (lhs[3] * rhs[1][3]);
    result[2] = (lhs[0] * rhs[2][0]) + (lhs[1] * rhs[2][1]) + (lhs[2] * rhs[2][2]) + (lhs[3] * rhs[2][3]);
    result[3] = (lhs[0] * rhs[3][0]) + (lhs[1] * rhs[3][1]) + (lhs[2] * rhs[3][2]) + (lhs[3] * rhs[3][3]);

    return result;
}

template <typename T>
constexpr vector4<T> operator *(const mat4<T> &lhs, const vector4<T> &rhs) noexcept
{
    return (lhs[0] * rhs.x) + (lhs[1] * rhs.y) + (lhs[2] * rhs.z) + (lhs[3] * rhs.w);
}

template <typename T>
constexpr vector3<T> operator*(const mat4<T>& lhs, const vector3<T>& rhs) noexcept
{
    return vector3<T>{
        lhs[0].x * rhs.x + lhs[1].x * rhs.y + lhs[2].x * rhs.z + lhs[3].x,
        lhs[0].y * rhs.x + lhs[1].y * rhs.y + lhs[2].y * rhs.z + lhs[3].y,
        lhs[0].z * rhs.x + lhs[1].z * rhs.y + lhs[2].z * rhs.z + lhs[3].z
    };
}



