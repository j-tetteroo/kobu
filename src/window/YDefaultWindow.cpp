#include "window/YDefaultWindow.h"
#include "widgets/YDefaultWindowDecorator.h"
#include "window/YGuiContainer.h"


kobu::YDefaultWindow::YDefaultWindow(YRect w, YContainer *c, YDefaultWindowDecorator *d) : 	YWindow(w, c, (YWindowDecorator *)d) {
	YRect bounds;
	bounds.x = w.x - d->GetEdgeWidth();
	bounds.y = w.y - d->GetEdgeWidth() - d->GetTitleBarHeight();
	bounds.w = w.w + d->GetEdgeWidth();
	bounds.h = w.h + d->GetEdgeWidth();

	SetBounds(bounds);

}


kobu::YDefaultWindow::~YDefaultWindow(void) {

}

void kobu::YDefaultWindow::Resize(YRect bounds) {
	SetBounds(bounds);
	GetContainer()->Resize(bounds);
}

void kobu::YDefaultWindow::Draw(YGraphics *g) {
	GetDecorator()->Draw(g);
	GetContainer()->Draw(g);

}
void kobu::YDefaultWindow::TriggerEvent(YEvent *e) {
	GetContainer()->TriggerEvent(e);
}





