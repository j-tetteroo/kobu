#ifndef YMOUSE_EVENT_H
#define YMOUSE_EVENT_H

#include "core/YEvent.h"
#include "util/YTypes.h"


namespace kobu {
    
enum class MouseEventType { 
    M_DOWN, 
    M_UP, 
    M_DOUBLECLICK,
    M_SCROLL_DOWN,
    M_SCROLL_UP
};

enum class MouseButton {
    M_LEFT,
    M_RIGHT,
    M_MIDDLE,
    M_AUX1,
    M_AUX2
};

class YMouseEvent : public YEvent
{
    
private :
    Vec2 xy_;
    MouseEventType met_;
    MouseButton mb_;
    
public :
    YMouseEvent(Vec2 xy, MouseEventType met, MouseButton mb) 
                :  YEvent(YEventType::MOUSE), xy_(xy), met_(met), mb_(mb) {}
                
    MouseEventType GetMeType(void) const { return met_; }
    MouseButton GetButton(void) const { return mb_; }
    Vec2 GetXY(void) const { return xy_; }
    void SetXY(Vec2 xy) { xy_ = xy; }
    
};

} // namespace kobu

#endif