#include "Engine.h"

Engine::Engine() {
    fps = 30;
    last = 0;
    running = false;
}

void Engine::loop(std::function<void(double)> f) {
    while(running) {
        clock_t now = clock();
        double dur = (now - last) / CLOCKS_PER_SEC;
        last = now;
        
        f(dur);
        
        double left = (1.0 / fps) - dur;
        if(left > 0) {
            usleep(left * 1000 * 1000);
        }
    }
}

void Engine::start(Scene* scene) {
    running = true;
    scene->start();
    loop([=](double dlt) -> void {
        scene->update(dlt);
        scene->render();
    });
    scene->stop();
}

void Engine::stop() {
    running = false;
}

Engine* Engine::instance() {
    static Engine ins;
    return &ins;
}