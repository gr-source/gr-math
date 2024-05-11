#pragma once

#include <istream>
#include <ostream>

#if DOUBLE_PRECISION
using vvalue = double;
#else
using vvalue = float;
#endif


struct Vector2;
struct Vector3;
struct Vector4;

struct Matrix3x3;
struct Matrix4x4;

struct Quaternion;
