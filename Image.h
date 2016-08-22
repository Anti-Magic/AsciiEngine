#ifndef Image_h
#define Image_h

#include "FrameBuffer.h"
#include "Math.h"
#include <functional>

class Image {
public:
    int width;
    int height;
    
    int loadFromJpg(const char* path);
    uint8_t* getPixel(int x, int y);
    
    void drawBinary(FrameBuffer* frame, Pixel black, Pixel white);
    void drawColor(FrameBuffer* frame);
    void drawCustom(FrameBuffer* frame, std::function<Pixel(uint8_t*)> f);
    
private:
    uint8_t* buffer;
};

#endif /* Image_h */
