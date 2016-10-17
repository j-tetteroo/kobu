#ifndef YDEFAULTWINDOW_H
#define YDEFAULTWINDOW_H

#include <climits>

#include "core/YWindow.h"

namespace kobu {

class YDefaultWindow : public YWindow
{

private:
	YContainer *container_;
    YRect bounds_;
    uint32_t z_;

    YSpace padding_;

public :

    YDefaultWindow(YContainer *c, YRect w) : container_(c), bounds_(w), z_(INT_MAX) {
        padding_.top = padding_.bottom = padding_.left = padding_.right = 0.0;
    };
    ~YDefaultWindow(void);
    
    void Draw(YGraphics *g) override;
    void Resize(YRect bounds) override;
    void TriggerEvent(YEvent *e) override;
    void Destroy() override;

    YContainer *GetContainer(void) const override { return container_; }
    void SetContainer(YContainer *container) override { container_ = container; }

    // layout
    uint32_t GetZ(void) const override { return z_; }
    void SetZ(uint32_t z) override { z_ = z; }
    YRect GetBounds(void) const override { return bounds_; }
    void SetBounds(YRect bounds) override { bounds_ = bounds; }
    YSpace GetPadding(void) const override { return padding_; }
    void SetPadding(YSpace p) override { padding_ = p; }

    // extra
    void HandleMouseEvent(YMouseEvent *e);

};


} // namespace kobu

#endif
