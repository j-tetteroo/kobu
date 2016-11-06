#ifndef YMOUSE_MOVE_EVENT_H
#define YMOUSE_MOVE_EVENT_H

#include <cstdint>


#include "core/YEvent.h"
#include "util/YTypes.h"
#include "events/YMouseButtonEvent.h"

namespace kobu {


class YMouseMoveEvent : public YEvent
{
    
private :
    Vec2 pos_;   // last known position relative to widget reference frame.
    Vec2 pos_rel_; // relative position wrt previous (absolute) position.
    MouseButton m_button_down_; // current mouse button down

    
public :
    YMouseMoveEvent(Vec2 pos, Vec2 pos_rel, MouseButton mb, uint32_t time) 
                :  YEvent(YEventType::MOUSE, time), pos_(pos), pos_rel_(pos_rel), m_button_down_(mb) {}
                
    MouseButton GetButtonDown(void) const { return m_button_down_; }
    
    Vec2 GetPos(void) const { return pos_; }
    void SetPos(Vec2 pos) { pos_ = pos; }

    Vec2 GetPosRel(void) const { return pos_rel_; }
    void SetPosRel(Vec2 pos_rel) { pos_rel_ = pos_rel; }
    
};

} // namespace kobu

#endif