#ifndef BadApple_h
#define BadApple_h

#include "Scene.h"
#include "Image.h"

class BadApple : public Scene {
public:
    virtual void start() override;
    virtual void update(double dlt) override;
    
private:
    Image* image;
};

#endif /* BadApple_h */
