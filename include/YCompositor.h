#ifndef YCOMPOSITOR_H
#define YCOMPOSITOR_H


#include "YTypes.h"
#include "core/YWindow.h"

class YCompositor
{
private :
    std::vector<YWindow *> windows;
    

public :
    YCompositor(void) {};
    ~YCompositor(void) {};
    virtual draw(void)=0;


};
 


#endif