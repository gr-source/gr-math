#include "../include/quaternion.h"

#include "../include/gmath.h"

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

Vector3 Quaternion::operator*(const Vector3& rhs) const {
    Matrix3x3 m(*this);

    return {
        Math::dot(m.getColumn(0), rhs),
        Math::dot(m.getColumn(1), rhs),
        Math::dot(m.getColumn(2), rhs)
    };
}

Quaternion Quaternion::operator *(const Quaternion& rhs) const {
    return {
        (w * rhs.w) - (x * rhs.x) - (y * rhs.y) - (z * rhs.z),
        (w * rhs.x) + (x * rhs.w) + (y * rhs.z) - (z * rhs.y),
        (w * rhs.y) - (x * rhs.z) + (y * rhs.w) + (z * rhs.x),
        (w * rhs.z) + (x * rhs.y) - (y * rhs.x) + (z * rhs.w)
    };
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
    return {w, -x, -y, -z};
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

    float sinr_cosp = 2 * (w * x + y * z);
    float cosr_cosp = 1 - 2 * (x * x + y * y);
    angles.x = std::atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    float sinp = std::sqrt(1 + 2 * (w * y - x * z));
    float cosp = std::sqrt(1 - 2 * (w * y - x * z));
    angles.y = 2 * std::atan2(sinp, cosp) - M_PI / 2;

    // yaw (z-axis rotation)
    float siny_cosp = 2 * (w * z + x * y);
    float cosy_cosp = 1 - 2 * (y * y + z * z);
    angles.z = std::atan2(siny_cosp, cosy_cosp);

    return angles;
}

const Quaternion Quaternion::LookRotation(const Vector3& forward, const Vector3& upward) {
    /*const Vector3 right = Math::normalize(Math::cross(forward, upward));
    const Vector3 up = Math::normalize(Math::cross(right, forward));

    vvalue m00 = right.x;
    vvalue m10 = right.y;
    vvalue m20 = right.z;

    vvalue m01 = up.x;
    vvalue m11 = up.y;
    vvalue m21 = up.z;

    vvalue m02 = -forward.x;
    vvalue m12 = -forward.y;
    vvalue m22 = -forward.z;

    vvalue s = std::sqrt(1.0f + (m00 + m11 + m22)) * 2.0f;

    return {
        0.25f * s,
        (m21 - m12) / s,
        (m02 - m20) / s,
        (m10 - m01) / s
    };*/
    
    
    const Vector3 right = Math::normalize(Math::cross(forward, upward));
    const Vector3 up = Math::normalize(Math::cross(right, forward));

    vvalue m00 = right.x;
    vvalue m10 = right.y;
    vvalue m20 = right.z;

    vvalue m01 = up.x;
    vvalue m11 = up.y;
    vvalue m21 = up.z;

    vvalue m02 = -forward.x;
    vvalue m12 = -forward.y;
    vvalue m22 = -forward.z;

    vvalue trace = m00 + m11 + m22;

    vvalue w, x, y, z;

    if (trace > 0) {
        vvalue s = std::sqrt(trace + 1.0f) * 2.0f;
        w = 0.25f * s;
        x = (m21 - m12) / s;
        y = (m02 - m20) / s;
        z = (m10 - m01) / s;
    } else if ((m00 > m11) && (m00 > m22)) {
        vvalue s = std::sqrt(1.0f + m00 - m11 - m22) * 2.0f;
        w = (m21 - m12) / s;
        x = 0.25f * s;
        y = (m01 + m10) / s;
        z = (m02 + m20) / s;
    } else if (m11 > m22) {
        vvalue s = std::sqrt(1.0f + m11 - m00 - m22) * 2.0f;
        w = (m02 - m20) / s;
        x = (m01 + m10) / s;
        y = 0.25f * s;
        z = (m12 + m21) / s;
    } else {
        vvalue s = std::sqrt(1.0f + m22 - m00 - m11) * 2.0f;
        w = (m10 - m01) / s;
        x = (m02 + m20) / s;
        y = (m12 + m21) / s;
        z = 0.25f * s;
    }
    return { w, x, y, z };
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
    Quaternion q;
    vvalue cosHalfTheta = (lhs.w * rhs.w) + (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);

	if (std::abs(cosHalfTheta) >= 1.0) {
		q.w = lhs.w;
		q.x = lhs.x;
		q.y = lhs.y;
		q.z = lhs.z;

		return q;
	}

	double halfTheta = std::acos(cosHalfTheta);
	double sinHalfTheta = std::sqrt(1.0f - cosHalfTheta * cosHalfTheta);

	if (std::abs(sinHalfTheta) < 0.001) {
		q.w = (lhs.w * 0.5f + rhs.w * 0.5f);
		q.x = (lhs.x * 0.5f + rhs.x * 0.5f);
		q.y = (lhs.y * 0.5f + rhs.y * 0.5f);
		q.z = (lhs.z * 0.5f + rhs.z * 0.5f);

		return q;
	}

	vvalue ratioA = std::sin((1 - t) * halfTheta) / sinHalfTheta;
	vvalue ratioB = std::sin(t * halfTheta) / sinHalfTheta;

	q.w = (lhs.w * ratioA + rhs.w * ratioB);
	q.x = (lhs.x * ratioA + rhs.x * ratioB);
	q.y = (lhs.y * ratioA + rhs.y * ratioB);
	q.z = (lhs.z * ratioA + rhs.z * ratioB);

    return q;

}

const Quaternion Quaternion::identity = {1.0f, 0.0f, 0.0f, 0.0f};
