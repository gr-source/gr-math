#pragma once

typedef struct Rect
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





