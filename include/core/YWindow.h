#ifndef YWINDOW_H
#define YWINDOW_H

#include <climits>

namespace kobu {

class YWindow
{
protected :
    YWindow(YRect w) : window(w), z(INT_MAX) {}

	YContainer *container;
	YRect window;
	uint32_t z;


public :
    virtual ~YWindow(void) {}
    virtual void Draw(void)=0;
    virtual void Resize(YRect bounds);
    virtual void TriggerEvent(YEvent e)=0;
    uint32_t GetZ(void) const { return z; }
    void SetContainer(YContainer *container) { container = container; }

};


} // namespace kobu

#endif

