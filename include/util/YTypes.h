#ifndef YTYPES_H
#define YTYPES_H

namespace kobu {


// TODO: consider adding constructors

struct Vec2 {
    float x;
    float y;
};

struct YRect {
    float x;
    float y;
    float w;
    float h;
};

struct YSpace {
	float top;
	float bottom;
	float left;
	float right;
};

} // namespace kobu


#endif