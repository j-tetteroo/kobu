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
    Vec2 pos;
    Vec2 wh;
    WidgetState state;


public :
    YWidget(Vec2 pos) : pos(pos) {}
    virtual ~YWidget() {};
    virtual void Draw(YGraphics *g) = 0;
    virtual YRect GetBounds() = 0;
    virtual void TriggerEvent(YEvent e) = 0;
    WidgetState GetState() const { return state; }
    

};

} // namespace kobu

#endif