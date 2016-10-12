#ifndef YABSOLUTELAYOUT_H
#define YABSOLUTELAYOUT_H

#include "window/YWidget.h"
#include "window/YContainer.h"
#include "window/YLayout.h"

namespace kobu {
    

// Layout for absolute positioning of widgets
// This does not change widget positions when Layout() is called, only suitable for prototype purposes

class YAbsoluteLayout : public YLayout
{

private :


public :
	YAbsoluteLayout();
    ~YAbsoluteLayout(void);

    void Layout(void);

};

} // namespace kobu

#endif