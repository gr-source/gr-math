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

#include "color.hpp"
#include "rect.hpp"

namespace Math
{
    template <typename T>
    T rand(const T &max, const T &min) noexcept
    {
        return  (max - min) * (((T(std::rand())) / T(RAND_MAX))) + min;
    }

    /* converte graus para radianos */
    template <typename T>
    constexpr T rad(T degrees) noexcept
    {
        return degrees * (T(M_PI) / T(180));
    }

    /* convert radianos para graus */
    template <typename T>
    constexpr T degree(T rad) noexcept
    {
        return rad * (180.0f / M_PI);
    }

    template <typename T>
    T cross(const T& rhs, const T& lhs);

    template <typename T>
    float magnitude(const T &rhs);

    template <typename T>
    float dot(const T &lhs, const T& rhs);

    template <typename T>
    T normalize(T rhs);

    template <typename T>
    float distance(const T &lhs, const T &rhs);

    template <typename T>
    T min(T lhs, T rhs);

    template <typename T>
    T max(T lhs, T rhs);

    template <typename T>
    T mix(T lhs, T rhs, float f);

    template <typename T>
    T lerp(T lhs, T rhs, float t);

    template <typename T>
    T abs(const T& rhs);

    template <typename T, typename V>
    T translate(const V& vector);

    template <typename T>
    T rotate(const Quaternion& q);

    template <typename T, typename V>
    T scale(const V& vector);

    Matrix4x4 CreateTRS(const Vector3 &position, const Quaternion &rotate, const Vector3 &scale);

    /* perspectiva calcula a view com profundidade de um plano de fundo, ideal pra render 3d
    * @param far plano distante
    * @param near plano proximo
    */
    Matrix4x4 perspective(float fovy, float aspect, float near, float far);

    /* orthographic calcula a view sem fundo Ideal para render 2d
    * @param far plano distante
    * @param near plano proximo
    */
    Matrix4x4 orthographic(float left, float right, float bottom, float top, float near, float far);

    Matrix4x4 lookAt(const Vector3& eye, const Vector3& center, const Vector3& upward);

    /*********** Quaternion ***********/
    Quaternion Mat4ToQuat(const Matrix4x4& lhs);

    Quaternion lookRotation(const Vector3& forward, const Vector3& up);

    Quaternion euler(const Vector3& axis, float angle);

    Quaternion euler(const Vector3& axis);

    Quaternion slerp(const Quaternion& lhs, const Quaternion& rhs, float t);

    Vector3 eulerAngles(const Quaternion &lhs);
};
