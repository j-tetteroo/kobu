#ifndef YWINDOW_H
#define YWINDOW_H

#include <climits>

namespace kobu {

class YWindow
{
protected :
	YRect window;
	uint32_t z;



public :
    YWindow(YRect w) : window(w), z(INT_MAX) {}
    virtual ~YWindow(void) {}
    virtual void Draw(void)=0;
    virtual void TriggerEvent(YEvent e)=0;
    uint32_t GetZ(void) { return z; }

};


} // namespace kobu

#endif

