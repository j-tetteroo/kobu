#include <iostream>
#include <algorithm>

#include "widgets/YDefaultWindowDecorator.h"
#include "util/YTypes.h"
#include "widgets/YCloseButton.h"



// decorator dimensions
const float EDGE_W = 1.0;
const float BAR_H = 20.0;

// close button position
const float BPOS_OFFSET_X = 15.0;
const float BPOS_OFFSET_Y = 5.0;

kobu::YDefaultWindowDecorator::YDefaultWindowDecorator(YWindow *parent) 
	: YWindowDecorator(parent) {


	YRect bounds = GetParent()->GetBounds();

	//SetBounds(bounds);

	// Adjust bounds for decorator
	
	bounds.x -= EDGE_W;
	bounds.w += (EDGE_W);//std::max(bounds.w - EDGE_W, bounds.x + EDGE_W + EDGE_W);

	bounds.y -= (BAR_H+EDGE_W);//std::min(bounds.y + BAR_H + EDGE_W, bounds.y + bounds.h - EDGE_W - EDGE_W);
	bounds.h += BAR_H+(EDGE_W);//std::max(bounds.h - EDGE_W, bounds.y + EDGE_W + BAR_H + EDGE_W);

	SetBounds(bounds);

	// TODO: make relative positioning
	close_button_ = new YCloseButton(this, 
		std::max(bounds.x + bounds.w - BPOS_OFFSET_X, bounds.x),
		std::max(bounds.y + BPOS_OFFSET_Y, bounds.y));
	
}


kobu::YDefaultWindowDecorator::~YDefaultWindowDecorator() {


}


void kobu::YDefaultWindowDecorator::Draw(YGraphics *g) {

	DrawWindowEdge(g);
	DrawTitleBar(g);
	GetParent()->Draw(g);
	close_button_->Draw(g);

}

void kobu::YDefaultWindowDecorator::TriggerEvent(YEvent *e) {
	switch(e->GetType()) {
		case YEventType::MOUSE:
			HandleMouseEvent((YMouseEvent *)e);
			break;
		default:
			return;
	}
}

void kobu::YDefaultWindowDecorator::Resize(YRect bounds) {

    GetParent()->Resize(bounds);
}

void kobu::YDefaultWindowDecorator::DrawTitleBar(YGraphics *g) {

	YRect bounds;
	//YRect new_bounds;

	bounds = GetBounds();

	//new_bounds.x = bounds.x;
	//new_bounds.y = bounds.y;
	//new_bounds.w = bounds.w+(EDGE_W*2.0);
	bounds.h = BAR_H;

	g->DrawRect(0xFF000000, bounds, 0);
}

bool kobu::YDefaultWindowDecorator::DecoratorHit(YMouseEvent *e) {
	YRect b = GetBounds();
	Vec2 hit = e->GetXY();

	float edge_width = GetEdgeWidth();
	float title_height = GetTitleBarHeight();

	// TODO: clean up if statements
	if (hit.x <= edge_width || hit.x >= b.w - edge_width) {
		return true;
	}

	if (hit.y <= edge_width+title_height || hit.y >= b.h - edge_width) {
		return true;
	}

	return false;

}

void kobu::YDefaultWindowDecorator::HandleMouseEvent(YMouseEvent *e) {

	Vec2 xy = e->GetXY();

	if (DecoratorHit(e)) {
		// WindowDecorator hit
		if (close_button_->CheckHit(xy)) {
			// Close window
			std::cout << "Close window\n";
		}
	} else {
		// Window hit
		GetParent()->TriggerEvent(e);
	}

}


void kobu::YDefaultWindowDecorator::DrawWindowEdge(YGraphics *g) {
	//YRect bounds;
	//YRect new_bounds;

	//bounds = GetBounds();

	//new_bounds.x = bounds.x;
	//new_bounds.y = bounds.y;
	//new_bounds.w = bounds.w+(EDGE_W*2.0);
	//new_bounds.h = bounds.h+BAR_H+(EDGE_W*2.0);

	g->DrawRect(0xFF000000, GetBounds(), 0);

}


float kobu::YDefaultWindowDecorator::GetEdgeWidth(void) {
	return EDGE_W;
}


float kobu::YDefaultWindowDecorator::GetTitleBarHeight(void) {
	return BAR_H;

}

void kobu::YDefaultWindowDecorator::Destroy() {
	GetParent()->Destroy();
}