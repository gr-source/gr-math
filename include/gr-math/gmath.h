#pragma once

#include <cmath>
#include <istream>
#include <ostream>
#include <iostream>

#include "types.h"

#include "matrix3x3.h"
#include "matrix4x4.h"

#include "quaternion.h"

#include "vector2.h"
#include "vector3.h"
#include "vector4.h"

#include "gVector2.hpp"

#include "color.h"

namespace Math {
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
    const vvalue magnitude(const T& rhs);

    template <typename T>
    const vvalue dot(const T& rhs, const T& lhs);

    template <typename T>
    T normalize(T rhs);

    template <typename T>
    vvalue distance(const T& rhs, const T& lhs);

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

    /* perspectiva calcula a view com profundidade de um plano de fundo, ideal pra render 3d
    * @param far plano distante
    * @param near plano proximo
    */
    const Matrix4x4 perspective(vvalue fovy, vvalue aspect, vvalue far, vvalue near);

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
