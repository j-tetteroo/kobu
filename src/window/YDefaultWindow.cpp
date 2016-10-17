#include <iostream>

#include "core/YEvent.h"
#include "events/YMouseEvent.h"
#include "window/YDefaultWindow.h"
#include "window/YGuiContainer.h"



kobu::YDefaultWindow::~YDefaultWindow(void) {

}

void kobu::YDefaultWindow::Resize(YRect bounds) {
	SetBounds(bounds);
	// TODO: Adjust bounds for padding
	GetContainer()->Resize(bounds);
}

void kobu::YDefaultWindow::Draw(YGraphics *g) {
	YRect b = GetBounds();
	YSpace p = GetPadding();

	g->Push();
		g->Translate(b.x + p.left, b.y + p.top);	// Translate to upperleft corner of container position
		GetContainer()->Draw(g);
	g->Pop();
}

void kobu::YDefaultWindow::TriggerEvent(YEvent *e) {

	GetContainer()->TriggerEvent(e);
	if (e->GetType() == YEventType::MOUSE) {
		HandleMouseEvent((YMouseEvent *)e);
	}
}

void kobu::YDefaultWindow::HandleMouseEvent(YMouseEvent *e) {


}

void kobu::YDefaultWindow::Destroy() {

}







