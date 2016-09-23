#ifndef Y2DCOORD_H
#define Y2DCOORD_H

namespace Kobu {

class Y2DCoord
{
    
private :
    float x;
    float y;
    

public :
    Y2DCoord(float x, float y) : x(x), y(y) {}
    float getX() const { return x; }
    float getY() const { return y; }

};

} // namespace Kobu

#endif