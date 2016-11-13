#ifndef TEST_MOUSEMOVE_HANDLER_H
#define TEST_MOUSEMOVE_HANDLER_H



#include <iostream>
#include "events/YMouseButtonEventHandler.h"
#include "events/YMouseButtonEvent.h"
#include "events/YMouseMoveEventHandler.h"
#include "events/YMouseMoveEvent.h"
#include "util/YTypes.h"


namespace kobu {
    
class TestMouseMoveHandler : public YMouseMoveEventHandler
{
    
private :

    
public :
    TestMouseMoveHandler() {}
    ~TestMouseMoveHandler() {}

    void OnMouseMove(YMouseMoveEvent *e) override {
        Vec2 pos = e->GetPos();
        std::cout << "MouseMove " << pos.x << "," << pos.y << "\n";
    };
    void OnMouseDrag(YMouseMoveEvent *e) override {
        Vec2 pos = e->GetPos();
        std::cout << "MouseDrag " << pos.x << "," << pos.y << "\n";
    };
    void OnMouseEnter(YMouseMoveEvent *e) override {

    };
    void OnMouseLeave(YMouseMoveEvent *e) override {

    };

};

} // namespace kobu

#endif