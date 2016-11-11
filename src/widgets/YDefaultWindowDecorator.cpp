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

void kobu::YDefaultWindowDecorator::TriggerEvent(YMouseMoveEvent *e) {
	/*
	Vec2 hit = e->GetPos();
	YRect b = GetBounds();
	hit.x -= b.x;
	hit.y -= b.y;

	Vec2 hit_rel = e->GetPosRel();
	Vec2 hit_prev = hit;

	hit_prev.x -= hit_rel.x;
	hit_prev.y -= hit_rel.y;
	YWidget *w = GetParent()->GetDragWidget();

	
	if (DecoratorHit(hit) && w == nullptr) {
		// WindowDecorator hit
		if (close_button_->CheckHit(hit)) {
			close_button_->TriggerEvent(e, false);
		} else if (close_button_->CheckHit(hit_prev)) {
			close_button_->TriggerEvent(e, true);
		}
	} else {
		// Window hit
		
	}
	*/
	GetParent()->TriggerEvent(e);
}

void kobu::YDefaultWindowDecorator::TriggerEvent(YMouseButtonEvent *e) {
	// Delegate as much state as possible to the parent window
	/*
	Vec2 xy = e->GetPos();
	YRect b = GetBounds();
	xy.x -= b.x;
	xy.y -= b.y;
	e->SetPos(xy);
	
	if (DecoratorHit(xy)) {
		// WindowDecorator hit
		std::cout << "Decorator hit\n";
		GetParent()->SetDragWidget(nullptr);
		if (close_button_->CheckHit(xy)) {
			// TODO: PLACEHOLDER CODE replace with container
			// Close window
			close_button_->TriggerEvent(e);
			if (e->GetMeType() == MouseButtonEventType::M_DOWN) {
				GetParent()->SetDragWidget(close_button_);
			}
			std::cout << "Close window\n";

			//YRect newPos = GetParent()->GetBounds();
			//newPos.x += 50.0;
			//newPos.y += 20.0;
			//Resize(newPos);
			// END PLACEHOLDER CODE
		}
	} else {
		// Window hit
		GetParent()->TriggerEvent(e);
	}
	*/
	GetParent()->TriggerEvent(e);
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