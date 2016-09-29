#ifndef YDEFAULTCOMPOSITOR_H
#define YDEFAULTCOMPOSITOR_H

#include "core/YCompositorInterface.h"
#include "util/YTypes.h"
#include "core/YWindow.h"
#include "core/YEvent.h"

namespace kobu {
    
class YDefaultCompositor : public YCompositorInterface
{
private:
    std::vector<YWindow *> windows;

public :
    YDefaultCompositor(void);
    ~YDefaultCompositor(void);

    void AddWindow(YWindow *window);
    void Draw(void);
    void TriggerEvent(YEvent e);


};

} // namespace kobu


#endif