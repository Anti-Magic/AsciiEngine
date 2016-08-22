#include "Graph.h"

void Graph::start() {
    pen = new Pen();
}

void Graph::update(double dlt) {
    frame->clear(' ');
    pen->drawDot(frame, Vec2(10, 20), 'D');
    pen->drawLine(frame, Vec2(0, 0), Vec2(20, 20), 'L');
    pen->drawTriangle(frame, Vec2(15, 10), Vec2(25, 10), Vec2(20, 15), 'T');
    pen->drawRect(frame, Vec2(40, 20), Vec2(5, 5), 'R');
    pen->drawPolygon(frame, std::vector<Vec2> {Vec2(30, 10), Vec2(40, 10), Vec2(45, 15), Vec2(35, 15)}, 'P');
    
    static int x = 0;
    pen->drawRect(frame, Vec2(x, 0), Vec2(5, 5), 'M');
    x = (x + 1) % frame->width;
}
