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

    Color(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f) : r(r), g(g), b(b), a(a) {}

    Color(const Color& other) : r(other.r), g(other.g), b(other.b), a(other.a) {}

    static const Color red;

    static const Color green;

    static const Color blue;

    static const Color white;

    static const Color black;

    Color& operator=(const Color& other);

    friend std::istream& operator>>(std::istream& is, Color& color) {
        is >> color.r >> color.g >> color.b >> color.a;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Color& color) {
        os << color.r << " " << color.g << " " << color.b << " " << color.a;
        return os;
    }
};

