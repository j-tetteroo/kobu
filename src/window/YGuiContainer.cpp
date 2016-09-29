#include "window/YGuiContainer.h"



kobu::YGuiContainer::YGuiContainer(void) {


}
kobu::YGuiContainer::~YGuiContainer(void) {


}
    
void kobu::YGuiContainer::AddWidget(YWidget *w) {


}

void kobu::YGuiContainer::Draw(void) {


}

void kobu::YGuiContainer::Resize(YRect bounds) {


}

void kobu::YGuiContainer::TriggerEvent(YEvent e) {


}

void kobu::YGuiContainer::SetLayout(YLayout *l) {
	this->layout = l;
}

Layout* kobu::YGuiContainer::Getlayout() {
	return this->layout;
}
