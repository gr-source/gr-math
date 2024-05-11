#include "../include/vector3.h"

#include "../include/gmath.h"

Vector3::Vector3(vvalue x, vvalue y, vvalue z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector2& rhs, vvalue z) : x(rhs.x), y(rhs.y), z(z) {}

Vector3::Vector3(const Vector4& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {}

vvalue Vector3::operator[](int index) const {
    return data[index];
}

vvalue& Vector3::operator[](int index) {
    return data[index];
}

Vector3 Vector3::operator -(const Vector3& other) const {
    return {x - other.x, y - other.y, z - other.z};
}

Vector3 Vector3::operator -() const {
    return {-x, -y, -z};
}

Vector3 Vector3::operator +(const Vector3& other) const {
    return {x + other.x, y + other.y, z + other.z};
}

Vector3 Vector3::operator /(const Vector3& other) const {
    return {x / other.x, y / other.y, z / other.z};
}

Vector3& Vector3::operator /=(const Vector3& rhs) {
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    return *this;
}

Vector3& Vector3::operator /=(vvalue rhs) {
    x /= rhs;
    y /= rhs;
    z /= rhs;
    return *this;
}

Vector3& Vector3::operator +=(const Vector3& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3& Vector3::operator -=(const Vector3& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3 Vector3::operator *(const Vector3& other) const {
    return {x * other.x, y * other.y, z * other.z};
}

Vector3& Vector3::operator *=(const Vector3& other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Vector3& Vector3::operator *=(vvalue other) {
    x *= other;
    y *= other;
    z *= other;
    return *this;
}

bool Vector3::operator==(const Vector3& other) const {
    return ((x == other.x) && (y == other.y) && (z == other.z));
}

bool Vector3::operator!=(const Vector3& other) const {
    return ((x != other.x) || (y != other.y) || (z != other.z));
}

Vector3& Vector3::operator=(const Vector3& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

bool Vector3::operator>(const Vector3& other) const {
    return (x > other.x) && (y > other.y) && (z > other.z);
}

bool Vector3::operator<(const Vector3& other) const {
    return (x < other.x) && (y < other.y) && (z < other.z);
}

const Vector3 Vector3::zero = {0.0f, 0.0f, 0.0f};

const Vector3 Vector3::one = {1.0f, 1.0f, 1.0f};

const Vector3 Vector3::forward = {0.0f, 0.0f, 1.0f};

const Vector3 Vector3::right = {1.0f, 0.0f, 0.0f};

const Vector3 Vector3::up = {0.0f, 1.0f, 0.0f};

const Vector3 Vector3::down = {0.0f, -1.0f, 0.0f};


