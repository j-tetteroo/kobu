#ifndef YLABEL_H
#define YLABEL_H

#include <string>
#include <cstdint>

#include "window/YWidget.h"

namespace kobu {

class YLabel : YWidget
{
    
private :
    String label_text;

public :
    YLabel(String text, float x, float y) : labelText(text), YWidget(x,y) {};
    

};

} // namespace kobu

#endif