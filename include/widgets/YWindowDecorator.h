#ifndef YWINDOWDECORATOR_H
#define YWINDOWDECORATOR_H

#include <string>

#include "core/YGraphics.h"
#include "window/YWidget.h"
#include "util/YTypes.h"
#include "core/YWindow.h"

namespace kobu {
    
    
class YWindowDecorator : public YWindow
{
private :
	YWindow *parent_;
    

public :

	YWindowDecorator(YWindow *parent) : parent_(parent) {}
    virtual ~YWindowDecorator() {};

    virtual void Draw(YGraphics *g) override = 0;
    virtual void TriggerEvent(YEvent *e) override = 0;
    virtual void Resize(YRect bounds) override = 0;
    virtual void Destroy() override = 0;

    YContainer *GetContainer(void) const override { return parent_->GetContainer(); }
    void SetContainer(YContainer *container) override { parent_->SetContainer(container); }

    // layout
    uint32_t GetZ(void) const override { return parent_->GetZ(); }
    void SetZ(uint32_t z) override { parent_->SetZ(z); }
    YRect GetBounds(void) const override { return parent_->GetBounds(); }
    void SetBounds(YRect bounds) override { parent_->SetBounds(bounds); }
    YSpace GetPadding(void) const override { return parent_->GetPadding(); }
    void SetPadding(YSpace p) override { parent_->SetPadding(p); }


    // extra
    YWindow *GetParent(void) { return parent_; }
    void SetParent(YWindow *p) { parent_ = p; }

};

} // namespace kobu


#endif