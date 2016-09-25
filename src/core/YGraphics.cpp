
#include <string>
#include "SkCanvas.h"
#include "SkRect.h"
#include "SkRRect.h"
#include "core/YGraphics.h"
#include "util/Y2DCoord.h"


void kobu::YGraphics::DrawRoundRect(kobu::Y2DCoord xy, kobu::Y2DCoord wh, float r) {
    
    SkPaint paint;
    SkRect rect = SkRect::MakeXYWH(xy.GetX(), xy.GetY(), 
        wh.GetX(), wh.GetY());
        
    paint.setColor(SK_ColorBLUE);
    paint.setAntiAlias(true);
        
    this->canvas->save();
    this->canvas->translate(xy.GetX(), xy.GetY());
    SkRRect rrect;
    rrect.setRectXY(rect, r, r);
    this->canvas->drawRRect(rrect, paint);
    this->canvas->restore();
}

void kobu::YGraphics::DrawText(std::string text, kobu::Y2DCoord xy) {
    
    
    // Render with Skia
    // TODO: add harfbuzz support
    SkPaint paint;
    this->canvas->save();

    paint.setAntiAlias(true);
    paint.setColor(SK_ColorBLACK);
    
    this->canvas->translate(SkIntToScalar(xy.GetX()), SkIntToScalar(xy.GetY()));
    
    this->canvas->drawText(text.c_str(), text.length(), SkIntToScalar(0),
                         SkIntToScalar(0), paint);
    this->canvas->restore();

    
}
