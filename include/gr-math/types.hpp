#pragma once

#include <istream>
#include <ostream>

#include <cstdint>

#if DOUBLE_PRECISION
using vvalue = double;
#else
using vvalue = float;
#endif

template <typename T>
struct gVector2;

using iVector2 = gVector2<int>;
using fVector2 = gVector2<float>;
using dVector2 = gVector2<double>;

struct Vector2;
struct Vector3;
struct Vector4;

struct Matrix3x3;
struct Matrix4x4;

struct Quaternion;

namespace grm {
    // 1 byte unsigned - 0 to 255
    using u8  = std::uint8_t;

    // 2 byte unsigned - 0 to 65.535
    using u16 = std::uint16_t;

    // 4 byte unsigned - 0 to 4.294.967.295
    using u32 = std::uint32_t;

    // 8 byte unsigned - 0 to 18.446.744.073.209.551.615
    using u64 = std::uint64_t;

    using size = std::size_t;
} // namespace grm
