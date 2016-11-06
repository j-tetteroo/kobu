
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

kobu::YWidget* kobu::YCloseButton::AcceptFocus() {
	return nullptr;
}

void kobu::YCloseButton::Draw(YGraphics *g) {

	YRect b = GetBounds();
	switch(GetState()) {
		case WidgetState::ACTIVE:
			g->FillRect(0xFF000000, b.x, b.y, b.w+1.0, b.h+1.0);
    		g->DrawLine(0xFFFFFFFF, b.x+2.0, b.y+2.0, b.x+b.w-1.0, b.y+b.h-1.0, 0.0);
    		g->DrawLine(0xFFFFFFFF, b.x+2.0, b.y+b.h-1.0, b.x+b.w-1.0, b.y+2.0, 0.0);
			break;

		case WidgetState::IDLE:
		default:
		    g->DrawRect(0xFF000000, b, 0);
    		g->DrawLine(0xFF000000, b.x+2.0, b.y+2.0, b.x+b.w-1.0, b.y+b.h-1.0, 0.0);
    		g->DrawLine(0xFF000000, b.x+2.0, b.y+b.h-1.0, b.x+b.w-1.0, b.y+2.0, 0.0);
    		break;
	}

}


void kobu::YCloseButton::TriggerEvent(kobu::YMouseButtonEvent *e) {

}



