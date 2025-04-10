#include "scene_manager.hpp"

SceneManager::SceneManager() = default;
SceneManager::~SceneManager() = default;

void SceneManager::addScene(const std::string& name, std::shared_ptr<Scene> scene) {
    scenes[name] = scene;
}

void SceneManager::changeScene(const std::string& name) {
    if (scenes.find(name) != scenes.end()) {
        currentScene = scenes[name];
    }
}

void SceneManager::update() {
    if (currentScene) {
        currentScene->update();
    }
}

void SceneManager::render(Renderer& renderer) {
    if (currentScene) {
        currentScene->render(renderer);
    }
}

void SceneManager::handleInput(SDL_Event& event) {
    if (currentScene) {
        currentScene->handleInput(event);
    }
}
