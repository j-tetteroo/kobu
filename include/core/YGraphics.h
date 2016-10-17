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
    SkCanvas *canvas_;
    

public :
    YGraphics(SkCanvas *c);
    ~YGraphics(void);
    
    
    void DrawRoundRect(uint32_t color, float x, float y, float w, float h, float r);
    void DrawRect(YRect r);
    void DrawText(uint32_t color, const char *text, float x, float y);
    void SetCanvas(SkCanvas *c);

    void Push();
    void Pop();
    void Translate(float x, float y);

};

} // namespace kobu


#endif