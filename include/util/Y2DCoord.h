#ifndef Y2DCOORD_H
#define Y2DCOORD_H

namespace kobu {

class Y2DCoord
{
    
private :
    float x;
    float y;
    

public :
    Y2DCoord(float x, float y) : x(x), y(y) {}
    float GetX() const { return x; }
    float GetY() const { return y; }

};

} // namespace kobu

#endif