#include "core/YWindow.h"




void kobu::YWindow::Draw(void) {
	this->container->Draw();

}
void kobu::YWindow::TriggerEvent(YEvent e) {
	this->container->TriggerEvent(e);

}

