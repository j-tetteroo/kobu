#ifndef YCOMPOSITOR_H
#define YCOMPOSITOR_H


#include "util/YTypes.h"
#include "core/YWindow.h"

namespace Kobu {
    
class YCompositor
{
private :
    std::vector<YWindow *> windows;
    

public :
    YCompositor(void) {};
    ~YCompositor(void) {};
    virtual draw(void)=0;


};

} // namespace Kobu


#endif