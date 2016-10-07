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
    Vec2 xy;
    MouseEventType met;
    MouseButton mb;
    
public :
    YMouseEvent(Vec2 xy, MouseEventType met, MouseButton mb) 
                : YEvent(YEventType::MOUSE), xy(xy), met(met), mb(mb) {}
                
    MouseEventType GetMeType(void) const { return met; }
    MouseButton GetButton(void) const { return mb; }
    Vec2 GetXY(void) const { return xy; }
    
};

} // namespace kobu

#endif