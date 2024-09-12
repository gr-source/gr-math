#include "gmath.h"

/* ========== cross ========== */
template <>
const Vector3 Math::cross(const Vector3& rhs, const Vector3& lhs) {
    return {
        (rhs.y * lhs.z) - (rhs.z * lhs.y),
        (rhs.z * lhs.x) - (rhs.x * lhs.z),
        (rhs.x * lhs.y) - (rhs.y * lhs.x)
    };
}

/* ========== magnitude ========== */
template <>
vvalue Math::magnitude(const Vector2 &rhs) {
    return std::sqrt((rhs.x * rhs.x) + (rhs.y * rhs.y));
}

template <>
vvalue Math::magnitude(const Vector3 &rhs) {
    return std::sqrt((rhs.x * rhs.x) + (rhs.y * rhs.y) + (rhs.z * rhs.z));
}

template <>
vvalue Math::magnitude(const Vector4 &rhs) {
    return std::sqrt((rhs.x * rhs.x) + (rhs.y * rhs.y) + (rhs.z * rhs.z) + (rhs.w * rhs.w));
}

template <>
vvalue Math::magnitude(const Quaternion &rhs) {
    return std::sqrt((rhs.w * rhs.w) + (rhs.x * rhs.x) + (rhs.y * rhs.y) + (rhs.z * rhs.z));
}

/* ========== dot product ========== */
template <>
vvalue Math::dot(const Vector2 &lhs, const Vector2 &rhs) {
    return (lhs.x * rhs.x) + (lhs.y * rhs.y);
}

template <>
vvalue Math::dot(const Vector3 &lhs, const Vector3 &rhs) {
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

template <>
vvalue Math::dot(const Vector4 &lhs, const Vector4 &rhs) {
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w);
}

template <>
vvalue Math::dot(const Quaternion &lhs, const Quaternion &rhs) {
    return (lhs.w * rhs.w) + (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

/* ========== normalize ========== */
template <>
Vector2 Math::normalize(Vector2 rhs) {
    vvalue mag = magnitude(rhs);

    return mag > 1e-5f ? rhs / mag : Vector2::zero;
}

template <>
Vector3 Math::normalize(Vector3 rhs) {
    vvalue mag = magnitude(rhs);

    return mag > 1e-5f ? rhs / mag : Vector3::zero;
}

template <>
Vector4 Math::normalize(Vector4 rhs) {
    vvalue mag = magnitude(rhs);

    return mag > 1e-5f ? rhs / mag : Vector4::zero;
}

template <>
Quaternion Math::normalize(Quaternion rhs) {
    vvalue mag = magnitude(rhs);
    
    return mag > 1e-5f ? rhs / mag : Quaternion::identity;
}

/* ========== distance ========== */
template <>
vvalue Math::distance(const Vector3& lhs, const Vector3& rhs) {
    return magnitude(rhs - lhs);
}

/* ========== min ========== */
template <>
Vector3 Math::min(Vector3 lhs, Vector3 rhs) {
    return {
        rhs.x < lhs.x ? rhs.x : lhs.x,
        rhs.y < lhs.y ? rhs.y : lhs.y,
        rhs.z < lhs.z ? rhs.z : lhs.z
    };
}

/* ========== max ========== */
template <>
Vector3 Math::max(Vector3 lhs, Vector3 rhs) {
    return {
        lhs.x < rhs.x ? rhs.x : lhs.x,
        lhs.y < rhs.y ? rhs.y : lhs.y,
        lhs.z < rhs.z ? rhs.z : lhs.z
    };
}

/* ========== mix ========== */
template <>
Vector3 Math::mix(const Vector3 &lhs, const Vector3 &rhs, vvalue f) {
    return (1.0f - f) * rhs + f * lhs;
}

/* ========== lerp ========== */
template <>
vvalue Math::lerp(vvalue lhs, vvalue rhs, vvalue t) {
    return rhs + (lhs - rhs) * t;
}

template <>
Vector3 Math::lerp(Vector3 lhs, Vector3 rhs, vvalue t) {
    return rhs + (lhs - rhs) * t;
}

/* ========== abs ========== */
template <>
const Vector3 Math::abs(const Vector3& rhs) {
    return {std::abs(rhs.x), std::abs(rhs.y), std::abs(rhs.z)};
}

/* ========== Matrix ========== */
template <>
const Matrix4x4 Math::translate(const Vector3& vector) {
    Matrix4x4 result = Matrix4x4::identityMatrix;

    result.m30 = vector.x;
    result.m31 = vector.y;
    result.m32 = vector.z;

    return result;
}

template <>
const Matrix3x3 Math::translate(const Vector2& vector) {
    Matrix3x3 result = Matrix3x3::identityMatrix;

    result.m20 = vector.x;
    result.m21 = vector.y;

    return result;
}

template <>
const Matrix4x4 Math::rotate(const Quaternion& q) {
    Matrix4x4 result = Matrix4x4::identityMatrix;

    result.m00 = 1.0f - 2.0f * ((q.y * q.y) + (q.z * q.z));
    result.m01 = 2.0f * ((q.x * q.y) + (q.z * q.w));
    result.m02 = 2.0f * ((q.x * q.z) - (q.y * q.w));

    result.m10 = 2.0f * ((q.x * q.y) - (q.z * q.w));
    result.m11 = 1.0f - 2.0f * ((q.x * q.x) + (q.z * q.z));
    result.m12 = 2.0f * ((q.y * q.z) + (q.x * q.w));

    result.m20 = 2.0f * ((q.x * q.z) + (q.y * q.w));
    result.m21 = 2.0f * ((q.y * q.z) - (q.x * q.w));
    result.m22 = 1.0f - 2.0f * ((q.x * q.x) + (q.y * q.y));

    return result;
}

template <>
const Matrix3x3 Math::rotate(const Quaternion& q) {
    Matrix3x3 result = Matrix3x3::identityMatrix;
    
    result.m00 = 1.0f - 2.0f * ((q.y * q.y) + (q.z * q.z));
    result.m01 = 2.0f * ((q.x * q.y) + (q.z * q.w));

    result.m10 = 2.0f * ((q.x * q.y) - (q.z * q.w));
    result.m11 = 1.0f - 2.0f * ((q.x * q.x) + (q.z * q.z));
    return result;
}

template <>
const Matrix4x4 Math::scale(const Vector3& vector) {
    Matrix4x4 result = Matrix4x4::identityMatrix;

    result.m00 = vector.x;
    result.m11 = vector.y;
    result.m22 = vector.z;

    return result;
}

template <>
const Matrix3x3 Math::scale(const Vector2& vector) {
    Matrix3x3 result = Matrix3x3::identityMatrix;

    result.m00 = vector.x;
    result.m11 = vector.y;

    return result;
}

Matrix4x4 Math::CreateTRS(const Vector3 &scale, const Quaternion &rotate, const Vector3 &position) {
    Matrix4x4 result = Matrix4x4::identityMatrix;

    // translate
    result.m30 = position.x;
    result.m31 = position.y;
    result.m32 = position.z;

    //rotate
    result.m00 = 1.0f - 2.0f * ((rotate.y * rotate.y) + (rotate.z * rotate.z));
    result.m01 = 2.0f * ((rotate.x * rotate.y) + (rotate.z * rotate.w));
    result.m02 = 2.0f * ((rotate.x * rotate.z) - (rotate.y * rotate.w));

    result.m10 = 2.0f * ((rotate.x * rotate.y) - (rotate.z * rotate.w));
    result.m11 = 1.0f - 2.0f * ((rotate.x * rotate.x) + (rotate.z * rotate.z));
    result.m12 = 2.0f * ((rotate.y * rotate.z) + (rotate.x * rotate.w));

    result.m20 = 2.0f * ((rotate.x * rotate.z) + (rotate.y * rotate.w));
    result.m21 = 2.0f * ((rotate.y * rotate.z) - (rotate.x * rotate.w));
    result.m22 = 1.0f - 2.0f * ((rotate.x * rotate.x) + (rotate.y * rotate.y));

    // scale
    result.m00 *= scale.x;
    result.m01 *= scale.x;
    result.m02 *= scale.x;

    result.m10 *= scale.y;
    result.m11 *= scale.y;
    result.m12 *= scale.y;

    result.m20 *= scale.z;
    result.m21 *= scale.z;
    result.m22 *= scale.z;

    return result;
}

const Matrix4x4 Math::perspective(vvalue fovy, vvalue aspect, vvalue far, vvalue near) {
    vvalue tanHalfFovy = std::tan(fovy / 2.0f);
    
    Matrix4x4 result = Matrix4x4::zeroMatrix;

    result.m00 = 1.0f / (aspect * tanHalfFovy);
    result.m11 = 1.0f / tanHalfFovy;
    result.m22 = -((far + near) / (far - near));

    result.m23 = -1.0f;

    result.m32 = -(2.0f * (far * near) / (far - near));

    return result;
}

const Matrix4x4 Math::orthographic(vvalue left, vvalue right, vvalue bottom, vvalue top, vvalue near, vvalue far) {
    Matrix4x4 result = Matrix4x4::identityMatrix;

    result.m00 =  2.0f / (right - left);
    result.m11 =  2.0f / (top   - bottom);
    result.m22 = -2.0f / (far   - near);

    result.m30 = -((right + left)   / (right - left));
    result.m31 = -((top   + bottom) / (top   - bottom));
    result.m32 = -((far   + near)   / (far   - near));

    return result;
}

const Matrix4x4 Math::lookAt(const Vector3& eye, const Vector3& center, const Vector3& upward) {
    const Vector3 forward = Math::normalize(center - eye);
    const Vector3 right = Math::normalize(Math::cross(forward, upward));
    const Vector3 up = Math::cross(right, forward);

    Matrix4x4 result = Matrix4x4::identityMatrix;
    result.m00 = right.x;
    result.m10 = right.y;
    result.m20 = right.z;
    
    result.m01 = up.x;
    result.m11 = up.y;
    result.m21 = up.z;

    result.m02 = -forward.x;
    result.m12 = -forward.y;
    result.m22 = -forward.z;

    result.m30 = -Math::dot(right, eye);
    result.m31 = -Math::dot(up, eye);
    result.m32 =  Math::dot(forward, eye);

    return result;
}

/*********** Quaternion ***********/
const Quaternion Math::Mat4ToQuat(const Matrix4x4 &lhs) {
    vvalue trace = lhs.m00 + lhs.m11 + lhs.m22;

    Quaternion q;

    if (trace > 0) {
        vvalue s = std::sqrt(trace + 1.0f) * 2.0f;
        q.w = 0.25f * s;
        q.x = (lhs.m21 - lhs.m12) / s;
        q.y = (lhs.m02 - lhs.m20) / s;
        q.z = (lhs.m10 - lhs.m01) / s;
    } else if ((lhs.m00 > lhs.m11) && (lhs.m00 > lhs.m22)) {
        vvalue s = std::sqrt(1.0f + lhs.m00 - lhs.m11 - lhs.m22) * 2.0f;
        q.w = (lhs.m21 - lhs.m12) / s;
        q.x = 0.25f * s;
        q.y = (lhs.m01 + lhs.m10) / s;
        q.z = (lhs.m02 + lhs.m20) / s;
    } else if (lhs.m11 > lhs.m22) {
        vvalue s = std::sqrt(1.0f + lhs.m11 - lhs.m00 - lhs.m22) * 2.0f;
        q.w = (lhs.m02 - lhs.m20) / s;
        q.x = (lhs.m01 + lhs.m10) / s;
        q.y = 0.25f * s;
        q.z = (lhs.m12 + lhs.m21) / s;
    } else {
        vvalue s = std::sqrt(1.0f + lhs.m22 - lhs.m00 - lhs.m11) * 2.0f;
        q.w = (lhs.m10 - lhs.m01) / s;
        q.x = (lhs.m02 + lhs.m20) / s;
        q.y = (lhs.m12 + lhs.m21) / s;
        q.z = 0.25f * s;
    }
    return q;
}

const Quaternion Math::lookRotation(const Vector3& forward, const Vector3& up) {
    const Vector3 right = Math::normalize(Math::cross(forward, up));
    const Vector3 upward = Math::normalize(Math::cross(right, forward));

    vvalue m00 = right.x;
    vvalue m10 = right.y;
    vvalue m20 = right.z;

    vvalue m01 = upward.x;
    vvalue m11 = upward.y;
    vvalue m21 = upward.z;

    vvalue m02 = -forward.x;
    vvalue m12 = -forward.y;
    vvalue m22 = -forward.z;

    vvalue trace = m00 + m11 + m22;

    return Mat4ToQuat({
        m00,  m01,  m02,  0.0f,
        m10,  m11,  m12,  0.0f,
        m20,  m21,  m22,  0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    });
}

const Quaternion Math::euler(const Vector3& axis, vvalue angle) {
    Quaternion result;
    result.w = std::cos(angle / 2.0f);
    result.x = std::sin(angle / 2.0f) * axis.x;
    result.y = std::sin(angle / 2.0f) * axis.y;
    result.z = std::sin(angle / 2.0f) * axis.z;
    return result;
}

const Quaternion Math::euler(const Vector3& axis) {
    Quaternion result;

    // Roll
    vvalue cr = std::cos(axis.x * 0.5f);
    vvalue sr = std::sin(axis.x * 0.5f);

    // Pitch
    vvalue cp = std::cos(axis.y * 0.5f);
    vvalue sp = std::sin(axis.y * 0.5f);

    // Yaw
    vvalue cy = std::cos(axis.z * 0.5f);
    vvalue sy = std::sin(axis.z * 0.5f);

    result.w = cr * cp * cy + sr * sp * sy;
    result.x = sr * cp * cy - cr * sp * sy;
    result.y = cr * sp * cy + sr * cp * sy;
    result.z = cr * cp * sy - sr * sp * cy;

    return result;
}

const Quaternion Math::slerp(const Quaternion& lhs, const Quaternion& rhs, vvalue t) {
	Quaternion result = lhs;
	float c = Math::dot(lhs, rhs);
	if (c < 0.0f) {
		c = -c;
		result = -result;
	}
    
	float phi = std::cos(c);
	if (phi > 0.001f) {
		float s = std::sin(phi);
		return result * (std::sin((1.0f - t) * phi) / s) + rhs * (std::sin(t * phi) / s);
	}
	return result;
}

const Vector3 Math::eulerAngles(const Quaternion &lhs) {
    Vector3 angles;

    // Roll (x-axis rotation)
    float sinr_cosp = 2.0f * ((lhs.w * lhs.x) + (lhs.y * lhs.z));
    float cosr_cosp = 1.0f - 2.0f * ((lhs.x * lhs.x) + (lhs.y * lhs.y));
    angles.x = Math::degree(std::atan2(sinr_cosp, cosr_cosp));

    // Falta corrigir, mas não achei nenhuma referencia

    // pitch (y-axis rotation)
    float sinp = std::sqrt(1.0f + 2.0f * ((lhs.w * lhs.y) - (lhs.x * lhs.z)));
    float cosp = std::sqrt(1.0f - 2.0f * ((lhs.w * lhs.y) - (lhs.x * lhs.z)));
    angles.y = Math::degree(-M_PI / 2.0f + 2.0f * std::atan2(sinp, cosp));

    // yaw (z-axis rotation)
    float siny_cosp = 2.0f * ((lhs.w * lhs.z) + (lhs.x * lhs.y));
    float cosy_cosp = 1.0f - 2.0f * ((lhs.y * lhs.y) + (lhs.z * lhs.z));
    angles.z = Math::degree(std::atan2(siny_cosp, cosy_cosp));

    return angles;
}


