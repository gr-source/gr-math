#pragma once

#include <cmath>
#include <istream>
#include <ostream>
#include <iostream>

#include "types.hpp"

#include "matrix3x3.hpp"
#include "matrix4x4.hpp"

#include "quaternion.hpp"

#include "vector.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

#include "color.h"
#include "rect.h"

namespace Math
{
    template <typename T>
    T rand(const T &max, const T &min) noexcept;

    /* converte graus para radianos */
    template <typename T>
    constexpr T rad(T degrees) noexcept;

    /* convert radianos para graus */
    template <typename T>
    constexpr T degree(T rad) noexcept;

    template <typename T>
    T cross(const T& rhs, const T& lhs);

    template <typename T>
    f32 dot(const T &rhs, const T& lhs) noexcept;

    template <typename T>
    f32 magnitudeSqrt(const T &v) noexcept;

    template <typename T>
    f32 magnitude(const T &v) noexcept;

    template <typename T>
    T normalize(const T& v) noexcept;

    template <typename T>
    f32 distance(const T &lhs, const T &rhs);

    Vector3 min(const Vector3& rhs, const Vector3& lhs) noexcept;

    Vector3 max(const Vector3& rhs, const Vector3& lhs) noexcept;

    template <typename T>
    T mix(const T& rhs, const T& lhs, f32 f) noexcept;

    template <typename T>
    T lerp(const T& rhs, const T& lhs, f32 t) noexcept;

    template <typename T>
    T abs(const T& rhs);

    template <typename T, typename V>
    T translate(const V& vector);

    template <typename T>
    T rotate(const Quaternion& q) noexcept;

    template <typename T, typename V>
    T scale(const V& vector);

    Matrix4x4 CreateTRS(const Vector3 &position, const Quaternion &rotate, const Vector3 &scale);

    Matrix3x3 CreateTRS(const Vector2 &position, const Quaternion &rotate, const Vector2 &scale);

    /* perspectiva calcula a view com profundidade de um plano de fundo, ideal pra render 3d
    * @param far plano distante
    * @param near plano proximo
    */
    Matrix4x4 perspective(f32 fovy, f32 aspect, f32 near, f32 far);

    /* orthographic calcula a view sem fundo Ideal para render 2d
    * @param far plano distante
    * @param near plano proximo
    */
    Matrix4x4 orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far);

    Matrix4x4 lookAt(const Vector3& eye, const Vector3& center, const Vector3& upward);

    /*********** Quaternion ***********/
    Quaternion Mat4ToQuat(const Matrix4x4& lhs);

    Quaternion lookRotation(const Vector3& forward, const Vector3& up);

    Quaternion fromAxisAngle(const Vector3& axis, f32 angle);

    Quaternion euler(const Vector3& axis);

    Quaternion slerp(const Quaternion& lhs, const Quaternion& rhs, f32 t);

    Vector3 eulerAngles(const Quaternion &lhs);

    template <typename T>
    inline constexpr void mat4_decompose(const mat4<T>& _this, vector3<T>& scale, quaternion<T>& rotation, vector3<T>& position) noexcept
    {
        auto col0 = _this[0];
        auto col1 = _this[1];
        auto col2 = _this[2];
        auto col3 = _this[3];

        auto p = _this[3];

        position =
            { p.x, p.y, p.z };

        scale =
        {
            magnitude(col0),
            magnitude(col1),
            magnitude(col2)
        };

        col0 /= scale.x;
        col1 /= scale.y;
        col2 /= scale.z;


        Matrix4x4 m =
        {
            {
                {col0.x,   col1.x,   col2.x,   0.0f},
                {col0.y,   col1.y,   col2.y,   0.0f},
                {col0.z,   col1.z,   col2.z,   0.0f},
                {0.0f,     0.0f,     0.0f,     0.0f},
            }
        };
        /*m[0] = (*this)[0] / scale.x;*/
        /*m[1] = (*this)[0] / scale.y;*/
        /*m[2] = (*this)[0] / scale.z;*/

        rotation = normalize(Mat4ToQuat(m));
    }
};

template <typename T>
inline T Math::rand(const T &max, const T &min) noexcept
{
    return  (max - min) * (((T(std::rand())) / T(RAND_MAX))) + min;
}

template <typename T>
inline constexpr T Math::rad(T degrees) noexcept
{
    return degrees * (T(M_PI) / T(180));
}

template <typename T>
inline constexpr T Math::degree(T rad) noexcept
{
    return rad * (180.0f / M_PI);
}

// mag
template <typename V>
inline f32 Math::magnitudeSqrt(const V& v) noexcept
{
    return dot(v, v);
}

template <typename V>
inline f32 Math::magnitude(const V& v) noexcept
{
    return std::sqrtf(magnitudeSqrt(v));
}

template <typename T>
inline T Math::mix(const T& rhs, const T& lhs, f32 f) noexcept
{
    return (1.0f - f) * rhs + f * lhs;
}

template <typename T>
inline T Math::lerp(const T& rhs, const T& lhs, f32 t) noexcept
{
    return lhs + (rhs - lhs) * t;
}






