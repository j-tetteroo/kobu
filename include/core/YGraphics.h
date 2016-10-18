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
    
    void DrawRect(uint32_t color, float x, float y, float w, float h, float lineWidth);
    void DrawRect(uint32_t color, YRect r, float lineWidth);

    void FillRect(uint32_t color, float x, float y, float w, float h);
    void FillRect(uint32_t color, YRect r);

    void DrawRoundRect(uint32_t color, float x, float y, float w, float h, float radius, float lineWidth);
    void DrawRoundRect(uint32_t color, YRect r, float radius, float lineWidth);

    void FillRoundRect(uint32_t color, float x, float y, float w, float h, float radius);
    void FillRoundRect(uint32_t color, YRect r, float radius);

    void DrawLine(uint32_t color, float x0, float y0, float x1, float y1, float lineWidth);
    //void DrawLine(uint32_t color, Vec2 xy, float lineWidth);

    void DrawText(uint32_t color, const char *text, float x, float y);
    void SetCanvas(SkCanvas *c);

    void Push();
    void Pop();
    void Translate(float x, float y);

};

} // namespace kobu


#endif