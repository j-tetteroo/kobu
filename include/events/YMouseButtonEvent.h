#ifndef YMOUSE_BUTTON_EVENT_H
#define YMOUSE_BUTTON_EVENT_H

#include "core/YEvent.h"
#include "util/YTypes.h"


namespace kobu {
    
enum class MouseButtonEventType { 
    M_DOWN, 
    M_UP, 
    M_SCROLL_DOWN,
    M_SCROLL_UP
};

enum class MouseButton {
    M_LEFT,
    M_RIGHT,
    M_MIDDLE,
    M_AUX1,
    M_AUX2,
    M_UNDEFINED
};

class YMouseButtonEvent : public YEvent
{
    
private :
    Vec2 pos_;
    MouseButtonEventType met_;
    MouseButton mb_;
    
public :
    YMouseButtonEvent(Vec2 pos, MouseButtonEventType met, MouseButton mb) 
                :  YEvent(YEventType::MOUSE), pos_(pos), met_(met), mb_(mb) {}
                
    MouseButtonEventType GetMeType(void) const { return met_; }
    MouseButton GetButton(void) const { return mb_; }
    Vec2 GetPos(void) const { return pos_; }
    void SetPos(Vec2 pos) { pos_ = pos; }
    
};

} // namespace kobu

#endif