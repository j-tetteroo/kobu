#ifndef YWIDGET_H
#define YWIDGET_H

#include "core/YGraphics.h"
#include "core/YEvent.h"
#include "util/YTypes.h"

namespace kobu {

enum class WidgetState { ACTIVE, TRIGGERED, IDLE, DISABLED, INVISIBLE };

class YWidget
{
    
private :

    YRect bounds_;
    WidgetState state_;
    float padding_;
    float margin_;


public :
    YWidget() {
    	bounds_.x = bounds_.y = bounds_.w = bounds_.h = 0.0;
        padding_ = margin_ = 0.0;
        state_ = WidgetState::IDLE;
    }
    YWidget(YRect bounds) : bounds_(bounds), state_(WidgetState::IDLE), padding_(0.0), margin_(0.0) {}
    virtual ~YWidget() {};

    virtual void Draw(YGraphics *g) = 0;
    virtual void TriggerEvent(YEvent *e) = 0;

    void SetState(WidgetState state) { state_ =  state; }
    WidgetState GetState(void) const { return state_; }

    // layout
    YRect GetBounds(void) const { return bounds_; }
    void SetBounds(YRect bounds) { bounds_ = bounds; }
    float GetPadding(void) const { return padding_; }
    void SetPadding(float p) { padding_ = p; }
    float GetMargin(void) const { return margin_; }
    void SetMargin(float m) { margin_ = m; }

    // events

    // Check if coordinates fall in widget bounds
    bool CheckHit(Vec2 hit) {
        if (hit.x >= bounds_.x && hit.x <= (bounds_.x+bounds_.w) && hit.y >= bounds_.y && hit.y <= (bounds_.y+bounds_.h)) {
            return true;
        } else {
            return false;
        }
    }


};

} // namespace kobu

#endif