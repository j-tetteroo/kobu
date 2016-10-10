#ifndef YWINDOWDECORATOR_H
#define YWINDOWDECORATOR_H

#include <string>

#include "core/YGraphics.h"
#include "window/YWidget.h"
#include "util/YTypes.h"

namespace kobu {
    
    
// Skia wrapper class

class YWindowDecorator : public YWidget
{
private :
	YRect container_bounds_;
    

public :

	YWindowDecorator(YRect bounds) : YWidget(bounds) {}
    virtual ~YWindowDecorator() {};

    virtual void Draw(YGraphics *g) = 0;
    virtual void TriggerEvent(YEvent *e) = 0;
    virtual YRect GetContainerSize(YRect bounds) = 0; // subtract decorator dimensions from window bounds to get inner container size

};

} // namespace kobu


#endif