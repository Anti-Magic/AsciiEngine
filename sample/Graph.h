#ifndef Graph_h
#define Graph_h

#include "Scene.h"
#include "Pen.h"

class Graph : public Scene {
public:
    virtual void start() override;
    virtual void update(double dlt) override;
    
private:
    Pen* pen;
};

#endif /* Graph_h */
