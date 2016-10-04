#ifndef YBUTTON_H
#define YBUTTON_H

#include <string>
#include <cstdint>

#include "window/YWidget.h"
#include "core/YEvent.h"
#include "events/YMouseEvent.h"

namespace kobu {

class YButton : public YWidget
{
    
private :
    std::string button_text_;

public :
    YButton(std::string text, Vec2 pos);
    ~YButton();
    
    void Draw(YGraphics *g);
    YRect GetBounds();
    void TriggerEvent(YEvent *e);
	void HandleMouseEvent(YMouseEvent *e);


    

};

} // namespace kobu

#endif