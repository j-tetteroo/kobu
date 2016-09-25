#ifndef YMOUSE_EVENT_H
#define YMOUSE_EVENT_H

#include "core/YEvent.h"
#include "util/Y2DCoord.h"


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

class YMouseEvent : YEvent
{
    
private :
    float x;
    float y;
    MouseEventType met;
    MouseButton mb;
    
public :
    YMouseEvent(float x, float y, MouseEventType met, MouseButton mb) 
                : YEvent(EventType::MOUSE), x(x), y(y), met(met), mb(mb) {}
                
    MouseEventType GetMeType() const { return met; }
    MouseButton GetButton() const { return mb; }
    Y2DCoord GetXY() const { return Y2DCoord(x, y); }
    
};

} // namespace kobu

#endif