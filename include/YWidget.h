#ifndef YWIDGET_H
#define YWIDGET_H

#include "util/YRect.h"

namespace Kobu {

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
    virtual void draw() = 0;
    virtual YRect getBounds() = 0;
    virtual void triggerEvent(YEvent e) = 0;
    WidgetState getState() const { return state; }
    

};

} // namespace Kobu

#endif