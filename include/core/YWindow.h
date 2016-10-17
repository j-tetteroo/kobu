#ifndef YWINDOW_H
#define YWINDOW_H

#include <climits>

#include "core/YGraphics.h"
#include "util/YTypes.h"
#include "window/YContainer.h"

namespace kobu {

class YWindow
{


private : 



protected :



public :
    virtual ~YWindow(void) {};
    virtual void Draw(YGraphics *g)=0;
    virtual void Resize(YRect bounds)=0;
    virtual void TriggerEvent(YEvent *e)=0;
    virtual void Destroy()=0;


    virtual YContainer *GetContainer(void) const = 0;
    virtual void SetContainer(YContainer *container) = 0;

    // layout
    virtual uint32_t GetZ(void) const = 0;
    virtual void SetZ(uint32_t z) = 0;
    virtual YRect GetBounds(void) const = 0;
    virtual void SetBounds(YRect bounds) = 0;
    virtual YSpace GetPadding(void) const = 0;
    virtual void SetPadding(YSpace p) = 0;


};


} // namespace kobu

#endif

