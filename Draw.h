#ifndef Draw_h
#define Draw_h

#include <stdio.h>
#include <functional>
#include "Math.h"
#include "FrameBuffer.h"

class Draw {
public:
    void draw(FrameBuffer* frame);
    void drawCustom(FrameBuffer* frame, std::function<void(Pixel&)> f);
};

#endif /* Draw_h */
