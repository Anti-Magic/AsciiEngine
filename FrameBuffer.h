#ifndef FrameBuffer_h
#define FrameBuffer_h

#include <vector>
#include "Enums.h"

class Pixel {
public:
    char c;
    Color color;
    BgColor bgColor;
    
    Pixel();
    Pixel(char c);
    Pixel(char c, Color color, BgColor bgColor);
};

enum class FrameType {
    Char,
    Color
};

class FrameBuffer {
public:
    int width;
    int height;
    FrameType type;
    Pixel* buffer;
    
    FrameBuffer(int width, int height);
    void set(int x, int y, Pixel& t);
    Pixel& get(int x, int y);
    void clear(Pixel t);
};

#endif /* FrameBuffer_h */
