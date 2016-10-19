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
	bounds.w += (EDGE_W);

	bounds.y -= (BAR_H+EDGE_W);
	bounds.h += BAR_H+(EDGE_W);

	SetBounds(bounds);

	// TODO: make relative positioning
	close_button_ = new YCloseButton(this, 
		std::max(bounds.w - BPOS_OFFSET_X, 0.0f),
		std::max(BPOS_OFFSET_Y, 0.0f));
	
}


kobu::YDefaultWindowDecorator::~YDefaultWindowDecorator() {


}


void kobu::YDefaultWindowDecorator::Draw(YGraphics *g) {

	YRect b = GetBounds();

	DrawWindowEdge(g);
	DrawTitleBar(g);
	GetParent()->Draw(g);

	g->Push();
		g->Translate(b.x, b.y);
		close_button_->Draw(g);
	g->Pop();

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

	YRect decBounds = bounds;

	decBounds.x -= EDGE_W;
	decBounds.w += (EDGE_W);

	decBounds.y -= (BAR_H+EDGE_W);
	decBounds.h += BAR_H+(EDGE_W);

	SetBounds(decBounds);
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

bool kobu::YDefaultWindowDecorator::DecoratorHit(Vec2 loc) {
	YRect b = GetBounds();
	Vec2 hit = loc;

	float edge_width = GetEdgeWidth();
	float title_height = GetTitleBarHeight();

	// TODO: clean up if statements
	if ((hit.x <= edge_width) || (hit.x >= (b.w - edge_width))) {
		return true;
	}

	if ((hit.y <= (edge_width+title_height)) || (hit.y >= (b.h - edge_width))) {
		return true;
	}

	return false;

}

void kobu::YDefaultWindowDecorator::HandleMouseEvent(YMouseEvent *e) {

	Vec2 xy = e->GetXY();
	YRect b = GetBounds();
	xy.x -= b.x;
	xy.y -= b.y;

	if (DecoratorHit(xy)) {
		// WindowDecorator hit
		std::cout << "Decorator hit\n";
		if (close_button_->CheckHit(xy)) {
			// Close window
			close_button_->TriggerEvent(e);
			std::cout << "Close window\n";

			YRect newPos = GetParent()->GetBounds();
			newPos.x += 50.0;
			newPos.y += 20.0;
			Resize(newPos);
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