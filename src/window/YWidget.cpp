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

// Check if coordinates fall in widget bounds
bool kobu::YWidget::CheckHit(Vec2 hit) {
    if (hit.x >= bounds_.x && hit.x <= (bounds_.x+bounds_.w) && hit.y >= bounds_.y && hit.y <= (bounds_.y+bounds_.h)) {
        return true;
    } else {
        return false;
    }
}

void kobu::YWidget::TriggerEvent(YMouseButtonEvent *e) {

	switch(e->GetButton()) {

		case MouseButton::M_LEFT:
			switch (e->GetMeType()) {
				case MouseButtonEventType::M_DOWN:
					SetState(WidgetState::ACTIVE);
					if (m_button_handler_ != nullptr) {
						m_button_handler_->OnMouseDown(e);
					}
					break;
				case MouseButtonEventType::M_UP:
					if (m_button_handler_ != nullptr) {
						m_button_handler_->OnMouseUp(e);
						if (IsDoubleClick(e->GetTime(), last_click_, DOUBLE_CLICK_DELAY) && GetState() == WidgetState::ACTIVE) {
							// call double click
							m_button_handler_->OnDoubleClick(e);
						} else {
							// call single click
							m_button_handler_->OnClick(e);
						}
						last_click_ = e->GetTime();
					}
					SetState(WidgetState::IDLE);
					break;
				default:
					break;
			}
			break;

		case MouseButton::M_RIGHT:
			switch (e->GetMeType()) {
				case MouseButtonEventType::M_DOWN:
					m_button_handler_->OnMouseDown(e);
					break;
				case MouseButtonEventType::M_UP:
					m_button_handler_->OnMouseUp(e);
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