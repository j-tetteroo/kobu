#ifndef YCOMPOSITOR_H
#define YCOMPOSITOR_H


#include "util/YTypes.h"
#include "core/YWindow.h"
#include "core/YEvent.h"

namespace kobu {
    
class YCompositor
{
protected:
    std::vector<YWindow *> windows;
    

public :
    YCompositor(void) {};
    virtual ~YCompositor(void) {};
    virtual void AddWindow(YWindow *window)=0;
    virtual void Draw(void)=0;
    virtual void TriggerEvent(YEvent e)=0;


};

} // namespace kobu


#endif