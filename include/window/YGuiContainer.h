#ifndef YGUICONTAINER_H
#define YGUICONTAINER_H

#include <vector>

#include "window/YContainer.h"
#include "window/YLayout.h"
#include "window/YWidget.h"
#include "core/YEvent.h"
#include "events/YMouseEvent.h"
#include "util/YTypes.h"
#include "window/YLayout.h"


namespace kobu {

class YGuiContainer : public YContainer
{

private :
    std::vector<YWidget *> widgets_;
	YLayout *layout_;
	void HandleMouseEvent(YMouseEvent *e);


public :
	YGuiContainer(YRect bounds, YRect clip_region, YLayout *l);
    ~YGuiContainer(void);
    
    void AddWidget(YWidget *w);
    void Draw(YGraphics *g);
    void Resize(YRect bounds);
    void TriggerEvent(YEvent *e);
    void Layout();

    void SetLayout(YLayout *l) { layout_ = l; }
    YLayout *Getlayout(void) const { return layout_; }

    std::vector<YWidget *> *GetWidgetPtr() { return &widgets_; }

};


} // namespace kobu

#endif