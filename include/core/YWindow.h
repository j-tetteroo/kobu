#ifndef YWINDOW_H
#define YWINDOW_H

#include <climits>

#include "window/YWidget.h"
#include "core/YGraphics.h"
#include "util/YTypes.h"
#include "window/YContainer.h"
#include "events/YMouseButtonEvent.h"
#include "events/YMouseMoveEvent.h"

namespace kobu {

class YWindow
{


private : 



protected :



public :
    virtual ~YWindow(void) {};
    virtual void Draw(YGraphics *g)=0;
    virtual void Resize(YRect bounds)=0;
    virtual void TriggerEvent(YMouseButtonEvent *e)=0;
    virtual void TriggerEvent(YMouseMoveEvent *e)=0;
    virtual void Destroy()=0;


    virtual YContainer *GetContainer(void) const = 0;
    virtual void SetContainer(YContainer *container) = 0;
    virtual YWidget *GetCurrentFocus() const = 0;
    virtual void SetCurrentFocus(YWidget *f) = 0;

    virtual bool WindowHasFocus() const = 0;
    virtual void WindowSetFocus(bool f) = 0;

    virtual YWidget* GetActiveWidget() const = 0;
    virtual void SetActiveWidget(YWidget *w) = 0;

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

