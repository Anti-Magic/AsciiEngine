#ifndef Engine_h
#define Engine_h

#include "Scene.h"
#include <time.h>
#include <unistd.h>

class Engine {
public:
    void start(Scene* scene);
    void stop();
    static Engine* instance();
    
private:
    Engine();
    void loop(std::function<void(double)> f);
    
    int fps;
    clock_t last;
    bool running;
};

#endif /* Engine_h */
