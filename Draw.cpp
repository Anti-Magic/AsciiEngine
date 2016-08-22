#include "Draw.h"

void Draw::draw(FrameBuffer* frame) {
    switch(frame->type) {
        case FrameType::Char:
            drawCustom(frame, [=](Pixel& unit) -> void {
                putchar(unit.c);
            });
            break;
        case FrameType::Color:
            drawCustom(frame, [=](Pixel& unit) -> void {
                printf("\033[%d;%dm%c", (int)unit.color, (int)unit.bgColor, unit.c);
            });
            break;
    }
}

void Draw::drawCustom(FrameBuffer* frame, std::function<void(Pixel&)> f) {
    printf("\033[1;1H");
    int width = frame->width;
    int height = frame->height;
    for(int y = height - 1; y >= 0; y--) {
        for(int x = 0; x < width; x++) {
            f(frame->get(x, y));
        }
        puts("\033[0m");
    }
}
