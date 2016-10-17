

#include "widgets/YCloseButton.h"
#include "core/YGraphics.h"
#include <iostream>

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

void kobu::YCloseButton::Draw(YGraphics *g) {

	YRect b = GetBounds();
    g->DrawRect(0xFF000000, b.x, b.y, b.w, b.h);
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



