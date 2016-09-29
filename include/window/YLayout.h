#ifndef YLAYOUT_H
#define YLAYOUT_H

namespace kobu {
    
class YLayout
{

protected :	


public :
    virtual ~YLayout(void) {}

    virtual void AddWidget(YWidget *w)=0;
    virtual void Layout()=0;

    virtual YRect GetBounds()=0;
    virtual void SetBounds(YRect bounds)=0;



};

} // namespace kobu

#endif