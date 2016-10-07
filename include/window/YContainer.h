#ifndef YCONTAINER_H
#define YCONTAINER_H


#include "core/YGraphics.h"
#include "window/YWidget.h"
#include "util/YTypes.h"

namespace kobu {

class YContainer : public YWidget
{

private :
	YRect bounds_;
	YRect clip_region_;

public :
    YContainer(YRect clip_region) : YWidget(), clip_region_(clip_region) { }
    virtual ~YContainer(void) {}

    virtual void Draw(YGraphics *g)=0;
    virtual void Resize(YRect bounds)=0;
    virtual void TriggerEvent(YEvent *e)=0;

    YRect GetBounds(void) { return bounds_; }
    void SetBounds(YRect bounds) { bounds_ = bounds; }
    YRect GetClipRegion(void) { return clip_region_; } 
    void SetClipRegion(YRect clip_region) { clip_region_ = clip_region; }

};


} // namespace kobu

#endif

