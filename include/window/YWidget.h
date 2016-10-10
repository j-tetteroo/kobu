#ifndef YWIDGET_H
#define YWIDGET_H

#include "core/YGraphics.h"
#include "core/YEvent.h"
#include "util/YTypes.h"

namespace kobu {

enum class WidgetState { ACTIVE, TRIGGERED, DISABLED, INVISIBLE };

class YWidget
{
    
private :

    YRect bounds_;
    WidgetState state_;


public :
    YWidget() {
    	bounds_.x = bounds_.y = bounds_.w = bounds_.h = 0.0;
    }
    YWidget(YRect bounds) : bounds_(bounds) {}
    virtual ~YWidget() {};

    virtual void Draw(YGraphics *g) = 0;
    virtual void TriggerEvent(YEvent *e) = 0;

    void SetState(WidgetState state) { state_ =  state; }
    WidgetState GetState(void) const { return state_; }
    YRect GetBounds(void) const { return bounds_; }
    void SetBounds(YRect bounds) { bounds_ = bounds; }
    

};

} // namespace kobu

#endif