#ifndef YDEFAULTCOMPOSITOR_H
#define YDEFAULTCOMPOSITOR_H


#include "util/YTypes.h"
#include "core/YWindow.h"
#include "core/YEvent.h"

namespace kobu {
    
class YDefaultCompositor : public YCompositor
{


public :
    YDefaultCompositor(void) {};
    ~YDefaultCompositor(void) {};
    void AddWindow(YWindow *window)=0;
    void Draw(void);
    void TriggerEvent(YEvent e);


};

} // namespace kobu


#endif