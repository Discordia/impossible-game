#pragma once

#include <cstdint>

struct PosColorVertex {
    float x;
    float y;
    float z;
    uint32_t abgr;
};

enum VertexType {
    POS3_COLOR4
};
