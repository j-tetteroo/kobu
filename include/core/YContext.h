#ifndef YCONTEXT_H
#define YCONTEXT_H


#include "util/YTypes.h"

namespace kobu {

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
    virtual void SetupBuffer(uint32 *buffer, uint32 width, uint32 height)=0;
    virtual void Flip()=0;
    virtual void Flush()=0;
    virtual void DestroyBuffer()=0;

};
 
 
} // namespace kobu


#endif