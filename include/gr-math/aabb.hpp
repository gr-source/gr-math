#pragma once

#include "vector3.hpp"

#include "types.hpp"

#include <algorithm>

struct AABB
{
    Vector3 min;
    Vector3 max;

    inline Vector3 Center() const { return (min + max) * 0.5f; }
    inline Vector3 Size() const { return max - min; }
    inline Vector3 Extents() const { return (max - min) * 0.5f; }

    inline void Merge(const AABB& other)
    {
        min.x = std::min(min.x, other.min.x);
        min.y = std::min(min.y, other.min.y);
        min.z = std::min(min.z, other.min.z);

        max.x = std::max(max.x, other.max.x);
        max.y = std::max(max.y, other.max.y);
        max.z = std::max(max.z, other.max.z);
    }

    inline bool Contains(const Vector3& point) const
    {
        return (point.x >= min.x && point.x <= max.x) &&
               (point.y >= min.y && point.y <= max.y) &&
               (point.z >= min.z && point.z <= max.z);
    }

    bool Intersects(const AABB& other) const
    {
        if (max.x < other.min.x || min.x > other.max.x) return false;
        if (max.y < other.min.y || min.y > other.max.y) return false;
        if (max.z < other.min.z || min.z > other.max.z) return false;

        return true;
    }

    inline float SurfaceArea() const
    {
        Vector3 s = max - min;
        return 2.0f * (s.x*s.y + s.y*s.z + s.z*s.x);
    }

    inline float Volume() const
    {
        Vector3 s = max - min;
        return s.x * s.y * s.z;
    }

    static AABB Merged(const AABB& a, const AABB& b)
    {
        return AABB{
            Vector3{
                std::min(a.min.x, b.min.x),
                std::min(a.min.y, b.min.y),
                std::min(a.min.z, b.min.z)
            },
            Vector3{
                std::max(a.max.x, b.max.x),
                std::max(a.max.y, b.max.y),
                std::max(a.max.z, b.max.z)
            }
        };
    }
};



