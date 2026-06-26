#ifndef RECT_H
#define RECT_H

#include "default.h"

typedef struct ALIGN16 Rect
{
    union {
        struct {
            float x;
            float y;
            float w;
            float h;
        };
        float data[4];
    };
} Rect;


#endif // !RECT_H






