#ifndef Snake_h
#define Snake_h

#include "Scene.h"
#include "Pen.h"

class Snake : public Scene {
public:
    virtual void start() override;
    virtual void update(double dlt) override;
    
private:
    Pen* pen;
};

#endif /* Snake_h */
