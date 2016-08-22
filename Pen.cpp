#include "Pen.h"
#include <cstdlib>

void Pen::drawDot(FrameBuffer* frame, Vec2 p, Pixel t) {
    frame->set(p.x, p.y, t);
}

void Pen::drawLine(FrameBuffer* frame, Vec2 p1, Vec2 p2, Pixel t) {
    int x1 = p1.x;
    int y1 = p1.y;
    int x2 = p2.x;
    int y2 = p2.y;
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    while(true) {
        drawDot(frame, Vec2(x1, y1), t);
        if((x1 == x2) && (y1 == y2)) {
            break;
        }
        int e2 = 2 * err;
        if(e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if(e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void Pen::drawTriangle(FrameBuffer* frame, Vec2 p1, Vec2 p2, Vec2 p3, Pixel t) {
    // sort by y
    Vec2 tmp;
    if(p1.y < p2.y) {
        tmp = p1;
        p1 = p2;
        p2 = tmp;
    }
    if(p2.y < p3.y) {
        tmp = p2;
        p2 = p3;
        p3 = tmp;
    }
    if(p1.y < p2.y) {
        tmp = p1;
        p1 = p2;
        p2 = tmp;
    }
    
    auto drawScanLine = [&](int y, int x1, int x2) -> void {
        int xs = (x1 > x2) ? x2 : x1;
        int xe = (x1 > x2) ? x1 : x2;
        for(int x = xs; x < xe; x++) {
            drawDot(frame, Vec2(x, y), t);
        }
    };
    
    auto drawFlatBottom = [=](Vec2 p1, Vec2 p2, Vec2 p3) -> void {
        int kP12 = (p1.x - p2.x) / (p1.y - p2.y);
        int kP13 = (p1.x - p3.x) / (p1.y - p3.y);
        int ys = p2.y;
        int ye = p1.y;
        int xs = p2.x;
        int xe = p3.x;
        
        for(int y = ys; y <= ye; y++) {
            drawScanLine(y, xs, xe);
            xs += kP12;
            xe += kP13;
        }
    };
    
    auto drawFlatTop = [=](Vec2 p1, Vec2 p2, Vec2 p3) -> void {
        int kP31 = (p3.x - p1.x) / (p3.y - p1.y);
        int kP32 = (p3.x - p2.x) / (p3.y - p2.y);
        int ys = p3.y;
        int ye = p1.y;
        int xs = p3.x;
        int xe = p3.x;
        for(int y = ys; y <= ye; y++) {
            drawScanLine(y, xs, xe);
            xs += kP31;
            xe += kP32;
        }
    };
    
    if(p2.y == p3.y) {
        drawFlatBottom(p1, p2, p3);
    }
    else if(p1.y == p2.y) {
        drawFlatTop(p1, p2, p3);
    }
    else {
        // horizontal ray from p2
        int kP13 = (p1.x - p3.x) / (p1.y - p3.y);
        int x = p1.x - (p1.y - p2.y) * kP13;
        int y = p2.y;
        auto p4 = Vec2(x, y);
        
        drawFlatBottom(p1, p2, p4);
        drawFlatTop(p2, p4, p3);
    }
}

void Pen::drawRect(FrameBuffer* frame, Vec2 p, Vec2 size, Pixel t) {
    int xs = p.x;
    int xe = p.x + size.x;
    int ys = p.y;
    int ye = p.y + size.y;
    for(int x = xs; x < xe; x++) {
        for(int y = ys; y < ye; y++) {
            drawDot(frame, Vec2(x, y), t);
        }
    }
}

void Pen::drawPolygon(FrameBuffer* frame, std::vector<Vec2> vs, Pixel t) {
    for(size_t i = 2; i < vs.size(); i++) {
        drawTriangle(frame, vs[i], vs[i-1], vs[i-2], t);
    }
    drawTriangle(frame, vs[vs.size()-1], vs[0], vs[1], t);
}
