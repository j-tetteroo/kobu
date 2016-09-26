#ifndef YBUTTON_H
#define YBUTTON_H

#include <string>
#include <cstdint>

#include "window/YWidget.h"

namespace kobu {

class YButton : public YWidget
{
    
private :
    char *button_text;

public :
    
    void Draw(YGraphics *g);
    YRect GetBounds();
    void TriggerEvent(YEvent e);
    ~YButton() {};
    YButton(char *text, Vec2 pos);
    

};

} // namespace kobu

#endif