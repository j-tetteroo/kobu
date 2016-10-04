#ifndef YEVENT_H
#define YEVENT_H

namespace kobu {

enum class YEventType { 
    MOUSE, 
    KEYBOARD, 
    TOUCH
};

class YEvent
{
    
private :
    YEventType et;
    

public :
    YEvent(YEventType e) : et(e) {}
    YEventType GetType() const { return et; }
    
};

} // namespace kobu

#endif