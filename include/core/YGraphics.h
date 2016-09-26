#ifndef YGRAPHICS_H
#define YGRAPHICS_H

#include <string>

#include "SkCanvas.h"
#include "util/YTypes.h"

namespace kobu {
    
    
// Skia wrapper class

class YGraphics
{
private :
    SkCanvas *canvas;
    

public :
    YGraphics(SkCanvas *c) : canvas(c) {};
    ~YGraphics(void) {};
    
    
    
    void DrawRoundRect(uint32_t color, Vec2 pos, Vec2 wh, float r);
    void DrawRect(Vec2 pos, Vec2 wh);
    void DrawText(uint32_t color, char *text, Vec2 pos);

};

} // namespace kobu


#endif