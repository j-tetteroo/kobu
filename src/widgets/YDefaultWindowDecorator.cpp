#include "widgets/YDefaultWindowDecorator.h"
#include "util/YTypes.h"

const float EDGE_W = 1.0;
const float BAR_H = 20.0;

kobu::YDefaultWindowDecorator::YDefaultWindowDecorator(YRect bounds) : YWindowDecorator(bounds) {

}


kobu::YDefaultWindowDecorator::~YDefaultWindowDecorator() {


}


void kobu::YDefaultWindowDecorator::Draw(YGraphics *g) {
	DrawTitleBar(g);
	DrawWindowEdge(g);

}

void kobu::YDefaultWindowDecorator::TriggerEvent(YEvent *e) {

}

void kobu::YDefaultWindowDecorator::DrawTitleBar(YGraphics *g) {

	YRect bounds;
	YRect new_bounds;

	bounds = GetBounds();

	new_bounds.x = bounds.x;
	new_bounds.y = bounds.y;
	new_bounds.w = bounds.w;
	new_bounds.h = BAR_H;

	g->DrawRect(new_bounds);
}

void kobu::YDefaultWindowDecorator::DrawWindowEdge(YGraphics *g) {
	g->DrawRect(GetBounds());

}

kobu::YRect kobu::YDefaultWindowDecorator::GetContainerSize(YRect bounds) {

	// TODO: move to constructor as data member so can be immediately returned
	YRect new_bounds;
	new_bounds.x = bounds.x - EDGE_W;
	new_bounds.y = bounds.y + (BAR_H);
	new_bounds.w = bounds.w - (EDGE_W*2.0);
	new_bounds.h = bounds.h - (BAR_H) - (EDGE_W*2.0);

	return new_bounds;

}


