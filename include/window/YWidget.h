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

protected :
    Vec2 pos_;
    Vec2 wh_;
    WidgetState state_;


public :
    YWidget() {
    	pos_.x = pos_.y = 0.0;
    }
    YWidget(Vec2 pos) : pos_(pos) {}
    virtual ~YWidget() {};
    virtual void Draw(YGraphics *g) = 0;
    virtual YRect GetBounds(void) = 0;
    virtual void TriggerEvent(YEvent *e) = 0;
    WidgetState GetState(void) const { return state_; }
    

};

} // namespace kobu

#endif