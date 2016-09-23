#ifndef YCONTEXT_H
#define YCONTEXT_H


#include "util/YTypes.h"

namespace Kobu {

class YContext
{
    
private :
    uint32 *buffer;
    uint32 *bufferCopy;
    
    uint32 width;
    uint32 height;
    
    YCompositor *compositor;
    
public :
    YContext(void) {};
    ~YContext(void) {};
    virtual void setupBuffer(uint32 *buffer, uint32 width, uint32 height)=0;
    virtual void flip()=0;
    virtual void flush()=0;
    virtual void destroyBuffer()=0;

};
 
 
} // namespace Kobu


#endif