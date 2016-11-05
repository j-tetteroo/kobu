#ifndef YMOUSE_BUTTON_EVENT_HANDLER_H
#define YMOUSE_BUTTON_EVENT_HANDLER_H

#include "core/YEvent.h"
#include "events/YMouseButtonEvent.h"
#include "util/YTypes.h"


namespace kobu {
    
class YMouseButtonEventHandler
{
    
private :

    
public :
    YMouseButtonEventHandler() {}

    virtual void OnMouseDown(YMouseButtonEvent *e);
    virtual void OnMouseUp(YMouseButtonEvent *e);
    virtual void OnClick(YMouseButtonEvent *e);
    virtual void OnDoubleClick(YMouseButtonEvent *e);

};

} // namespace kobu

#endif