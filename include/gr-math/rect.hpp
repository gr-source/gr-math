#pragma once

struct alignas(16) Rect
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
};





