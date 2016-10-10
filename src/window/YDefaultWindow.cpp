#include "window/YDefaultWindow.h"
#include "widgets/YDefaultWindowDecorator.h"
#include "window/YGuiContainer.h"


kobu::YDefaultWindow::YDefaultWindow(YRect w, YContainer *c, YWindowDecorator *d) : YWindow(w, c, d) {

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





