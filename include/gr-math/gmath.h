#pragma once

#include <cmath>
#include <istream>
#include <ostream>
#include <iostream>

#include "types.h"
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"

#include "matrix3x3.h"
#include "matrix4x4.h"

#include "quaternion.h"

namespace Math {
    /* converte graus para radianos */
    const vvalue rad(vvalue degrees);

    /* convert radianos para graus */
    const vvalue degree(vvalue rad);

    template <typename T>
    const T cross(const T& rhs, const T& lhs);

    template <typename T>
    const vvalue magnitude(const T& rhs);

    template <typename T>
    const vvalue dot(const T& rhs, const T& lhs);

    template <typename T>
    const T normalize(const T& rhs);

    template <typename T>
    const vvalue distance(const T& rhs, const T& lhs);

    template <typename T>
    const T min(const T& rhs, const T& lhs);

    template <typename T>
    const T max(const T& rhs, const T& lhs);

    template <typename T>
    const T mix(const T& rhs, const T& lhs, vvalue f);

    template <typename T>
    const T lerp(const T& rhs, const T& lhs, vvalue t);

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
};


