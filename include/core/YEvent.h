#ifndef YEVENT_H
#define YEVENT_H

namespace kobu {

enum class EventType { 
    MOUSE, 
    KEYBOARD, 
    TOUCH
};

class YEvent
{
    
private :
    EventType et;
    

public :
    YEvent(EventType e) : et(e) {}
    EventType GetType() const { return et; }
    
};

} // namespace kobu

#endif