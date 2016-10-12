#ifndef YDEFAULTWINDOW_H
#define YDEFAULTWINDOW_H

#include <climits>

#include "core/YWindow.h"
#include "widgets/YDefaultWindowDecorator.h"

namespace kobu {

class YDefaultWindow : public YWindow
{

public :
    YDefaultWindow(YRect w, YContainer *c, YDefaultWindowDecorator *d);
    ~YDefaultWindow(void);
    
    void Draw(YGraphics *g);
    void Resize(YRect bounds);
    void TriggerEvent(YEvent *e);

};


} // namespace kobu

#endif
