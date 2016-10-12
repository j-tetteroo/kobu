#ifndef YLAYOUT_H
#define YLAYOUT_H

#include <vector>
#include "window/YWidget.h"
#include "window/YContainer.h"


namespace kobu {
    
class YLayout
{

private :	
	float padding_;
	YRect bounds_;

	std::vector<YWidget *> *widgets_;


public :
	YLayout() { bounds_.x = bounds_.y = bounds_.w = bounds_.h = 0.0; widgets_ = nullptr; }
    virtual ~YLayout(void) {}

    virtual void Layout(void)=0;

    YRect GetBounds(void) const { return bounds_; }
    void SetBounds(YRect bounds) { bounds_ = bounds; }
    std::vector<YWidget *> *GetWidgets() const { return widgets_; }
    void SetWidgets(std::vector<YWidget *> *w) { widgets_ = w; }



};

} // namespace kobu

#endif