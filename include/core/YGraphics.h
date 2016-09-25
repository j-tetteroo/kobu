#ifndef YGRAPHICS_H
#define YGRAPHICS_H

#include <string>

#include "SkCanvas.h"
#include "util/YTypes.h"
#include "util/Y2DCoord.h"

namespace kobu {
    
    
// Skia wrapper class

class YGraphics
{
private :
    SkCanvas *canvas;
    

public :
    YGraphics(SkCanvas *c) : canvas(c) {};
    ~YGraphics(void) {};
    
    void DrawRoundRect(Y2DCoord xy, Y2DCoord wh, float r);
    void DrawRect(Y2DCoord xy, Y2DCoord wh);
    void DrawText(std::string text, Y2DCoord xy);
    

};

} // namespace kobu


#endif