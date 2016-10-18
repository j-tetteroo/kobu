
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

void kobu::YGraphics::DrawRect(uint32_t color, float x, float y, float w, float h, float lineWidth) {
    SkPaint paint;
    SkRect rect = SkRect::MakeXYWH(x, y, w, h);
    
    paint.setColor(color);
    paint.setAntiAlias(false);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(lineWidth);
        
    //canvas_->save();
    //canvas_->translate(r.x, r.y);
    canvas_->drawRect(rect, paint);
    //canvas_->restore();
}

void kobu::YGraphics::DrawRect(uint32_t color, YRect r, float lineWidth) {
    DrawRect(color, r.x, r.y, r.w, r.h, lineWidth);
}

void kobu::YGraphics::FillRect(uint32_t color, float x, float y, float w, float h) {
    SkPaint paint;
    SkRect rect = SkRect::MakeXYWH(x, y, w, h);
    
    paint.setColor(color);
    paint.setAntiAlias(true);

    canvas_->drawRect(rect, paint);
}

void kobu::YGraphics::FillRect(uint32_t color, YRect r) {
    FillRect(color, r.x, r.y, r.w, r.h);
}

void kobu::YGraphics::DrawRoundRect(uint32_t color, float x, float y, float w, float h, float radius, float lineWidth) {
    
    SkPaint paint;
    SkRect rect = SkRect::MakeXYWH(x, y, w, h);
    
    paint.setColor(color);
    paint.setAntiAlias(true);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(lineWidth);

    SkRRect rrect;
    rrect.setRectXY(rect, radius, radius);
    canvas_->drawRRect(rrect, paint);
}

;
void kobu::YGraphics::DrawRoundRect(uint32_t color, YRect r, float radius, float lineWidth) {
    DrawRoundRect(color, r.x, r.y, r.w, r.h, radius, lineWidth);
}

void kobu::YGraphics::FillRoundRect(uint32_t color, float x, float y, float w, float h, float radius) {
    SkPaint paint;
    SkRect rect = SkRect::MakeXYWH(x, y, w, h);
    
    paint.setColor(color);
    paint.setAntiAlias(true);

    SkRRect rrect;
    rrect.setRectXY(rect, radius, radius);
    canvas_->drawRRect(rrect, paint);
}

void kobu::YGraphics::FillRoundRect(uint32_t color, YRect r, float radius) {
    FillRoundRect(color, r.x, r.y, r.w, r.h, radius);
}

void kobu::YGraphics::DrawLine(uint32_t color, float x0, float y0, float x1, float y1, float lineWidth) {
    SkPaint paint;
    
    paint.setColor(color);
    paint.setAntiAlias(true);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(lineWidth);

    canvas_->drawLine (x0, y0, x1, y1, paint);
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
