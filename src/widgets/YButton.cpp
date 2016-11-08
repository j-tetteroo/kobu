
#include <iostream>

#include "widgets/YButton.h"
#include "core/YGraphics.h"
#include "events/YMouseButtonEvent.h"

void kobu::YButton::Draw(YGraphics *g) {

	YRect b = GetBounds();

    switch(GetState()) {
    	case WidgetState::ACTIVE:
    	   	g->FillRoundRect(0xFF00FF00, b, 10.0);
    		g->DrawText(0xFFFFFFFF, button_text_.c_str(), b.x+10.0, b.y+20.0);
    		break;
    	case WidgetState::TRIGGERED:
    	    g->DrawRoundRect(0x00000000, b, 10.0, 1.0);
    		g->FillRoundRect(color_, b, 10.0);
    		g->DrawText(0xFFFFFFFF, button_text_.c_str(), b.x+10.0, b.y+20.0);
    		break;
    	case WidgetState::IDLE:
    	    g->FillRoundRect(color_, b, 10.0);
    		g->DrawText(0xFFFFFFFF, button_text_.c_str(), b.x+10.0, b.y+20.0);
    		break;
    	case WidgetState::DISABLED:
    	case WidgetState::INVISIBLE:
    	default:
    		break;
    }

}


void kobu::YButton::TriggerEvent(kobu::YMouseButtonEvent *e) {
	YWidget::TriggerEvent(e);
	if (e->GetButton() == MouseButton::M_LEFT) {
		if (e->GetMeType() ==  MouseButtonEventType::M_DOWN) {
			button_text_ = "Flop";
		} else if (e->GetMeType() ==  MouseButtonEventType::M_UP) {
			button_text_ = "Flap";
		}
	}
}

kobu::YWidget* kobu::YButton::AcceptFocus() {
	return nullptr;
}


kobu::YButton::YButton(std::string text, uint32_t color, float x, float y) : YWidget() {

	YRect b;
	b.x = x;
	b.y = y;
	b.w = 70.0;
	b.h = 30.0;
	SetBounds(b);
	color_ = color;
	button_text_ = text;
}

kobu::YButton::~YButton() {

}

