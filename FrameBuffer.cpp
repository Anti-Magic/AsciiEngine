#include "FrameBuffer.h"

Pixel::Pixel() {
    this->c = ' ';
    this->color = Color::Black;
    this->bgColor = BgColor::White;
}

Pixel::Pixel(char c) {
    this->c = c;
}

Pixel::Pixel(char c, Color color, BgColor bgColor) {
    this->c = c;
    this->color = color;
    this->bgColor = bgColor;
}

FrameBuffer::FrameBuffer(int width, int height) {
    this->width = width;
    this->height = height;
    this->type = FrameType::Char;
    buffer = new Pixel[width * height];
}

void FrameBuffer::set(int x, int y, Pixel& t) {
    int idx = y * width + x;
    if(idx < width * height) {
        buffer[idx] = t;
    }
}

Pixel& FrameBuffer::get(int x, int y) {
    int idx = y * width + x;
    return buffer[idx];
}

void FrameBuffer::clear(Pixel t) {
    int size = width * height;
    for(int i = 0; i < size; i++) {
        buffer[i] = t;
    }
}