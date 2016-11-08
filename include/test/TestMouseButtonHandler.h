#ifndef TEST_MOUSEBUTTON_HANDLER_H
#define TEST_MOUSEBUTTON_HANDLER_H



#include <iostream>
#include "events/YMouseButtonEventHandler.h"
#include "events/YMouseButtonEvent.h"
#include "util/YTypes.h"


namespace kobu {
    
class TestMouseButtonHandler : public YMouseButtonEventHandler
{
    
private :

    
public :
    TestMouseButtonHandler() {}
    ~TestMouseButtonHandler() {}

    void OnMouseDown(YMouseButtonEvent *e) {
    	Vec2 pos = e->GetPos();
    	std::cout << "MouseDown " << pos.x << "," << pos.y << "\n";
    };
    void OnMouseUp(YMouseButtonEvent *e) {
    	Vec2 pos = e->GetPos();
    	std::cout << "MouseUp " << pos.x << "," << pos.y << "\n";
    };
    void OnClick(YMouseButtonEvent *e) {
    	std::cout << "OnClick\n";

    };
    void OnDoubleClick(YMouseButtonEvent *e) {
    	std::cout << "OnDoubleClick\n";
    };

};

} // namespace kobu

#endif