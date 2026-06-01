#pragma once

#include "vector3.hpp"

struct alignas(16) Boundbox
{
    vector<float, 3> min;
    vector<float, 3> max;
};


