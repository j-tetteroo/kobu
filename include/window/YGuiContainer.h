#ifndef YGUICONTAINER_H
#define YGUICONTAINER_H

#include <vector>

#include "window/YContainer.h"
#include "window/YLayout.h"
#include "window/YWidget.h"
#include "core/YEvent.h"
#include "events/YMouseButtonEvent.h"
#include "util/YTypes.h"
#include "window/YLayout.h"


namespace kobu {

class YGuiContainer : public YContainer
{

private :
    std::vector<YWidget *> widgets_;
	YLayout *layout_;


public :
	YGuiContainer(YRect bounds, YRect clip_region, YLayout *l);
    ~YGuiContainer(void);
    
    void AddWidget(YWidget *w);
    YWidget* AcceptFocus() override;
    void Draw(YGraphics *g) override;
    void Resize(YRect bounds);
    void Scroll(float x_offset, float y_offset);

    void TriggerEvent(YMouseMoveEvent *e, bool leave_widget) override;
    YWidget* TriggerEvent(YMouseButtonEvent *e) override;
    
    void Layout();


    void SetLayout(YLayout *l) override { layout_ = l; }
    YLayout *Getlayout(void) const override { return layout_; }

    std::vector<YWidget *> *GetWidgetPtr() { return &widgets_; }

};


} // namespace kobu

#endif