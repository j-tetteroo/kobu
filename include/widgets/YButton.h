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
    YButton(char *text, Vec2 pos);
    void Draw(YGraphics *g);
    YRect GetBounds();
    void TriggerEvent(YEvent e);
    ~YButton() {};

    

};

} // namespace kobu

#endif