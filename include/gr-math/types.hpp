#pragma once

#include <istream>
#include <ostream>

#include <cstdint>

#include "vector.hpp"

using Vector2 = vector<float, 2>;
using Vector3 = vector<float, 3>;
using Vector4 = vector<float, 4>;

using Matrix3x3 = mat<float, 3, 3>;

using Quaternion = quat<float>;

struct Matrix4x4;

namespace grm {
    // 1 byte unsigned - 0 to 255
    using uint8  = std::uint8_t;

    // 2 byte unsigned - 0 to 65.535
    using uint16 = std::uint16_t;

    // 4 byte unsigned - 0 to 4.294.967.295
    using uint32 = std::uint32_t;

    // 8 byte unsigned - 0 to 18.446.744.073.209.551.615
    using uint64 = std::uint64_t;

    using size = std::size_t;
} // namespace grm
