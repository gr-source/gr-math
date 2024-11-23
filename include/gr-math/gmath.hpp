#pragma once

#include <cmath>
#include <istream>
#include <ostream>
#include <iostream>

#include "types.hpp"

#include "matrix3x3.hpp"
#include "matrix4x4.hpp"

#include "quaternion.hpp"

#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

#include "gVector2.hpp"

#include "color.hpp"

namespace Math {
    template <typename T>
    T rand(T max, T min);

    /* converte graus para radianos */
    template <typename T>
    inline T rad(T degrees) {
        return degrees * (M_PI / 180.0f);
    }

    /* convert radianos para graus */
    template <typename T>
    inline T degree(T rad) {
        return rad * (180.0f / M_PI);
    }

    template <typename T>
    const T cross(const T& rhs, const T& lhs);

    template <typename T>
    vvalue magnitude(const T &rhs);

    template <typename T>
    vvalue dot(const T &lhs, const T& rhs);

    template <typename T>
    T normalize(T rhs);

    template <typename T>
    vvalue distance(const T &lhs, const T &rhs);

    template <typename T>
    T min(T lhs, T rhs);

    template <typename T>
    T max(T lhs, T rhs);

    template <typename T>
    T mix(const T &lhs, const T &rhs, vvalue f);

    template <typename T>
    T lerp(T lhs, T rhs, vvalue t);

    template <typename T>
    const T abs(const T& rhs);

    template <typename T, typename V>
    const T translate(const V& vector);

    template <typename T>
    const T rotate(const Quaternion& q);

    template <typename T, typename V>
    const T scale(const V& vector);

    Matrix4x4 CreateTRS(const Vector3 &scale, const Quaternion &rotate, const Vector3 &position);

    /* perspectiva calcula a view com profundidade de um plano de fundo, ideal pra render 3d
    * @param far plano distante
    * @param near plano proximo
    */
    const Matrix4x4 perspective(vvalue fovy, vvalue aspect, vvalue near, vvalue far);

    /* orthographic calcula a view sem fundo Ideal para render 2d
    * @param far plano distante
    * @param near plano proximo
    */
    const Matrix4x4 orthographic(vvalue left, vvalue right, vvalue bottom, vvalue top, vvalue near, vvalue far);

    const Matrix4x4 lookAt(const Vector3& eye, const Vector3& center, const Vector3& upward);

    /*********** Quaternion ***********/
    const Quaternion Mat4ToQuat(const Matrix4x4& lhs);

    const Quaternion lookRotation(const Vector3& forward, const Vector3& up);

    const Quaternion euler(const Vector3& axis, vvalue angle);

    const Quaternion euler(const Vector3& axis);

    const Quaternion slerp(const Quaternion& lhs, const Quaternion& rhs, vvalue t);

    const Vector3 eulerAngles(const Quaternion &lhs);
};
