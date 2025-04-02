#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <memory>
#include <unordered_map>
#include "scenes/scene.hpp"

class SceneManager {
public:
    SceneManager();
    ~SceneManager();

    void changeScene(const std::string& sceneName);
    void update();
    void render(Renderer& renderer);
    void handleInput(SDL_Event& event);

    void addScene(const std::string& name, std::shared_ptr<Scene> scene);

private:
    std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> currentScene;
};

#endif
