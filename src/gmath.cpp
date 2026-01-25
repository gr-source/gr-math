#include "gmath.hpp"
#include "matrix4x4.hpp"
#include "quaternion.hpp"
#include "types.hpp"
#include "vector3.hpp"
#include "vector2.hpp"

/* ========== cross ========== */
template <>
Vector3 Math::cross(const Vector3& rhs, const Vector3& lhs) {
    return {
        (rhs.y * lhs.z) - (rhs.z * lhs.y),
        (rhs.z * lhs.x) - (rhs.x * lhs.z),
        (rhs.x * lhs.y) - (rhs.y * lhs.x)
    };
}

/* ========== magnitude ========== */
template <>
f32 Math::magnitude(const Vector2 &rhs)
{
    return std::sqrt((rhs.x * rhs.x) + (rhs.y * rhs.y));
}

template <>
f32 Math::magnitude(const Vector3 &rhs)
{
    return std::sqrt((rhs.x * rhs.x) + (rhs.y * rhs.y) + (rhs.z * rhs.z));
}

template <>
f32 Math::magnitude(const Vector4 &rhs)
{
    return std::sqrt((rhs.x * rhs.x) + (rhs.y * rhs.y) + (rhs.z * rhs.z) + (rhs.w * rhs.w));
}

template <>
f32 Math::magnitude(const Quaternion &rhs)
{
    return std::sqrt((rhs.w * rhs.w) + (rhs.x * rhs.x) + (rhs.y * rhs.y) + (rhs.z * rhs.z));
}

/* ========== dot product ========== */
template <>
f32 Math::dot(const Vector2 &rhs, const Vector2 &lhs) noexcept
{
    return rhs.x * lhs.x + rhs.y * lhs.y;
}

template <>
f32 Math::dot(const Vector3 &rhs, const Vector3 &lhs) noexcept
{
    return rhs.x * lhs.x + rhs.y * lhs.y + rhs.z * lhs.z;
}

template <>
f32 Math::dot(const Vector4 &rhs, const Vector4 &lhs) noexcept
{
    return rhs.x * lhs.x + rhs.y * lhs.y + rhs.z * lhs.z + rhs.w * lhs.w;
}

template <>
f32 Math::dot(const Quaternion &rhs, const Quaternion &lhs) noexcept
{
    return rhs.w * lhs.w + rhs.x * lhs.x + rhs.y * lhs.y + rhs.z * lhs.z;
}

/* ========== normalize ========== */
template <>
Vector2 Math::normalize(const Vector2& rhs) noexcept
{
    f32 mag = magnitude(rhs);

    return mag > 1e-5f ? rhs / mag : Vector2::zero;
}

template <>
Vector3 Math::normalize(const Vector3& v) noexcept
{
    f32 magSq = dot(v, v);
    if (magSq > 1e-10f)
    {
        f32 invMag = 1.0f / std::sqrt(magSq);
        return v * invMag;
    }
    return Vector3::zero;
}

template <>
Vector4 Math::normalize(const Vector4& rhs) noexcept
{
    f32 mag = magnitude(rhs);

    return mag > 1e-5f ? rhs / mag : Vector4::zero;
}

template <>
Quaternion Math::normalize(const Quaternion& v) noexcept
{
    f32 magSq = dot(v, v);
    if (magSq > 1e-10f)
    {
        f32 invMag = 1.0f / std::sqrt(magSq);
        return v * invMag;
    }
    return Quaternion::identity;
}

/* ========== distance ========== */
template <>
f32 Math::distance(const Vector3& lhs, const Vector3& rhs) {
    return magnitude(rhs - lhs);
}

/* ========== min ========== */
template <>
Vector3 Math::min(const Vector3& rhs, const Vector3& lhs) noexcept
{
    return {
        rhs.x < lhs.x ? rhs.x : lhs.x,
        rhs.y < lhs.y ? rhs.y : lhs.y,
        rhs.z < lhs.z ? rhs.z : lhs.z
    };
}

/* ========== max ========== */
template <>
Vector3 Math::max(const Vector3& rhs, const Vector3& lhs) noexcept
{
    return {
        rhs.x > lhs.x ? rhs.x : lhs.x,
        rhs.y > lhs.y ? rhs.y : lhs.y,
        rhs.z > lhs.z ? rhs.z : lhs.z
    };
}

/* ========== abs ========== */
template <>
Vector3 Math::abs(const Vector3& rhs) {
    return {std::abs(rhs.x), std::abs(rhs.y), std::abs(rhs.z)};
}

/* ========== Matrix ========== */
template <>
Matrix4x4 Math::translate(const Vector3& vector) {
    Matrix4x4 result = Matrix4x4::identityMatrix;

    result[3][0] = vector.x;
    result[3][1] = vector.y;
    result[3][2] = vector.z;

    return result;
}

template <>
Matrix3x3 Math::translate(const Vector2& vector) {
    Matrix3x3 result = Matrix3x3::identityMatrix;

    result[2][0] = vector.x;
    result[2][1] = vector.y;

    return result;
}

template <>
Matrix4x4 Math::rotate(const Quaternion& rotate) noexcept
{
    Matrix4x4 result = Matrix4x4::identityMatrix;

    f32 xx = rotate.x * rotate.x;
    f32 yy = rotate.y * rotate.y;
    f32 zz = rotate.z * rotate.z;

    f32 xy = rotate.x * rotate.y;
    f32 xz = rotate.x * rotate.z;
    f32 xw = rotate.x * rotate.w;

    f32 yw = rotate.y * rotate.w;
    f32 yz = rotate.y * rotate.z;

    f32 zw = rotate.z * rotate.w;

    result[0][0] = (1.0f - 2.0f * (yy + zz));
    result[0][1] = (2.0f * (xy + zw));
    result[0][2] = (2.0f * (xz - yw));
    result[0][3] = 0.0f;

    result[1][0] = (2.0f * (xy - zw));
    result[1][1] = (1.0f - 2.0f * (xx + zz));
    result[1][2] = (2.0f * (yz + xw));
    result[1][3] = 0.0f;

    result[2][0] = (2.0f * (xz + yw));
    result[2][1] = (2.0f * (yz - xw));
    result[2][2] = (1.0f - 2.0f * (xx + yy));
    result[2][3] = 0.0f;

    return result;
}

template <>
Matrix3x3 Math::rotate(const Quaternion& q) noexcept
{
    Matrix3x3 result = Matrix3x3::identityMatrix;
    
    result[0][0] = 1.0f - 2.0f * ((q.y * q.y) + (q.z * q.z));
    result[0][1] = 2.0f * ((q.x * q.y) + (q.z * q.w));

    result[1][0] = 2.0f * ((q.x * q.y) - (q.z * q.w));
    result[1][1] = 1.0f - 2.0f * ((q.x * q.x) + (q.z * q.z));
    return result;
}

template <>
Matrix4x4 Math::scale(const Vector3& vector) {
    Matrix4x4 result = Matrix4x4::identityMatrix;

    result[0][0] = vector.x;
    result[1][1] = vector.y;
    result[2][2] = vector.z;

    return result;
}

template <>
Matrix3x3 Math::scale(const Vector2& vector) {
    Matrix3x3 result = Matrix3x3::identityMatrix;

    result[0][0] = vector.x;
    result[1][1] = vector.y;

    return result;
}

Matrix4x4 Math::CreateTRS(const Vector3 &position, const Quaternion &rotate, const Vector3 &scale)
{
    Matrix4x4 result = Matrix4x4::identityMatrix;

    f32 xx = rotate.x * rotate.x;
    f32 yy = rotate.y * rotate.y;
    f32 zz = rotate.z * rotate.z;

    f32 xy = rotate.x * rotate.y;
    f32 xz = rotate.x * rotate.z;
    f32 xw = rotate.x * rotate.w;

    f32 yw = rotate.y * rotate.w;
    f32 yz = rotate.y * rotate.z;

    f32 zw = rotate.z * rotate.w;

    result[0][0] = (1.0f - 2.0f * (yy + zz)) * scale.x;
    result[0][1] = (2.0f * (xy + zw)) * scale.x;
    result[0][2] = (2.0f * (xz - yw)) * scale.x;
    result[0][3] = 0.0f;

    result[1][0] = (2.0f * (xy - zw)) * scale.y;
    result[1][1] = (1.0f - 2.0f * (xx + zz)) * scale.y;
    result[1][2] = (2.0f * (yz + xw)) * scale.y;
    result[1][3] = 0.0f;

    result[2][0] = (2.0f * (xz + yw)) * scale.z;
    result[2][1] = (2.0f * (yz - xw)) * scale.z;
    result[2][2] = (1.0f - 2.0f * (xx + yy)) * scale.z;
    result[2][3] = 0.0f;

    result[3][0] = position.x;
    result[3][1] = position.y;
    result[3][2] = position.z;
    result[3][3] = 1.0f;

    return result;
}

Matrix4x4 Math::perspective(f32 fovy, f32 aspect, f32 near, f32 far)
{
    f32 tanHalfFovy = std::tan(fovy / 2.0f);
    
    Matrix4x4 result = Matrix4x4::zeroMatrix;

    result[0][0] = 1.0f / (aspect * tanHalfFovy);
    result[1][1] = 1.0f / tanHalfFovy;
    result[2][2] = -((far + near) / (far - near));

    result[2][3] = -1.0f;

    result[3][2] = -(2.0f * (far * near) / (far - near));

    return result;
}

Matrix4x4 Math::orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far) {
    Matrix4x4 result = Matrix4x4::identityMatrix;

    result[0][0] =  2.0f / (right - left);
    result[1][1] =  2.0f / (top   - bottom);
    result[2][2] = -2.0f / (far   - near);

    result[3][0] = -((right + left)   / (right - left));
    result[3][1] = -((top   + bottom) / (top   - bottom));
    result[3][2] = -((far   + near)   / (far   - near));

    return result;
}

Matrix4x4 Math::lookAt(const Vector3& eye, const Vector3& center, const Vector3& upward) {
    auto forward = Math::normalize(center - eye);
    auto right = Math::normalize(Math::cross(forward, upward));
    auto up = Math::cross(right, forward);

    Matrix4x4 result = Matrix4x4::identityMatrix;
    result[0][0] = right.x;
    result[1][0] = right.y;
    result[2][0] = right.z;
    
    result[0][1] = up.x;
    result[1][1] = up.y;
    result[2][1] = up.z;

    result[0][2] = -forward.x;
    result[1][2] = -forward.y;
    result[2][2] = -forward.z;

    result[3][0] = -Math::dot(right, eye);
    result[3][1] = -Math::dot(up, eye);
    result[3][2] =  Math::dot(forward, eye);

    return result;
}

/*********** Quaternion ***********/
Quaternion Math::Mat4ToQuat(const Matrix4x4 &lhs) {
    f32 trace = lhs[0][0] + lhs[1][1] + lhs[2][2];

    Quaternion q = Quaternion::identity;

    if (trace > 0) {
        f32 s = std::sqrt(trace + 1.0f) * 2.0f;
        q.w = 0.25f * s;
        q.x = (lhs[2][1] - lhs[1][2]) / s;
        q.y = (lhs[0][2] - lhs[2][0]) / s;
        q.z = (lhs[1][0] - lhs[0][1]) / s;
    } else if ((lhs[0][0] > lhs[1][1]) && (lhs[0][0] > lhs[2][2])) {
        f32 s = std::sqrt(1.0f + lhs[0][0] - lhs[1][1] - lhs[2][2]) * 2.0f;
        q.w = (lhs[2][1] - lhs[1][2]) / s;
        q.x = 0.25f * s;
        q.y = (lhs[0][1] + lhs[1][0]) / s;
        q.z = (lhs[0][2] + lhs[2][0]) / s;
    } else if (lhs[1][1] > lhs[2][2]) {
        f32 s = std::sqrt(1.0f + lhs[1][1] - lhs[0][0] - lhs[2][2]) * 2.0f;
        q.w = (lhs[0][2] - lhs[2][0]) / s;
        q.x = (lhs[0][1] + lhs[1][0]) / s;
        q.y = 0.25f * s;
        q.z = (lhs[1][2] + lhs[2][1]) / s;
    } else {
        f32 s = std::sqrt(1.0f + lhs[2][2] - lhs[0][0] - lhs[1][1]) * 2.0f;
        q.w = (lhs[1][0] - lhs[0][1]) / s;
        q.x = (lhs[0][2] + lhs[2][0]) / s;
        q.y = (lhs[1][2] + lhs[2][1]) / s;
        q.z = 0.25f * s;
    }
    return q;
}

Quaternion Math::lookRotation(const Vector3& forward, const Vector3& up) {
    auto right = Math::normalize(Math::cross(forward, up));
    auto upward = Math::normalize(Math::cross(right, forward));

    Matrix4x4 result = Matrix4x4::identityMatrix;
    result[0][0] = right.x;
    result[1][0] = right.y;
    result[2][0] = right.z;

    result[0][1] = upward.x;
    result[1][1] = upward.y;
    result[2][1] = upward.z;

    result[0][2] = -forward.x;
    result[1][2] = -forward.y;
    result[2][2] = -forward.z;

    return Mat4ToQuat(result);
}

Quaternion Math::euler(const Vector3& axis, f32 angle) {
    Quaternion result;
    result.w = std::cos(angle / 2.0f);
    result.x = std::sin(angle / 2.0f) * axis.x;
    result.y = std::sin(angle / 2.0f) * axis.y;
    result.z = std::sin(angle / 2.0f) * axis.z;
    return result;
}

Quaternion Math::euler(const Vector3& axis) {
    Quaternion result;

    // Roll
    f32 cr = std::cos(axis.x * 0.5f);
    f32 sr = std::sin(axis.x * 0.5f);

    // Pitch
    f32 cp = std::cos(axis.y * 0.5f);
    f32 sp = std::sin(axis.y * 0.5f);

    // Yaw
    f32 cy = std::cos(axis.z * 0.5f);
    f32 sy = std::sin(axis.z * 0.5f);

    result.w = cr * cp * cy + sr * sp * sy;
    result.x = sr * cp * cy - cr * sp * sy;
    result.y = cr * sp * cy + sr * cp * sy;
    result.z = cr * cp * sy - sr * sp * cy;

    return result;
}

Quaternion Math::slerp(const Quaternion& lhs, const Quaternion& rhs, f32 t) {
	Quaternion result = lhs;
	f32 c = Math::dot(lhs, rhs);
	if (c < 0.0f) {
		c = -c;
		result = -result;
	}
    
	f32 phi = std::acos(c);
	if (phi > 0.001f) {
		f32 s = std::sin(phi);
		return result * (std::sin((1.0f - t) * phi) / s) + rhs * (std::sin(t * phi) / s);
	}
	return result;
}

Vector3 Math::eulerAngles(const Quaternion &lhs) {
    Vector3 angles = Vector3::zero;

    // Roll (x-axis rotation)
    f32 sinr_cosp = 2.0f * ((lhs.w * lhs.x) + (lhs.y * lhs.z));
    f32 cosr_cosp = 1.0f - 2.0f * ((lhs.x * lhs.x) + (lhs.y * lhs.y));
    angles.x = Math::degree(std::atan2(sinr_cosp, cosr_cosp));

    // pitch (y-axis rotation)
    f32 sinp = std::sqrt(1.0f + 2.0f * ((lhs.w * lhs.y) - (lhs.x * lhs.z)));
    f32 cosp = std::sqrt(1.0f - 2.0f * ((lhs.w * lhs.y) - (lhs.x * lhs.z)));
    angles.y = Math::degree(-M_PI / 2.0f + 2.0f * std::atan2(sinp, cosp));

    // yaw (z-axis rotation)
    f32 siny_cosp = 2.0f * ((lhs.w * lhs.z) + (lhs.x * lhs.y));
    f32 cosy_cosp = 1.0f - 2.0f * ((lhs.y * lhs.y) + (lhs.z * lhs.z));
    angles.z = Math::degree(std::atan2(siny_cosp, cosy_cosp));

    return angles;
}


