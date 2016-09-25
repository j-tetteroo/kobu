#ifndef YRECT_H
#define YRECT_H

namespace kobu {

class YRect
{
    
private :
    float width;
    float height;
    

public :
    YRect(float w, float h) : width(w), height(h) {}
    float GetWidth() const { return width; }
    float GetHeight() const { return height; }

};

} // namespace kobu

#endif