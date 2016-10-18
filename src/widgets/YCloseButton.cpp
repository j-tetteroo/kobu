
#include <iostream>

#include "widgets/YCloseButton.h"

const float BUT_DIM = 10.0;

kobu::YCloseButton::YCloseButton(YWindow *parent, float x, float y) : YWidget() {

	YRect b;
	b.x = x;
	b.y = y;
	b.w = BUT_DIM;
	b.h = BUT_DIM;
	SetBounds(b);
}

kobu::YCloseButton::~YCloseButton() {

}

void kobu::YCloseButton::Draw(YGraphics *g) {

	YRect b = GetBounds();
    g->DrawRect(0xFF000000, b, 0);
    g->DrawLine(0xFF000000, b.x+2.0, b.y+2.0, b.x+b.w-1.0, b.y+b.h-1.0, 1.0);
    g->DrawLine(0xFF000000, b.x+2.0, b.y+b.h-1.0, b.x+b.w-1.0, b.y+2.0, 1.0);
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



