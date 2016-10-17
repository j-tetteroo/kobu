
#include <string>

#include "SkCanvas.h"
#include "SkRect.h"
#include "SkRRect.h"

#include "core/YGraphics.h"
#include "util/YTypes.h"

kobu::YGraphics::YGraphics(SkCanvas *c) : canvas_(c) {

}

kobu::YGraphics::~YGraphics(void) {

}

void kobu::YGraphics::DrawRect(YRect r) {
    SkPaint paint;
    SkRect rect = SkRect::MakeXYWH(0.0, 0.0, r.w, r.h);
        
    //paint.setColor(SK_ColorRED);
    //this->canvas->drawRect(rect, paint);
    
    paint.setColor(SK_ColorBLACK);
    paint.setAntiAlias(false);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(0);
        
    canvas_->save();
    canvas_->translate(r.x, r.y);
    canvas_->drawRect(rect, paint);
    canvas_->restore();
}

void kobu::YGraphics::DrawRoundRect(uint32_t color, float x, float y, float w, float h, float r) {
    
    SkPaint paint;
    SkRect rect = SkRect::MakeXYWH(0.0, 0.0, w, h);
        
    //paint.setColor(SK_ColorRED);
    //this->canvas->drawRect(rect, paint);
    
    paint.setColor(color);
    paint.setAntiAlias(true);
        
    canvas_->save();
    canvas_->translate(x, y);
    SkRRect rrect;
    rrect.setRectXY(rect, r, r);
    canvas_->drawRRect(rrect, paint);
    canvas_->restore();
}

void kobu::YGraphics::DrawText(uint32_t color, const char *text, float x, float y) {
    
    
    // Render with Skia
    // TODO: add harfbuzz support
    SkPaint paint;
    canvas_->save();

    paint.setAntiAlias(true);
    paint.setColor(color);
    
    canvas_->translate(x, y);
    
    canvas_->drawText(text, strlen(text), SkIntToScalar(0),
                         SkIntToScalar(0), paint);
    canvas_->restore();

    
}

void kobu::YGraphics::SetCanvas(SkCanvas *c) {
    canvas_ = c;
}
void kobu::YGraphics::Push() {
    canvas_->save();
}
void kobu::YGraphics::Pop() {
    canvas_->restore();
}
void kobu::YGraphics::Translate(float x, float y) {
    canvas_->translate(x, y);
}
