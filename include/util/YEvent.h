#ifndef YEVENT_H
#define YEVENT_H

namespace Kobu {

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
    EventType getType() const { return et; }
    
};

} // namespace Kobu

#endif