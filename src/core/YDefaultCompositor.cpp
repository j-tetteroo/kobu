#include "compositor/YDefaultCompositor.h"
#include "core/YWindow.h"

kobu::YDefaultCompositor::YDefaultCompositor(void) {
	

}

kobu::YDefaultCompositor::~YDefaultCompositor(void) {


}

void kobu::YDefaultCompositor::AddWindow(YWindow *window) {
	this->windows.push_back(window);

}
void kobu::YDefaultCompositor::Draw(void) {
	// TODO: Draw with proper z-order
    for(YWindow *w : this->windows) {
    	w->Draw();
    }
}

void kobu::YDefaultCompositor::TriggerEvent(YEvent e) {
	// TODO: only send to relevant window (with focus, or based on XY)
	for(YWindow *w : this->windows) {
    	w->TriggerEvent(e);
    }

}
