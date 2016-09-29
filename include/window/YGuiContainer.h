#ifndef YGUICONTAINER_H
#define YGUICONTAINER_H

#include "window/YContainer.h"
#include "window/YLayout.h"

namespace kobu {

class YGuiContainer : public YContainer
{

private :
	YLayout *layout;
	std::vector<YWidget *> widgets;


public :
	YGuiContainer(void);
    ~YGuiContainer(void);
    
    void AddWidget(YWidget *w);
    void Draw(void);
    void Resize(YRect bounds);
    void TriggerEvent(YEvent e);

    void SetLayout(YLayout *l);
    Layout *Getlayout();

};


} // namespace kobu

#endif