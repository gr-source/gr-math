#include "quaternion.h"
#include "gmath.h"

Quaternion::Quaternion(vvalue value) : w(value), x(value), y(value), z(value) {}
    
Quaternion::Quaternion(vvalue w, vvalue x, vvalue y, vvalue z) : w(w), x(x), y(y), z(z) {}

Quaternion::Quaternion(const Matrix3x3& rhs) {
    vvalue trace = rhs.m00 + rhs.m11 + rhs.m22;

    if (trace > 0) {
        vvalue s = std::sqrt(trace + 1.0f) * 2.0f;
        w = 0.25f * s;
        x = (rhs.m21 - rhs.m12) / s;
        y = (rhs.m02 - rhs.m20) / s;
        z = (rhs.m10 - rhs.m01) / s;
    } else if ((rhs.m00 > rhs.m11) && (rhs.m00 > rhs.m22)) {
        vvalue s = std::sqrt(1.0f + rhs.m00 - rhs.m11 - rhs.m22) * 2.0f;
        w = (rhs.m21 - rhs.m12) / s;
        x = 0.25f * s;
        y = (rhs.m01 + rhs.m10) / s;
        z = (rhs.m02 + rhs.m20) / s;
    } else if (rhs.m11 > rhs.m22) {
        vvalue s = std::sqrt(1.0f + rhs.m11 - rhs.m00 - rhs.m22) * 2.0f;
        w = (rhs.m02 - rhs.m20) / s;
        x = (rhs.m01 + rhs.m10) / s;
        y = 0.25f * s;
        z = (rhs.m12 + rhs.m21) / s;
    } else {
        vvalue s = std::sqrt(1.0f + rhs.m22 - rhs.m00 - rhs.m11) * 2.0f;
        w = (rhs.m10 - rhs.m01) / s;
        x = (rhs.m02 + rhs.m20) / s;
        y = (rhs.m12 + rhs.m21) / s;
        z = 0.25f * s;
    }
}

Quaternion::Quaternion(vvalue angle, const Vector3& axis) {
    w = std::cos(angle / 2.0f);
    x = std::sin(angle / 2.0f) * axis.x;
    y = std::sin(angle / 2.0f) * axis.y;
    z = std::sin(angle / 2.0f) * axis.z;
}

Quaternion& Quaternion::operator *=(const Quaternion& rhs) {
    *this = *this * rhs;
    return *this;
}

Quaternion Quaternion::operator +(const Quaternion& lhs) const {
    return {w + lhs.w, x + lhs.x, y + lhs.y, z + lhs.z};
}

Quaternion Quaternion::operator -(const Quaternion& lhs) const {
    return {w - lhs.w, x - lhs.x, y - lhs.y, z - lhs.z};
}

Quaternion Quaternion::operator -() const {
    return {-w, -x, -y, -z};
}

Quaternion Quaternion::operator =(const Quaternion& other) {
    if (this != &other) {
        w = other.w;
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

Quaternion& Quaternion::operator +=(const Quaternion& lhs) {
    w += lhs.w;
    x += lhs.x;
    y += lhs.y;
    z += lhs.z;
    return *this;
}

Vector3 Quaternion::eulerAngles() const {
    Vector3 angles;

    float sinr_cosp = 2.0f * ((w * x) + (y * z));
    float cosr_cosp = 1.0f - 2.0f * ((x * x) + (y * y));
    angles.x = Math::degree(std::atan2(sinr_cosp, cosr_cosp));

    // pitch (y-axis rotation)
    float sinp = std::sqrt(1.0f + 2.0f * ((w * y) - (x * z)));
    float cosp = std::sqrt(1.0f - 2.0f * ((w * y) - (x * z)));
    angles.y = Math::degree(2 * std::atan2(sinp, cosp) - M_PIf / 2.0f);

    // yaw (z-axis rotation)
    float siny_cosp = 2.0f * ((w * z) + (x * y));
    float cosy_cosp = 1.0f - 2.0f * ((y * y) + (z * z));
    angles.z = Math::degree(std::atan2(siny_cosp, cosy_cosp));

    return angles;
}

const Quaternion Quaternion::Euler(vvalue angle, const Vector3& axis) {
    Quaternion result;
    result.w = std::cos(angle / 2.0f);
    result.x = std::sin(angle / 2.0f) * axis.x;
    result.y = std::sin(angle / 2.0f) * axis.y;
    result.z = std::sin(angle / 2.0f) * axis.z;
    return result;
}

const Quaternion Quaternion::Euler(const Vector3& axis) {
    Quaternion result;
    vvalue cr = std::cos(axis.x * 0.5f);
    vvalue sr = std::sin(axis.x * 0.5f);
    vvalue cp = std::cos(axis.y * 0.5f);
    vvalue sp = std::sin(axis.y * 0.5f);
    vvalue cy = std::cos(axis.z * 0.5f);
    vvalue sy = std::sin(axis.z * 0.5f);

    result.w = cr * cp * cy + sr * sp * sy;
    result.x = sr * cp * cy - cr * sp * sy;
    result.y = cr * sp * cy + sr * cp * sy;
    result.z = cr * cp * sy - sr * sp * cy;

    return result;
}

const Quaternion Quaternion::Slerp(const Quaternion& lhs, const Quaternion& rhs, vvalue t) {
    float c;
	Quaternion q1 = lhs;
	c = Math::dot(q1, rhs);
	if(c < 0.0f){
		c = -c;
		q1 = -q1;
	}
	float phi = std::acos(c);
	if(phi > 0.00001f){
		float s = sinf(phi);
		return q1 * (std::sin((1.0f - t) * phi) / s) + rhs * (std::sin(t * phi) / s);
	}
	return q1;
}

const Quaternion Quaternion::identity = {1.0f, 0.0f, 0.0f, 0.0f};

const Quaternion operator*(const Quaternion &lhs, const Quaternion &rhs) noexcept {
    return {
        (lhs.w * rhs.w) - (lhs.x * rhs.x) - (lhs.y * rhs.y) - (lhs.z * rhs.z),
        (lhs.w * rhs.x) + (lhs.x * rhs.w) + (lhs.y * rhs.z) - (lhs.z * rhs.y),
        (lhs.w * rhs.y) - (lhs.x * rhs.z) + (lhs.y * rhs.w) + (lhs.z * rhs.x),
        (lhs.w * rhs.z) + (lhs.x * rhs.y) - (lhs.y * rhs.x) + (lhs.z * rhs.w)
    };
}

const Vector3 operator*(const Quaternion &lhs, const Vector3 &rhs) noexcept {
    Matrix3x3 m(lhs);

    return {
        Math::dot(m.getColumn(0), rhs),
        Math::dot(m.getColumn(1), rhs),
        Math::dot(m.getColumn(2), rhs)
    };
}

const Quaternion operator*(const Quaternion &lhs, const float &rhs) noexcept {
    return Quaternion(lhs.w * rhs, lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}
