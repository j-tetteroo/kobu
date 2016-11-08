#ifndef YCONTAINER_H
#define YCONTAINER_H


#include "core/YGraphics.h"
#include "window/YWidget.h"
#include "util/YTypes.h"

namespace kobu {

class YContainer : public YWidget
{

private :
	YRect clip_region_;
	YSpace padding_;


    // TODO: scrollbars

public :
    YContainer(YRect bounds, YRect clip_region) : YWidget(bounds), clip_region_(clip_region) { }
    virtual ~YContainer(void) {}

    virtual void Draw(YGraphics *g)=0;
    virtual void Resize(YRect bounds)=0;
    virtual void Scroll(float x_offset, float y_offset)=0;
    virtual void Layout()=0;
    //virtual void TriggerEvent(YMouseButtonEvent *e)=0;
    //virtual void TriggerEvent(YMouseMoveEvent *e)=0;

    YRect GetClipRegion(void) { return clip_region_; } 
    void SetClipRegion(YRect clip_region) { clip_region_ = clip_region; }

};


} // namespace kobu

#endif

