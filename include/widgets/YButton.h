#ifndef YBUTTON_H
#define YBUTTON_H

#include <string>
#include <cstdint>

#include "window/YWidget.h"

namespace kobu {

class YButton : YWidget
{
    
private :
    String button_text;

public :
    YButton(String text, float x, float y) : buttonText(text), YWidget(x,y) {};
    

};

} // namespace kobu

#endif