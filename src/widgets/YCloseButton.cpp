

#include "widgets/YCloseButton.h"
#include "core/YGraphics.h"
#include <iostream>


void kobu::YCloseButton::Draw(YGraphics *g) {

	YRect b = GetBounds();
    g->DrawRoundRect(color_, b.x, b.y, b.w, b.h, 10.0);
    g->DrawText(0xFFFFFFFF, button_text_.c_str(), b.x+10.0, b.y+20.0);

}


void kobu::YCloseButton::TriggerEvent(kobu::YEvent *e) {
    
	switch(e->GetType()) {
		case YEventType::MOUSE:
			HandleMouseEvent((YMouseEvent *)e);
			break;
		default:
			return;
	}
    
}

void kobu::YCloseButton::HandleMouseEvent(YMouseEvent *e) {
	if (e->GetButton() == MouseButton::M_LEFT) {
		if (e->GetMeType() ==  MouseEventType::M_DOWN) {

		} else if (e->GetMeType() ==  MouseEventType::M_UP) {

		}
	}
}

kobu::YCloseButton::YCloseButton(YWindow *parent, float x, float y) : YWidget() {

	YRect b;
	b.x = x;
	b.y = y;
	b.w = 20.0;
	b.h = 20.0;
	SetBounds(b);
}

kobu::YCloseButton::~YCloseButton() {

}

