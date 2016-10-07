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
    YGraphics(SkCanvas *c);
    ~YGraphics(void);
    
    
    void DrawRoundRect(uint32_t color, Vec2 pos, Vec2 wh, float r);
    void DrawRect(YRect r);
    void DrawText(uint32_t color, const char *text, Vec2 pos);
    void SetCanvas(SkCanvas *c);

};

} // namespace kobu


#endif