#ifndef YWIDGET_H
#define YWIDGET_H

#include "core/YGraphics.h"
#include "core/YEvent.h"
#include "util/YTypes.h"
#include "events/YMouseButtonEvent.h"
#include "events/YMouseButtonEventHandler.h"
#include "events/YMouseMoveEvent.h"
#include "events/YMouseMoveEventHandler.h"

namespace kobu {

enum class WidgetState { ACTIVE, TRIGGERED, IDLE, DISABLED, INVISIBLE };

class YWidget
{
    
private :

    YRect bounds_;
    WidgetState state_;
    float padding_;
    float margin_;


    // mouse events
    uint32_t last_click_;
    MouseButton last_button_;
    bool has_focus_;
    YMouseButtonEventHandler *m_button_handler_;
    YMouseMoveEventHandler *m_move_handler_;

public :
    YWidget() {
    	bounds_.x = bounds_.y = bounds_.w = bounds_.h = 0.0;
        padding_ = margin_ = 0.0;
        state_ = WidgetState::IDLE;
        last_click_ = 0;
        m_button_handler_ = nullptr;
        m_move_handler_ = nullptr;
        has_focus_ = false;
    }
    YWidget(YRect bounds) : 
        bounds_(bounds), 
        state_(WidgetState::IDLE), 
        padding_(0.0), 
        margin_(0.0), 
        last_click_(0.0), 
        has_focus_(false),
        m_button_handler_(nullptr),
        m_move_handler_(nullptr) {}
    virtual ~YWidget() {};

    virtual void Draw(YGraphics *g) = 0;


    virtual YWidget* TriggerEvent(YMouseButtonEvent *e);
    virtual void TriggerEvent(YMouseMoveEvent *e, bool leave_widget);


    virtual YWidget* AcceptFocus() = 0;

    void SetState(WidgetState state) { state_ =  state; }
    WidgetState GetState(void) const { return state_; }
    bool GetFocus(void) const { return has_focus_; }
    void SetFocus(bool f) { has_focus_ = f; }

    void SetMouseButtonHandler(YMouseButtonEventHandler *m) { m_button_handler_ = m; }
    YMouseButtonEventHandler *GetMouseButtonHandler() { return m_button_handler_; }
    void SetMouseMoveHandler(YMouseMoveEventHandler *m) { m_move_handler_ = m; }
    YMouseMoveEventHandler *GetMouseMoveHandler() { return m_move_handler_; }

    // layout
    YRect GetBounds(void) const { return bounds_; }
    void SetBounds(YRect bounds) { bounds_ = bounds; }
    float GetPadding(void) const { return padding_; }
    void SetPadding(float p) { padding_ = p; }
    float GetMargin(void) const { return margin_; }
    void SetMargin(float m) { margin_ = m; }

    // events
    // Check if coordinates fall in widget bounds
    bool CheckHit(Vec2 hit);


};

} // namespace kobu

#endif