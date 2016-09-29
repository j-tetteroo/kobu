#ifndef YCONTAINER_H
#define YCONTAINER_H

#include "core/YSurface.h"
#include "core/YGraphics.h"

namespace kobu {

class YContainer : public YWidget
{

protected :
	YRect bounds;
	YRect clip_region;


public :
    YContainer(YRect clip_region) : clip_region(clip_region) {}
    virtual ~YContainer(void) {}
    virtual void Draw(YGraphics *g)=0;
    virtual void TriggerEvent(YEvent e)=0;

};


} // namespace kobu

#endif

