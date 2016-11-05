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
    uint32_t time;

    

public :
    YEvent(YEventType e, uint32_t time) : et(e), time(time) {}
    YEventType GetType(void) const { return et; }
    uint32_t GetTime(void) const { return time; }
    
};

} // namespace kobu

#endif