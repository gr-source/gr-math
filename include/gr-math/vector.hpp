#pragma once

#include "default.h"

template <typename T>
struct ALIGN8 vector2
{
    union
    {
        struct
        {
            T x;
            T y;
        };
        T data[2];
    };

    constexpr const T& operator[](int index) const
    {
        return data[index];
    }

    constexpr T& operator[](int index)
    {
        return data[index];
    }
};

template <typename T>
struct ALIGN16 vector3
{
    union
    {
        struct
        {
            T x;
            T y;
            T z;
        };
        T data[3];
    };

    constexpr const T& operator[](int index) const
    {
        return data[index];
    }

    constexpr T& operator[](int index)
    {
        return data[index];
    }
};


template <typename T>
struct ALIGN16 vector4
{
    union
    {
        struct
        {
            T x;
            T y;
            T z;
            T w;
        };
        T data[4];
    };

    constexpr const T& operator[](int index) const
    {
        return data[index];
    }

    constexpr T& operator[](int index)
    {
        return data[index];
    }
};

template <typename T>
struct ALIGN16 quaternion
{
    union
    {
        struct
        {
            T w;
            T x;
            T y;
            T z;
        };
        T data[4];
    };

    constexpr const T& operator[](int index) const
    {
        return data[index];
    }

    constexpr T& operator[](int index)
    {
        return data[index];
    }
};

template <typename T>
struct ALIGN16 mat3
{
    vector3<T> columns[3];

    constexpr const vector3<T>& operator[](int index) const
    {
        return columns[index];
    }

    constexpr vector3<T>& operator[](int index)
    {
        return columns[index];
    }
};

template <typename T>
struct ALIGN16 mat4
{
    vector4<T> columns[4];

    constexpr const vector4<T>& operator[](int index) const
    {
        return columns[index];
    }

    constexpr vector4<T>& operator[](int index)
    {
        return columns[index];
    }
};

template <typename T>
struct type_traits;



