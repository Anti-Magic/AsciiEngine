#include "Scene.h"
#include "Config.h"

Scene::Scene() {
    draw = new Draw();
    frame = new FrameBuffer(Config::ScreenWidth, Config::ScreenHeight);
}

void Scene::render() {
    draw->draw(frame);
}

void Scene::start() {
}

void Scene::update(double dlt) {
}

void Scene::stop() {
}
