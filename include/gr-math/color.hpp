#pragma once

#include <istream>
#include <ostream>

typedef struct Color
{
    union {
        struct {
            float r;
            float g;
            float b;
            float a;
        };
        float data[4];
    };

    static const Color red;

    static const Color green;

    static const Color blue;

    static const Color white;

    static const Color black;
} Color;

