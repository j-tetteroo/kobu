#ifndef YMOUSE_MOVE_EVENT_HANDLER_H
#define YMOUSE_MOVE_EVENT_HANDLER_H

#include "core/YEvent.h"
#include "events/YMouseMoveEvent.h"
#include "util/YTypes.h"


namespace kobu {
    
class YMouseMoveEventHandler
{
    
private :
    
public :
    YMouseMoveEventHandler() {}
    virtual ~YMouseMoveEventHandler() {}

    virtual void OnMouseMove(YMouseMoveEvent *e) {};
    virtual void OnMouseDrag(YMouseMoveEvent *e) {};
    virtual void OnMouseEnter(YMouseMoveEvent *e) {};
    virtual void OnMouseLeave(YMouseMoveEvent *e) {};

};

} // namespace kobu

#endif