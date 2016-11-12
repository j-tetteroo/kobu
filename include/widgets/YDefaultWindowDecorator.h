#ifndef YDEFAULTWINDOWDECORATOR_H
#define YDEFAULTWINDOWDECORATOR_H

#include <string>

#include "core/YGraphics.h"
#include "window/YWidget.h"
#include "widgets/YWindowDecorator.h"
#include "util/YTypes.h"
#include "widgets/YCloseButton.h"
#include "events/YMouseButtonEvent.h"
#include "events/YMouseMoveEvent.h"
#include "window/YGuiContainer.h"
#include "window/YLayout.h"
#include "layout/YAbsoluteLayout.h"

namespace kobu {

class YDefaultWindowDecorator : public YWindowDecorator
{

private :
	YCloseButton *close_button_;
	YWindow *parent_;
	YRect bounds_;
    YGuiContainer *title_bar_container_;


public :

	YDefaultWindowDecorator(YWindow *parent);
    ~YDefaultWindowDecorator();

    void Draw(YGraphics *g) override;
    void Resize(YRect bounds) override;
    void TriggerEvent(YMouseButtonEvent *e) override;
    void TriggerEvent(YMouseMoveEvent *e) override;
    void Destroy() override;

    void DrawTitleBar(YGraphics *g);
    void DrawWindowEdge(YGraphics *g);

    float GetEdgeWidth(void);
    float GetTitleBarHeight(void);

    bool DecoratorHit(Vec2 loc);

};

} // namespace kobu


#endif