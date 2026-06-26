#ifndef COLOR_H
#define COLOR_H

#include "default.h"

#define COLOR_WHITE   ((Color){ 1.0f, 1.0f, 1.0f, 1.0f })

#define COLOR_BLACK   ((Color){ 0.0f, 0.0f, 0.0f, 1.0f })

#define COLOR_RED     ((Color){ 1.0f, 0.0f, 0.0f, 1.0f });

#define COLOR_GREEN   ((Color){ 0.0f, 1.0f, 0.0f, 1.0f })

#define COLOR_BLUE    ((Color){ 0.0f, 0.0f, 1.0f, 1.0f })

typedef struct ALIGN16 Color
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
} Color;

#endif // COLOR_H



