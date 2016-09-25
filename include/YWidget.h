#ifndef YWIDGET_H
#define YWIDGET_H

#include "util/YRect.h"

namespace kobu {

enum class WidgetState { ACTIVE, TRIGGERED, DISABLED, INVISIBLE };

class YWidget
{
    
private :
    float x;
    float y;
    float width;
    float height;
    WidgetState state;
    

public :
    YWidget(float x, float y) : x(x), y(y) {}
    virtual void Draw() = 0;
    virtual YRect GetBounds() = 0;
    virtual void TriggerEvent(YEvent e) = 0;
    WidgetState GetState() const { return state; }
    

};

} // namespace kobu

#endif