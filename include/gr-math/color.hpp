#pragma once

#include <istream>
#include <ostream>

struct Color {
    union {
        struct {
            float r;
            float g;
            float b;
            float a;
        };
        float data[4];
    };

    static Color red;

    static Color green;

    static Color blue;

    static Color white;

    static Color black;

    friend std::istream& operator>>(std::istream& is, Color& color) {
        is >> color.r >> color.g >> color.b >> color.a;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Color& color) {
        os << color.r << " " << color.g << " " << color.b << " " << color.a;
        return os;
    }
};

