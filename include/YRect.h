#ifndef YRECT_H
#define YRECT_H

namespace Kobu {

class YRect
{
    
private :
    float width;
    float height;
    

public :
    YRect(float w, float h) : width(w), height(h) {}
    float getWidth() const { return width; }
    float getHeight() const { return height; }

};

} // namespace Kobu

#endif