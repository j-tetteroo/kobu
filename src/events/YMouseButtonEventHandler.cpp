#include "events/YMouseButtonEventHandler.h"


void kobu::YMouseButtonEventHandler::HandleEvent(YMouseButtonEvent *e) {
    uint32_t last_mouseup_event_;
    MouseButton last_button_;

	switch(e->GetButton()) {

		case MouseButton::M_LEFT:
			switch (e->GetMeType()) {
				case MouseButtonEventType::M_DOWN:
					OnMouseDown(e);
					break;
				case MouseButtonEventType::M_UP:
					OnMouseUp(e);
					break;
				default:
					break;
			}
			break;

		case MouseButton::M_RIGHT:
			switch (e->GetMeType()) {
				case MouseButtonEventType::M_DOWN:
					OnMouseDown(e);
					break;
				case MouseButtonEventType::M_UP:
					OnMouseUp(e);
					break;
				default:
					break;
			}
			break;

		case MouseButton::M_MIDDLE:
			switch (e->GetMeType()) {
				case MouseButtonEventType::M_DOWN:
					break;
				case MouseButtonEventType::M_UP:
					break;
				case MouseButtonEventType::M_SCROLL_DOWN:
					break;
				case MouseButtonEventType::M_SCROLL_UP:
					break;
				default:
					break;
			}
			break;

		case MouseButton::M_AUX1:
		case MouseButton::M_AUX2:
		case MouseButton::M_UNDEFINED:
		default:
			break;
	}

    
public :
    YMouseButtonEvent(Vec2 xy, MouseButtonEventType met, MouseButton mb) 
                :  YEvent(YEventType::MOUSE), xy_(xy), met_(met), mb_(mb) {}
                
    MouseButtonEventType GetMeType(void) const { return met_; }
    MouseButton GetButton(void) const { return mb_; }

}