#include <iostream>

#include "core/YEvent.h"
#include "events/YMouseButtonEvent.h"
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

kobu::YWidget* kobu::YDefaultWindow::GetActiveWidget() const { 
	return active_widget_; 
}


void kobu::YDefaultWindow::SetActiveWidget(YWidget *w) {
	if (active_widget_ != nullptr) {
		active_widget_->SetFocus(false);
	}
	if (w != nullptr) {
		w->SetFocus(true);
	}
	active_widget_ = w;
}

void kobu::YDefaultWindow::TriggerEvent(YMouseMoveEvent *e) {
	
	YRect b = GetBounds();
	YSpace p = GetPadding();
	Vec2 xy;
	xy = e->GetPos();
	xy.x -= b.x - p.left;
	xy.y -= b.y - p.top;
	e->SetPos(xy);
	//YWidget *w = GetActiveWidget();
	//e->SetActiveWidget(w);
	
	/*
	if (e->GetButtonDown() == MouseButton::M_LEFT && w != nullptr) {
		// Fire drag widget
		if (w->CheckHit(xy)) {
			w->TriggerEvent(e, false);
		} else {
			w->TriggerEvent(e, true);
		}
	} else {
		GetContainer()->TriggerEvent(e, false);
	}
	*/
	GetContainer()->TriggerEvent(e, false);

}

void kobu::YDefaultWindow::TriggerEvent(YMouseButtonEvent *e) {

	YWidget *w_return;
	YRect b = GetBounds();
	YSpace p = GetPadding();
	Vec2 xy;
	xy = e->GetPos();
	xy.x -= b.x - p.left;
	xy.y -= b.y - p.top;
	e->SetPos(xy);
	
	std::cout << "container defaultwindow call\n";
	w_return = GetContainer()->TriggerEvent(e);

	if (e->GetMeType() == MouseButtonEventType::M_DOWN) {
		SetActiveWidget(w_return);
	} else {
		SetActiveWidget(nullptr);
	}
}

void kobu::YDefaultWindow::Destroy() {

}







