#include "window/YWidget.h"


namespace kobu {
	const uint32_t DOUBLE_CLICK_DELAY = 100; // milliseconds

	bool IsDoubleClick(uint32_t current_time, uint32_t last_time, uint32_t max_delay) {
		if (current_time - last_time > max_delay) {
			return false;
		} else {
			return true;
		}
	}
}

void kobu::YWidget::TriggerEvent(YMouseButtonEvent *e) {

	switch(e->GetButton()) {

		case MouseButton::M_LEFT:
			switch (e->GetMeType()) {
				case MouseButtonEventType::M_DOWN:
					SetWidgetState(WidgetState::ACTIVE);
					if (mbutton_handler_ != nullptr) {
						m_button_handler_.OnMouseDown(e);
					}
					break;
				case MouseButtonEventType::M_UP:
					SetWidgetState(WidgetState::IDLE);
					if (mbutton_handler_ != nullptr) {
						m_button_handler_.OnMouseUp(e);
						if (IsDoubleClick(e->GetTime(), last_click_, DOUBLE_CLICK_DELAY) && GetWidgetState() == WidgetState::ACTIVE) {
							// call double click
							m_button_handler_.OnDoubleClick(e);
						} else {
							// call single click
							m_button_handler_.OnClick(e);
						}
						last_click_ = e->GetTime();
					}
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


}