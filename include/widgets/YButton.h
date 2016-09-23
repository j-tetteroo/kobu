#ifndef YBUTTON_H
#define YBUTTON_H

#include <string>
#include <cstdint>

#include "window/YWidget.h"

namespace Kobu {

class YButton : YWidget
{
    
private :
    String buttonText;

public :
    YButton(String text, float x, float y) : buttonText(text), YWidget(x,y) {};
    

};

} // namespace Kobu

#endif