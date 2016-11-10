#ifndef YBUTTON_H
#define YBUTTON_H

#include <string>
#include <cstdint>

#include "window/YWidget.h"
#include "core/YEvent.h"
#include "events/YMouseButtonEvent.h"

namespace kobu {

class YButton : public YWidget
{
    
private :
    std::string button_text_;
    uint32_t color_;

public :
    YButton(std::string text, uint32_t color, float x, float y);
    ~YButton();
    
    void Draw(YGraphics *g) override;
    YWidget* TriggerEvent(YMouseButtonEvent *e) override;
    YWidget* AcceptFocus() override;

    

};

} // namespace kobu

#endif