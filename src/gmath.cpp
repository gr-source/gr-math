#include "gmath.hpp"
#include "matrix4x4.hpp"
#include "quaternion.hpp"
#include "vector3.hpp"

template <>
float Math::rand(float min, float max)
{
    return  (max - min) * (((static_cast<float>(std::rand())) / static_cast<float>(RAND_MAX))) + min;
}

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
vvalue Math::magnitude(const Vector2 &rhs)
{
    return std::sqrt((rhs.x * rhs.x) + (rhs.y * rhs.y));
}

template <>
vvalue Math::magnitude(const Vector3 &rhs)
{
    return std::sqrt((rhs.x * rhs.x) + (rhs.y * rhs.y) + (rhs.z * rhs.z));
}

template <>
vvalue Math::magnitude(const Vector4 &rhs)
{
    return std::sqrt((rhs.x * rhs.x) + (rhs.y * rhs.y) + (rhs.z * rhs.z) + (rhs.w * rhs.w));
}

template <>
vvalue Math::magnitude(const Quaternion &rhs)
{
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
float Math::mix(float lhs, float rhs, vvalue f)
{
    return (1.0f - f) * rhs + f * lhs;
}

template <>
Vector2 Math::mix(Vector2 lhs, Vector2 rhs, vvalue f)
{
    return (1.0f - f) * rhs + f * lhs;
}

template <>
Vector3 Math::mix(Vector3 lhs, Vector3 rhs, vvalue f)
{
    return (1.0f - f) * rhs + f * lhs;
}

template <>
Vector4 Math::mix(Vector4 lhs, Vector4 rhs, vvalue f)
{
    return (1.0f - f) * rhs + f * lhs;
}

/* ========== lerp ========== */
template <>
vvalue Math::lerp(vvalue lhs, vvalue rhs, vvalue t) {
    return lhs + (rhs - lhs) * t;
}

template <>
Vector2 Math::lerp(Vector2 lhs, Vector2 rhs, vvalue t) {
    return lhs + (rhs - lhs) * t;
}

template <>
Vector3 Math::lerp(Vector3 lhs, Vector3 rhs, vvalue t) {
    return lhs + (rhs - lhs) * t;
}
template <>
Vector4 Math::lerp(Vector4 lhs, Vector4 rhs, vvalue t) {
    return lhs + (rhs - lhs) * t;
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
Matrix4x4 Math::rotate(const Quaternion& q) {
    Matrix4x4 result = Matrix4x4::identityMatrix;

    result[0][0] = 1.0f - 2.0f * ((q.y * q.y) + (q.z * q.z));
    result[0][1] = 2.0f * ((q.x * q.y) + (q.z * q.w));
    result[0][2] = 2.0f * ((q.x * q.z) - (q.y * q.w));

    result[1][0] = 2.0f * ((q.x * q.y) - (q.z * q.w));
    result[1][1] = 1.0f - 2.0f * ((q.x * q.x) + (q.z * q.z));
    result[1][2] = 2.0f * ((q.y * q.z) + (q.x * q.w));

    result[2][0] = 2.0f * ((q.x * q.z) + (q.y * q.w));
    result[2][1] = 2.0f * ((q.y * q.z) - (q.x * q.w));
    result[2][2] = 1.0f - 2.0f * ((q.x * q.x) + (q.y * q.y));

    return result;
}

template <>
Matrix3x3 Math::rotate(const Quaternion& q)
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

    // translate
    result[3][0] = position.x;
    result[3][1] = position.y;
    result[3][2] = position.z;

    //rotate
    result[0][0] = 1.0f - 2.0f * ((rotate.y * rotate.y) + (rotate.z * rotate.z));
    result[0][1] = 2.0f * ((rotate.x * rotate.y) + (rotate.z * rotate.w));
    result[0][2] = 2.0f * ((rotate.x * rotate.z) - (rotate.y * rotate.w));

    result[1][0] = 2.0f * ((rotate.x * rotate.y) - (rotate.z * rotate.w));
    result[1][1] = 1.0f - 2.0f * ((rotate.x * rotate.x) + (rotate.z * rotate.z));
    result[1][2] = 2.0f * ((rotate.y * rotate.z) + (rotate.x * rotate.w));

    result[2][0] = 2.0f * ((rotate.x * rotate.z) + (rotate.y * rotate.w));
    result[2][1] = 2.0f * ((rotate.y * rotate.z) - (rotate.x * rotate.w));
    result[2][2] = 1.0f - 2.0f * ((rotate.x * rotate.x) + (rotate.y * rotate.y));

    // scale
    result[0][0] *= scale.x;
    result[0][1] *= scale.x;
    result[0][2] *= scale.x;

    result[1][0] *= scale.y;
    result[1][1] *= scale.y;
    result[1][2] *= scale.y;

    result[2][0] *= scale.z;
    result[2][1] *= scale.z;
    result[2][2] *= scale.z;

    return result;
}

Matrix4x4 Math::perspective(vvalue fovy, vvalue aspect, vvalue near, vvalue far)
{
    vvalue tanHalfFovy = std::tan(fovy / 2.0f);
    
    Matrix4x4 result = Matrix4x4::zeroMatrix;

    result[0][0] = 1.0f / (aspect * tanHalfFovy);
    result[1][1] = 1.0f / tanHalfFovy;
    result[2][2] = -((far + near) / (far - near));

    result[2][3] = -1.0f;

    result[3][2] = -(2.0f * (far * near) / (far - near));

    return result;
}

Matrix4x4 Math::orthographic(vvalue left, vvalue right, vvalue bottom, vvalue top, vvalue near, vvalue far) {
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
    vvalue trace = lhs[0][0] + lhs[1][1] + lhs[2][2];

    Quaternion q = Quaternion::identity;

    if (trace > 0) {
        vvalue s = std::sqrt(trace + 1.0f) * 2.0f;
        q.w = 0.25f * s;
        q.x = (lhs[2][1] - lhs[1][2]) / s;
        q.y = (lhs[0][2] - lhs[2][0]) / s;
        q.z = (lhs[1][0] - lhs[0][1]) / s;
    } else if ((lhs[0][0] > lhs[1][1]) && (lhs[0][0] > lhs[2][2])) {
        vvalue s = std::sqrt(1.0f + lhs[0][0] - lhs[1][1] - lhs[2][2]) * 2.0f;
        q.w = (lhs[2][1] - lhs[1][2]) / s;
        q.x = 0.25f * s;
        q.y = (lhs[0][1] + lhs[1][0]) / s;
        q.z = (lhs[0][2] + lhs[2][0]) / s;
    } else if (lhs[1][1] > lhs[2][2]) {
        vvalue s = std::sqrt(1.0f + lhs[1][1] - lhs[0][0] - lhs[2][2]) * 2.0f;
        q.w = (lhs[0][2] - lhs[2][0]) / s;
        q.x = (lhs[0][1] + lhs[1][0]) / s;
        q.y = 0.25f * s;
        q.z = (lhs[1][2] + lhs[2][1]) / s;
    } else {
        vvalue s = std::sqrt(1.0f + lhs[2][2] - lhs[0][0] - lhs[1][1]) * 2.0f;
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

Quaternion Math::euler(const Vector3& axis, vvalue angle) {
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

Quaternion Math::slerp(const Quaternion& lhs, const Quaternion& rhs, vvalue t) {
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

Vector3 Math::eulerAngles(const Quaternion &lhs) {
    Vector3 angles = Vector3::zero;

    // Roll (x-axis rotation)
    float sinr_cosp = 2.0f * ((lhs.w * lhs.x) + (lhs.y * lhs.z));
    float cosr_cosp = 1.0f - 2.0f * ((lhs.x * lhs.x) + (lhs.y * lhs.y));
    angles.x = Math::degree(std::atan2(sinr_cosp, cosr_cosp));

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


