#ifndef Pen_h
#define Pen_h

#include <vector>
#include "FrameBuffer.h"
#include "Math.h"

class Pen {
public:
    void drawDot(FrameBuffer* frame, Vec2 p, Pixel t);
    void drawLine(FrameBuffer* frame, Vec2 p1, Vec2 p2, Pixel t);
    void drawTriangle(FrameBuffer* frame, Vec2 p1, Vec2 p2, Vec2 p3, Pixel t);
    void drawRect(FrameBuffer* frame, Vec2 p, Vec2 size, Pixel t);
    void drawPolygon(FrameBuffer* frame, std::vector<Vec2> vs, Pixel t);
};

#endif /* Pen_h */
