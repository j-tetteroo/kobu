#ifndef YCOMPOSITOR_H
#define YCOMPOSITOR_H


#include "util/YTypes.h"
#include "core/YWindow.h"

namespace kobu {
    
class YCompositor
{
private :
    std::vector<YWindow *> windows;
    

public :
    YCompositor(void) {};
    ~YCompositor(void) {};
    virtual Draw(void)=0;


};

} // namespace kobu


#endif