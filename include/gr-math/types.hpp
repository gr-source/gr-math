#pragma once

#include <cstdint>

#include "vector.hpp"

using Vector2 = vector<float, 2>;
using Vector3 = vector<float, 3>;
using Vector4 = vector<float, 4>;

using Matrix3x3 = mat<float, 3, 3>;
using Matrix4x4 = mat<float, 4, 4>;

using Quaternion = quat<float>;

typedef std::uint8_t  u8;
typedef std::uint16_t u16;
typedef std::uint32_t u32;
typedef std::uint64_t u64;

typedef std::int8_t   i8;
typedef std::int16_t  i16;
typedef std::int32_t  i32;
typedef std::int64_t  i64;

typedef float         f32;
typedef double        f64;

typedef std::size_t   usize;



