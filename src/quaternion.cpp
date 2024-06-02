#include "quaternion.h"
#include "gmath.h"

Quaternion::Quaternion(vvalue value) : w(value), x(value), y(value), z(value) {}
    
Quaternion::Quaternion(vvalue w, vvalue x, vvalue y, vvalue z) : w(w), x(x), y(y), z(z) {}

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
    const auto m = Math::rotate<Matrix4x4>(lhs);
    const Vector4 result = m * Vector4(rhs, 1.0f);

    return {result.x, result.y, result.z};
}

const Quaternion operator*(const Quaternion &lhs, vvalue rhs) noexcept {
    return Quaternion(lhs.w * rhs, lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}
