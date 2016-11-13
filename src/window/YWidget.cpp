#include <iostream>
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

void kobu::YWidget::TriggerEvent(YMouseMoveEvent *e, bool leave_widget) {
	
	Vec2 pos = e->GetPos();
	YRect widget_pos = GetBounds();
	pos.x -= widget_pos.x;
	pos.y -= widget_pos.y;
	e->SetPos(pos);

	Vec2 pos_prev = pos;
	Vec2 pos_rel = e->GetPosRel();

	pos_prev.x -= pos_rel.x;
	pos_prev.y -= pos_rel.y;

	if (!leave_widget) {
		// Mouse enter
		if (pos_prev.x < 0.0 || 
			pos_prev.x > widget_pos.w || 
			pos_prev.y < 0.0 || 
			pos_prev.y > widget_pos.h) 
		{	// Check if mouse entered from outside the widget
			if (m_move_handler_ != nullptr) {
				m_move_handler_->OnMouseEnter(e);
			}
			std::cout << "Mouse enter\n";
			if (e->GetButtonDown() == MouseButton::M_LEFT) {
				if (GetFocus()) {
					SetState(WidgetState::ACTIVE);
				} else {
					SetState(WidgetState::IDLE);
				}
			} else {
				SetState(WidgetState::TRIGGERED);
			}
		}

		// Mouse move/drag
		if (m_move_handler_ != nullptr) {
			if ((e->GetButtonDown() == MouseButton::M_LEFT) && GetFocus()) {
				std::cout << "Mouse drag\n";
				m_move_handler_->OnMouseDrag(e);
			} else {
				m_move_handler_->OnMouseMove(e);
			}
		}
	} else {
		// Mouse leave
		if (m_move_handler_ != nullptr) {
			m_move_handler_->OnMouseLeave(e);
		}
		std::cout << "Mouse leave\n";
		SetState(WidgetState::IDLE);
	}
	

}

kobu::YWidget* kobu::YWidget::TriggerEvent(YMouseButtonEvent *e) {

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
					SetState(WidgetState::TRIGGERED);
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

	return this;


}