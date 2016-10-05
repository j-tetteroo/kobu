

#include "widgets/YButton.h"
#include "core/YGraphics.h"
#include <iostream>

void kobu::YButton::Draw(YGraphics *g) {

	Vec2 newpos = pos_;
	newpos.x += 20.0;
	newpos.y += 50.0;
    g->DrawRoundRect(color_, pos_, wh_, 10.0);
    g->DrawText(0xFFFFFFFF, button_text_.c_str(), newpos);

}

kobu::YRect kobu::YButton::GetBounds() {
    
	YRect rect;
	rect.x = pos_.x;
	rect.y = pos_.y;
	rect.w = wh_.x;
	rect.h = wh_.y;
    return rect;
    
}


void kobu::YButton::TriggerEvent(kobu::YEvent *e) {
    
	switch(e->GetType()) {
		case YEventType::MOUSE:
			HandleMouseEvent((YMouseEvent *)e);
			break;
		default:
			return;
	}
    
}

void kobu::YButton::HandleMouseEvent(YMouseEvent *e) {
	if (e->GetButton() == MouseButton::M_LEFT) {
		if (e->GetMeType() ==  MouseEventType::M_DOWN) {
			button_text_ = "Flop";
		} else if (e->GetMeType() ==  MouseEventType::M_UP) {
			button_text_ = "Flap";
		}
	}
}

kobu::YButton::YButton(std::string text, Vec2 pos) : YWidget(pos), button_text_(text) {

	Vec2 wh;
	wh.x = 100.0;
	wh.y = 100.0;
	wh_ = wh;
	pos_ = pos;
	color_ = 0xFFFF0000;
}

kobu::YButton::YButton(std::string text, uint32_t color, float x, float y) : YWidget() {

	Vec2 wh;
	wh.x = 100.0;
	wh.y = 100.0;
	wh_ = wh;
	pos_.x = x;
	pos_.y = y;
	color_ = color;
	button_text_ = text;
}

kobu::YButton::~YButton() {

}

