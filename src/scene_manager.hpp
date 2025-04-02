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
    void render();

    void addScene(const std::string& name, std::unique_ptr<Scene> scene);

private:
    std::unordered_map<std::string, std::unique_ptr<Scene>> scenes;
    Scene* currentScene;
};

#endif
