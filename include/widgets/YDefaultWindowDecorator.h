#ifndef YDEFAULTWINDOWDECORATOR_H
#define YDEFAULTWINDOWDECORATOR_H

#include <string>

#include "core/YGraphics.h"
#include "window/YWidget.h"
#include "widgets/YWindowDecorator.h"
#include "util/YTypes.h"

namespace kobu {

class YDefaultWindowDecorator : public YWindowDecorator
{

private :


public :

	YDefaultWindowDecorator(YRect bounds);
    ~YDefaultWindowDecorator();

    void Draw(YGraphics *g);
    void TriggerEvent(YEvent *e);

    void DrawTitleBar(YGraphics *g);
    void DrawWindowEdge(YGraphics *g);
    YRect GetContainerSize(YRect bounds);

};

} // namespace kobu


#endif