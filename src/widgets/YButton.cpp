

#include "widgets/YButton.h"
#include "core/YGraphics.h"

void kobu::YButton::Draw(YGraphics *g) {

	Vec2 newpos = this->pos;
	newpos.x += 20.0;
	newpos.y += 50.0;
    g->DrawRoundRect(0xFFFF0000, this->pos, this->wh, 10.0);
    g->DrawText(0xFFFFFFFF, this->button_text, newpos);

}

kobu::YRect kobu::YButton::GetBounds() {
    
	kobu::YRect rect;

    return rect;
    
}


void kobu::YButton::TriggerEvent(kobu::YEvent e) {
    
    return;
    
}

kobu::YButton::YButton(char *text, Vec2 pos) : YWidget(pos), button_text(text) {

	kobu::Vec2 wh;
	wh.x = 100.0;
	wh.y = 100.0;
	this->wh = wh;
}
/*
kobu::YButton::~YButton() {

}
*/
