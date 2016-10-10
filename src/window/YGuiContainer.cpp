#include "window/YGuiContainer.h"
#include <iostream>


kobu::YGuiContainer::YGuiContainer(YRect bounds, YRect clip_region) : YContainer(bounds, clip_region) {


}

kobu::YGuiContainer::~YGuiContainer(void) {


}
    
void kobu::YGuiContainer::AddWidget(YWidget *w) {

	widgets_.push_back(w);
}

void kobu::YGuiContainer::Draw(YGraphics *g) {

	for (YWidget *w : widgets_) {
		w->Draw(g);
	}

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
	YRect dim;

	// Iterate over widgets to find hit
	for (YWidget *it : widgets_) {
		dim = it->GetBounds();
		std::cout << "Bounds " << dim.x << " " << dim.y << " " << dim.w << " " << dim.h << "\n";
		if (hit.x >= dim.x && hit.x <= (dim.x+dim.w) && hit.y >= dim.y && hit.y <= (dim.y+dim.h)) {
            // Hit
            std::cout << "Hit\n";
            it->TriggerEvent((YEvent *)e);
            break;
		}
	}
}


void kobu::YGuiContainer::SetLayout(YLayout *l) {
	layout_ = l;
}

kobu::YLayout* kobu::YGuiContainer::Getlayout() {
	return layout_;
}
