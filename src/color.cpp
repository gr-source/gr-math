#include "color.h"

const Color Color::red = {1.0f, 0.0f, 0.0f};

const Color Color::green = {0.0f, 1.0f, 0.0f};

const Color Color::blue = {0.0f, 0.0f, 1.0f};

const Color Color::white = {1.0f, 1.0f, 1.0f};

const Color Color::black {0.0f, 0.0f, 0.0f};

Color & Color::operator=(const Color & other) {
    if (this != &other) {
        r = other.r;
        g = other.g;
        b = other.b;
        a = other.a;
    }
    return *this;
}