#ifndef YWINDOW_H
#define YWINDOW_H

#include <climits>

#include "core/YGraphics.h"
#include "util/YTypes.h"
#include "window/YContainer.h"
#include "widgets/YWindowDecorator.h"

namespace kobu {

class YWindow
{


private : 
    YWindowDecorator *decorator_;
    YContainer *container_;
    YRect bounds_;
    uint32_t z_;

protected :
    YWindow(YRect w, YContainer *c, YWindowDecorator *d) : decorator_(d), container_(c), bounds_(w), z_(INT_MAX) {};


public :
    virtual ~YWindow(void) {};
    virtual void Draw(YGraphics *g)=0;
    virtual void Resize(YRect bounds)=0;
    virtual void TriggerEvent(YEvent *e)=0;


    YContainer *GetContainer(void) const { return container_; }
    void SetContainer(YContainer *container) { container_ = container; }
    uint32_t GetZ(void) const { return z_; }
    void SetZ(uint32_t z) { z_ = z; }
    YRect GetBounds(void) const { return bounds_; }
    void SetBounds(YRect bounds) { bounds_ = bounds; }
    YWindowDecorator *GetDecorator(void) const { return decorator_; }
    void SetDecorator(YWindowDecorator *d) { decorator_ = d; }


};


} // namespace kobu

#endif

