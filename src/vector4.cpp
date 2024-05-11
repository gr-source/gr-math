#include "gr-math/vector4.h"
#include "gr-math/vector3.h"

Vector4::Vector4(const Vector3& rhs, vvalue w) : x(rhs.x), y(rhs.y), z(rhs.z), w(w) {}

Vector4::Vector4(vvalue x, vvalue y, vvalue z, vvalue w) : x(x), y(y), z(z), w(w) {}

Vector4 Vector4::operator*(const Vector4& rhs) {
    return {x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w};
}

Vector4& Vector4::operator /=(vvalue rhs) {
    x /= rhs;
    y /= rhs;
    z /= rhs;
    w /= rhs;
    return  *this;
}

Vector4& Vector4::operator =(const Vector4& rhs) {
    if (this != &rhs) {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        w = rhs.w;
    }
    return *this;
}


const Vector4 Vector4::zero = {0.0f, 0.0f, 0.0f, 0.0f};

