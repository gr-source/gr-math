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

Quaternion& Quaternion::operator =(const Quaternion& other) {
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

const bool Quaternion::operator!=(const Quaternion &lhs) {
    return (x != lhs.x) && (y != lhs.y) && (z != lhs.z) && (w != lhs.w);
}

const Quaternion Quaternion::identity = {1.0f, 0.0f, 0.0f, 0.0f};

Quaternion operator *(const Quaternion &lhs, const Quaternion &rhs) noexcept {
    return {
        (lhs.w * rhs.w) - (lhs.x * rhs.x) - (lhs.y * rhs.y) - (lhs.z * rhs.z),
        (lhs.w * rhs.x) + (lhs.x * rhs.w) + (lhs.y * rhs.z) - (lhs.z * rhs.y),
        (lhs.w * rhs.y) - (lhs.x * rhs.z) + (lhs.y * rhs.w) + (lhs.z * rhs.x),
        (lhs.w * rhs.z) + (lhs.x * rhs.y) - (lhs.y * rhs.x) + (lhs.z * rhs.w)
    };
}

Vector3 operator *(const Quaternion &lhs, const Vector3 &rhs) noexcept {
    // cria uma matriz de rotação
    auto m = Math::rotate<Matrix4x4>(lhs);

    // multiplica para um ponto no mundo
    auto result = m * Vector4(rhs, 1.0f);

    return {result.x, result.y, result.z};
}

Quaternion operator*(const Quaternion &lhs, vvalue rhs) noexcept {
    return {lhs.w * rhs, lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}
