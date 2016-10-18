#ifndef YCLOSEBUTTON_H
#define YCLOSEBUTTON_H

#include <string>
#include <cstdint>

#include "window/YWidget.h"
#include "core/YEvent.h"
#include "events/YMouseEvent.h"
#include "core/YGraphics.h"
#include "core/YWindow.h"


namespace kobu {

class YCloseButton : public YWidget
{
    
private :
	YWindow *parent_;


public :
    YCloseButton(YWindow *parent, float x, float y);
    ~YCloseButton();
    
    void Draw(YGraphics *g);
    void TriggerEvent(YEvent *e);
	void HandleMouseEvent(YMouseEvent *e);

};

} // namespace kobu

#endif