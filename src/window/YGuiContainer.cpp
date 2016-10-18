#include <iostream>
#include <algorithm>

#include "window/YContainer.h"
#include "window/YGuiContainer.h"


kobu::YGuiContainer::YGuiContainer(YRect bounds, YRect clip_region, YLayout *l) : YContainer(bounds, clip_region), layout_(l) {

	layout_->SetWidgets(&widgets_);
	layout_->SetBounds(bounds);

}

kobu::YGuiContainer::~YGuiContainer(void) {


}
    
void kobu::YGuiContainer::AddWidget(YWidget *w) {

	widgets_.push_back(w);
}

void kobu::YGuiContainer::Draw(YGraphics *g) {
	YRect b = GetBounds();
	// TODO: Translate padding
	g->DrawRoundRect(0xFF99AAFF, b.x, b.y, b.w, b.h, 5.0);
	for (YWidget *w : widgets_) {
		w->Draw(g);
	}

}

void kobu::YGuiContainer::Scroll(float x_offset, float y_offset) {

	YRect c = GetClipRegion();
	YRect b = GetBounds();
	c.x = std::min(std::max(c.x+x_offset, b.x), b.x+b.w);
	c.y = std::min(std::max(c.y+y_offset, b.y), b.y+b.h);
	SetClipRegion(c);
}

void kobu::YGuiContainer::Layout() {
	layout_->Layout();
}

void kobu::YGuiContainer::Resize(YRect bounds) {


}

void kobu::YGuiContainer::TriggerEvent(YEvent *e) {
	switch(e->GetType()) {
		case YEventType::MOUSE:
			HandleMouseEvent((YMouseEvent *)e);
			break;
		default:
			return;
	}
}

void kobu::YGuiContainer::HandleMouseEvent(YMouseEvent *e) {
	Vec2 hit = e->GetXY();

	// Iterate over widgets to find hit
	for (YWidget *it : widgets_) {
		if (it->CheckHit(hit)) {
            std::cout << "Hit\n";
            it->TriggerEvent((YEvent *)e);
            break;
		}
	}
}


