#ifndef YGUICONTAINER_H
#define YGUICONTAINER_H

#include <vector>

#include "window/YContainer.h"
#include "window/YLayout.h"
#include "window/YWidget.h"
#include "core/YEvent.h"
#include "events/YMouseEvent.h"
#include "util/YTypes.h"


namespace kobu {

class YGuiContainer : public YContainer
{

private :
	YLayout *layout_;
	std::vector<YWidget *> widgets_;

	void HandleMouseEvent(YMouseEvent *e);


public :
	YGuiContainer(YRect bounds, YRect clip_region);
    ~YGuiContainer(void);
    
    void AddWidget(YWidget *w);
    void Draw(YGraphics *g);
    void Resize(YRect bounds);
    void TriggerEvent(YEvent *e);

    void SetLayout(YLayout *l);
    YLayout *Getlayout(void);

};


} // namespace kobu

#endif