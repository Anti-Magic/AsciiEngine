#ifndef Scene_h
#define Scene_h

#include "Draw.h"
#include "FrameBuffer.h"

class Scene {
public:
    Scene();
    virtual void render();
    
    virtual void start();
    virtual void update(double dlt);
    virtual void stop();
    
protected:
    Draw* draw;
    FrameBuffer* frame;
};

#endif /* Scene_h */
