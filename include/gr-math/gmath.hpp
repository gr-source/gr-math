#pragma once

#include <cmath>
#include <istream>
#include <ostream>
#include <iostream>

#include "boundbox.hpp"
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

    Quaternion euler(const Vector3& axis, f32 angle);

    Quaternion euler(const Vector3& axis);

    Quaternion slerp(const Quaternion& lhs, const Quaternion& rhs, f32 t);

    Vector3 eulerAngles(const Quaternion &lhs);

    Boundbox Encapsulate(const Boundbox& lhs, const Boundbox& rhs) noexcept;

    Vector3 Size(const Boundbox& b) noexcept;

    Vector3 Center(const Boundbox& b) noexcept;

    f32 Area(const Boundbox& b) noexcept;
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

inline Boundbox Math::Encapsulate(const Boundbox& lhs, const Boundbox& rhs) noexcept
{
    return {
        Math::min(lhs.min, rhs.min),
        Math::max(lhs.max, rhs.max)
    };
}

inline Vector3 Math::Size(const Boundbox &b) noexcept
{
    return b.max - b.min;
}

inline Vector3 Math::Center(const Boundbox &b) noexcept
{
    return (b.min + b.max) * 0.5f;
}

inline f32 Math::Area(const Boundbox &b) noexcept
{
    Vector3 size = Size(b);

    return 2.0f * (size.x * size.y + size.y * size.z + size.z * size.x);
}





