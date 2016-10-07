#include "window/YDefaultWindow.h"



kobu::YDefaultWindow::YDefaultWindow(YRect w, YContainer *c) : YWindow(w, c) {

}

kobu::YDefaultWindow::~YDefaultWindow(void) {

}

void kobu::YDefaultWindow::Resize(YRect bounds) {
	SetBounds(bounds);
	GetContainer()->Resize(bounds);
}

void kobu::YDefaultWindow::Draw(YGraphics *g) {
	g->DrawRect(GetBounds());
	GetContainer()->Draw(g);

}
void kobu::YDefaultWindow::TriggerEvent(YEvent *e) {
	GetContainer()->TriggerEvent(e);

}





