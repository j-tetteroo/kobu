
#include <string>

#include "SkCanvas.h"
#include "SkRect.h"
#include "SkRRect.h"

#include "core/YGraphics.h"
#include "util/YTypes.h"


void kobu::YGraphics::DrawRoundRect(uint32_t color, kobu::Vec2 pos, 
    kobu::Vec2 wh, float r) {
    
    SkPaint paint;
    SkRect rect = SkRect::MakeXYWH(0.0, 0.0, wh.x, wh.y);
        
    paint.setColor(color);
    paint.setAntiAlias(true);
        
    this->canvas->save();
    this->canvas->translate(pos.x, pos.y);
    SkRRect rrect;
    rrect.setRectXY(rect, r, r);
    this->canvas->drawRRect(rrect, paint);
    this->canvas->restore();
}

void kobu::YGraphics::DrawText(uint32_t color, char *text, 
    kobu::Vec2 pos) {
    
    
    // Render with Skia
    // TODO: add harfbuzz support
    SkPaint paint;
    this->canvas->save();

    paint.setAntiAlias(true);
    paint.setColor(SK_ColorBLACK);
    
    this->canvas->translate(pos.x, pos.y);
    
    this->canvas->drawText(text, strlen(text), SkIntToScalar(0),
                         SkIntToScalar(0), paint);
    this->canvas->restore();

    
}