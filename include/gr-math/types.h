#pragma once

#include <istream>
#include <ostream>

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
