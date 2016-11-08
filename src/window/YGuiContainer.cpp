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
	g->FillRoundRect(0xFF99AAFF, b, 5.0);
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

kobu::YWidget* kobu::YGuiContainer::AcceptFocus() {
	return nullptr;
}

void kobu::YGuiContainer::TriggerEvent(YMouseMoveEvent *e, bool leave_widget) {
	// TODO: Container event handler

	Vec2 hit_prev = e->GetPos();
	Vec2 hit_rel = e->GetPosRel();
	Vec2 hit = e->GetPos();

	hit_prev.x -= hit_rel.x;
	hit_prev.y -= hit_rel.y;

	// Iterate over widgets to find hit and mouseleave
	for (YWidget *it : widgets_) {
		if (it->CheckHit(hit_prev)) {
            it->TriggerEvent(e, true);
		} else if (it->CheckHit(hit)) {
			it->TriggerEvent(e, false);
		}
	}

}

void kobu::YGuiContainer::TriggerEvent(YMouseButtonEvent *e) {
	// TODO: Container event handler

	Vec2 hit = e->GetPos();

	// Iterate over widgets to find hit
	for (YWidget *it : widgets_) {
		if (it->CheckHit(hit)) {
            std::cout << "Hit\n";
            it->TriggerEvent(e);
            break;
		}
	}
}



