#ifndef YCONTAINER_H
#define YCONTAINER_H


#include "core/YGraphics.h"
#include "window/YWidget.h"
#include "util/YTypes.h"

namespace kobu {

class YContainer : public YWidget
{

protected :
	YRect bounds_;
	YRect clip_region_;

public :
    YContainer(YRect clip_region) : YWidget(), clip_region_(clip_region) { }
    virtual ~YContainer(void) {}
    virtual YRect GetBounds() = 0;
    virtual void Draw(YGraphics *g)=0;
    virtual void TriggerEvent(YEvent *e)=0;

};


} // namespace kobu

#endif

